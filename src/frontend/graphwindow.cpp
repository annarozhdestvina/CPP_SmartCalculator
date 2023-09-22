#include "graphwindow.h"

#include "./ui/ui_graphwindow.h"

int polish_count;
lexeme_t polish[BUFF_SIZE] = {};

GraphWindow::GraphWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::start_graph(lexeme_t *external_polish,
                              int external_polish_count) {
  polish_count = external_polish_count;

  for (int i = 0; i < external_polish_count; i++) {
    polish[i].token = external_polish[i].token;
    polish[i].priority = external_polish[i].priority;
    polish[i].number = external_polish[i].number;
  }
}

void GraphWindow::on_run_graph_clicked() {
  int y_min_var = ui->y_min_var->value();
  int y_max_var = ui->y_max_var->value();

  int x_min_var = ui->x_min_var->value();
  int x_max_var = ui->x_max_var->value();

  if (y_min_var >= y_max_var) {
    QMessageBox::warning(this, "Ошибка: некорректные значения",
                         "Обнаружены некорректные значения оси ординат. "
                         "Отредактируйте значения!");
  } else if (x_min_var >= x_max_var) {
    QMessageBox::warning(this, "Ошибка: некорректные значения",
                         "Обнаружены некорректные значения оси абсцисс. "
                         "Отредактируйте значения!");
  } else {
    ui->graph_view->yAxis->setRange(y_min_var, y_max_var);
    ui->graph_view->xAxis->setRange(x_min_var, x_max_var);

    ui->graph_view->setInteraction(QCP::iRangeZoom, true);
    ui->graph_view->setInteraction(QCP::iRangeDrag, true);

    double step_var = ui->step_var->value();
    int step_count = (x_max_var - x_min_var) / step_var;

    int code;
    double var = x_min_var;

    QVector<double> x_var, y_var;

    for (int step = 0; step <= step_count; step++) {
      set_value(polish, polish_count, var);
      double res = calculate(polish, polish_count, &code);

      if (code == OK) {
        x_var.push_back(var);
        y_var.push_back(res);
      }

      var += step_var;
    }

    ui->graph_view->clearGraphs();
    ui->graph_view->addGraph();
    ui->graph_view->graph(0)->addData(x_var, y_var);
    ui->graph_view->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->graph_view->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
    ui->graph_view->replot();
  }
}
