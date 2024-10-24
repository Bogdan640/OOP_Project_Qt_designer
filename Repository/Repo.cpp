#include "Repo.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include "RepositoryExceptions.h"

using namespace std;

// Default constructor
//Repository::Repository(const std::string filename) {
//    this->filename = filename;
//    this->readFromFile();
//}



// Copy constructor
// Creates a new repository as a copy of another repository
Repository::Repository(const std::string& filename)  {
    this->filename = filename;
    this->readFromFile();
}


// Assignment operator
// Assigns the contents of one repository to another
Repository& Repository::operator=(const Repository& repo)
{
    if (this == &repo)
        return *this;
    this->coats = repo.coats;
    return *this;
}


// Destructor
// Deallocates memory used by the repository
Repository::~Repository() {}


void Repository::readFromFile()
{

    ifstream file(this->filename);
    if (!file.is_open()) {
        throw FileException("The file could not be opened!");
    }

    Coat c;

    while (file >> c){
        this->coats.push_back(c);
    }

    file.close();

}

void Repository::writeToFile()
{
    ofstream file(this->filename);
    if (!file.is_open())
        throw FileException("The file could not be opened!");

    for (auto c : this->coats)
    {
        file << c;
    }

    file.close();
}



Coat Repository::find_by_size_and_colour(const std::string &size, const std::string &colour) {
    for (auto coat : this->coats)
    {
        if (coat.get_size() == size && coat.get_colour() == colour)
            return coat;
    }
    return Coat{};

}



// Adds a coat to the repository
// Parameters:
// - coat: The coat to be added
void Repository::add_repo(const Coat& coat)
{
    if (this->find_by_size_and_colour(coat.get_size(), coat.get_colour()).get_size() != "")
        throw DuplicateCoatException();
    this->coats.push_back(coat);
    this->writeToFile();

}


// Removes a coat from the repository at a specified index
// Parameters:
// - index: The index of the coat to be removed
void Repository::remove_repo(int index)
{
    if (index >= 0 && index < coats.size())
        coats.erase(coats.begin() + index);
    this->writeToFile();
}


// Updates the information of a coat in the repository at a specified index
// Parameters:
// - coat: The new information for the coat
// - index: The index of the coat to be updated
void Repository::update_repo(const Coat& coat, int index)
{
    if (index >= 0 && index < coats.size())
        coats[index] = coat;
    this->writeToFile();
}


// Increases the quantity of a coat in the repository at a specified index
// Parameters:
// - index: The index of the coat to be updated
void Repository::inc(int index)
{
    if (index >= 0 && index < coats.size())
        coats[index].inc();
    this->writeToFile();
}


// Decreases the quantity of a coat in the repository at a specified index
// Parameters:
// - index: The index of the coat to be updated
void Repository::dec(int index)
{
    if (index >= 0 && index < coats.size())
        coats[index].dec();
    this->writeToFile();
}

// Returns the number of coats in the repository
int Repository::get_size()
{
    return coats.size();
}


// Returns all coats in the repository
std::vector<Coat> Repository::get_all_repo()
{
    return coats;
}
