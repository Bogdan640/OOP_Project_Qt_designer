#pragma once
#include "Repo.h"
#include "shopping_basket.h"
#include <map>
#include <memory>
#include "Action.h"


using std::make_unique;
using std::unique_ptr;
using std::move;



class Service
{
private:
    Repository repo;
    Shopping_basket* basket;

public:

    std::vector <unique_ptr<Action>> undoActions;
    std::vector <unique_ptr<Action>> redoActions;

    void undo();
    void redo();


    Service();
    Service(const Repository& r, Shopping_basket* b);

    Service& operator=(const Service& service);

    ~Service();

    void add(const std::string& size, const std::string& colour, int price, int quantity, const std::string& photo);
    void remove(const std::string& size, const std::string& colour);
    void update(const std::string& size, const std::string& colour, int price, int quantity, const std::string& photo);
    void inc(int index);
    void dec(int index);

    std::vector<Coat> get_all();
    int check_colour_and_size(const std::string& size, const std::string& colour);
    void add_generated_coats();
    std::vector<Coat> get_by_size_and_colour(const std::string& size);
    void UpdateBasket(Shopping_basket* b);
    std::map<std::string, int> get_by_size();

    Shopping_basket* get_all_basket();
    void add_to_basket(const Coat& coat);
    void remove_from_basket(const std::string& size, const std::string& colour);

    void save_basket();
    void open_basket();

};
