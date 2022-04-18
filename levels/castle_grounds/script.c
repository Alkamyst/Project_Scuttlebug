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
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group10_yay0SegmentRomStart, _group10_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_grounds_geo_0006F4), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_VCUTM_GRILL, castle_grounds_geo_00070C), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_FLAG, castle_grounds_geo_000660), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CANNON_GRILL, castle_grounds_geo_000724), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x32, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1503, 1776, 2079, 0, 159, 0, (1 << 16), bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, 471, 2385, -982, 0, 159, 0, (1 << 16), bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, -1823, 1564, 1650, 0, 159, 0, (1 << 16), bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, 16, 1468, 1663, 0, 159, 0, (1 << 16), bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, -980, 1863, 2739, 0, 159, 0, (1 << 16), bhvBirdsSoundLoop),
		OBJECT(MODEL_BOBOMB_BUDDY, -389, -739, 3098, 0, 159, 0, (51 << 16), bhvBobombBuddy),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -430, -127, -836, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -1087, -127, -296, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -1301, -127, -1072, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 683, -127, -471, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 1525, -127, -922, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 1071, -362, 1180, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -1092, -362, 1254, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 289, -127, -1366, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_NONE, 0, 16, 8, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 0, -239, 2510, 0, 0, 0, (50 << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_NONE, 0, -739, 3621, 0, 90, 0, (1 << 16), bhvWarp),
		OBJECT(MODEL_WOODEN_SIGNPOST, -396, -362, 1491, 0, -180, 0, (3 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 411, -362, 1491, 0, -180, 0, (2 << 16), bhvMessagePanel),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
