#pragma once
#include "Graphics.h"

namespace SDLFramework {

	class SDLGraphics : public Graphics
	{
	public:
		static SDLGraphics* Instance();

		virtual void DrawTexture(SDL_Texture* tex, SDL_Rect* srcRect = nullptr, SDL_Rect* dstRect = nullptr, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE) override;

		virtual void ClearBackBuffer() override;
		virtual void Render() override;

		SDLGraphics();
		~SDLGraphics();

	protected:
		virtual bool Init() override;
	};
}