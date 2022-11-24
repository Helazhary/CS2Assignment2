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
    if (ui->InputDatasetSizeLineEdit->text()!="")
    {
        DataSetGenerated = true;
        sorted = false;
        ui->ArrayDisplay->clear();
        arrsize = ui->InputDatasetSizeLineEdit->text().toInt();
        arr = new int[arrsize];
            for (int i=0; i<arrsize; i++) //filling array with random integers 1-99
            {
                arr[i]=(1+rand()%99);
            }
            for (int i=0; i<arrsize; i++) //displaying unsorted array
            {
               ui->ArrayDisplay->addItem(QString::number(arr[i]));
            }
            ui->UnsortedArrLabel->setText("Unsorted Array");
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
                ui->SortTypeLabel->setText("Sorted Using STL Sort");
        sorted=true;
        sort(arr,arr+arrsize);
        ui->ArrayDisplay->clear();
        for (int i=0; i<arrsize; i++) //displaying sorted array
        {
          ui->ArrayDisplay->addItem(QString::number(arr[i]));
        }
        ui->UnsortedArrLabel->setText("Sorted Array");
    }
}



void MainWindow::on_MergeSortpb_clicked()
{

    if (DataSetGenerated==true && sorted==false)
    {
        ui->SortTypeLabel->setText("Sorted Using Merge Sort");
        sorted=true;
           mergeSort(arr,0,arrsize-1);
         ui->ArrayDisplay->clear();
        for (int i=0; i<arrsize; i++) //displaying sorted array
        {
          ui->ArrayDisplay->addItem(QString::number(arr[i]));
        }
        ui->UnsortedArrLabel->setText("Sorted Array");
    }
}

void MainWindow::mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      m = l+(r-l)/2;
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

void MainWindow::on_pbfindit_clicked()
{
    if(DataSetGenerated == true)
    {
    if(SearchType == "Binary" && sorted==true)
    {
        int result = binarySearch(arr, (ui->SearchValueLineEdit->text()).toInt(), 0, arrsize - 1);
        if(result == -1)
        {
            ui->found->setText("NOT found");
        }
        else
            ui->found->setText("found");
    }
    else if (SearchType == "Binary" && sorted == false)
    {
        ui->SearchValueLineEdit->setText("Please sort array to use binary search!");
    }
    else if(SearchType == "Normal")
    {
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
}
    else
        ui->found->setText("NO DATA GENERATED");
}

