//

#ifndef PACMAN_ENTITY_H
#define PACMAN_ENTITY_H

#include "Coordinate/Coordinate.h"
#include "ISubject/ISubject.h"
#include "IVisitor/IVisitor.h"

class PMLogic::Entity : public PMLogic::ISubject {
protected:
    const Coordinate2D::NormalizedCoordinate startPosition;
public:
    explicit Entity(Coordinate2D::NormalizedCoordinate startPosition);
    Entity();
    ~Entity() override = default;

    void NotifyAll() override;

    Coordinate2D::NormalizedCoordinate GetStartPosition() const;
    virtual Coordinate2D::NormalizedCoordinate GetCurrentPosition() const;

    virtual void Accept(const std::weak_ptr<PMLogic::IVisitor> &visitor) const = 0;
};

#endif // PACMAN_ENTITY_H
