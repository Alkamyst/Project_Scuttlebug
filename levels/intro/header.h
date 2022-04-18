#ifndef INTRO_HEADER_H
#define INTRO_HEADER_H

#include "types.h"

// geo
extern const GeoLayout intro_geo_splash_screen[];
extern const GeoLayout intro_geo_mario_head_regular[];
extern const GeoLayout intro_geo_mario_head_dizzy[];
extern const GeoLayout intro_geo_debug_level_select[];

// leveldata
extern Lights1 ScuttlePirate_Title_Wood_lights;
extern Lights1 ScuttlePirate_Title_Gold_001_lights;
extern Lights1 ScuttlePirate_Title_Red_lights;
extern Lights1 ScuttlePirate_Title_Green_lights;
extern Lights1 ScuttlePirate_Title_Yellow_lights;
extern Lights1 ScuttlePirate_Title_Blue_lights;
extern Lights1 ScuttlePirate_Title_Black_lights;
extern Lights1 ScuttlePirate_Title_Gold_lights;
extern Lights1 ScuttlePirate_Title_Rainbow_lights;
extern u8 ScuttlePirate_Title_Material8_ci8[];
extern u8 ScuttlePirate_Title_Material8_ci8_pal_rgba16[];
extern u8 ScuttlePirate_Title__0xC60_rgba16[];
extern u8 ScuttlePirate_Title__0xC60_rgba16_copy[];
extern u8 ScuttlePirate_Title_Bright_Rainbow_Gradient_ci8[];
extern u8 ScuttlePirate_Title_Bright_Rainbow_Gradient_ci8_pal_rgba16[];
extern Vtx ScuttlePirate_Title_Treasure_Chest_mesh_vtx_0[56];
extern Gfx ScuttlePirate_Title_Treasure_Chest_mesh_tri_0[];
extern Vtx ScuttlePirate_Title_Treasure_Chest_mesh_vtx_1[20];
extern Gfx ScuttlePirate_Title_Treasure_Chest_mesh_tri_1[];
extern Vtx ScuttlePirate_Title_Treasure_Chest_mesh_vtx_2[13];
extern Gfx ScuttlePirate_Title_Treasure_Chest_mesh_tri_2[];
extern Vtx ScuttlePirate_Title_Treasure_Chest_mesh_vtx_3[23];
extern Gfx ScuttlePirate_Title_Treasure_Chest_mesh_tri_3[];
extern Vtx ScuttlePirate_Title_Treasure_Chest_mesh_vtx_4[10];
extern Gfx ScuttlePirate_Title_Treasure_Chest_mesh_tri_4[];
extern Vtx ScuttlePirate_Title_Treasure_Chest_mesh_vtx_5[13];
extern Gfx ScuttlePirate_Title_Treasure_Chest_mesh_tri_5[];
extern Vtx ScuttlePirate_Title_Treasure_Chest_mesh_vtx_6[976];
extern Gfx ScuttlePirate_Title_Treasure_Chest_mesh_tri_6[];
extern Vtx ScuttlePirate_Title_Treasure_Chest_mesh_vtx_7[162];
extern Gfx ScuttlePirate_Title_Treasure_Chest_mesh_tri_7[];
extern Vtx ScuttlePirate_Title_Treasure_Chest_mesh_vtx_8[92];
extern Gfx ScuttlePirate_Title_Treasure_Chest_mesh_tri_8[];
extern Gfx mat_ScuttlePirate_Title_Wood[];
extern Gfx mat_revert_ScuttlePirate_Title_Wood[];
extern Gfx mat_ScuttlePirate_Title_Gold_001[];
extern Gfx mat_ScuttlePirate_Title_Red[];
extern Gfx mat_ScuttlePirate_Title_Green[];
extern Gfx mat_ScuttlePirate_Title_Yellow[];
extern Gfx mat_ScuttlePirate_Title_Blue[];
extern Gfx mat_ScuttlePirate_Title_Black[];
extern Gfx mat_ScuttlePirate_Title_Gold[];
extern Gfx mat_ScuttlePirate_Title_Rainbow[];
extern Gfx mat_revert_ScuttlePirate_Title_Rainbow[];
extern Gfx ScuttlePirate_Title_Treasure_Chest_mesh[];

extern const Gfx intro_seg7_dl_copyright_trademark[];
extern const f32 intro_seg7_table_scale_1[];
extern const f32 intro_seg7_table_scale_2[];

// script
extern const LevelScript level_intro_splash_screen[];
extern const LevelScript level_intro_mario_head_regular[];
extern const LevelScript level_intro_mario_head_dizzy[];
extern const LevelScript level_intro_entry_level_select[];
extern const LevelScript script_intro_file_select[];
extern const LevelScript script_intro_level_select[];
extern const LevelScript script_intro_main_level_entry_stop_music[];
extern const LevelScript script_intro_main_level_entry[];
extern const LevelScript script_intro_splash_screen[];

#endif
