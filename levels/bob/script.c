#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x32, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_EXCLAMATION_BOX, -2622, 439, -7669, 0, -160, 0, 0x00050000, bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 1424, 620, -4268, 0, -55, 0, 0x00050000, bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 4223, 3136, -6646, 0, 0, 0, 0x00060000, bhvExclamationBox),
		OBJECT(MODEL_DL_CANNON_LID, 1969, 492, -3081, 0, 0, 0, 0x00000000, bhvCannonClosed),
		OBJECT(MODEL_YELLOW_COIN, 1864, -4553, -5859, 0, -15, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1931, -4553, -6231, 0, -15, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 2152, -4553, -5244, 0, -15, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 2475, -4553, -5008, 0, -15, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 5525, -4658, -4268, 0, 80, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 5279, -4658, -4140, 0, 80, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 5942, -4658, -4490, 0, 80, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 6171, -4658, -4608, 0, 80, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 6156, 61, -3878, 0, -15, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 7766, 61, -6468, 0, -15, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 7952, 61, -7278, 0, -15, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, 2, 264, -956, 0, 0, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -744, 515, -6222, 0, 0, 0, 0x00110000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4476, -5960, -6719, 0, 0, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5011, -5052, -8480, 0, 21, 0, (19 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 4223, 55, -6647, 0, 0, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1158, 256, -7035, 0, -6, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6533, 536, -6644, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4942, 34, -10248, 0, 86, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 3749, -28, -12863, 0, 55, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_GOOMBA, -398, -1105, -15046, 0, 177, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -400, 424, -14676, 0, -162, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 4664, 31, -11709, 0, -165, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1171, -929, -13640, 0, 147, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 3386, -834, -15409, 0, 115, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_BREAKABLE_BOX, -3277, 1653, -5266, 0, 26, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3456, 1653, -5177, 0, 26, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3189, 1653, -5086, 0, 26, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3369, 1653, -4998, 0, 26, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3172, 1936, -4695, 0, 10, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3370, 1936, -4660, 0, 10, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3138, 1936, -4498, 0, 10, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3336, 1936, -4463, 0, 10, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -2505, 979, -7387, 0, 26, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_PARAGOOMBA, -1457, 460, -1231, 0, -180, 0, 0x00000000, bhvParagoomba),
		OBJECT(MODEL_PARAGOOMBA, -1883, 460, -1231, 0, -180, 0, 0x00000000, bhvParagoomba),
		OBJECT(MODEL_PARAGOOMBA, -1847, 460, -660, 0, -180, 0, 0x00000000, bhvParagoomba),
		OBJECT(MODEL_PARAGOOMBA, -791, 460, -652, 0, -180, 0, 0x00000000, bhvParagoomba),
		OBJECT(MODEL_PARAGOOMBA, -1379, 460, -652, 0, -180, 0, 0x00000000, bhvParagoomba),
		OBJECT(MODEL_BOBOMB_BUDDY, 2513, 34, -3056, 0, 0, 0, 0x00000000, bhvBobombBuddyOpensCannon),
		OBJECT(MODEL_PURPLE_SWITCH, -744, 412, -6221, 0, 22, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_RED_COIN, 7095, -4301, -7288, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5011, -4852, -8480, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1961, -4553, -5523, 0, -15, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5735, -4658, -4376, 0, 80, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7682, 61, -4625, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4476, -5892, -6719, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7174, 702, -6644, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4054, -508, -6644, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_SCUTTLEBUG, -1288, 34, -385, 0, -130, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -2378, 34, -1153, 0, 147, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 1142, 34, -393, 0, 31, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -1729, 34, -3687, 0, -33, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -2767, 34, -5479, 0, 161, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -1519, 922, -7543, 0, 81, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -3436, 1457, -6772, 0, -48, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 4234, 55, -5994, 0, -33, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 4256, 55, -7319, 0, 147, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 3465, 34, -2681, 0, 147, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 5663, 429, -6644, 0, 90, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 3736, 34, -10196, 0, -33, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 6633, 34, -9921, 0, 52, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_NONE, 1080, -624, -12697, 0, -15, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 510, -829, -15225, 0, -15, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -745, -825, -13522, 0, -15, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -213, 720, -15026, 0, -15, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 3580, -538, -15503, 0, -15, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -2672, 227, -3429, 0, 0, 0, (0 << 24) | (1 << 8), bhvHiddenParagoombaStar),
		OBJECT(MODEL_STAR, -2672, 2701, -3429, 0, 0, 0, 0x01000000, bhvStar),
		OBJECT(MODEL_NONE, 8, -563, -12745, 0, -56, 0, (2 << 24) | (0 << 8), bhvHiddenStar),
		OBJECT(MODEL_NONE, 5401, -5220, -5041, 0, 0, 0, (3 << 24) | (1 << 8), bhvHiddenRedCoinStar),
		OBJECT(MODEL_SUSHI, 5284, -4532, -6933, 0, 0, 0, 0x00000000, bhvSushiShark),
		OBJECT(MODEL_NONE, -800, 403, 1455, 0, 162, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 162, -800, 203, 1455),
		OBJECT(MODEL_NONE, 5, 744, -959, 0, -180, 0, 0x00320000, bhvAirborneStarCollectWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x23, SEQ_SPM_FLORO_CAVERNS),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 162, -800, 203, 1455),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
