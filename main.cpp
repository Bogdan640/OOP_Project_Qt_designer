//#include <QApplication>
//#include <QPushButton>
//
//int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
//    return QApplication::exec();
//}


#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <crtdbg.h>
#include "UI.h"
#include "Services.h"
#include "Repo.h"
#include "DynamicArr.h"
#include "coat.h"
#include "shopping_basket.h"
#include "FileBasket.h"
#include "RepositoryExceptions.h"
#include "GUI.h"

using namespace std;

//int main()
//{
////    Tests tests;
////    tests.runAllTests();
////    Repository repo = Repository("C:\\Users\\COSTY\\Desktop\\github repos\\oop-a4-5-Bogdan640\\coats.txt");
////    Service service = Service(repo);
////    UI ui = UI(service);
////    ui.run();
//
//    try{
//        Repository repo = Repository("C:\\Users\\COSTY\\Desktop\\github-repos\\oop-a4-5-Bogdan640\\coats.txt");
//        FileBasket* b= nullptr;
//        cout << "What type of file would you like to use to store the adoption list (csv/html)?" << endl;
//        cout << "File type: ";
//        string fileType{};
//        cin >> fileType;
//        cout << endl;
//        if (fileType == "csv")
//            b = new CSVBasket{ "basket.csv" };
//        else if (fileType == "html")
//            b = new HTMLBasket{ "basket.html" };
//        else
//            cout << "Invalid file type!" << endl;
//        Service service(repo, b);
//        UI ui(service);
//        ui.run();
//        delete b;
//    }
//    catch (FileException&)
//    {
//        cout << "Repository file could not be opened! The application will terminate." << endl;
//        return 1;
//    }
//
//    return 0;
//}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Repository repo = Repository("C:\\Users\\COSTY\\Desktop\\github-repos\\oop-a4-5-Bogdan640\\coats.txt");
    FileBasket* b= nullptr;
    Service service(repo, b);
    GUI gui(service);

    // Create widgets
    QLabel label("What type of file would you like to use to store the Adoption List (CSV/HTML)?");
    QLineEdit fileTypeEdit;
    QPushButton startButton("Start");

    // Layout setup
    QVBoxLayout layout;
    layout.addWidget(&label);
    layout.addWidget(&fileTypeEdit);
    layout.addWidget(&startButton);

    // Signal-slot connections
    QObject::connect(&startButton, &QPushButton::clicked, [&]() {
        QString fileType = fileTypeEdit.text().trimmed().toLower();
        if (fileType == "csv" || fileType == "html")
        {
            // Start the application
            // For now, let's just print the file type
            try {
                std::string type = fileType.toStdString();
                gui.createBasket(type);
                gui.show();
                delete b;
            }
            catch (FileException&)
            {
                cout << "Repository file could not be opened! The application will terminate." << endl;
            }
            qDebug() << "File type selected:" << fileType;
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "Invalid file type. Please enter CSV or HTML.");
        }
    });


    QWidget window;
    window.setLayout(&layout);
    window.show();

    return app.exec();
}