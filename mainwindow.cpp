#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

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
            for (int i=0; i<arrsize; i++) //filling array with random integers 1-1000
            {
                arr[i]=(1+rand()%1000);
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
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        sort(arr,arr+arrsize);
           std::chrono::steady_clock::time_point then = std::chrono::steady_clock::now();
           this->sorttime=std::chrono::duration_cast<std::chrono::nanoseconds>(then-now).count();
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
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
           mergeSort(arr,0,arrsize-1);
           std::chrono::steady_clock::time_point then = std::chrono::steady_clock::now();
           this->sorttime=std::chrono::duration_cast<std::chrono::nanoseconds>(then-now).count();
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

bool MainWindow::binarySearch(int array[], int x, int low, int high) {

    // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return true;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return false;
}

bool MainWindow::normalSearch()
{
    for (int i=0; i<arrsize; i++)
    {
       if(arr[i] == (ui->SearchValueLineEdit->text()).toInt())
       {
          return true;
       }
    }
   return false;
}

void MainWindow::on_pbfindit_clicked()
{
    if(DataSetGenerated == true)
    {
    if(SearchType == "Binary" && sorted==true)
    {        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        bool result = binarySearch(arr, (ui->SearchValueLineEdit->text()).toInt(), 0, arrsize - 1);
        std::chrono::steady_clock::time_point then = std::chrono::steady_clock::now();
        this->searchtime=std::chrono::duration_cast<std::chrono::nanoseconds>(then-now).count();

        if(result)
        {
            QMessageBox::information(this,"REPORT","the time taken to search for this number in nanoseconds is "+QString::number(this->searchtime)+" and the time taken to sort the list was "+QString::number(this->sorttime));

        }else
        {
          QMessageBox::information(this,"REPORT","THERE IS NO SUCH NUMBER, YOU BLIND\n we wasted "+QString::number(this->searchtime)+" nanoseconds to seach for that number  and "+QString::number(this->sorttime)+" to sort the list");
        }
    }

    else if (SearchType == "Binary" && sorted == false)
    {
        ui->SearchValueLineEdit->setText("Please sort array to use binary search!");
    }
    else if(SearchType == "Normal")
    {
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        bool found =normalSearch();
        std::chrono::steady_clock::time_point then = std::chrono::steady_clock::now();
        this->sorttime=std::chrono::duration_cast<std::chrono::nanoseconds>(then-now).count();

        if(found)
        {
            QMessageBox::information(this,"REPORT","the time taken to search for this number in nanoseconds is "+QString::number(this->searchtime)+" and the time taken to sort the list was "+QString::number(this->sorttime));

        }else
        {
         QMessageBox::information(this,"REPORT","THERE IS NO SUCH NUMBER, YOU BLIND\n we wasted "+QString::number(this->searchtime)+" nanoseconds to seach for that number  and "+QString::number(this->sorttime)+" to sort the list");
}
    }
    }
    else
        ui->found->setText("NO DATA GENERATED");
}


