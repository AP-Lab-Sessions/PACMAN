//
#include "Coordinate.h"
#include <cassert>
#include <cmath>

Coordinate2D::PixelCoordinate::PixelCoordinate(const unsigned int& x, const unsigned int& y) : x(x), y(y) {}

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

Coordinate2D::PixelCoordinate Coordinate2D::Project(
    const Coordinate2D::NormalizedCoordinate& coord, const unsigned int& width, const unsigned int& height) {
    const unsigned int x = std::lroundf((float)(width)/2*(coord.GetX()+1));
    const unsigned int y = std::lroundf((float)(height)/2*(coord.GetY()+1));
    return PixelCoordinate{x,y};
}