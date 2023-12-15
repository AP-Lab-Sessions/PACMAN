//

#ifndef PACMAN_COORDINATE_H
#define PACMAN_COORDINATE_H

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
};

const float normalizedMin=-1.0f, normalizedMax=1.0f;

bool IsNormalized(const float &n);
bool IsNormalized(const Coordinate &coordinate);

class NormalizedCoordinate : public Coordinate {
public:
    NormalizedCoordinate(const float &xArg, const float &yArg);

    void SetX(const float &newX) override;
    void SetY(const float &newY) override;
};

Coordinate Project(const NormalizedCoordinate &coord, const unsigned int &width, const unsigned int &height);

bool IsOverlapping(const NormalizedCoordinate &pos1, const Coordinate &size1,
                   const NormalizedCoordinate &pos2, const Coordinate &size2);

float GetManhattanDistance(const NormalizedCoordinate &coord1, const NormalizedCoordinate &coord2);
}



#endif // PACMAN_COORDINATE_H
