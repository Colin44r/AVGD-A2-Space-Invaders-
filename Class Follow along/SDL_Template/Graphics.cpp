#include "Graphics.h"
#include "SDLGraphics.h"

namespace SDLFramework {

	Graphics* Graphics::sInstance = nullptr;
	bool Graphics::sInitialized = false;

	// static member functions
	Graphics* Graphics::Instance() {
		if (sInstance == nullptr) {
			sInstance = new SDLGraphics();
		}

		return sInstance;
	}

	void Graphics::Release() {
		delete sInstance;
		sInstance = nullptr;
		sInitialized = false;
	}

	bool Graphics::Initialized() {
		return sInitialized;
	}

	SDL_Texture* Graphics::LoadTexture(std::string path) {
		SDL_Texture* tex = nullptr;
		SDL_Surface* surface = IMG_Load(path.c_str());

		if (surface == nullptr) {
			std::cerr << "Unable to load " << path << ". IMG Error: " << IMG_GetError() << std::endl;
			return nullptr;
		}

		tex = SDL_CreateTextureFromSurface(mRenderer, surface);
		if (tex == nullptr) {
			std::cerr << "Unable to create texture from surface! IMG Error: " << IMG_GetError() << std::endl;
			return nullptr;
		}

		SDL_FreeSurface(surface);
		return tex;
	}

	SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color) {
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
		if (surface == nullptr) {
			std::cerr << "CreateTextTexture:: TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
			return nullptr;
		}

		SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);
		if (tex == nullptr) {
			std::cerr << "CreateTextTexture:: SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			return nullptr;
		}

		SDL_FreeSurface(surface);
		return tex;
	}

	//void Graphics::DrawTexture(SDL_Texture * tex, SDL_Rect * srcRect, SDL_Rect * dstRect, float angle, SDL_RendererFlip flip) {
	//	SDL_RenderCopyEx(mRenderer, tex, srcRect, dstRect, angle, nullptr, flip);
	//}

	void Graphics::DrawLine(float startX, float startY, float endX, float endY) {
		SDL_Color color;
		SDL_GetRenderDrawColor(mRenderer, &color.r, &color.g, &color.b, &color.a);
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(mRenderer, (int)startX, (int)startY, (int)endX, (int)endY);
		SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, color.a);
	}

	//void Graphics::ClearBackBuffer() {
	//	SDL_RenderClear(mRenderer);
	//}

	//public member functions
	//void Graphics::Render() {
	//	SDL_RenderPresent(mRenderer);

	//	////sets the depth to 1.0
	//	//glClearDepth(1.0);

	//	////clear the color and depth buffer
	//	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	////Let GL know we want to use color
	//	//glEnableClientState(GL_COLOR_ARRAY);

	//	////Draw the triangle
	//	//glBegin(GL_TRIANGLES);
	//	//glColor3f(1.0f, 0.0f, 0.0f);

	//	//glVertex2f(0.0f, 0.0f);
	//	//glVertex2f(0.0f, -1.0f);
	//	//glVertex2f(-1.0f, -1.0f);

	//	//glEnd();

	//	////Swap our buffer and draw to the screen.
	//	//SDL_GL_SwapWindow(mWindow);

	//}

	//private member functions
	Graphics::Graphics() : mRenderer(nullptr) {
		sInitialized = Init();
	}

	Graphics::~Graphics() {
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);

		mRenderer = nullptr;
		mWindow = nullptr;

		TTF_Quit();
		IMG_Quit();
	}

	bool Graphics::Init() {
		if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
			std::cerr << "Unable to initialize SDL video! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}
		mWindow = SDL_CreateWindow(
			WINDOW_TITLE,				// window title
			SDL_WINDOWPOS_UNDEFINED,	// window xpos
			SDL_WINDOWPOS_UNDEFINED,	// window ypos
			SCREEN_WIDTH,				// window width
			SCREEN_HEIGHT,				// window height
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);			// window flags
		if (mWindow == nullptr) {
			std::cerr << "Unable to create Window! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		if (mRenderer == nullptr) {
			std::cerr << "Unable to create renderer! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		int flags = IMG_INIT_PNG;
		if (!(IMG_Init(flags) & flags)) {
			std::cerr << "Unable to initialize SDL_image! IMG Error: " << IMG_GetError() << std::endl;
			return false;
		}

		if (TTF_Init() == -1) {
			std::cerr << "Unable to initialized SDL_ttf! TTF Error: " << TTF_GetError() << std::endl;
			return false;
		}

		//Setup openGL Context

		//glContext = SDL_GL_CreateContext(mWindow);
		//if (glContext == nullptr)
		//{
		//	std::cerr << "SDL_GL context could not be created!";
		//}

		////Setup glew
		//GLenum error = glewInit();
		//if (error != GLEW_OK)
		//{
		//	std::cerr << "Could not initialize glew!";
		//}

		////Enables a double buffer window - removes flickering.
		//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		//glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

		return true;
	}
}