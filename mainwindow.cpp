#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot()
{
    std::vector<Film> v=this->ctrl.getByGenre("action");
    int n1=v.size();
    std::vector<Film> v2=this->ctrl.getByGenre("comedy");
    int n2=v2.size();
    std::vector<Film> v3=this->ctrl.getByGenre("horror");
    int n3=v3.size();
    std::cout<<n1<<endl;
    qDebug() << n1;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *action = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *comedy = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *horror = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    action->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    comedy->setAntialiased(false);
    horror->setAntialiased(false);
    action->setStackingGap(1);
    comedy->setStackingGap(1);
    horror->setStackingGap(1);
    // set names and colors:
    action->setName("Action");
    action->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    action->setBrush(QColor(111, 9, 176));
    comedy->setName("Comedy");
    comedy->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    comedy->setBrush(QColor(250, 170, 20));
    horror->setName("Horror");
    horror->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    horror->setBrush(QColor(0, 168, 140));

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3;
    labels << "Action" << "Comedy" << "Horror";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, 10);
    ui->customPlot->yAxis->setPadding(1); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> actionData, comedyData, horrorData;
    actionData  << n1;
    comedyData << 0 << n2;
    horrorData   << 0 << 0 << n3;
    action->setData(ticks, actionData);
    comedy->setData(ticks, comedyData);
    horror->setData(ticks, horrorData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

