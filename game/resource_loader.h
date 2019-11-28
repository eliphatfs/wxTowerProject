#include <wx/wx.h>
#include <memory>

long load_png_image(const char * path);
wxImage * get_image_by_id(long id);
void unload_all_loaded_images();
