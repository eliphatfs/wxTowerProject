#include "game_map_editor.h"
#include "game_render.h"
#include "world.h"
#include "vec3.h"

static int editing = 1;
static vec3_t center;

bool editor_mouse(wxMouseEvent& event) {
    if (event.LeftIsDown()) {
        int wx = (int)((event.GetX() - 400.0 + center.vector[0]) / 36.0);
        int wy = (int)((event.GetY() - 300.0 + center.vector[1]) / 36.0);
        if (!event.ControlDown()) {
            set_world_block(wx, wy, (world_block_t)editing);
            game_render_inbuffer(center);
            return true;
        }
        else {
            // spawnX = wx; spawnY = wy;
        }
    }
    else if (event.RightDown()) {
        center.vector[0] += event.GetX() - 400.0;
        center.vector[1] += event.GetY() - 300.0;
        game_render_inbuffer(center);
        return true;
    }
    return false;
}

bool editor_key(wxKeyEvent& event) {
    int code = event.GetKeyCode();
    if (code <= '9' && code >= '0') {
        editing = code - '0' + 1;
    }
    else if (code == WXK_LEFT) {
        center.vector[0] -= 36.0f;
        game_render_inbuffer(center);
        return true;
    }
    else if (code == WXK_RIGHT) {
        center.vector[0] += 36.0f;
        game_render_inbuffer(center);
        return true;
    }
    else if (code == WXK_UP) {
        center.vector[1] -= 36.0f;
        game_render_inbuffer(center);
        return true;
    }
    else if (code == WXK_DOWN) {
        center.vector[1] += 36.0f;
        game_render_inbuffer(center);
        return true;
    }
    else if (code == 'S' && event.ControlDown()) {
        // IO
    }
    return false;
}
