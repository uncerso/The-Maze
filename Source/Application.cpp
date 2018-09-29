#include "Application.h"
#include "MainForm.h"

Application::Application()
	: mainWindow(nullptr)
{}

Application::~Application() {};

void Application::initialise(String const &) {
	mainWindow.reset(new MainForm());
}

void Application::shutdown() {}

void Application::systemRequestedQuit() {
	quit();
}

const String Application::getApplicationName() {
	return "Some project...";
}

const String Application::getApplicationVersion() {
	return ProjectInfo::versionString;
}

bool Application::moreThanOneInstanceAllowed() {
	return false;
}