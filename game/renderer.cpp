#include "renderer.h"
#include "resource_loader.h"
#include "math_helpers.h"
#include <cstdio>
#include <wx/dcbuffer.h>
static wxImage * realBuf;
static wxBitmap * rbuf;
static wxImage * ascii[128];

void initialize_render_buffer() {
    rbuf = new wxBitmap(RBUF_W, RBUF_H, 32);
    realBuf = new wxImage(RBUF_W, RBUF_H);
    for (int i = 32; i <= 127; i++) {
        char pathbuf[32];
        sprintf(pathbuf, "res/font/ascii_%03d.png", i);
        ascii[i] = new wxImage();
        ascii[i]->LoadFile(wxString::FromAscii(pathbuf), wxBITMAP_TYPE_PNG);
        ascii[i]->Rescale(16, 16, wxIMAGE_QUALITY_NORMAL);
    }
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

void draw_string(char * str, vec3_t screenPos, vec3_t rgb) {
    int startX = (int)screenPos.vector[0];
    int startY = (int)screenPos.vector[1];
    int curX = startX;
    int curY = startY;
    while (*str) {
        if (*str == '\n') {
            curX = startX;
            curY += 16;
        }
        else if (*str >= 32 && *str <= 127) {
            wxImage tempCopy = ascii[*str]->Copy();
            tempCopy.Replace(255, 255, 255,
                             (unsigned char)(clampd(rgb.vector[0], 0.0, 1.0) * 255),
                             (unsigned char)(clampd(rgb.vector[1], 0.0, 1.0) * 255),
                             (unsigned char)(clampd(rgb.vector[2], 0.0, 1.0) * 255));
            realBuf->Paste(tempCopy, curX, curY);
            curX += 13;
        }
        ++str;
    }
}

void end_frame(wxWindow * target) {
    wxBufferedPaintDC rpainter(target, *rbuf);
    rpainter.DrawBitmap(wxBitmap(*realBuf), 0, 0);
}

void release_render_buffer() {
    for (int i = 32; i <= 127; i++) {
        delete ascii[i];
    }
    delete rbuf;
    delete realBuf;
}
