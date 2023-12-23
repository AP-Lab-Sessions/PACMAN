//
#include "Coordinate.h"
#include <cassert>
#include <cmath>

PMGame::Logic::Coordinate2D::Coordinate::Coordinate(const float& x, const float& y) : x(x), y(y) {}

float PMGame::Logic::Coordinate2D::Coordinate::GetX() const { return x; }
float PMGame::Logic::Coordinate2D::Coordinate::GetY() const { return y; }

void PMGame::Logic::Coordinate2D::Coordinate::SetX(const float& newX) { x = newX; }
void PMGame::Logic::Coordinate2D::Coordinate::SetY(const float& newY) { y = newY; }

bool PMGame::Logic::Coordinate2D::IsNormalized(const float& n) { return normalizedMin <= n && n <= normalizedMax; }
bool PMGame::Logic::Coordinate2D::IsNormalized(const PMGame::Logic::Coordinate2D::Coordinate& coordinate) {
    return IsNormalized(coordinate.GetX()) && IsNormalized(coordinate.GetY());
}

PMGame::Logic::Coordinate2D::NormalizedCoordinate::NormalizedCoordinate(const float& xArg, const float& yArg)
    : Coordinate(xArg, yArg) {
    assert(IsNormalized(*this));
}

void PMGame::Logic::Coordinate2D::NormalizedCoordinate::SetX(const float& newX) {
    assert(IsNormalized(newX));
    x = newX;
}

void PMGame::Logic::Coordinate2D::NormalizedCoordinate::SetY(const float& newY) {
    assert(IsNormalized(newY));
    y = newY;
}

bool PMGame::Logic::Coordinate2D::IsOverlapping(const PMGame::Logic::Coordinate2D::NormalizedCoordinate& pos1,
                                                const PMGame::Logic::Coordinate2D::Coordinate& size1,
                                                const PMGame::Logic::Coordinate2D::NormalizedCoordinate& pos2,
                                                const PMGame::Logic::Coordinate2D::Coordinate& size2) {
    return (pos1.GetX() < pos2.GetX() + size2.GetX() && pos1.GetX() + size1.GetX() > pos2.GetX() &&
            pos1.GetY() < pos2.GetY() + size2.GetY() && pos1.GetY() + size1.GetY() > pos2.GetY());
}

float PMGame::Logic::Coordinate2D::GetManhattanDistance(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& coord1,
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& coord2) {
    return std::abs(coord2.GetX() - coord1.GetX()) + std::abs(coord2.GetY() - coord1.GetY());
}

bool PMGame::Logic::Coordinate2D::Coordinate::operator==(const PMGame::Logic::Coordinate2D::Coordinate& other) const {
    return GetX() == other.GetX() && GetY() == other.GetY();
}

float PMGame::Logic::Coordinate2D::Normalize(const float& position, const float& length) {
    if (position + length > PMGame::Logic::Coordinate2D::normalizedMax) {
        return PMGame::Logic::Coordinate2D::normalizedMin;
    } else if (position < PMGame::Logic::Coordinate2D::normalizedMin) {
        return PMGame::Logic::Coordinate2D::normalizedMax - length;
    }
    return position;
}

PMGame::Logic::Coordinate2D::NormalizedCoordinate PMGame::Logic::Coordinate2D::Normalize(
    const PMGame::Logic::Coordinate2D::Coordinate& coordinate, const PMGame::Logic::Coordinate2D::Coordinate& size) {
    return {Normalize(coordinate.GetX(), size.GetX()), Normalize(coordinate.GetY(), size.GetY())};
}

PMGame::Logic::Coordinate2D::NormalizedCoordinate PMGame::Logic::Coordinate2D::GetCenteredShrinked(
    const PMGame::Logic::Coordinate2D::NormalizedCoordinate& pos, const PMGame::Logic::Coordinate2D::Coordinate& size,
    const float& smallFactor) {
    return {pos.GetX() + (size.GetX() / 2) - (size.GetX() / (2 * smallFactor)),
            pos.GetY() + (size.GetY() / 2) - (size.GetY() / (2 * smallFactor))};
}