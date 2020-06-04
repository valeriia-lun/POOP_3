#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), inputFileName(""), OutputFileName(""){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_inputFileButton_clicked(){
    inputFileName = QFileDialog::getOpenFileName(0,QString::fromUtf8("Open file"),QDir::currentPath(),"*.*");
    if(inputFileName!=""){
    ui->inputFileLabel->setText(inputFileName);
     }
}

void MainWindow::on_outputFileButton_clicked(){
    OutputFileName = QFileDialog::getOpenFileName(0,QString::fromUtf8("Open file"),QDir::currentPath(),"*.*");
    if(OutputFileName!=""){
    ui->outputFileLabel->setText(OutputFileName);
    }
}

void MainWindow::on_copyButton_clicked(){
    if(inputFileName==""||OutputFileName==""){
       ui->title->setText("Choose file!");
    }else if(inputFileName==OutputFileName){
        ui->title->setText("Input file and Output file have to be different!");
    }else{
        QFile output(OutputFileName);
        if(!output.open(QIODevice::WriteOnly)) {
            QMessageBox::information(0,"error",output.errorString());
        }

        QFile input(inputFileName);
        if(!input.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0,"error",input.errorString());
        }

        QTextStream os(&output);

        char symbol;

        while(!input.atEnd()){
            input.read(&symbol, sizeof (char));
            switch (symbol) {
            case '\n':
                os << " ";
                break;

            case '\t':
                os << " ";
                break;

            default:
                os << symbol;
            }
        }

        input.close();
        output.close();

        os.flush();

        ui->title->setText("File copied!!!");
    }
}



