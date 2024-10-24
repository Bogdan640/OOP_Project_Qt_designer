#include "Action.h"
#include <QDebug>
#include <vector>
using namespace std;


ActionAdd::ActionAdd(Repository& repo, Coat addedCoat) : repo{ repo }, addedCoat{ addedCoat } {}

ActionAdd::~ActionAdd() {}

void ActionAdd::executeUndo()
{
    vector<Coat> Coats = this->repo.get_all_repo();
    int i = 0;
    for (auto c : Coats) {
        if (c.get_size() == this->addedCoat.get_size() && c.get_colour() == this->addedCoat.get_colour()) {
            //qDebug() << " remove Coat from repo action \n" ;
            this->repo.remove_repo(i);
            break;
        }
        i++;
    }
}

void ActionAdd::executeRedo()
{
    this->repo.add_repo(this->addedCoat);
}

ActionRemove::ActionRemove(Repository& repo, Coat removedCoat) : repo{ repo }, removedCoat{ removedCoat } {}

ActionRemove::~ActionRemove() {}

void ActionRemove::executeUndo()
{
    this->repo.add_repo(this->removedCoat);
}

void ActionRemove::executeRedo()
{
    vector<Coat> Coats = this->repo.get_all_repo();
    int i = 0;
    for (auto c : Coats) {
        if (c.get_size() == this->removedCoat.get_size() && c.get_colour() == this->removedCoat.get_colour()) {
            this->repo.remove_repo(i);
            break;
        }
        i++;
    }
}

ActionUpdate::ActionUpdate(Repository& repo, Coat oldCoat, Coat newCoat) : repo{ repo }, oldCoat{ oldCoat }, newCoat{ newCoat } {}

ActionUpdate::~ActionUpdate() {}

void ActionUpdate::executeUndo()
{
    vector<Coat> Coats = this->repo.get_all_repo();
    int i = 0;
    for (auto c : Coats) {
        if (c.get_size() == this->newCoat.get_size() && c.get_colour() == this->newCoat.get_colour()) {
            this->repo.update_repo(this->oldCoat, i);
            break;
        }
        i++;
    }
}

void ActionUpdate::executeRedo()
{
    vector<Coat> Coats = this->repo.get_all_repo();
    int i = 0;
    for (auto c : Coats) {
        if (c.get_size() == this->oldCoat.get_size() && c.get_colour() == this->oldCoat.get_colour()) {
            this->repo.update_repo(this->newCoat, i);
            break;
        }
        i++;
    }
}

