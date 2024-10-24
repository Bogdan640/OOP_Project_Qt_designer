#pragma once
#include "Repo.h"
#include "Coat.h"

class Action
{
public:
    virtual ~Action()=default;
    virtual void executeUndo() = 0;
    virtual void executeRedo() = 0;

};

class ActionAdd : public Action {
private:
    Repository& repo;
    Coat addedCoat;
public:
    ActionAdd(Repository& repo, Coat addedCoat);
    ~ActionAdd() override;
    void executeUndo() override;
    void executeRedo() override;

};

class ActionRemove : public Action {
private:
    Repository& repo;
    Coat removedCoat;
public:
    ActionRemove(Repository& repo, Coat removedCoat);
    ~ActionRemove() override;
    void executeUndo() override;
    void executeRedo() override;
};


class ActionUpdate : public Action {
private:
    Repository& repo;
    Coat oldCoat;
    Coat newCoat;
public:
    ActionUpdate(Repository& repo, Coat oldCoat, Coat newCoat);
    ~ActionUpdate() override;
    void executeUndo() override;
    void executeRedo() override;
};

