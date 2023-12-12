//

#ifndef PACMAN_COORDINATE_H
#define PACMAN_COORDINATE_H

namespace Coordinate2D {
class Coordinate {
protected:
    float x, y;
public:
    ~Coordinate() = default;
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

}



#endif // PACMAN_COORDINATE_H
