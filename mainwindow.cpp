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
        arr = new int[arrsize];
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
        ui->UnsortedArrLabel->setText("Sorted Array");
    }
}


void MainWindow::on_MergeSortpb_clicked()
{

    if (DataSetGenerated==true && sorted==false)
    {
        sorted=true;
           mergeSort(arr,0,arrsize-1);
        ui->ArrayDisplay->setText("");
        for (int i=0; i<arrsize; i++) //displaying sorted array
        {
           ui->ArrayDisplay->setText(ui->ArrayDisplay->text() + "\n" + QString::number(arr[i]));
        }
        ui->UnsortedArrLabel->setText("Sorted Array");
    }
}

void MainWindow::mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

void MainWindow::merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
