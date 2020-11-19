#include <stdlib.h>
#include <3ds.h>
#include "menu.hpp"
#include "patch.hpp"
#include "settings.hpp"

u8 mode;
u8 settingIdx;
u8 menuIdx;
int settingBound;
int menuBound;
Menu* currentMenu;
Option* currentSetting;
PrintConsole topScreen, bottomScreen;

void MenuInit() {
  consoleInit(GFX_TOP,    &topScreen);
  consoleInit(GFX_BOTTOM, &bottomScreen);
  consoleSelect(&topScreen);

  printf("OoT3D Randomizer testing!\n");
  printf("Press Select to exit!\n");
  printf("Use D-pad to select settings!\n");
  printf("Press Start to create the patch!\n");

  mode = MAIN_MENU;
  menuIdx = 0;
  menuBound = 0;
  settingIdx = 0;
  settingBound = 0;
  currentMenu = Settings::mainMenu[menuIdx];
  currentSetting = Settings::mainMenu[menuIdx]->settingsList[settingIdx];
}

void MenuUpdate(u32 kDown) {
  //clear the console if a button was pressed
  if (kDown & KEY_DUP || kDown & KEY_DDOWN || kDown & KEY_DLEFT || kDown & KEY_DRIGHT || kDown & KEY_A || kDown & KEY_B) {
			consoleSelect(&bottomScreen);
			consoleClear();
	}

	if (kDown & KEY_START) {
    GenerateRandomizer();
    return;
  }


	//Check for a menu change
	if (kDown & KEY_A && mode == MAIN_MENU) {
		mode = SUB_MENU;
		settingIdx = 0;
		currentSetting = currentMenu->settingsList[settingIdx];
	} else if (kDown & KEY_B && mode == SUB_MENU) {
		mode = MAIN_MENU;
		currentMenu = Settings::mainMenu[menuIdx];
	}

	//Print current menu
	consoleSelect(&bottomScreen);
	if (mode == MAIN_MENU) {
		UpdateMainMenu(kDown);
		PrintMainMenu();
	} else if (mode == SUB_MENU) {
		UpdateSubMenu(kDown);
		PrintSubMenu();
	}
	consoleSelect(&topScreen);
}

void UpdateMainMenu(u32 kDown) {
	if (kDown & KEY_DUP && menuIdx != 0)
			menuIdx--;

	if (kDown & KEY_DDOWN && menuIdx != Settings::mainMenu.size() - 1)
			menuIdx++;

	currentMenu = Settings::mainMenu[menuIdx];
}

void UpdateSubMenu(u32 kDown) {
	if (kDown & KEY_DUP && settingIdx != 0)
    settingIdx--;

	if (kDown & KEY_DDOWN && settingIdx != currentMenu->settingsList.size() - 1)
		settingIdx++;

	currentSetting = currentMenu->settingsList[settingIdx];

	if (kDown & KEY_DRIGHT) {
		if (currentSetting->selectedOption != currentSetting->options.size() - 1)
			currentSetting->selectedOption++;
	}
	if (kDown & KEY_DLEFT) {
		if (currentSetting->selectedOption != 0)
			currentSetting->selectedOption--;
	}
}

void PrintMainMenu() {
	printf("\x1b[0;%dHMain Settings Menu", (BOTTOM_COLUMNS/2) - 9);

	for (u8 i = 0; i < MAX_SETTINGS_ON_SCREEN; i++) {
		if (i + menuBound >= Settings::mainMenu.size()) break;

		Menu* menu = Settings::mainMenu[i + menuBound];

    //make the current menu green
    u8 row = 3 + i;
		if (menuIdx == i + menuBound) {
			printf("\x1b[%d;%dH\x1b[32m>", row,  1);
			printf("\x1b[%d;%dH%s\x1b[0m", row,  2, menu->name.c_str());
		} else {
			printf("\x1b[%d;%dH%s\x1b[0m", row,  2, menu->name.c_str());
		}
	}
}

void PrintSubMenu() {
	//bounds checking incase settings go off screen
	if (settingIdx >= settingBound + MAX_SETTINGS_ON_SCREEN) {
		settingBound++;
	} else if (settingIdx < settingBound)  {
		settingBound = settingIdx;
	}

	//print menu name
	printf("\x1b[0;%dH%s", (BOTTOM_COLUMNS/2) - (currentMenu->name.length()/2), currentMenu->name.c_str());

	for (u8 i = 0; i < MAX_SETTINGS_ON_SCREEN; i++) {

    //break if there are no more settings
		if (i + settingBound >= currentMenu->settingsList.size()) break;

		Option* setting = currentMenu->settingsList[i + settingBound];

		u8 row = 3 + (i * 2);
    //make the current setting green
		if (settingIdx == i + settingBound) {
			printf("\x1b[%d;%dH\x1b[32m>", row,  1);
			printf("\x1b[%d;%dH%s:",       row,  2, setting->name.c_str());
			printf("\x1b[%d;%dH%s\x1b[0m", row, 26, setting->options[setting->selectedOption].c_str());
		} else {
			printf("\x1b[%d;%dH%s:",       row,  2, setting->name.c_str());
			printf("\x1b[%d;%dH%s",        row, 26, setting->options[setting->selectedOption].c_str());
		}

		setting->SetVariable();
	}
}

void GenerateRandomizer() {
	Overrides.clear();
	consoleClear();
	int ret = Playthrough::Fill(0, Settings::seed, Overrides);
	if (ret < 0) {
		printf("Error %d with fill. Press Start to exit.\n", ret);
		return;
	}
	printf("about to write overrides to patch\n");
	if (WriteOverridesToPatch()) {
		printf("Created the patch. Have fun!\n");
	} else {
		printf("Error creating patch. Press Start to exit.\n");
	}
}
