#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QVector>

extern "C" {
#include "../backend/base/calculator.h"
}

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QDialog {
  Q_OBJECT

 public:
  explicit GraphWindow(QWidget *parent = nullptr);
  ~GraphWindow();

 private:
  Ui::GraphWindow *ui;

 public slots:
  void start_graph(lexeme_t *polish, int polish_count);

 private slots:
  void on_run_graph_clicked();
};

#endif  // GRAPHWINDOW_H
