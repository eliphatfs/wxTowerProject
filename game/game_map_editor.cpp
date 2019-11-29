#include "game_map_editor.h"
#include "game_render.h"
#include "world.h"
#include "vec3.h"
#include "game_io.h"
#include "player.h"

static int editing = 1;
static vec3_t center;

bool editor_mouse(wxMouseEvent& event) {
    if (event.LeftIsDown()) {
        int wx = (int)((event.GetX() - 400.0 + center.vector[0]) / 36.0);
        int wy = (int)((event.GetY() - 300.0 + center.vector[1]) / 36.0);
        if (!event.ControlDown()) {
            set_world_block(wx, wy, (world_block_t)editing);
            game_render_inbuffer(center, true);
            return true;
        }
        else {
            get_player().x = wx;
            get_player().y = wy;
            game_render_inbuffer(center, true);
            return true;
        }
    }
    else if (event.RightDown()) {
        center.vector[0] += event.GetX() - 400.0;
        center.vector[1] += event.GetY() - 300.0;
        game_render_inbuffer(center, true);
        return true;
    }
    return false;
}

bool editor_key(wxKeyEvent& event) {
    int code = event.GetKeyCode();
    if (code <= '9' && code >= '0') {
        editing = code - '0' + 1;
    }
    else if (code == 'a') {
        center.vector[0] -= 36.0f;
        game_render_inbuffer(center, true);
        return true;
    }
    else if (code == 'd') {
        center.vector[0] += 36.0f;
        game_render_inbuffer(center, true);
        return true;
    }
    else if (code == 'w') {
        center.vector[1] -= 36.0f;
        game_render_inbuffer(center, true);
        return true;
    }
    else if (code == 's' && event.ControlDown()) {
        dump_state("res/map_data.bin");
    }
    else if (code == 's') {
        center.vector[1] += 36.0f;
        game_render_inbuffer(center, true);
        return true;
    }
    return false;
}
