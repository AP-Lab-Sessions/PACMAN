//

#ifndef PACMAN_COORDINATE_H
#define PACMAN_COORDINATE_H

namespace Coordinate2D {

struct PixelCoordinate{
    unsigned int x,y;
    PixelCoordinate(const unsigned int &x, const unsigned int &y);
};

struct NormalizedCoordinate {
    float x,y;
    NormalizedCoordinate(const float &xArg, const float &yArg);
};

}



#endif // PACMAN_COORDINATE_H
