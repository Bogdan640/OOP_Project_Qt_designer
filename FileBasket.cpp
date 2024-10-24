#include "FileBasket.h"
#include <fstream>
#include <Windows.h>
#include <shellapi.h>

FileBasket::FileBasket(std::string filename) : filename{ filename } {}

CSVBasket::CSVBasket(std::string filename) : FileBasket(filename) {}

void CSVBasket::writeToFile() {
    std::ofstream out(filename);
    for (auto c : coats) {
        out << c;
    }
    out.close();
}

void CSVBasket::displayBasket() {
    ShellExecuteA(NULL, "open", "excel.exe", filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}

HTMLBasket::HTMLBasket(std::string filename) : FileBasket(filename) {}

void HTMLBasket::writeToFile() {
    std::ofstream out(filename);
    out << "<!DOCTYPE html>\n<html>\n<head>\n<title>Shopping Basket</title>\n</head>\n<body>\n<table border=\"1\">\n<tr>\n<td>Size</td>\n<td>Colour</td>\n<td>Price</td>\n<td>Quantity</td>\n</tr>\n";
    for (auto c : coats) {
        out << "<tr>\n<td>" << c.get_size() << "</td>\n<td>" << c.get_colour() << "</td>\n<td>" << c.get_price() << "</td>\n<td>" << c.get_quantity()<< "</td>\n</tr>\n";
    }
    out << "</table>\n</body>\n</html>";
    out.close();
}

void HTMLBasket::displayBasket() {
    std::string path = "file:///C:/Users/COSTY/Desktop/github-repos/oop-a4-5-Bogdan640/cmake-build-debug-coverage/basket.html";
    ShellExecuteA(NULL, "open", "chrome.exe", path.c_str(), NULL, SW_SHOWMAXIMIZED);
}

