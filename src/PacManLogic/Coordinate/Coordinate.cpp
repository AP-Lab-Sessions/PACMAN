//
#include "Coordinate.h"
#include <cassert>

Coordinate2D::Coordinate::Coordinate(const float& x, const float& y) : x(x), y(y) {}

float Coordinate2D::Coordinate::GetX() const {return x;}
float Coordinate2D::Coordinate::GetY() const {return y;}

void Coordinate2D::Coordinate::SetX(const float &newX) {x=newX;}
void Coordinate2D::Coordinate::SetY(const float& newY) {y=newY;}

bool Coordinate2D::IsNormalized(const float& n) {
    return normalizedMin <= n && n <= normalizedMax;
}
bool Coordinate2D::IsNormalized(const Coordinate2D::Coordinate& coordinate) {
    return IsNormalized(coordinate.GetX()) && IsNormalized(coordinate.GetY());
}

Coordinate2D::NormalizedCoordinate::NormalizedCoordinate(const float& xArg, const float& yArg) : Coordinate(xArg,yArg) {
    assert(IsNormalized(*this));
}

void Coordinate2D::NormalizedCoordinate::SetX(const float& newX) {
    assert(IsNormalized(newX));
    x = newX;
}

void Coordinate2D::NormalizedCoordinate::SetY(const float& newY) {
    assert(IsNormalized(newY));
    y = newY;
}

Coordinate2D::Coordinate Coordinate2D::Project(
    const Coordinate2D::NormalizedCoordinate& coord, const unsigned int& width, const unsigned int& height) {
    const float x = static_cast<float>(width)/2*(coord.GetX()+1);
    const float y = static_cast<float>(height)/2*(coord.GetY()+1);
    return Coordinate{x,y};
}

bool Coordinate2D::IsOverlapping(const Coordinate2D::NormalizedCoordinate &pos1, const Coordinate2D::Coordinate &size1,
                                 const Coordinate2D::NormalizedCoordinate &pos2,
                                 const Coordinate2D::Coordinate &size2) {
    return (pos1.GetX() < pos2.GetX()+size2.GetX() && pos1.GetX()+size1.GetX() > pos2.GetX()
            && pos1.GetY() < pos2.GetY()+size2.GetY() && pos1.GetY()+size1.GetY() > pos2.GetY());
}