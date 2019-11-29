#ifndef GAME_RENDER_H
#define GAME_RENDER_H
#include "renderer.h"
#include "resource_loader.h"
#include "vec3.h"

void game_render_initialize();
void game_render_inbuffer(const vec3_t& center, bool editormode);

#endif
