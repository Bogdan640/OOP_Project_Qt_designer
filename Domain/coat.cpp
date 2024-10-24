#include "coat.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Utils.h"
using namespace  std;

// Default constructor initializes all member variables to default values
Coat::Coat() : size{ "" }, colour{ "" }, price{ 0 }, quantity{ 0 }, photo{ "" } {}

// Parameterized constructor initializes member variables with provided values
Coat::Coat(const std::string& size, const std::string& colour, int price, int quantity, const std::string& photo)
        : size{ size }, colour{ colour }, price{ price }, quantity{ quantity }, photo{ photo } {}

// Retrieves the size of the coat
std::string Coat::get_size() const
{
    return this->size;
}

// Retrieves the color of the coat
std::string Coat::get_colour() const
{
    return this->colour;
}

// Retrieves the price of the coat
int Coat::get_price() const
{
    return this->price;
}

// Retrieves the quantity of the coat
int Coat::get_quantity() const
{
    return this->quantity;
}

// Increments the quantity of the coat by 1
void Coat::inc()
{
    this->quantity++;
}

// Decrements the quantity of the coat by 1
void Coat::dec() {
    this->quantity--;
}

// Retrieves the photo link of the coat
std::string Coat::get_photo() const
{
    return this->photo;
}

istream & operator>>(istream & is, Coat & c)
{
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, ',');
    if (tokens.size() != 5)
        return is;

    c.size = tokens[0];
    c.colour = tokens[1];
    c.price = stoi(tokens[2]);
    c.quantity = stoi(tokens[3]);
    c.photo = tokens[4];


    return is;

}

ostream & operator<<(ostream & os, const Coat & c)
{
    os << c.size << "," << c.colour << "," << c.price << "," << c.quantity << "," << c.photo << "\n";
    return os;
}

