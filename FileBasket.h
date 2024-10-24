#pragma once
#include "shopping_basket.h"

class FileBasket : public Shopping_basket {

protected:
    std::string filename;
public:
FileBasket(std::string filename);

    virtual void writeToFile() = 0;
    virtual void displayBasket() = 0;
};

class CSVBasket : public FileBasket {
public:
    CSVBasket(std::string filename);
    void writeToFile();
    void displayBasket();
};

class HTMLBasket : public FileBasket {
public:
    HTMLBasket(std::string filename);
    void writeToFile();
    void displayBasket();
};




