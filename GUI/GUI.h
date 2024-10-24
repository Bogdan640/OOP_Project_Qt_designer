#pragma once
#include <vector>
#include <qwidget.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <qtablewidget.h>
#include <qlineedit.h>
#include <QCoreApplication>
#include <QtNetwork\qnetworkaccessmanager.h>
#include <QtNetwork\qnetworkrequest.h>
#include <QtNetwork\qnetworkreply.h>
#include <qlabel.h>
#include <qimage.h>
#include <qfile.h>
#include "Services.h"
#include "FileBasket.h"
#include <QKeySequence>
#include <QShortcut>

class GUI : public QWidget
{
private:
    Service& service;
    std::vector<Coat> itCoats;
    int currCoatIndex;

    QPushButton* undoButton;
    QPushButton* redoButton;
    QShortcut* undoShortcut;
    QShortcut* redoShortcut;

    QTableWidget* coatsListWidget;
    QTableWidget* shopListWidget;
    QTabWidget* tabWidget;

    QLineEdit* sizeLineEdit;
    QLineEdit* colourLineEdit;
    QLineEdit* priceLineEdit;
    QLineEdit* quantityLineEdit;
    QLineEdit* photoLineEdit;


    QPushButton* addButton;
    QPushButton* removeButton;
    QPushButton* updateButton;

    QPushButton* viewBasketButton;
    QPushButton* buyButton;
    QPushButton* nextButton;
    QPushButton* filterButton;
    QPushButton* viewAllButton;
    QPushButton* saveButton;

    QWidget* addDialog;
    QWidget* removeDialog;
    QWidget* updateDialog;

    QWidget* buyDialog;
    QWidget* filterDialog;

    QLabel* sizeInfo;
    QLabel* colourInfo;
    QLabel* priceInfo;
    QLabel* quantityInfo;
    QLabel* imageLabel;


    QHBoxLayout* mainUserLayout;


public:
    GUI(Service& service);

    void createBasket(const std::string& type);
    void updateShoppingBasket(FileBasket* newbasket);

private:
    void undoButtonHandler();
    void redoButtonHandler();

    void buildAdminGUI(QTabWidget* mainWidget);
    void buildUserGUI(QTabWidget* mainWidget);
    //void buildPanelGUI(QTabWidget* mainWidget);

    void buildGUI();
    void populateList();

    void addButtonHandler();
    void addConfirmButtonHandler();

    void removeButtonHandler();
    void removeConfirmButtonHandler();

    void updateButtonHandler();
    void updateConfirmButtonHandler();

    void nextButtonHandler();

    void filterButtonHandler();
    void filterConfirmButtonHandler();

    void viewAllButtonHandler();

    void buyButtonHandler();

    void viewBuyButtonHandler();

    void updateLabel();

    void tabChanged();

    void saveButtonHandler();
    void updatePlot();
};