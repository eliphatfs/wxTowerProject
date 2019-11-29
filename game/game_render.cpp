#include "game_render.h"
#include "world.h"
#include "player.h"
#include <cstdio>
using namespace std;

static long bg_tile, walk_0, outside;
static long tile_extras[16];
static long walk_frames[32];
extern vec3_t pos, pos2;

void game_render_initialize() {
    bg_tile = load_png_image("res/bg_0.png");
    tile_extras[0] = bg_tile;

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
    outside = load_png_image("res/outside.png");
    walk_0 = load_png_image("res/walks/flandre_000.png");

    char buf[48];
    for (int i = 0; i < 32; i++) {
        sprintf(buf, "res/walks/flandre_%03d.png", i);
        walk_frames[i] = load_png_image(buf);
    }
}

void game_render_inbuffer(const vec3_t& center, bool editormode) {
    begin_frame(true);
    vec3_t origin = { { center.vector[0] - 400.0, center.vector[1] - 300.0, 1.0 } };
    int originX = floor(origin.vector[0] / 36.0);
    int originY = floor(origin.vector[1] / 36.0);
    for (int i = originX; i < originX + 25; i++) {
        for (int j = originY; j < originY + 20; j++) {
            vec3_t pos = { { i * 36.0 - origin.vector[0], j * 36.0 - origin.vector[1], 1.0 } };
            if (i < 0 || i >= 1000 || j < 0 || j >= 1000) {
                draw_bitmap(get_image_by_id(outside), pos);
                continue;
            }
            draw_bitmap(get_image_by_id(bg_tile), pos);
            draw_bitmap(get_image_by_id(tile_extras[(int)get_world_block(i, j)]), pos);
            if (editormode && i == get_player().x && j == get_player().y)
                draw_bitmap(get_image_by_id(walk_0), pos);
            if (!editormode) {
                int req = -1;
                switch (get_world_block(i, j)) {
                    case skeleton:
                        req = get_player().hp_down(50, 2, 0);
                        break;
                    case witch:
                        req = get_player().hp_down(150, 42, 10);
                        break;
                    case boss:
                        req = get_player().hp_down(3000, 101, 20);
                        break;
                }
                if (req > -1) {
                    char buf[18];
                    sprintf(buf, "%d", get_player().hp - req);
                    vec3_t red = { { 0.7, 0.2, 0.2 } };
                    draw_string(buf, pos, red);
                }
            }
        }
    }
    if (!editormode) {
        vec3_t screenC = { { 400.0, 300.0, 1.0 } };
        draw_bitmap(get_image_by_id(walk_frames[get_player().frame]), screenC);
        vec3_t f0 = { { 10.0, 4.0, 1.0 } };
        vec3_t f1 = { { 10.0, 30.0, 1.0 } };
        vec3_t f2 = { { 10.0, 56.0, 1.0 } };
        vec3_t f7 = { { 10.0, 82.0, 1.0 } };
        draw_bitmap(get_image_by_id(tile_extras[(int)potion]), f0);
        draw_bitmap(get_image_by_id(tile_extras[(int)sword]), f1);
        draw_bitmap(get_image_by_id(tile_extras[(int)shield]), f2);
        draw_bitmap(get_image_by_id(tile_extras[(int)key]), f7);
        vec3_t f3 = { { 50.0, 14.0, 1.0 } };
        vec3_t f4 = { { 50.0, 40.0, 1.0 } };
        vec3_t f5 = { { 50.0, 66.0, 1.0 } };
        vec3_t f6 = { { 50.0, 92.0, 1.0 } };
        char buf[18];
        vec3_t black = { { 0.0, 0.0, 0.0 } };
        sprintf(buf, "%d", get_player().hp);
        draw_string(buf, f3, black);
        sprintf(buf, "%d", get_player().attack);
        draw_string(buf, f4, black);
        sprintf(buf, "%d", get_player().defence);
        draw_string(buf, f5, black);
        sprintf(buf, "%d", get_player().keynumber);
        draw_string(buf, f6, black);
    }
    // draw_bitmap(get_image_by_id(image_id), pos);
    // draw_bitmap(get_image_by_id(image_id), pos2);
}
