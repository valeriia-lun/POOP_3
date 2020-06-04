#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_inputFileButton_clicked();
    void on_outputFileButton_clicked();
    void on_copyButton_clicked();

private:
    Ui::MainWindow *ui;
    QString inputFileName,OutputFileName;
};

#endif // MAINWINDOW_H
