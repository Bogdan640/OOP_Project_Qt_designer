#pragma once
#include "coat.h"
#include "Repo.h"
#include "Services.h"
#include <iostream>
#include <vector>

class UI
{
private:
    Service service;

public:

    UI(const Service& service);

    UI& operator=(const UI& ui);

    ~UI();

    void add_ui(const std::string& size, const std::string& colour, int price, int quantity, const std::string& photo);
    void remove_ui(const std::string& size, const std::string& colour);
    void update_ui(const std::string& size, const std::string& colour, int price, int quantity, const std::string& photo);
    void remove_single_ui(const std::string& size, const std::string& colour);
    void display_all();

    void save_basket_to_file();

    void print_starting_menu();
    void print_menu_admin();
    void print_menu_user();
    void print_menu_user_2();
    void do_sub(int price, const Coat& coat);

    void run();
    int option_int();
};

