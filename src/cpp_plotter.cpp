#include "cpp_plotter.h"

#include <QApplication>
#include <QMainWindow>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

namespace cpp_plotter {

int Plot::show(const std::string &title)const
{
    // Pass arbitary argc, argv to Qt application since it
    // requires this, although unused here.
    int argc = 1;
    char argv0[] = "cpp_plotter";
    char *argv[] = {argv0};
    QApplication app(argc, argv);

    auto series = new QtCharts::QLineSeries();
    for (int i = 0; i < x.size(); i++) {
        series->append(x[i], y[i]);
    }

    auto chart = new QtCharts::QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(title.c_str());
    chart->setGeometry(5, 5, 200, 200);

    QWidget window;
    auto vbox = new QVBoxLayout(&window);
    auto chart_view = new QtCharts::QChartView(chart, &window);
    vbox->addWidget(chart_view);
    window.setLayout(vbox);

    window.resize(900, 600);
    window.setWindowTitle(title.c_str());
    window.show();

    return app.exec();
}

};
