#pragma once
#include <string>
#include <fstream>

class Coat
{
private:
    std::string size, colour;
    int price, quantity;
    std::string photo;

public:
    Coat();

    Coat(const std::string& size, const std::string& colour, int price, int quantity, const std::string& photo);

    std::string get_size() const;
    std::string get_colour() const;
    int get_price() const;
    int get_quantity() const;
    std::string get_photo() const;
    void inc();
    void dec();

    friend std::istream& operator>>(std::istream& is, Coat& s);
    friend std::ostream& operator<<(std::ostream& os, const Coat& s);
};
