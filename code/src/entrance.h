#ifndef _ENTRANCE_H_
#define _ENTRANCE_H_

//Entrance Table Data: https://wiki.cloudmodding.com/oot/Entrance_Table_(Data)

#define ENTRANCE_TABLE_SIZE 0x0614

#define DEKU_TREE_ENTRANCE 0x0000
#define DODONGOS_CAVERN_ENTRANCE 0x0004
#define JABU_JABUS_BELLY_ENTRANCE 0x0028
#define FOREST_TEMPLE_ENTRANCE 0x169
#define FIRE_TEMPLE_ENTRANCE 0x165
#define WATER_TEMPLE_ENTRANCE 0x0010
#define SPIRIT_TEMPLE_ENTRANCE 0x0082
#define SHADOW_TEMPLE_ENTRANCE 0x0037
#define BOTTOM_OF_THE_WELL_ENTRANCE 0x0098
#define GERUDO_TRAINING_GROUNDS_ENTRANCE 0x0008
#define ICE_CAVERN_ENTRANCE 0x0088
#define GANONS_CASTLE_ENTRANCE 0x0467

#define ENTRANCE_OVERRIDES_MAX_COUNT 256
#define ENTRANCE_PAIRS_MAX_COUNT 128
#define ENTRANCE_PAIRS_STRING_DATA_SIZE 8192
#define ENTRANCE_INVALID_STRING_OFFSET 65535

typedef struct {
    s16 index;
    s16 destination;
    s16 blueWarp;
    s16 override;
    s16 overrideDestination;
} EntranceOverride;

typedef enum {
    ENTRANCE_GROUP_NO_GROUP,
    ENTRANCE_GROUP_ROOT_EXITS,
    ENTRANCE_GROUP_KOKIRI_FOREST,
    ENTRANCE_GROUP_LOST_WOODS,
    ENTRANCE_GROUP_KAKARIKO,
    ENTRANCE_GROUP_GRAVEYARD,
    ENTRANCE_GROUP_DEATH_MOUNTAIN_TRAIL,
    ENTRANCE_GROUP_DEATH_MOUNTAIN_CRATER,
    ENTRANCE_GROUP_GORON_CITY,
    ENTRANCE_GROUP_ZORAS_DOMAIN,
    ENTRANCE_GROUP_HYRULE_FIELD,
    ENTRANCE_GROUP_LON_LON_RANCH,
    ENTRANCE_GROUP_LAKE_HYLIA,
    ENTRANCE_GROUP_GERUDO_VALLEY,
    ENTRANCE_GROUP_HAUNTED_WASTELAND,
    ENTRANCE_GROUP_MARKET,
    ENTRANCE_GROUP_HYRULE_CASTLE,
    SPOILER_ENTRANCE_GROUP_COUNT,
} SpoilerEntranceGroup;

typedef struct {
    u8 EntranceCount;
    u16 GroupEntranceCounts[SPOILER_ENTRANCE_GROUP_COUNT];
    u16 GroupOffsets[SPOILER_ENTRANCE_GROUP_COUNT];
} EntranceTrackingData;

#define ENTRANCE_NAME_SOURCE 0
#define ENTRANCE_NAME_DESTINATION 1

typedef struct {
    s16 index;
    char* source;
    char* destination;
    SpoilerEntranceGroup group;
} EntranceName;

extern EntranceName entranceNames[ENTRANCE_OVERRIDES_MAX_COUNT];
extern EntranceOverride rEntranceOverrides[ENTRANCE_OVERRIDES_MAX_COUNT];
extern EntranceTrackingData gEntranceTrackingData;

void Entrance_Init(void);
s16  Entrance_GetOverride(s16 index);
s16  Entrance_OverrideNextIndex(s16 nextEntranceIndex);
u32  Entrance_IsLostWoodsBridge(void);
void Entrance_EnteredLocation(void);
u32  Entrance_SceneAndSpawnAre(u8 scene, u8 spawn);
void Entrance_CheckEpona(void);
void Entrance_SetSpeed(void);
char* GetEntranceName(s16 index_, u8 type);
void InitEntranceTrackingData(void);

#endif //_ENTRANCE_H_
