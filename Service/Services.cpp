#include <iostream>
#include "Services.h"
#include <algorithm>
#include "FileBasket.h"
#include <string>
#include <exception>
#include <utility>
#include <qdebug.h>
#include <stdexcept>


//// Default constructor
//Service::Service() {
//    this->repo=
//}


// Constructor with parameters
// Creates a service with a specified repository
Service::Service(const Repository& r, Shopping_basket* b) : repo(r), basket(b) {}


// Assignment operator
// Assigns the contents of one service to another
Service& Service::operator=(const Service& service)
{
    if (this == &service)
        return *this;
    this->repo = service.repo;
    return *this;
}


// Destructor
// Deallocates memory used by the service
Service::~Service()
{
}


// Adds a new coat to the repository
// Parameters:
// - size: The size of the coat
// - colour: The color of the coat
// - price: The price of the coat
// - quantity: The quantity of the coat
// - photo: The photo link of the coat
void Service::add(const std::string& size, const std::string& colour, int price, int quantity, const std::string& photo)
{
    Coat coat{ size, colour, price, quantity, photo };
    repo.add_repo(coat);

    this->undoActions.push_back(make_unique<ActionAdd>(this->repo, coat));
    this->redoActions.clear();
}


// Removes a coat from the repository based on its size and color
// Parameters:
// - size: The size of the coat to be removed
// - colour: The color of the coat to be removed
void Service::remove(const std::string& size, const std::string& colour)
{

    int index=0;
    for(auto coat: this->repo.get_all_repo())
    {
        if(coat.get_size() == size && coat.get_colour() == colour)
        {
            this->repo.remove_repo(index);
            this->undoActions.push_back(make_unique<ActionRemove>(this->repo, coat));
            this->redoActions.clear();
            break;
        }
        index++;
    }
}


// Updates the information of a coat in the repository
// Parameters:
// - size: The size of the coat to be updated
// - colour: The color of the coat to be updated
// - price: The new price of the coat
// - quantity: The new quantity of the coat
// - photo: The new photo link of the coat
void Service::update(const std::string& size, const std::string& colour, int price, int quantity, const std::string& photo)
{
    int index=0;
    for (auto coat: this->repo.get_all_repo())
    {
        if (coat.get_size() == size && coat.get_colour() == colour)
        {
            Coat new_coat = {size, colour, price, quantity, photo};
            this->repo.update_repo(new_coat, index);
            this->undoActions.push_back(make_unique<ActionUpdate>( this->repo, coat, new_coat ));
            this->redoActions.clear();
            break;
        }
        index++;
    }
}


// Increases the quantity of a coat in the repository
// Parameters:
// - index: The index of the coat to be updated
void Service::inc(int index)
{
    if (index >= 0 && index < repo.get_size())
        repo.inc(index);
}

// Decreases the quantity of a coat in the repository
// Parameters:
// - index: The index of the coat to be updated
void Service::dec(int index)
{
    if (index >= 0 && index < repo.get_size())
        repo.dec(index);
}


// Retrieves all coats from the repository
std::vector<Coat> Service::get_all()
{
    return repo.get_all_repo();
}


// Checks if a coat with a given size and color exists in the repository
// Returns the index of the coat if found, otherwise returns -1
int Service::check_colour_and_size(const std::string& size, const std::string& colour)
{
    int index = 0;
    for (const auto& coat : repo.get_all_repo())
    {
        if (coat.get_size() == size && coat.get_colour() == colour)
            return index;
        index++;
    }
    return -1;
}


// Adds pre-generated coats to the repository
void Service::add_generated_coats()
{
    repo.add_repo({"M", "grey", 99, 4, "https://www.tods.com/fashion/tods/X1W5447111EVNYB601/X1W5447111EVNYB601-34.jpg?imwidth=810"});
    repo.add_repo({"S", "blue", 120, 3, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTbPSfnT-83ZnjZMkidz9jGNmC1mVu_mYTSS66Ue8VuzQ&s"});
    repo.add_repo({"L", "black", 150, 5, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcT5CoVF-3cFAOuPoGpN2WztrG1p60xpGY2lxwQ9NYtReg&s"});
    repo.add_repo({"XL", "red", 80, 2, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQJdlQGuzKA-8MB7efLMZn6BD5VU738r42VipcC29voDw&s"});
    repo.add_repo({"M", "green", 110, 6, "https://i5.walmartimages.com/asr/e300d5a4-8b46-4617-995c-81e5379d3fa5.2d76a248c576c4cf01611975bf524a19.jpeg"});
    repo.add_repo({"S", "white", 130, 1, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTJtheefSwX3cXMBSd3pB58x_y9Vo-UDcA4FZwQMfSQ1A&s"});
    repo.add_repo({"L", "brown", 100, 7, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR7od9cAmARpeiF3J_2VQ_dls3w_8cnOHfAMB8f2hxRzw&s"});
    repo.add_repo({"XL", "purple", 90, 3, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcREbXWs6bLwNmhbbtauMhMpcVs7zme0CVZQNPBFmoj4iA&s"});
    repo.add_repo({"M", "pink", 140, 2, "https://janesstall.co.uk/wp-content/uploads/2023/09/Facetune_11-09-2023-23-23-52.jpg"});
    repo.add_repo({"S", "orange", 70, 4, "https://media.boohoo.com/i/boohoo/gzz28386_orange_xl/female-orange-tall-oversized-belted-trench-coat/?w=900&qlt=default&fmt.jp2.qlt=70&fmt=auto&sm=fit"});
}


Shopping_basket *Service::get_all_basket() {
    return this->basket;
}

void Service::add_to_basket(const Coat &coat) {
    if (this->basket == nullptr)
        return;
    this->basket->add(coat);
}

void Service::remove_from_basket(const std::string &size, const std::string &colour) {
    int i=0;
for (const Coat& coat: this->basket->getCoats())
{
    if (coat.get_size() == size && coat.get_colour() == colour)
    {
        this->basket->remove(i);
        break;
    }
    i++;
}
}

void Service::save_basket() {
    if (this->basket == nullptr)
        return;

    FileBasket* fileBasket = dynamic_cast<FileBasket*>(this->basket);
    if (fileBasket != nullptr)
        fileBasket->writeToFile();
}

void Service::open_basket() {
    if (this->basket == nullptr)
        return;
    FileBasket* fileBasket = dynamic_cast<FileBasket*>(this->basket);
    if (fileBasket != nullptr)
        fileBasket->displayBasket();
}

std::vector<Coat> Service::get_by_size_and_colour(const std::string &size) {
    std::vector<Coat> coats = this->repo.get_all_repo();
    std::vector<Coat> result;


    std::copy_if(coats.begin(), coats.end(), std::back_inserter(result),
                 [size](const Coat& coat)
                 { return coat.get_size() == size ; });

    return result;
}

void Service::UpdateBasket(Shopping_basket *b) {

    this->basket=b;
}

std::map<std::string, int> Service::get_by_size() {
    std::vector<Coat> coats = this->repo.get_all_repo();
    std::map<std::string, int> result;

    for (const Coat& coat : coats)
    {
        if (result.find(coat.get_size()) == result.end())
            result[coat.get_size()] = 1;
        else
            result[coat.get_size()]++;
    }

    return result;
}



void Service::undo()
{
    if (undoActions.empty())
        throw std::runtime_error("No more undos!");

    /*Action* action = &this->undoActions.back();
    action->executeUndo();
    this->redoActions.push_back(*action);
    this->undoActions.pop_back();*/

    undoActions.back()->executeUndo();
    redoActions.push_back(move(undoActions.back()));
    undoActions.pop_back();
}

void Service::redo()
{
    if (redoActions.empty())
        throw std::runtime_error("No more redos!");

    /*Action* action = &this->redoActions.back();
    action->executeRedo();
    this->undoActions.push_back(*action);
    this->redoActions.pop_back();*/

    redoActions.back()->executeRedo();
    undoActions.push_back(move(redoActions.back()));
    redoActions.pop_back();
}


