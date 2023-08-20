#include "vec2.h"

Vec2 sumVec2(Vec2 a, Vec2 b)
{
    Vec2 r = {a.x + b.x, a.y + b.y};
    return r;
}