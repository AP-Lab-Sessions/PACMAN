//

#ifndef PACMAN_COORDINATE_H
#define PACMAN_COORDINATE_H

#include <list>


namespace Coordinate2D {
class Coordinate {
protected:
    float x, y;
public:
    virtual ~Coordinate() = default;
    Coordinate(const float &x, const float &y);
    float GetX() const;
    float GetY() const;

    virtual void SetX(const float &newX);
    virtual void SetY(const float &newY);

    bool operator==(const Coordinate &other) const;
};

enum DiscreteDirection2D {
    Direction_Left='L', Direction_Right='R', Direction_Up='U', Direction_Down='D'
};

const float normalizedMin{-1.0f}, normalizedMax{1.0f};

bool IsNormalized(const float &n);
bool IsNormalized(const Coordinate &coordinate);

class NormalizedCoordinate : public Coordinate {
public:
    NormalizedCoordinate(const float &xArg, const float &yArg);

    void SetX(const float &newX) override;
    void SetY(const float &newY) override;
};

bool IsOverlapping(const NormalizedCoordinate &pos1, const Coordinate &size1,
                   const NormalizedCoordinate &pos2, const Coordinate &size2);

float GetManhattanDistance(const NormalizedCoordinate &coord1, const NormalizedCoordinate &coord2);

float Normalize(const float &position, const float &length);
Coordinate2D::NormalizedCoordinate Normalize(const Coordinate2D::Coordinate &coordinate,
                                             const Coordinate2D::Coordinate &size);
}

const std::list<Coordinate2D::DiscreteDirection2D> directions2D {
    {Coordinate2D::Direction_Left,
     Coordinate2D::Direction_Right,
     Coordinate2D::Direction_Up,
     Coordinate2D::Direction_Down}};



#endif // PACMAN_COORDINATE_H
