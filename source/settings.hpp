#pragma once
#include <stdlib.h>
#include <3ds.h>
#include <string>
#include <vector>
#include "../code/src/settings.h"

class Option {
  public:
    Option(u8* var_, std::string name_, std::vector<std::string> options_, u8 defaultOption_ = 0)
          :   varu8(var_),       name(name_),                 options(options_), selectedOption(defaultOption_) {
        *varu8 = selectedOption;
        type == "u8";
    }

    Option(bool* var_, std::string name_, std::vector<std::string> options_, u8 defaultOption_ = 0)
          :varBool(var_),     name(name_),                 options(options_), selectedOption(defaultOption_) {
        type = "bool";
        *varBool = selectedOption ? true : false;
    }
    u8* varu8;
    bool* varBool;
    std::string name;
    std::vector<std::string> options;
    u8 selectedOption;
    std::string type;

    void SetVariable() {
      if (type == "bool") {
        *varBool = selectedOption ? true : false;
      } else {
        *varu8 = selectedOption;
      }
    }
};

class Menu {
  public:
    Menu(std::string name_, std::vector<Option *> settingsList_)
        :       name(name_),        settingsList(settingsList_) {
          selectedSetting = 0;
        }

    std::string name;
    std::vector<Option *> settingsList;
    int selectedSetting;
};

namespace Settings {
  extern u8 OpenForest;
  extern u8 OpenKakariko;
  extern u8 Bridge;
  extern u8 LACSCondition;
  extern u8 GerudoFortress;
  extern u8 DamageMultiplier;
  extern u8 ZorasFountain;
  extern u8 StartingAge;
  extern u8 Keysanity;
  extern u8 BossKeysanity;
  extern u8 MapsAndCompasses;
  extern u8 Skullsanity;
  extern u8 Scrubsanity;

  extern unsigned int seed;

  extern bool HasNightStart;
  extern bool BombchusInLogic;
  extern bool BombchuDrop;
  extern bool OpenDoorOfTime;
  extern bool SkippedTrials;
  extern bool ShuffleDungeonEntrances;
  extern bool ShuffleOverworldEntrances;
  extern bool ShuffleInteriorEntrances;
  extern bool ShuffleSpecialIndoorEntrances;
  extern bool ShuffleWeirdEgg;
  extern bool ShuffleGerudoToken;
  extern bool ShuffleZeldasLetter;
  extern bool ShuffleKokiriSword;
  extern bool ShuffleSongs;
  extern bool Shopsanity;

  //Logic Settings
  extern bool LogicMidoBackflip;
  extern bool LogicLostWoodsBridge;
  extern bool LogicGrottosWithoutAgony;
  extern bool LogicBiggoronBolero;
  extern bool LogicGerudoKitchen;
  extern bool LogicWaterHookshotEntry;
  extern bool LogicLensWasteland;
  extern bool LogicReverseWasteland;
  extern bool LogicVisibleCollision;
  extern bool LogicManOnRoof;
  extern bool LogicKakarikoTowerGS;
  extern bool LogicDMTBombable;
  extern bool LogicLinkGoronDins;
  extern bool LogicGoronCityLeftMost;
  extern bool LogicGoronCityPot;
  extern bool LogicGoronCityPotWithStrength;
  extern bool LogicChildRollingWithStrength;
  extern bool LogicCraterUpperToLower;
  extern bool LogicCraterBeanPoHWithHovers;
  extern bool LogicFewerTunicRequirements;
  extern bool LogicZoraWithHovers;
  extern bool LogicZoraWithCucco;
  extern bool LogicDekuB1Skip;
  extern bool LogicDekuB1WebsWithBow;
  extern bool LogicDCStaircase;
  extern bool LogicDCJump;
  extern bool LogicDCSlingshotSkip;
  extern bool LogicJabuBossGSAdult;
  extern bool LogicForestVines;
  extern bool LogicForestScarecrow;
  extern bool LogicForestOutsideBackdoor;
  extern bool LogicLabDiving;
  extern bool LogicZoraRiverLower;
  extern bool LogicZoraRiverUpper;
  extern bool LogicGraveyardPoH;
  extern bool LogicChildDampeRacePoH;
  extern bool LogicFireBossDoorJump;
  extern bool LogicFireStrength;
  extern bool LogicFireScarecrow;
  extern bool LogicFireFlameMaze;
  extern bool LogicWaterTempleTorchLongshot;
  extern bool LogicWaterCentralBow;
  extern bool LogicWaterCrackedWallNothing;
  extern bool LogicWaterCrackedWallHovers;
  extern bool LogicWaterBossKeyRegion;
  extern bool LogicWaterDragonBombchu;
  extern bool LogicWaterBKJumpDive;
  extern bool LogicWaterBKChest;
  extern bool LogicWaterNorthBasementLedgeJump;
  extern bool LogicWaterDragonBombchu;
  extern bool LogicWaterDragonJumpDive;
  extern bool LogicWaterNorthBasementLedgeJump;
  extern bool LogicWaterBKChest;
  extern bool LogicWaterDragonJumpDive;
  extern bool LogicSpiritLowerAdultSwitch;
  extern bool LogicSpiritChildBombchu;
  extern bool LogicSpiritWall;
  extern bool LogicSpiritLobbyGS;
  extern bool LogicSpiritMapChest;
  extern bool LogicSpiritSunChest;
  extern bool LogicShadowFireArrowEntry;
  extern bool LogicShadowUmbrella;
  extern bool LogicShadowFreestandingKey;
  extern bool LogicShadowStatue;
  extern bool LogicBotwCageGS;
  extern bool LogicChildDeadhand;
  extern bool LogicGtgWithoutHookshot;
  extern bool LogicGtgFakeWall;
  extern bool LogicLensSpirit;
  extern bool LogicLensShadow;
  extern bool LogicLensShadowBack;
  extern bool LogicLensBotw;
  extern bool LogicLensGtg;
  extern bool LogicLensCastle;
  extern bool LogicSpiritTrialHookshot;
  extern bool LogicLostWoodsGSBean;
  extern bool LogicLabWallGS;
  extern bool LogicColossusGS;
  extern bool LogicDMTSoilGS;
  extern bool LogicDekuBasementGS;
  extern bool LogicDCScarecrowGS;
  extern bool LogicForestOutdoorEastGS;
  extern bool LogicFireSongOfTime;
  extern bool LogicWaterRiverGS;
  extern bool LogicWaterFallingPlatformGS;

  extern void UpdateSettings();
  extern void PrintSettings();
  extern SettingsContext FillContext();

  extern std::vector<Option *> Options;
  extern std::vector<Menu *> mainMenu;
}
