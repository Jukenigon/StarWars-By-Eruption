#include "../Structures/box_struct.h"
#include "../H/box.h"

Box init_box(int x, int y, int w, int h)
{
    Box box;
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;
   
    return box;
}
