#include "game_render.h"
#include "world.h"

static long bg_tile, walk_0;
static long tile_extras[16];
extern vec3_t pos, pos2;

void game_render_initialize() {
    bg_tile = load_png_image("res/bg_0.png");
    tile_extras[(int)wall] = load_png_image("res/bg_1.png");
    tile_extras[(int)space] = bg_tile;

    tile_extras[(int)door] = load_png_image("res/door.png");
    tile_extras[(int)key] = load_png_image("res/key.png");

    tile_extras[(int)skeleton] = load_png_image("res/mobs/mob_0.png");
    tile_extras[(int)witch] = load_png_image("res/mobs/mob_1.png");
    tile_extras[(int)boss] = load_png_image("res/mobs/mob_2.png");

    tile_extras[(int)sword] = load_png_image("res/sword.png");
    tile_extras[(int)shield] = load_png_image("res/shield.png");
    tile_extras[(int)potion] = load_png_image("res/potion.png");
    walk_0 = load_png_image("res/walks/flandre_000.png");
}

void game_render_inbuffer(const vec3_t& center) {
    begin_frame(true);
    vec3_t origin = { { center.vector[0] - 400.0, center.vector[1] - 300.0, 1.0 } };
    int originX = (int)(origin.vector[0] / 36.0);
    int originY = (int)(origin.vector[1] / 36.0);
    for (int i = originX; i < originX + 25; i++) {
        if (i < 0) continue;
        if (i >= 1024) break;
        for (int j = originY; j < originY + 20; j++) {
            if (j < 0) continue;
            if (j >= 1024) break;
            vec3_t pos = { { i * 36.0 - origin.vector[0], j * 36.0 - origin.vector[1], 1.0 } };
            draw_bitmap(get_image_by_id(bg_tile), pos);
            draw_bitmap(get_image_by_id(tile_extras[(int)get_world_block(i, j)]), pos);
        }
    }
    // draw_bitmap(get_image_by_id(image_id), pos);
    // draw_bitmap(get_image_by_id(image_id), pos2);
}
