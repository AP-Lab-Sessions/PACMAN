//

#ifndef PACMAN_SCORE_H
#define PACMAN_SCORE_H

#include "PMLogic.h"
#include "Pattern/Observer/EventListener/IEventListener.h"
#include "Events/EntityEvent/EntityCollectedEvent.h"


class PMLogic::Score : public IEventListener<EntityCollectedEvent> {
protected:
    int currentScore;
public:
    Score();

    void IncreaseScore(const int &amount);
    void DecreaseScore(const int &amount);

    int GetScore() const;

    void Update(const EntityCollectedEvent &eventData) override;
};

#endif // PACMAN_SCORE_H
