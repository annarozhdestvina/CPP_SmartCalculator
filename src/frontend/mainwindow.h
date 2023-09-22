#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDoubleValidator>
#include <QIntValidator>
#include <QMainWindow>
#include <QMessageBox>

#include "graphwindow.h"

extern "C" {
#include "../backend/base/calculator.h"
#include "../backend/extra/loan_deposit.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
  void pressing_button();

  void clicked_text_add(QString toAdd);
  void pressing_on_mult();
  void pressing_on_div();
  void pressing_on_log();
  void pressing_on_ln();
  void pressing_on_sqrt();
  void pressing_on_sin();
  void pressing_on_cos();
  void pressing_on_tan();
  void pressing_on_asin();
  void pressing_on_acos();
  void pressing_on_atan();
  void pressing_on_xvar();
  void pressing_ac();
  void pressing_backspace();
  void pressing_graph();
  void pressing_main_calculate();
  void pressing_credit_calculate();
  void pressing_deposit_calculate();

signals:
  void signal(lexeme_t *, int);

};
#endif // MAINWINDOW_H
