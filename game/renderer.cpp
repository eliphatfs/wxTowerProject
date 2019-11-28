#include "renderer.h"
static wxBitmap * rbuf;
static wxImage * realBuf;
static wxMemoryDC * rpainter;

void initialize_render_buffer() {
    rbuf = new wxBitmap(RBUF_W, RBUF_H, 32);
    realBuf = new wxImage(RBUF_W, RBUF_H);
}

void begin_frame(bool clear) {
    rpainter = new wxMemoryDC(*rbuf);
    if (clear) {
        wxRect fullRect(0, 0, RBUF_W, RBUF_H);
        realBuf->SetRGB(fullRect, 255, 255, 255);
    }
}

void draw_bitmap(wxImage * bitmap, vec3_t screenPos) {
    realBuf->Paste(*bitmap, (int)screenPos.vector[0], (int)screenPos.vector[1]);
}

const wxBitmap& get_render_buffer() {
    return *rbuf;
}

void end_frame() {
    rpainter->DrawBitmap(wxBitmap(*realBuf), 0, 0);
    delete rpainter;
}

void release_render_buffer() {
    delete rbuf;
    delete realBuf;
}
