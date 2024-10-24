#include "shopping_basket.h"

Shopping_basket::Shopping_basket()
{
    this->current = 0;
}

Shopping_basket::~Shopping_basket()= default;

Coat Shopping_basket::getCurrentCoat() {
    if (this->current == this->coats.size())
        this->current = 0;
    return this->coats[this->current];
}

std::vector<Coat> Shopping_basket::getCoats() {
    return this->coats;
}

void Shopping_basket::add(const Coat &coat) {
    this->coats.push_back(coat);
}

void Shopping_basket::remove(int pos) {
    this->coats.erase(this->coats.begin() + pos);
}


