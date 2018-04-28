
#include "Vector2D.h"

std::ostream operator<<(std::ostream& o, const Vector2D& vec)
{
  o<<"("<<vec.x<<","<<vec.y<<")";
  return o;
}
