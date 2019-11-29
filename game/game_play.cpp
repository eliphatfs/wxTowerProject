#include "game_play.h"
#include "vec3.h"
#include "player.h"
#include "game_render.h"
#include "world.h"
static vec3_t center;
static int control;
static int timeleft;

bool play_mouse(wxMouseEvent& event) {
    return false;
}

void set_tl() {
    player_t& plr = get_player();
    vec3_t newcenter = { { plr.x * 36.0, plr.y * 36.0, 1.0 } };
    center = newcenter;
    timeleft = 4;
}

bool play_key(wxKeyEvent& event) {
    player_t& plr = get_player();
    if (timeleft) return false;
    int code = event.GetKeyCode();
    if (code == 'a') {
        if (plr.x == 0) return false;
        if (!plr.action(get_world_block(plr.x - 1, plr.y))) return false;
        set_tl();
        --plr.x;
        control |= 1;
    }
    else if (code == 'd') {
        if (plr.x == 999) return false;
        if (!plr.action(get_world_block(plr.x + 1, plr.y))) return false;
        set_tl();
        ++plr.x;
        control |= 2;
    }
    else if (code == 'w') {
        if (plr.y == 0) return false;
        if (!plr.action(get_world_block(plr.x, plr.y - 1))) return false;
        set_tl();
        --plr.y;
        control |= 4;
    }
    else if (code == 's') {
        if (plr.y == 999) return false;
        if (!plr.action(get_world_block(plr.x, plr.y + 1))) return false;
        set_tl();
        ++plr.y;
        control |= 8;
    }
    return false;
}

bool play_anim() {
    player_t& plr = get_player();
    if (timeleft > 0) {
        --timeleft;
        plr.frame = (4 - timeleft) % 4;
        set_world_block(plr.x, plr.y, space);
        if (control & 1) {
            vec3_t newcenter = { { center[0] - 9.0, center[1], 1.0 } };
            center = newcenter;
            plr.frame += 4;
        }
        if (control & 2) {
            vec3_t newcenter = { { center[0] + 9.0, center[1], 1.0 } };
            center = newcenter;
            plr.frame += 8;
        }
        if (control & 4) {
            vec3_t newcenter = { { center[0], center[1] - 9.0, 1.0 } };
            center = newcenter;
            plr.frame += 12;
        }
        if (control & 8) {
            vec3_t newcenter = { { center[0], center[1] + 9.0, 1.0 } };
            center = newcenter;
        }
        if (timeleft == 0) control = 0;
        game_render_inbuffer(center, false);
        return true;
    }
    return false;
}
