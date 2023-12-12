//

#ifndef PACMAN_ENTITY_H
#define PACMAN_ENTITY_H

#include "Coordinate/Coordinate.h"
#include "Pattern/Observer/ISubject/ISubject.h"
#include "IEntityVisitor/IEntityVisitor.h"

class PMLogic::Entity : public PMLogic::ISubject {
protected:
    Coordinate2D::NormalizedCoordinate position;
    const Coordinate2D::Coordinate size;
public:
    Coordinate2D::Coordinate GetSize() const;

    explicit Entity(Coordinate2D::NormalizedCoordinate startPosition, const Coordinate2D::Coordinate &size);
    ~Entity() override = default;

    void NotifyAll() override;

    Coordinate2D::NormalizedCoordinate GetPosition() const;

    void SetPosition(const Coordinate2D::NormalizedCoordinate &newPosition);

    virtual void Accept(const std::weak_ptr<IEntityVisitor> &visitor) = 0;
};

#endif // PACMAN_ENTITY_H
