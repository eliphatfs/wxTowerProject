#include "renderer.h"
#include <wx/dcbuffer.h>
static wxImage * realBuf;
static wxBitmap * rbuf;

void initialize_render_buffer() {
    rbuf = new wxBitmap(RBUF_W, RBUF_H, 32);
    realBuf = new wxImage(RBUF_W, RBUF_H);
}

void begin_frame(bool clear) {
    if (clear) {
        wxRect fullRect(0, 0, RBUF_W, RBUF_H);
        realBuf->SetRGB(fullRect, 255, 255, 255);
    }
}

void draw_bitmap(wxImage * bitmap, vec3_t screenPos) {
    realBuf->Paste(*bitmap, (int)screenPos.vector[0], (int)screenPos.vector[1]);
}

void end_frame(wxWindow * target) {
    wxBufferedPaintDC rpainter(target, *rbuf);
    rpainter.DrawBitmap(wxBitmap(*realBuf), 0, 0);
}

void release_render_buffer() {
    delete rbuf;
    delete realBuf;
}
