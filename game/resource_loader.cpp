#include "resource_loader.h"
#include <vector>
using namespace std;
static vector<wxImage *> images;

long load_png_image(const char * path) {
    wxImage * image = new wxImage();
    image->LoadFile(wxString::FromUTF8(path), wxBITMAP_TYPE_PNG);
    size_t index = images.size();
    images.push_back(image);
    return (long)index;
}

wxImage * get_image_by_id(long id) {
    return images[id];
}

void unload_all_loaded_images() {
    for (size_t i = 0; i < images.size(); i++) {
        delete images[i];
    }
    images.clear();
}
