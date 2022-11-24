#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_GenerateDatasetpb_clicked()
{
    if (ui->InputDatasetSizeLineEdit->text()!="" && DataSetGenerated == false)
    {
        DataSetGenerated = true;
        arrsize = ui->InputDatasetSizeLineEdit->text().toInt();
            for (int i=0; i<arrsize; i++) //filling array with random integers 1-99
            {
                arr[i]=(1+rand()%99);
            }
            for (int i=0; i<arrsize; i++) //displaying unsorted array
            {
               ui->ArrayDisplay->setText(ui->ArrayDisplay->text() + "\n" + QString::number(arr[i]));
            }


//                 //--testing scroll area-----//
//            for (int i=0; i<arrsize; i++) //displaying unsorted array
//            {
//               ui->scrollArea-> (ui->ArrayDisplay->text() + "\n" + QString::number(arr[i]));
//            }
    }
}


void MainWindow::on_NormalSearchpb_clicked()
{
    ui->Usingxsearch->setText("Using: Normal Search...");
    SearchType = "Normal";
}


void MainWindow::on_BinarySearchpb_clicked()
{
    ui->Usingxsearch->setText("Using: Binary Search...");
    SearchType = "Binary";
}


void MainWindow::on_STLSortpb_clicked()
{
    if (DataSetGenerated==true && sorted==false)
    {
        sorted=true;
        sort(arr,arr+arrsize);
        ui->ArrayDisplay->setText("");
        for (int i=0; i<arrsize; i++) //displaying sorted array
        {
           ui->ArrayDisplay->setText(ui->ArrayDisplay->text() + "\n" + QString::number(arr[i]));
        }
    }
}

