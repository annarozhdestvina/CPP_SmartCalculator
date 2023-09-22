#include "mainwindow.h"

#include "./ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->Button_0, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_1, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_2, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_3, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_4, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_5, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_6, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_7, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_8, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_9, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_dot, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_plus, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_minus, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_div, SIGNAL(clicked()), this, SLOT(pressing_on_div()));
  connect(ui->Button_mult, SIGNAL(clicked()), this, SLOT(pressing_on_mult()));
  connect(ui->Button_degree, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_mod, SIGNAL(clicked()), this, SLOT(pressing_button()));
  connect(ui->Button_sin, SIGNAL(clicked()), this, SLOT(pressing_on_sin()));
  connect(ui->Button_cos, SIGNAL(clicked()), this, SLOT(pressing_on_cos()));
  connect(ui->Button_asin, SIGNAL(clicked()), this, SLOT(pressing_on_asin()));
  connect(ui->Button_acos, SIGNAL(clicked()), this, SLOT(pressing_on_acos()));
  connect(ui->Button_tan, SIGNAL(clicked()), this, SLOT(pressing_on_tan()));
  connect(ui->Button_atan, SIGNAL(clicked()), this, SLOT(pressing_on_atan()));
  connect(ui->Button_sqrt, SIGNAL(clicked()), this, SLOT(pressing_on_sqrt()));
  connect(ui->Button_log, SIGNAL(clicked()), this, SLOT(pressing_on_log()));
  connect(ui->Button_ln, SIGNAL(clicked()), this, SLOT(pressing_on_ln()));
  connect(ui->Button_bracket_open, SIGNAL(clicked()), this,
          SLOT(pressing_button()));
  connect(ui->Button_bracket_close, SIGNAL(clicked()), this,
          SLOT(pressing_button()));
  connect(ui->Button_xvar, SIGNAL(clicked()), this, SLOT(pressing_on_xvar()));
  connect(ui->Button_AC, SIGNAL(clicked()), this, SLOT(pressing_ac()));
  connect(ui->Button_Backspace, SIGNAL(clicked()), this,
          SLOT(pressing_backspace()));
  connect(ui->Button_equal, SIGNAL(clicked()), this,
          SLOT(pressing_main_calculate()));
  connect(ui->Button_graph, SIGNAL(clicked()), this, SLOT(pressing_graph()));
  connect(ui->creditButton_calculate, SIGNAL(clicked()), this,
          SLOT(pressing_credit_calculate()));
  connect(ui->depositButton_calculate, SIGNAL(clicked()), this,
          SLOT(pressing_deposit_calculate()));

  QDate date = QDate::currentDate();
  ui->dateEdit_startdate->setDate(date);
  ui->Edit_tax_free->setText("1000000.00");
  ui->Edit_tax_rate->setText("13.0");
  ui->Edit_key_rate->setText("7.5");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::pressing_button() {
  QString res_str = ui->textEdit_main->toPlainText();
  QPushButton *button = (QPushButton *)sender();

  res_str.append(button->text());

  ui->textEdit_main->setPlainText(res_str);
}

void MainWindow::clicked_text_add(QString toAdd) {
  QString res_str = ui->textEdit_main->toPlainText();
  ui->textEdit_main->setText(res_str + toAdd);
}

void MainWindow::pressing_on_mult() { clicked_text_add("*"); }

void MainWindow::pressing_on_div() { clicked_text_add("/"); }

void MainWindow::pressing_on_log() { clicked_text_add("log("); }

void MainWindow::pressing_on_ln() { clicked_text_add("ln("); }

void MainWindow::pressing_on_sqrt() { clicked_text_add("sqrt("); }

void MainWindow::pressing_on_sin() { clicked_text_add("sin("); }

void MainWindow::pressing_on_cos() { clicked_text_add("cos("); }

void MainWindow::pressing_on_tan() { clicked_text_add("tan("); }

void MainWindow::pressing_on_asin() { clicked_text_add("asin("); }

void MainWindow::pressing_on_acos() { clicked_text_add("acos("); }

void MainWindow::pressing_on_atan() { clicked_text_add("atan("); }

void MainWindow::pressing_on_xvar() { clicked_text_add("X"); }

void MainWindow::pressing_ac() {
  ui->textEdit_main->clear();
  ui->textEdit_result->clear();
  ui->textEdit_xvar->clear();
}

void MainWindow::pressing_backspace() {
  QString res_str = ui->textEdit_main->toPlainText();
  res_str.truncate(res_str.length() - 1);
  ui->textEdit_main->setText(res_str);
}

void MainWindow::pressing_main_calculate() {
  result_t result;
  result.position = 0;
  result.result_code = OK;

  lexeme_t lexemes[BUFF_SIZE] = {};
  lexeme_t polish[BUFF_SIZE] = {};

  QByteArray str_bit = ui->textEdit_main->toPlainText().toLocal8Bit();
  char *input_str = str_bit.data();

  int lexeme_count = validate_input(input_str, lexemes, &result);

  if (result.result_code == NULL_LENGTH) {
    QMessageBox::warning(this, "Error: empty input", "Enter an expression");
  } else if (result.result_code == OVER_LENGTH) {
    QMessageBox::warning(this, "Error: input lenght",
                         "Exceeded input limit of 255 characters");
  } else if (result.result_code == INVALID_SYMBOL) {
    char message[BUFF_SIZE];
    sprintf(message, "Found unknown character at position %d", result.position);
    QMessageBox::warning(this, "Error: invalid character", message);
  } else if (result.result_code == INVALID_CLOSE_BRACKET) {
    char message[BUFF_SIZE];
    sprintf(message, "Found invalid close bracket at position %d",
            result.position);
    QMessageBox::warning(this, "Error: invalid close bracket", message);
  } else if (result.result_code == INVALID_OPEN_BRACKET) {
    QMessageBox::warning(this, "Error: invalid open bracket",
                         "Found invalid open bracket");
  } else if (result.result_code == INVALID_LEXEME) {
    QMessageBox::warning(this, "Error: invalid lexem",
                         "Found invalid open lexem");
  } else if (result.result_code == OK) {
    int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);
    bool check_val = check_value(polish, polish_count);

    if (!check_val ||
        (check_val && !ui->textEdit_xvar->toPlainText().isEmpty())) {
      if (check_val) {
        double x_var = ui->textEdit_xvar->toPlainText().toDouble();
        set_value(polish, polish_count, x_var);
      }

      int code = OK;
      long double ans = calculate(polish, polish_count, &code);

      if (code == DIV_ZERO) {
        QMessageBox::warning(this, "Error: division by zero",
                             "Found division by zero");
      } else if (code == NEGATIVE_ROOT) {
        QMessageBox::warning(this, "Error: negative root",
                             "Found negative root");
      } else if (code == NEGATIVE_LOG_LN) {
        QMessageBox::warning(this, "Error: logarithm of a negative number",
                             "Found logarithm of a negative number");
      } else if (code == OK) {
        ui->textEdit_result->setPlainText(QString::number(ans, 'f', 8));
      }
    } else {
      GraphWindow *graphwindow;
      graphwindow = new GraphWindow;

      connect(this, &MainWindow::signal, graphwindow,
              &GraphWindow::start_graph);
      emit signal(polish, polish_count);

      graphwindow->setModal(true);
      graphwindow->show();
    }
  }
}

void MainWindow::pressing_graph() {
  result_t result;
  result.position = 0;
  result.result_code = OK;

  lexeme_t lexemes[BUFF_SIZE] = {};
  lexeme_t polish[BUFF_SIZE] = {};

  // const char *input_str =
  // ui->textEdit_main->toPlainText().toLocal8Bit().data();
  QByteArray str_bit = ui->textEdit_main->toPlainText().toLocal8Bit();
  char *input_str = str_bit.data();
  int lexeme_count = validate_input(input_str, lexemes, &result);

  if (result.result_code == NULL_LENGTH) {
    QMessageBox::warning(this, "Error: empty input", "Enter an expression");
  } else if (result.result_code == OVER_LENGTH) {
    QMessageBox::warning(this, "Error: input lenght",
                         "Exceeded input limit of 255 characters");
  } else if (result.result_code == INVALID_SYMBOL) {
    char message[BUFF_SIZE];
    sprintf(message, "Found unknown character at position %d", result.position);
    QMessageBox::warning(this, "Error: invalid character", message);
  } else if (result.result_code == INVALID_CLOSE_BRACKET) {
    char message[BUFF_SIZE];
    sprintf(message, "Found invalid close bracket at position %d",
            result.position);
    QMessageBox::warning(this, "Error: invalid close bracket", message);
  } else if (result.result_code == INVALID_OPEN_BRACKET) {
    QMessageBox::warning(this, "Error: invalid open bracket",
                         "Found invalid open bracket");
  } else if (result.result_code == INVALID_LEXEME) {
    QMessageBox::warning(this, "Error: invalid lexem",
                         "Found invalid open lexem");
  } else if (result.result_code == OK) {
    int polish_count = revers_polish_notation(lexemes, lexeme_count, polish);
    bool check_val = check_value(polish, polish_count);
    if (!check_val) {
      QMessageBox::warning(this, "Error: no x-variable",
                           "Not found X-variable in input");
    } else {
      GraphWindow *graphwindow;
      graphwindow = new GraphWindow;

      connect(this, &MainWindow::signal, graphwindow,
              &GraphWindow::start_graph);
      emit signal(polish, polish_count);

      graphwindow->setModal(true);
      graphwindow->show();
    }
  }
}

void MainWindow::pressing_credit_calculate() {
  if (ui->Edit_credit_amount->toPlainText().isEmpty()) {
    QMessageBox::warning(this, "Error: empty field", "Enter credit amount");
  } else if (ui->Edit_credit_duration->toPlainText().isEmpty()) {
    QMessageBox::warning(this, "Error: empty field", "Enter credit duration");
  } else if (ui->Edit_credit_rate->toPlainText().isEmpty()) {
    QMessageBox::warning(this, "Error: empty field", "Enter interest rate");
  } else {
    loan_t loan;
    init_loan(&loan, ui->Edit_credit_amount->toPlainText().toDouble(),
              ui->Edit_credit_duration->toPlainText().toInt(),
              ui->comboBox_credit_duration->currentIndex(),
              ui->Edit_credit_rate->toPlainText().toDouble(),
              ui->comboBox_credit_type->currentIndex());

    calculate_loan(&loan);

    if (ui->comboBox_credit_type->currentIndex()) {
      QString num1 = QString::number(loan.payment_min, 'f', 2);
      QString num2 = QString::number(loan.payment_max, 'f', 2);
      ui->Edit_credit_payment->setPlainText(
          QString("from %1 to %2").arg(num1, num2));
    } else {
      ui->Edit_credit_payment->setPlainText(
          QString::number(loan.payment_min, 'f', 2));
    }

    ui->Edit_credit_overpayment->setPlainText(
        QString::number(loan.overpayment, 'f', 2));
    ui->Edit_credit_total->setPlainText(
        QString::number(loan.total_loan_repayment, 'f', 2));
  }
}

void MainWindow::pressing_deposit_calculate() {
  if (ui->Edit_deposit_amount->toPlainText().isEmpty()) {
    QMessageBox::warning(this, "Error: empty field", "Enter deposit amount");
  } else if (ui->Edit_deposit_duration->toPlainText().isEmpty()) {
    QMessageBox::warning(this, "Error: empty field", "Enter deposit duration");
  } else if (ui->Edit_interest_rate->toPlainText().isEmpty()) {
    QMessageBox::warning(this, "Error: empty field", "Enter interest rate");
  } else {
    deposit_t deposit;
    init_deposit(&deposit, ui->Edit_deposit_amount->toPlainText().toDouble(),
                 ui->Edit_interest_rate->toPlainText().toDouble(),
                 ui->comboBox_duration->currentIndex(),
                 ui->Edit_deposit_duration->toPlainText().toDouble(),
                 ui->comboBox_compound->currentIndex(),
                 ui->checkBox_capitalization->isChecked(),
                 ui->comboBox_replineshment->currentIndex(),
                 ui->Edit_replineshment_amount->toPlainText().toDouble(),
                 ui->comboBox_withdrawal->currentIndex(),
                 ui->Edit_withdrawal_amount->toPlainText().toDouble());

    date_t date;
    init_deposit_date(&date, ui->dateEdit_startdate->date().day(),
                      ui->dateEdit_startdate->date().month(),
                      ui->dateEdit_startdate->date().year(), &deposit);

    tax_t tax;
    init_tax_options(&tax, ui->Edit_key_rate->toPlainText().toDouble(),
                     ui->Edit_tax_rate->toPlainText().toDouble(),
                     ui->Edit_tax_free->toPlainText().toDouble());

    calculate_deposit(&deposit, &date, &tax);

    ui->Edit_accured_interest->setPlainText(
        QString::number(deposit.accrued_interest, 'f', 2));
    ui->Edit_tax_amount->setPlainText(QString::number(deposit.taxes, 'f', 2));
    ui->Edit_effective_percent->setPlainText(
        QString::number(deposit.effective_percent, 'f', 2));
    ui->Edit_end_balance->setPlainText(
        QString::number(deposit.total_sum, 'f', 2));
  }
}
