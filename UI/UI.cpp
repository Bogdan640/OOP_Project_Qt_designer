#include "UI.h"
#include "RepositoryExceptions.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



UI::UI(const Service& service) : service(service) {}

UI& UI::operator=(const UI& ui)
{
    if (this == &ui)
        return *this;
    this->service = ui.service;
    return *this;
}

UI::~UI() {}



void UI::save_basket_to_file() {
    std::string filename;
    cout << "Input the file name (absolute path): ";
    getline(cin, filename);
    try{
        this->service.save_basket();

        if(this->service.get_all_basket()== nullptr){
            cout<<"Basket cannot be displayed!"<<endl;
            return;
        }
    }
    catch (FileException& e){
        cout<<e.what()<<endl;
    }
}




void UI::add_ui(const std::string &size, const std::string &colour, int price, int quantity, const std::string &photo)
{
    if (service.check_colour_and_size(size, colour) == -1) {
        service.add(size, colour, price, quantity, photo);
        cout << "The coat with the size " << size << " and the colour " << colour << " was added to the database successfully!" << endl;
    }
    else {
        service.inc(service.check_colour_and_size(size, colour));
        cout << "\nAnother model of this coat was added to the stock!";
    }
}

void UI::remove_ui(const std::string& size, const std::string& colour)
{
    try
    {
        if (service.check_colour_and_size(size, colour) != -1) {
            service.remove(size, colour);
            cout << "The coat with the size " << size << " and the colour " << colour
                 << " was removed from the database successfully!" << endl;
        } else {
            throw RepositoryException("The coat with the size " + size +
            " and the colour " + colour + " does not exist in the database!");
            //cout << "The coat with the size " << size << " and the colour " << colour
                // << " does not exist in the database!" << endl;
                cout<<"\n";
        }
    }
    catch (RepositoryException& e)
    {
        std::cerr << "The coat with the size " << size << " and the colour " << colour
         << " does not exist in the database!" << endl;
    }
}

void UI::remove_single_ui(const std::string &size, const std::string &colour) {
    try {
        if (service.check_colour_and_size(size, colour) != -1) {
            if (this->service.get_all()[service.check_colour_and_size(size, colour)].get_quantity() > 1) {
                service.dec(service.check_colour_and_size(size, colour));
                cout << "The coat with the size " << size << " and the colour " << colour
                     << " was removed from the database successfully!" << endl;
            } else {
                this->remove_ui(size, colour);
            }
        } else {
            throw RepositoryException("The coat with the size " + size +
                                      " and the colour " + colour + " does not exist in the database!");
            //cout << "The coat with the size " << size << " and the colour " << colour
                // << " does not exist in the database!" << endl;
        }
    }
    catch (RepositoryException& e) {
        std::cerr << "The coat with the size " << size << " and the colour " << colour
         << " does not exist in the database!" << endl;
    }
}

void UI::update_ui(const std::string &size, const std::string &colour, int price, int quantity, const std::string &photo)
{
    try {
        if (service.check_colour_and_size(size, colour) != 0) {
            service.update(size, colour, price, quantity, photo);
            cout << "The coat with the size " << size << " and the colour " << colour << " was updated successfully!"
                 << endl;
        } else {
            throw RepositoryException("The coat with the size " + size +
                                      " and the colour " + colour + " does not exist in the database!");
            //cout << "The coat with the size " << size << " and the colour " << colour
                 //<< " does not exist in the database!" << endl;
        }
    }
    catch (RepositoryException& e) {
        std::cerr << "The coat with the size " << size << " and the colour " << colour
         << " does not exist in the database!" << endl;
    }
}

void UI::display_all()
{
    int i=1;
    vector<Coat> coats = service.get_all();
    for (const auto& coat : coats)
    {
        cout <<i<<": "<< "Size: " << coat.get_size() << ", Colour: " << coat.get_colour() <<
             ", Price: " << coat.get_price() << ", Quantity: " << coat.get_quantity() << "\n Photo link: "
             << coat.get_photo() << endl;
        i++;
    }
    cout<<"\n";
}

void UI::print_starting_menu()
{
    cout << "Welcome to the \"Proper Trench Coats\" database" << endl;
    cout << "1. Administrator mode" << endl;
    cout << "2. User mode" << endl;
    cout << "3. Exit the application" << endl;
    cout << endl;
}

void UI::print_menu_admin()
{
    cout << "\nYou are running the application in administrator mode." << endl;
    cout << "1. Add a coat to the database" << endl;
    cout << "2. Remove a whole stock of coats from the database " << endl;
    cout << "23. Remove a coat from the database " << endl;
    cout << "3. Update the information of a coat" << endl;
    cout << "4. Display all coats from the database" << endl;
    cout << "5. Exit the application" << endl;
    cout << endl;
}

void UI::print_menu_user()
{
    cout << "\nYou are running the application in user mode." << endl;
    cout << "1. See the trench coats" << endl;
    cout << "2. See the shopping basket and the total price of the items" << endl;
    cout << "3. Dsplay the shopping bag in file" << endl;
    cout << "4. Exit" << endl;
}

void UI::print_menu_user_2() {

    cout << "1. Add the trench to the shopping basket" << endl;
    cout << "2. Next item" << endl;
    cout << "3. Exit view mode"<<endl;
}

int UI::option_int() {
    try {
        std::string input;
        std::cout << "\nEnter an option: ";
        std::cin >> input;
        std::cin.ignore();


        // Try converting the input to an integer
        int num = std::stoi(input);
        return num;
        std::cout << "You entered: " << num << std::endl;
    } catch (const std::invalid_argument& e) {
        // Catch the exception if the input cannot be converted to an integer
        std::cerr << "Invalid input: Input cannot be converted to an integer" <<  std::endl;
        cout<<"\n";
    } catch (const InvalidInputException& e) {
        // Catch the custom exception if the input is a string
        std::cerr << "Invalid input: Input cannot be converted to an integer" << std::endl;
        cout<<"\n";
    }
    return 0;
}


void UI::run()
{
    int option, option_start;
    string size, colour, photo;
    int price, quantity;

    //service.add_generated_coats();

    print_starting_menu();
    cout << "Enter an option from the starting menu: ";
    cin >> option_start;
    cin.ignore();
    cout << endl;

    if (option_start == 1) {
        while (true)
        {

            print_menu_admin();
            option=this->option_int();
//            cout << "Enter an option: ";
//            cin >> option;
//            cin.ignore();
//            cout << endl;

            if (option == 1) {
                cout << "You are adding a coat to the database!" << endl;
                cout << "Enter the size: ";
                getline(cin, size);
                cout << "Enter the colour: ";
                getline(cin, colour);
                cout << "Enter the price: ";
                cin >> price;
                cout << "Enter the quantity: ";
                cin >> quantity;
                cin.ignore();
                cout << "Enter the photo link: ";
                getline(cin, photo);

                add_ui(size, colour, price, quantity, photo);
            }

            else if (option == 2) {
                cout << "You are removing a whole stock of a coat from the database!" << endl;
                cout << "Enter the size: ";
                getline(cin, size);
                cout << "Enter the colour: ";
                getline(cin, colour);

                remove_ui(size, colour);
            }

            else if (option == 23){
                cout << "You are removing a coat from the database!" << endl;
                cout << "Enter the size: ";
                getline(cin, size);
                cout << "Enter the colour: ";
                getline(cin, colour);

                remove_single_ui(size, colour);
            }

            else if (option == 3) {
                cout << "You are updating the information of a coat from the database!" << endl;
                cout << "Enter the size: ";
                getline(cin, size);
                cout << "Enter the colour: ";
                getline(cin, colour);
                cout << "Enter the price: ";
                cin >> price;
                cout << "Enter the quantity: ";
                cin >> quantity;
                cin.ignore();
                cout << "Enter the photo link: ";
                getline(cin, photo);

                update_ui(size, colour, price, quantity, photo);
            }

            else if (option == 4) {
                cout << "The coats in the database are: " << endl;
                display_all();
            }

            else if (option == 5) {
                cout << "You have exited the application!" << endl;
                break;
            }
//            else {
//                cout << "Invalid option!" << endl;
//            }
        }
    }

    else if (option_start == 2) {
        int price1 = 0;
        std::vector<Coat> bag;
        while (true) {
            this->print_menu_user();
            option=this->option_int();

            if (option == 1) {
                string siz;
                cout << "Choose a size: ";
                getline(cin, siz);
                int found=0;
                int index1=0, index2=0;
                bool exitloop=false;
                std::vector<Coat> v = this->service.get_all();
                while(!exitloop) {
                    index1=0;
                    index2=0;
                    for (const auto coat: v) {
                        if (siz.empty()) {
                            found = 1;
                            cout << index1++ +1 << " - Size: " << coat.get_size() << ", Colour: " << coat.get_colour() <<
                                 ", Price: " << coat.get_price() << ", Quantity: " << coat.get_quantity()
                                 << "\n Photo link: "
                                 << coat.get_photo() << endl;


                            int option1;
                            this->print_menu_user_2();
                            option1=option_int();

                            if (option1 == 1) {
                                price1 = price1 + coat.get_price();
                                bag.push_back(coat);
                                this->service.add_to_basket(coat);
                                cout << "\nThe current price of the bag is now: " << price1 << "\n";
                            } else if (option1 == 2) {
                                continue;
                            } else if (option1 == 3) {
                                exitloop= true;
                                break;
                            }
                            //index1++;

                        } else if (coat.get_size() == siz) {
                            found = 1;
                            cout << index2++ + 1 << " - Size: " << coat.get_size() << ", Colour: " << coat.get_colour() <<
                                 ", Price: " << coat.get_price() << ", Quantity: " << coat.get_quantity()
                                 << "\n Photo link: "
                                 << coat.get_photo() << endl;

                            int option1;
                            this->print_menu_user_2();
                            cout << "Enter an option: ";
                            cin >> option1;
                            cin.ignore();
                            cout << endl;
                            if (option1 == 1) {
                                price1 = price1 + coat.get_price();
                                bag.push_back(coat);
                                cout << "\nThe current price of the bag is now: " << price1 << "\n";
                            } else if (option1 == 2) {
                                continue;
                            } else if (option1 == 3) {
                                exitloop= true;
                            }


                        }
                    }
//                if (found == 0)
//                    break;
                }
            }

            else if (option == 2) {
                for (int i = 0; i < bag.size(); i++) {
                    Coat coat = bag[i];
                    cout << i + 1 << " - Size: " << coat.get_size() << ", Colour: " << coat.get_colour() <<
                         ", Price: " << coat.get_price() << ", Quantity: " << coat.get_quantity() << "\n Photo link: "
                         << coat.get_photo() << endl;
                }
                cout << "\nThe total cost of the shopping bag is: " << price1;


            }
            else if(option ==3)
            {
                cout<<"\n11111\n";
                this->save_basket_to_file();
                this->service.open_basket();
                cout<<"\n11111\n";
            }
            else if (option == 4) {
                exit(0);
            }
        }
    }


    else if (option_start == 3) {
        cout << "You have exited the application!" << endl;
    }
    else {
        cout << "Invalid option!" << endl;
    }
}
