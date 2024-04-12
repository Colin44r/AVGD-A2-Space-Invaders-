#include "GameManager.h"

namespace SDLFramework {

	GameManager* GameManager::sInstance = nullptr;

	GameManager* GameManager::Instance() {
		if (sInstance == nullptr) {
			sInstance = new GameManager();
		}
		return sInstance;
	}

	void GameManager::Release() {
		delete sInstance;
		sInstance = nullptr;
	}

	void GameManager::Run() {
		while (!mQuit) {
			mTimer->Update();

			while (SDL_PollEvent(&mEvent)) {
				switch (mEvent.type) {
				case SDL_QUIT:
					mQuit = true;
					break;
				}
			}

			if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE) {
				Update();
				LateUpdate();
				Render();
				mTimer->Reset();
			}
		}
	}

	void GameManager::Update() {
		mInputManager->Update();
		mScreenManager->Update();

	}

	void GameManager::LateUpdate() {
		mPhysicsManager->Update();

		mInputManager->UpdatePrevInput();
	}

	void GameManager::Render() {
		mGraphics->ClearBackBuffer();
		mScreenManager->Render();
		//DON'T ADD ANY RENDER CALLS BELOW THE mGraphics RENDER CALL
		//IF YOU DO, IT WON'T RENDER
		mGraphics->Render();
	}

	GameManager::GameManager() : mQuit(false) {
		mGraphics = Graphics::Instance();

		if (!Graphics::Initialized()) {
			mQuit = true;
		}

		mAssetManager = AssetManager::Instance();
		mInputManager = InputManager::Instance();
		mAudioManager = AudioManager::Instance();
		mScreenManager = ScreenManager::Instance();
		mPhysicsManager = PhysicsManager::Instance();

		mPhysicsManager->SetLayerCollisionMask(
			PhysicsManager::CollisionLayers::Friendly,
			PhysicsManager::CollisionFlags::Hostile |
			PhysicsManager::CollisionFlags::HostileProjectiles);

		mPhysicsManager->SetLayerCollisionMask(
			PhysicsManager::CollisionLayers::FriendlyProjectiles,
			PhysicsManager::CollisionFlags::Hostile);

		mPhysicsManager->SetLayerCollisionMask(
			PhysicsManager::CollisionLayers::Hostile,
			PhysicsManager::CollisionFlags::Friendly |
			PhysicsManager::CollisionFlags::FriendlyProjectiles);

		mPhysicsManager->SetLayerCollisionMask(
			PhysicsManager::CollisionLayers::HostileProjectiles,
			PhysicsManager::CollisionFlags::Friendly);

		mTimer = Timer::Instance();

		mStartScreen = new StartScreen();
	}

	GameManager::~GameManager() {

		delete mStartScreen;
		mStartScreen = nullptr;

		Timer::Release();
		mTimer = nullptr;

		AudioManager::Release();
		mAudioManager = nullptr;

		InputManager::Release();
		mInputManager = nullptr;

		AssetManager::Release();
		mAssetManager = nullptr;

		Graphics::Release();
		mGraphics = nullptr;

		ScreenManager::Release();
		mScreenManager = nullptr;

		PhysicsManager::Release();
		mPhysicsManager = nullptr;

		// Quit SDL subsystems
		SDL_Quit();
	}
}