#include "Game.h"
#include "FocusStates.h"
#include "EventQueue.h"
#include "Files.h"

void SetGameFunctions();

void PlayTest() {
	PlayAudio("test");
	PushEvent(PlayTest, 1000);
}

void InitGame() {
	InitWindow("MiniNinja");
	InitTextures();
	InitAudio();
	InitFonts();
	InitConsole();
	if (!SetFocusScene(LoadScene("Scenes/asdf"))) {
		Log("Default scene failed to load.", FAULT);
	}
	if (!SetPauseScene(LoadScene("Scenes/pausescreen"))) {
		Log("Pause scene failed to load.", FAULT);
	}
	SetFocus(FOCUS_SCENE);
	SetGameFunctions();
	Log("Type \"help()\" for a list of functions.");
	LoadAudio("Resources/Audio/test.mp3");
	// PlayTest();
}

void UpdateGame() {
	HandleWindowEvents();
	HandleInputEvents();

	HandleFocusSwitching();
	UpdateFocus();
}

void RenderGame() {
	RenderFocus();
}

void SetGameFunctions() {
	SetFunction([](std::vector<std::string> args) {
		if (args.size() == 1 && IsInteger(args[0])) {
			Game::targetFPS = std::stoi(args[0]);
			return true;
		}
		return false;
		}, "setfps"
	);
	SetFunction([](std::vector<std::string> args) {
		return std::to_string(Game::targetFPS);
		}, "getfps"
	);
	SetFunction([](std::vector<std::string> args) {
		return std::to_string(GetWindowSize().x) + ", " + std::to_string(GetWindowSize().y);
		}, "getwindowsize"
	);
	SetFunction([](std::vector<std::string> args) {
		if (args.size() == 2 && IsInteger(args[0]) && IsInteger(args[1])) {
			SetWindowSize({ std::stoi(args[0]), std::stoi(args[1]) });
			return true;
		}
		return false;
		}, "setwindowsize"
	);
	SetFunction([](std::vector<std::string> args) {
		if (args.size() == 1) {
			SetWindowTitle(args[0]);
			return true;
		}
		return false;
		}, "setwindowtitle"
	);
	SetFunction([](std::vector<std::string> args) {
		if (args.size() == 1) {
			return SaveScene(GetFocusScene(), ForceFileDirectory(args[0], "Scenes"));
		}
		return false;
		}, "savescene"
	);
	SetFunction([](std::vector<std::string> args) {
		if (args.size() == 1) {
			Scene* oldScene = GetFocusScene();
			if (SetFocusScene(LoadScene(ForceFileDirectory(args[0], "Scenes")))) {
				delete oldScene;
				return true;
			}
		}
		return false;
		}, "loadscene"
	);
}