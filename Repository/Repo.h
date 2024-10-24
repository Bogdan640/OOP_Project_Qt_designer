#pragma once
#include "coat.h"
#include <vector>

class Repository
{
private:
    std::vector<Coat> coats;
    std::string filename;


public:
//    Repository(const std::string filename);
    Repository(const std::string& filename);

    Repository& operator=(const Repository& repo);

    ~Repository();

    void readFromFile();
    void writeToFile();

    Coat find_by_size_and_colour(const std::string& size, const std::string& colour);
    void add_repo(const Coat& coat);
    void remove_repo(int index);
    void update_repo(const Coat& coat, int index);

    void inc(int index);
    void dec(int index);

    int get_size();

    std::vector<Coat> get_all_repo();

};
