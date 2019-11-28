#ifndef RENDERER_H
#define RENDERER_H
#include <wx/wx.h>
#include "vec3.h"

#define RBUF_W 800
#define RBUF_H 600

void initialize_render_buffer();
void begin_frame(bool clear);
void end_frame();
const wxBitmap& get_render_buffer();
void draw_bitmap(wxImage * bitmap, vec3_t screenPos);
void release_render_buffer();

#endif
