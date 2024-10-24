#pragma once
#include <vector>
#include "coat.h"

class Shopping_basket {
protected:
    std::vector<Coat> coats;
    int current;
public:
    Shopping_basket();
    virtual ~Shopping_basket();

    Coat getCurrentCoat();
    std::vector<Coat> getCoats();

    void add(const Coat& coat);
    void remove(int pos);

};



