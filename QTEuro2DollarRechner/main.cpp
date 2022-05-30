#include "mainwindow.h"

#include <QApplication>
#include "services/exchange_rate_service_impl.h"
#include "services/euro_to_dollar_calculator_impl.h"
#include "presenter/euro_to_dollar_presenter_impl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    exchange_rate_service_impl exchange_rate_service;
    euro_to_dollar_calculator_impl euro_to_dollar_rechner{exchange_rate_service};
    euro_to_dollar_presenter_impl euro_to_dollar_presenter;

    euro_to_dollar_presenter.set_model(&euro_to_dollar_rechner);
    euro_to_dollar_presenter.set_view(&w);
    w.set_presenter(&euro_to_dollar_presenter);

    w.show();
    return a.exec();
}
