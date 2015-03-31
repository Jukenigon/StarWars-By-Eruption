#include "../H/checkbox.h"
#include "../H/init_position.h"
#include "../H/box.h"

Checkbox init_checkbox(int x, int y, int w, int h)
{
    Checkbox checkbox;
    
    checkbox.img_active = IMG_Load("Res/Pictures/options/checkbox_a.png");
    checkbox.img_active_b = IMG_Load("Res/Pictures/options/checkbox_b.png");
    checkbox.img_non_active = IMG_Load("Res/Pictures/options/checkbox_c.png");
    checkbox.img_non_active_b = IMG_Load("Res/Pictures/options/checkbox_d.png");
    
    checkbox.tmp = checkbox.img_active;
    
    checkbox.pos = init_position(x, y, w, h);
    checkbox.box = init_box(x, y, w, h);
    
    return checkbox;
}
