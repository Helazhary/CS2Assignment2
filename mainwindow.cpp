#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));

//comment here

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

    }
}


void MainWindow::on_NormalSearchpb_clicked()
{
    ui->Usingxsearch->setText("Using: Normal Search...");
    SearchType = "Normal";
    bool x=false;
    for (int i=0; i<arrsize; i++)
    {
       if(arr[i] == (ui->SearchValueLineEdit->text()).toInt())
       {
           x=true;
           //ui->found->setText("found");
       }
    }
    if(x)
    {
        ui->found->setText("found");
    }
    else
        ui->found->setText("NOT found");

}


void MainWindow::on_BinarySearchpb_clicked()
{
    ui->Usingxsearch->setText("Using: Binary Search...");
    SearchType = "Binary";
    int f = binarySearch(arr, (ui->SearchValueLineEdit->text()).toInt(), 0, arrsize - 1);
    if(f == -1)
    {
        ui->found->setText("NOT found");
    }
    else
        ui->found->setText("found");
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
        ui->UnsortedArrLabel->setText("Sorted Array");
    }
}

int MainWindow::binarySearch(int array[], int x, int low, int high) {

    // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}
