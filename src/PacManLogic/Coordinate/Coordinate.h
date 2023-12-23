//

#ifndef PACMAN_COORDINATE_H
#define PACMAN_COORDINATE_H

#include <list>

/**
 * @brief A namespace related to coordinates of the game.
 */
namespace Coordinate2D {

/**
 * @brief General coordinates (not necessarily normalized)
 */
class Coordinate {
protected:
    float x, y;

public:
    virtual ~Coordinate() = default;
    Coordinate(const float& x, const float& y);
    float GetX() const;
    float GetY() const;

    virtual void SetX(const float& newX);
    virtual void SetY(const float& newY);

    bool operator==(const Coordinate& other) const;
};

const float normalizedMin{-1.0f}, normalizedMax{1.0f};

/**
 * @brief Normalized coordinates
 */
class NormalizedCoordinate : public Coordinate {
public:
    NormalizedCoordinate(const float& xArg, const float& yArg);

    void SetX(const float& newX) override;
    void SetY(const float& newY) override;
};
bool IsNormalized(const float& n);
bool IsNormalized(const Coordinate& coordinate);

/**
 * @brief Tells if two rectangles are overlapping
 * @param pos1 Position of first rectangle
 * @param size1 Size of first rectangle
 * @param pos2 Position of second rectangle
 * @param size2 Size of second rectangle
 * @return Boolean denoting if two rectangles are overlapping
 */
bool IsOverlapping(const NormalizedCoordinate& pos1, const Coordinate& size1, const NormalizedCoordinate& pos2,
                   const Coordinate& size2);
/**
 * @brief Gets the manhattan distance from one point to another
 * @param coord1
 * @param coord2
 * @return The distance
 */
float GetManhattanDistance(const NormalizedCoordinate& coord1, const NormalizedCoordinate& coord2);

/**
 * @brief Adjusts a one-dimensional point such that it's normalized (element of [-1,1])
 * @param position
 * @param length
 * @return
 */
float Normalize(const float& position, const float& length);

/**
 * @brief Adjusts a two-dimensional point such that x and y are normalized (element of [-1,1])
 * @param coordinate
 * @param size
 * @return
 */
Coordinate2D::NormalizedCoordinate Normalize(const Coordinate2D::Coordinate& coordinate,
                                             const Coordinate2D::Coordinate& size);

/**
 * @brief Gives coordinates of a centered rectangle that is of size size/smallfactor
 * @param pos The position.
 * @param size The size.
 * @param smallFactor
 * @return
 */
Coordinate2D::NormalizedCoordinate GetCenteredShrinked(const Coordinate2D::NormalizedCoordinate& pos,
                                                       const Coordinate2D::Coordinate& size, const float& smallFactor);
/**
 * @brief The only four two-dimensional directions that will be used.
 */
enum DiscreteDirection2D { Direction_Left = 'L', Direction_Right = 'R', Direction_Up = 'U', Direction_Down = 'D' };

/**
 * @brief The four directions but now in a list
 */
const std::list<Coordinate2D::DiscreteDirection2D> directions2D{
    {Coordinate2D::Direction_Left, Coordinate2D::Direction_Right, Coordinate2D::Direction_Up,
     Coordinate2D::Direction_Down}};

} // namespace Coordinate2D

#endif // PACMAN_COORDINATE_H
