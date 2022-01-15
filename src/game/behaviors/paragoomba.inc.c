
/**
 * Behavior for bhvParagoomba.
 */

/**
 * Hitbox for paragoomba.
 */
static struct ObjectHitbox sParaGoombaHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 2,
    /* radius:            */ 70,
    /* height:            */ 60,
    /* hurtboxRadius:     */ 60,
    /* hurtboxHeight:     */ 50,
};

/**
 * Unused jitter amounts.
 */
static s16 sParaGoombaJitterAmounts[] = { 0x1000, -0x2000, 0x2000 };

/**
 * Return to regular size. When mario is close enough or home is far enough,
 * turn toward mario/home and enter the approach mario action.
 */
static void paragoomba_act_idle(void) {
    o->oForwardVel = 0.0f;

    if (approach_f32_ptr(&o->header.gfx.scale[0], 1.5f, 0.02f)) {
        // If we are >2000 units from home or Mario is <2000 units from us
        if (o->oDistanceToMario >= 25000.0f || o->oDistanceToMario < 2000.0f) {
            // Turn toward home or Mario
            obj_face_yaw_approach(o->oAngleToMario, 0x300);

            if (cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x300)) {
                o->oAction = PARAGOOMBA_ACT_APPROACH_MARIO;
            }
        } else {
            // Randomly enter the approach mario action - but this doesn't
            // really do anything since we come right back to idle
            if (o->oParaGoombaIdleTimer >= 3 || o->oParaGoombaIdleTimer == ((u16)random_u16() & 1) + 2) {
                o->oParaGoombaIdleTimer = 0;
                o->oAction = PARAGOOMBA_ACT_APPROACH_MARIO;
            } else {
                o->oParaGoombaUnusedJitter = o->oMoveAngleYaw + sParaGoombaJitterAmounts[o->oParaGoombaIdleTimer];
                o->oParaGoombaIdleTimer++;
            }
        }
    }
}

/**
 * Turn toward mario or home, and when positioned nicely
 * If mario is far away, stop and return to the idle action.
 */
static void paragoomba_act_approach_mario(void) {
    // If we are >2000 units from home or Mario is <2000 units from us
    if (o->oDistanceToMario >= 25000.0f || o->oDistanceToMario < 2000.0f) {
        obj_forward_vel_approach(10.0f, 0.5f);

        // Turn toward home or Mario
        obj_face_yaw_approach(o->oAngleToMario, 0x400);
        cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x200);

        // If facing toward mario and we are either near mario laterally or
        // far above him
        if (abs_angle_diff(o->oAngleToMario, o->oFaceAngleYaw) < 0x2000
            && (o->oPosY - gMarioObject->oPosY > 400.0f || o->oDistanceToMario < 400.0f)) {
            // Lunge
            o->oAction = PARAGOOMBA_ACT_LUNGE;
            o->oParaGoombaLungeTargetPitch = obj_turn_pitch_toward_mario(-200.0f, 0);

            o->oForwardVel = 25.0f * coss(o->oParaGoombaLungeTargetPitch);
            o->oVelY = 25.0f * -sins(o->oParaGoombaLungeTargetPitch);
            o->oParaGoombaLungeYDecel = -o->oVelY / 30.0f;
        }
    } else if (obj_forward_vel_approach(0.0f, 0.2f)) {
        o->oAction = PARAGOOMBA_ACT_IDLE;
    }
}

/**
 * Lunge downward at mario, then twirl back up. Enter the approach mario action
 * afterward.
 */
static void paragoomba_act_lunge(void) {
    if (o->oVelY < 0.0f) {
        // Lunge downward

        o->oVelY += o->oFlyGuyLungeYDecel;

        cur_obj_rotate_yaw_toward(o->oFaceAngleYaw, 0x800);
        obj_face_pitch_approach(o->oParaGoombaLungeTargetPitch, 0x400);

        // Possible values: {-0x1000, 0x0000, 0x1000}
        o->oFlyGuyTargetRoll = 0x1000 * (s16)(random_float() * 3.0f) - 0x1000;
        o->oTimer = 0;
    } else {
        // Twirl back upward

        obj_face_pitch_approach(0, 0x100);
        obj_face_roll_approach(o->oParaGoombaTargetRoll, 300);

        // Twirl in a spiral with curvature proportional to oFaceAngleRoll
        o->oMoveAngleYaw -= o->oFaceAngleRoll / 4;
        obj_face_yaw_approach(o->oMoveAngleYaw, 0x800);

        // Continue moving upward until at least 200 units above mario
        if (o->oPosY < gMarioObject->oPosY + 200.0f) {
            obj_y_vel_approach(20.0f, 0.5f);
        } else if (obj_y_vel_approach(0.0f, 0.5f)) {
            // Wait until roll is zero
            if (o->oFaceAngleRoll == 0) {
                o->oAction = PARAGOOMBA_ACT_APPROACH_MARIO;
            }

            o->oParaGoombaTargetRoll = 0;
        }
    }
}

/**
 * Update function for paragoomba.
 */
void bhv_paragoomba_update(void) {
    // PARTIAL_UPDATE (appears in non-roomed levels)

    if (!(o->activeFlags & ACTIVE_FLAG_IN_DIFFERENT_ROOM)) {
        o->oDeathSound = SOUND_OBJ_ENEMY_DEATH_HIGH;

        cur_obj_scale(o->header.gfx.scale[0]);
        treat_far_home_as_mario(2000.0f);
        cur_obj_update_floor_and_walls();

        if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
            o->oMoveAngleYaw = cur_obj_reflect_move_angle_off_wall();
        } else if (o->oMoveFlags & OBJ_MOVE_MASK_IN_WATER) {
            o->oVelY = 6.0f;
        }

        // Oscillate up and down
        o->oParaGoombaOscTimer++;
        o->oPosY += coss(0x400 * o->oParaGoombaOscTimer) * 1.5f;

        switch (o->oAction) {
            case PARAGOOMBA_ACT_IDLE:
                paragoomba_act_idle();
                break;
            case PARAGOOMBA_ACT_APPROACH_MARIO:
                paragoomba_act_approach_mario();
                break;
            case PARAGOOMBA_ACT_LUNGE:
                paragoomba_act_lunge();
                break;
        }

        cur_obj_move_standard(78);
        // Checks if the paragoomba is killed. If so, adds 1 to the paragoomba star.
        if (obj_check_attacks(&sParaGoombaHitbox, o->oAction)) {
            if (--o->oHealth < 0) {
                struct Object *hiddenParagoombaStar = cur_obj_nearest_object_with_behavior(bhvHiddenParagoombaStar);

                if (hiddenParagoombaStar != NULL) {
                    hiddenParagoombaStar->oHiddenStarTriggerCounter++;

                    if (hiddenParagoombaStar->oHiddenStarTriggerCounter != 5) {
                        spawn_orange_number(hiddenParagoombaStar->oHiddenStarTriggerCounter, 0, 0, 0);
                    }

                    play_sound(SOUND_MENU_COLLECT_RED_COIN + (((u8) hiddenParagoombaStar->oHiddenStarTriggerCounter - 1) << 16), gGlobalSoundSource);
                }
            }
        }
    }
}
