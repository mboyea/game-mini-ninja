#include "FocusStates.h"
#include "Input.h"
#include "Draw.h"
#include "Scene.h"
#include "Window.h"
#include "Log.h"

static Scene emptyScene = Scene();
static Scene* currentScene = &emptyScene;

void HandleSwitchScene() {
	if (IsKeyPressed(SDL_SCANCODE_ESCAPE)) {
		SetFocus(FOCUS_PAUSE);
		return;
	}
	else if (IsKeyPressed(SDL_SCANCODE_GRAVE)) {
		if (IsKeyDown(SDL_SCANCODE_LSHIFT)) {
			SetFocus(FOCUS_EDITOR);
			return;
		}
		SetFocus(FOCUS_DEBUG);
		return;
	}
}

void UpdateScene() {
	currentScene->Update();
}

void RenderScene() {
	SetDrawColor(Colors::CYAN);
	Paint();
	currentScene->Render();
}

bool SetCurrentScene(Scene* scene) {
	if (!scene) {
		Log("Failed to change active scene.", WARNING);
		return false;
	}
	currentScene = scene;
	SetRenderTarget(currentScene->camera);
	return true;
}

Scene* GetCurrentScene() {
	return currentScene;
}