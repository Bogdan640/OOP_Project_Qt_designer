#include "GUI.h"
#include "TableModel.h"
#include <qlabel.h>
#include <qmessagebox.h>
#include <qheaderview.h>
#include <qtabwidget.h>


GUI::GUI(Service& service) : service{ service }
{
    this->itCoats = this->service.get_all();
    this->currCoatIndex = 0;

    this->buildGUI();
    this->populateList();

    connect(this->addButton, &QPushButton::clicked, this, &GUI::addButtonHandler);
    connect(this->removeButton, &QPushButton::clicked, this, &GUI::removeButtonHandler);
    connect(this->updateButton, &QPushButton::clicked, this, &GUI::updateButtonHandler);

    connect(this->nextButton, &QPushButton::clicked, this, &GUI::nextButtonHandler);
    connect(this->viewAllButton, &QPushButton::clicked, this, &GUI::viewAllButtonHandler);
    connect(this->filterButton, &QPushButton::clicked, this, &GUI::filterButtonHandler);
    connect(this->buyButton, &QPushButton::clicked, this, &GUI::buyButtonHandler);
    connect(this->viewBasketButton, &QPushButton::clicked, this, &GUI::viewBuyButtonHandler);
    connect(this->saveButton, &QPushButton::clicked, this, &GUI::saveButtonHandler);



    this->undoShortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z), this);
    this->redoShortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Y), this);

    connect(this->undoButton, &QPushButton::clicked, this, &GUI::undoButtonHandler);
    connect(this->redoButton, &QPushButton::clicked, this, &GUI::redoButtonHandler);

    connect(this->undoShortcut, &QShortcut::activated, this, &GUI::undoButtonHandler);
    connect(this->redoShortcut, &QShortcut::activated, this, &GUI::redoButtonHandler);
}

void GUI::buildAdminGUI(QTabWidget* tabWidget)
{
    QWidget* mainWidget = new QWidget{};
    QVBoxLayout* mainLayout = new QVBoxLayout{};
    this->coatsListWidget = new QTableWidget{};
    this->coatsListWidget->setColumnCount(4);
    this->coatsListWidget->setShowGrid(true);
    this->coatsListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    this->coatsListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->coatsListWidget->setHorizontalHeaderLabels(QStringList() << QString("Size") << QString("Colour") << QString("Price") << QString("Quantity")<< QString("Photo link"));
    this->coatsListWidget->horizontalHeader()->setStretchLastSection(true);

    mainLayout->addWidget(this->coatsListWidget);

    QGridLayout* bottomLayout = new QGridLayout{};

    this->addButton = new QPushButton{ "Add coat" };
    this->removeButton = new QPushButton{ "Remove coat" };
    this->updateButton = new QPushButton{ "Update coat" };

    this->undoButton = new QPushButton{ "Undo" };
    this->redoButton = new QPushButton{ "Redo" };

    bottomLayout->addWidget(this->addButton, 4, 0);
    bottomLayout->addWidget(this->removeButton, 4, 1);
    bottomLayout->addWidget(this->updateButton, 4, 2);

    bottomLayout->addWidget(this->undoButton, 5, 0);
    bottomLayout->addWidget(this->redoButton, 5, 1);

    mainLayout->addLayout(bottomLayout);

    mainWidget->setLayout(mainLayout);

    tabWidget->addTab(mainWidget, "Admin");
}

void GUI::buildUserGUI(QTabWidget* tabWidget)
{
    QWidget* mainWidget = new QWidget{};
    this->mainUserLayout = new QHBoxLayout{};
    QGridLayout* leftLayout = new QGridLayout{};

    this->sizeInfo = new QLabel{"Size: " };
    this->colourInfo = new QLabel{"Colour: " };
    this->priceInfo = new QLabel{"Price: " };
    this->quantityInfo = new QLabel{"Qunatity: " };
    this->imageLabel = new QLabel{ "Photo Link: " };

    leftLayout->addWidget(this->sizeInfo, 0, 0);
    leftLayout->addWidget(this->colourInfo, 1, 0);
    leftLayout->addWidget(this->priceInfo, 2, 0);
    leftLayout->addWidget(this->quantityInfo, 3, 0);
    leftLayout->addWidget(this->imageLabel, 4, 0);

    this->buyButton = new QPushButton{"Buy coat" };
    this->filterButton = new QPushButton{ "Filter by size " };
    this->nextButton = new QPushButton{ "Next coat" };
    this->viewAllButton = new QPushButton{ "View All" };
    this->viewBasketButton = new QPushButton{"View Basket" };
    this->saveButton = new QPushButton{ "Save to file" };



    leftLayout->addWidget(nextButton, 4, 0);
    leftLayout->addWidget(buyButton, 5, 0);
    leftLayout->addWidget(viewBasketButton, 6, 0);
    leftLayout->addWidget(viewAllButton, 7, 0);
    leftLayout->addWidget(filterButton, 8, 0);
    leftLayout->addWidget(saveButton, 9, 0);

    //this->imageLabel = new QLabel{};
    //this->imageLabel->setFixedSize(400, 400);
    this->updateLabel();

    this->mainUserLayout->addLayout(leftLayout);
    //this->mainUserLayout->addWidget(this->imageLabel);

    mainWidget->setLayout(this->mainUserLayout);

    tabWidget->addTab(mainWidget, "User");
}





void GUI::undoButtonHandler()
{
    try	{
        this->service.undo();
        this->populateList();
    }
    catch (const std::exception& e) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", e.what());
        messageBox.setFixedSize(500, 200);
        messageBox.show();
    }
}

void GUI::redoButtonHandler()
{
    try {
        this->service.redo();
        this->populateList();
    }
    catch (const std::exception& e) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", e.what());
        messageBox.setFixedSize(500, 200);
        messageBox.show();
    }
}






void GUI::buildGUI()
{
    this->tabWidget = new QTabWidget{ this };
    this->tabWidget->setFixedSize(800, 600);

    this->buildAdminGUI(tabWidget);
    this->buildUserGUI(tabWidget);
    //this->buildPanelGUI(tabWidget);

    QObject::connect(tabWidget, &QTabWidget::currentChanged, this, &GUI::tabChanged);
}

void GUI::populateList()
{
    this->coatsListWidget->setRowCount(0);

    int i = 0;
    for (auto p : this->service.get_all())
    {
        this->coatsListWidget->insertRow(i);

        this->coatsListWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(p.get_size())));
        this->coatsListWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(p.get_colour())));
        this->coatsListWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(p.get_price()))));
        this->coatsListWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(p.get_quantity()))));
        this->coatsListWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(p.get_photo())));
        i++;
    }

    this->coatsListWidget->resizeColumnsToContents();
}

void GUI::addButtonHandler()
{
    this->addDialog = new QWidget{};
    addDialog->setFixedSize(300, 300);
    addDialog->setWindowTitle("Add coat");

    this->sizeLineEdit = new QLineEdit{};
    this->colourLineEdit = new QLineEdit{};
    this->priceLineEdit = new QLineEdit{};
    this->quantityLineEdit = new QLineEdit{};
    this->photoLineEdit = new QLineEdit{};

    QLabel* sizeLabel = new QLabel{"Size" };
    QLabel* colourLabel = new QLabel{ "Colour" };
    QLabel* priceLabel = new QLabel{"Price" };
    QLabel* quantityLabel = new QLabel{"Quantity" };
    QLabel* photoLabel = new QLabel{ "Photo link" };

    QVBoxLayout* layout = new QVBoxLayout{};

    layout->addWidget(sizeLabel);
    layout->addWidget(sizeLineEdit);
    layout->addWidget(colourLabel);
    layout->addWidget(colourLineEdit);
    layout->addWidget(priceLabel);
    layout->addWidget(priceLineEdit);
    layout->addWidget(quantityLabel);
    layout->addWidget(quantityLineEdit);
    layout->addWidget(photoLabel);
    layout->addWidget(photoLineEdit);

    QPushButton* confirmButton = new QPushButton{ "Confirm" };

    layout->addWidget(confirmButton);

    addDialog->setLayout(layout);
    addDialog->show();

    QObject::connect(confirmButton, &QPushButton::clicked, this, &GUI::addConfirmButtonHandler);
}

void GUI::addConfirmButtonHandler()
{
    try {
        this->service.add(this->sizeLineEdit->text().toStdString(),
                          this->colourLineEdit->text().toStdString(),
                          std::stoi(this->priceLineEdit->text().toStdString()),
                          std::stoi(this->quantityLineEdit->text().toStdString()),
                          this->photoLineEdit->text().toStdString());
        this->populateList();
    }
    catch (const std::exception& e) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", e.what());
        messageBox.setFixedSize(500, 200);
        messageBox.show();
        this->addDialog->close();
    }
    this->addDialog->close();
}

void GUI::removeButtonHandler()
{
    this->removeDialog = new QWidget{};
    removeDialog->setFixedSize(300, 300);
    removeDialog->setWindowTitle("Remove coat");

    this->sizeLineEdit = new QLineEdit{};
    this->colourLineEdit = new QLineEdit{};

    QLabel* sizeLabel = new QLabel{"Size" };
    QLabel* colourLabel = new QLabel{"Colour" };

    QVBoxLayout* layout = new QVBoxLayout{};

    layout->addWidget(sizeLabel);
    layout->addWidget(sizeLineEdit);
    layout->addWidget(colourLabel);
    layout->addWidget(colourLineEdit);

    QPushButton* confirmButton = new QPushButton{ "Confirm" };

    layout->addWidget(confirmButton);

    removeDialog->setLayout(layout);
    removeDialog->show();

    QObject::connect(confirmButton, &QPushButton::clicked, this, &GUI::removeConfirmButtonHandler);
}

void GUI::removeConfirmButtonHandler()
{
    try {
        this->service.remove(this->sizeLineEdit->text().toStdString(),
                             this->colourLineEdit->text().toStdString());
        this->populateList();
    }
    catch (const std::exception& e) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", e.what());
        messageBox.setFixedSize(500, 200);
        messageBox.show();
        this->removeDialog->close();
    }
    this->removeDialog->close();
}

void GUI::updateButtonHandler()
{
    this->updateDialog = new QWidget{};
    updateDialog->setFixedSize(300, 300);
    updateDialog->setWindowTitle("Update coat");

    this->sizeLineEdit = new QLineEdit{};
    this->colourLineEdit = new QLineEdit{};
    this->priceLineEdit = new QLineEdit{};
    this->quantityLineEdit = new QLineEdit{};
    this->photoLineEdit = new QLineEdit{};

    QLabel* sizeLabel = new QLabel{"Size" };
    QLabel* colourLabel = new QLabel{"Colour" };
    QLabel* priceLabel = new QLabel{"New price" };
    QLabel* quntityLabel = new QLabel{"New quantity" };
    QLabel* photoLabel = new QLabel{ "New photo link" };

    QVBoxLayout* layout = new QVBoxLayout{};

    layout->addWidget(sizeLabel);
    layout->addWidget(sizeLineEdit);
    layout->addWidget(colourLabel);
    layout->addWidget(colourLineEdit);
    layout->addWidget(priceLabel);
    layout->addWidget(priceLineEdit);
    layout->addWidget(quntityLabel);
    layout->addWidget(quantityLineEdit);
    layout->addWidget(photoLabel);
    layout->addWidget(photoLineEdit);

    QPushButton* confirmButton = new QPushButton{ "Confirm" };

    layout->addWidget(confirmButton);

    updateDialog->setLayout(layout);
    updateDialog->show();

    QObject::connect(confirmButton, &QPushButton::clicked, this, &GUI::updateConfirmButtonHandler);
}

void GUI::updateConfirmButtonHandler()
{
    try {
        this->service.update(this->sizeLineEdit->text().toStdString(),
                             this->colourLineEdit->text().toStdString(),
                             std::stoi(this->priceLineEdit->text().toStdString()),
                             std::stoi(this->quantityLineEdit->text().toStdString()),
                             this->photoLineEdit->text().toStdString());
        this->populateList();
    }
    catch (const std::exception& e) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", e.what());
        messageBox.setFixedSize(500, 200);
        messageBox.show();
        this->updateDialog->close();
    }
    this->updateDialog->close();
}

void GUI::nextButtonHandler()
{
    this->currCoatIndex++;
    if (this->currCoatIndex == this->itCoats.size())
        this->currCoatIndex = 0;
    this->updateLabel();
}

void GUI::viewAllButtonHandler()
{
    this->itCoats = this->service.get_all();
    this->currCoatIndex = 0;
    this->updateLabel();
}

void GUI::filterButtonHandler()
{
    this->filterDialog = new QWidget{};
    filterDialog->setFixedSize(300, 300);
    filterDialog->setWindowTitle("Filter by size ");

    this->sizeLineEdit = new QLineEdit{};
    this->colourLineEdit = new QLineEdit{};

    QLabel* sizeLabel = new QLabel{"Size" };
    //QLabel* colourLabel = new QLabel{"Colour" };

    QVBoxLayout* layout = new QVBoxLayout{};

    layout->addWidget(sizeLabel);
    layout->addWidget(sizeLineEdit);
    //layout->addWidget(colourLabel);
    layout->addWidget(colourLineEdit);

    QPushButton* confirmButton = new QPushButton{ "Confirm" };

    layout->addWidget(confirmButton);

    filterDialog->setLayout(layout);
    filterDialog->show();

    QObject::connect(confirmButton, &QPushButton::clicked, this, &GUI::filterConfirmButtonHandler);
}

void GUI::filterConfirmButtonHandler()
{
    this->itCoats = this->service.get_by_size_and_colour(this->sizeLineEdit->text().toStdString());
    this->currCoatIndex = 0;
    this->updateLabel();
    this->filterDialog->close();
}

void GUI::buyButtonHandler()
{
    this->service.add_to_basket(this->itCoats[this->currCoatIndex]);
    this->service.dec(this->currCoatIndex);
}

void GUI::viewBuyButtonHandler()
{
    this->buyDialog = new QWidget{};
    QVBoxLayout* layout = new QVBoxLayout{};
    buyDialog->setFixedSize(500, 500);
    buyDialog->setWindowTitle("Shopping basket");

//    this->shopListWidget = new QTableWidget{};
//    this->shopListWidget->setColumnCount(4);
//    this->shopListWidget->setShowGrid(true);
//    this->shopListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
//    this->shopListWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
//    this->shopListWidget->setHorizontalHeaderLabels(QStringList() << QString("Size") << QString("Colour") << QString("Price") <<QString("Quantity") << QString("Photo Link"));
//    this->shopListWidget->horizontalHeader()->setStretchLastSection(true);
//
//    int i = 0;
//    std::vector<Coat> Basket = this->service.get_all_basket()->getCoats();
//    for (auto p : Basket)
//    {
//        this->shopListWidget->insertRow(i);
//
//        this->shopListWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(p.get_size())));
//        this->shopListWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(p.get_colour())));
//        this->shopListWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(p.get_price()))));
//        this->shopListWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(p.get_quantity()))));
//        this->shopListWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(p.get_photo())));
//        i++;
//    }
//
//    this->shopListWidget->resizeColumnsToContents();
//    layout->addWidget(this->shopListWidget);
//    this->buyDialog->setLayout(layout);
//    this->buyDialog->show();


    std::vector<Coat> shoppingbasket = this->service.get_all_basket()->getCoats();

    // create the adoption list model
    TableModel *model = new TableModel(*this->service.get_all_basket());

    // create the table view and set the model
    QTableView* shoppingbasketView = new QTableView{};
    shoppingbasketView->setModel(model);
    shoppingbasketView->setSelectionMode(QAbstractItemView::SingleSelection);
    shoppingbasketView->setSelectionBehavior(QAbstractItemView::SelectRows);
    shoppingbasketView->horizontalHeader()->setStretchLastSection(true);

    // add the table view to the layout
    layout->addWidget(shoppingbasketView);
    this->buyDialog->setLayout(layout);
    this->buyDialog->show();
}

void GUI::updateLabel()
{

    if (this->currCoatIndex == this->itCoats.size())
        this->currCoatIndex = 0;

    if (this->itCoats.size() == 0)
    {
        this->sizeInfo->setText(QString::fromStdString("Size: "));
        this->colourInfo->setText(QString::fromStdString("Colour: "));
        this->priceInfo->setText(QString::fromStdString("Price: "));
        this->quantityInfo->setText(QString::fromStdString("Quantity: "));
        //
        this->imageLabel->setText(QString::fromStdString("Photo Link: "));
        return;
    }

    Coat d = this->itCoats[this->currCoatIndex];

    this->sizeInfo->setText(QString::fromStdString("Size: " + d.get_size()));
    this->colourInfo->setText(QString::fromStdString("Colour: " + d.get_colour()));
    this->priceInfo->setText(QString::fromStdString("Price: " + std::to_string(d.get_price())));
    this->quantityInfo->setText(QString::fromStdString("Quantity: " + std::to_string(d.get_quantity())));
    //
    this->imageLabel->setText(QString::fromStdString("Photo Link: " + d.get_photo()));
}

void GUI::tabChanged()
{
    if (this->tabWidget->currentIndex() == 1) {
        qDebug() << "User tab";
        this->itCoats = this->service.get_all();
        this->currCoatIndex = 0;
        this->updateLabel();
    }
    else if (this->tabWidget->currentIndex() == 2) {
        qDebug() << "Data panel tab";
        //this->updatePlot();
    }
}

void GUI::updateShoppingBasket(FileBasket* newbasket)
{
    this->service.UpdateBasket(newbasket);
    this->itCoats = this->service.get_all();
    this->currCoatIndex = 0;
    this->updateLabel();
}

void GUI::saveButtonHandler()
{
    this->service.save_basket();
    this->service.open_basket();
}

void GUI::createBasket(const std::string& type)
{
    if (type == "CSV" || type == "csv")
    {
        FileBasket* p = new CSVBasket{ "basket.csv" };
        this->updateShoppingBasket(p);
    }
    else if (type == "HTML" || type == "html")
    {
        FileBasket* p = new HTMLBasket{ "basket.html" };
        this->updateShoppingBasket(p);
    }
}


//void GUI::updatePlot()
//{
//    std::map<std::string, int> get_by_size = this->service.get_by_size();
//
//    QVector<double> ticks;
//    QVector<QString> labels;
//    QVector<double> data;
//
//    int i = 0;
//    for (auto d : get_by_size)
//    {
//        ticks << i + 1;
//        labels << QString::fromStdString(d.first);
//        data << d.second;
//        i++;
//    }
//
//    QCPBars* bars = new QCPBars(this->plot->xAxis, this->plot->yAxis);
//    bars->setData(ticks, data);
//    bars->setWidth(0.5);
//
//    // Adjust x-axis
//    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
//    textTicker->addTicks(ticks, labels);
//    this->plot->xAxis->setTicker(textTicker);
//    this->plot->xAxis->setRange(0, i + 1);
//    this->plot->xAxis->setTickLabelRotation(60);
//    this->plot->xAxis->setSubTicks(false);
//    this->plot->xAxis->setTickLength(0, 4);
//    this->plot->xAxis->setBasePen(QPen(Qt::white));
//    this->plot->xAxis->setTickPen(QPen(Qt::white));
//    this->plot->xAxis->grid()->setVisible(true);
//    this->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
//    this->plot->xAxis->setTickLabelColor(Qt::black);
//    this->plot->xAxis->setLabelColor(Qt::black);
//
//    // Adjust y-axis
//    int maxCount = *std::max_element(data.constBegin(), data.constEnd());
//    this->plot->yAxis->setRange(0, maxCount + 1);
//    this->plot->yAxis->setPadding(5);
//    this->plot->yAxis->setLabel("Number of coats");
//    this->plot->yAxis->setBasePen(QPen(Qt::black));
//    this->plot->yAxis->setTickPen(QPen(Qt::black));
//    this->plot->yAxis->setSubTickPen(QPen(Qt::white));
//    this->plot->yAxis->grid()->setSubGridVisible(true);
//    this->plot->yAxis->setTickLabelColor(Qt::black);
//    this->plot->yAxis->setLabelColor(Qt::black);
//    this->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
//    this->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
//
//    // Replot
//    this->plot->replot();
//}


//void GUI::updatePlot()
//{
//    std::map<std::string, int> coats_by_size = this->service.get_by_size();
//
//    QVector<double> ticks;
//    QVector<QString> labels;
//    QVector<double> data;
//
//    int i = 0;
//    for (const auto& d : coats_by_size)
//    {
//        ticks << i + 1;
//        labels << QString::fromStdString(d.first);
//        data << d.second;
//        i++;
//    }
//
//
//
//    QVector<QColor> colors = { QColor(88, 153, 9), QColor(63, 1, 28), QColor(59, 181, 45),
//                               QColor(2, 4, 136), QColor(133, 204, 111), QColor(108, 91, 123),
//                               QColor(53, 92, 125), QColor(248, 177, 149) };
//    int colorIndex = 0;
//
//    for (int j = 0; j < ticks.size(); j++)
//    {
//
//        QColor color = colors[colorIndex % colors.size()];
//        bar->setBrush(QBrush(color));
//        bar->setPen(QPen(color));
//
//        QVector<double> singleTick;
//        QVector<double> singleData;
//        singleTick << ticks[j];
//        singleData << data[j];
//        bar->setData(singleTick, singleData);
//        bar->setWidth(0.5);
//        bar->setName(labels[j]);
//        //this->plot->addPlottable(bar);
//
//        colorIndex++;
//    }
//
//
//
//    // x-axis
//
//    //QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
//    //textTicker->addTicks(ticks, labels);
//    //this->plot->xAxis->setTicker(textTicker);
//    //QSharedPointer<QCPAxisTicker> numberTicker(new QCPAxisTicker);
//
//
//    numberTicker->setTickStep(1);
//    numberTicker->setScaleStrategy(QCPAxisTickerFixed::ssNone);
//    this->plot->xAxis->setTicker(numberTicker);
//    this->plot->xAxis->setRange(0, i + 1);
//    this->plot->xAxis->setTickLabelRotation(0);
//    this->plot->xAxis->setSubTicks(true);
//    this->plot->xAxis->setTickLength(0, 2);
//    this->plot->xAxis->setBasePen(QPen(Qt::black));
//    this->plot->xAxis->setTickPen(QPen(Qt::black));
//    this->plot->xAxis->grid()->setVisible(true);
//    this->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
//    this->plot->xAxis->setTickLabelColor(Qt::black);
//    this->plot->xAxis->setLabelColor(Qt::black);
//
//    // y-axis
//    int maxCount = *std::max_element(data.constBegin(), data.constEnd());
//    this->plot->yAxis->setRange(0, maxCount + 1);
//    this->plot->yAxis->setPadding(5);
//    this->plot->yAxis->setLabel("Number of coats");
//    this->plot->yAxis->setBasePen(QPen(Qt::black));
//    this->plot->yAxis->setTickPen(QPen(Qt::black));
//    this->plot->yAxis->setSubTickPen(QPen(Qt::white));
//    this->plot->yAxis->grid()->setSubGridVisible(true);
//    this->plot->yAxis->setTickLabelColor(Qt::black);
//    this->plot->yAxis->setLabelColor(Qt::black);
//    this->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
//    this->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
//
//    this->plot->replot();
//}

