#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int binarySearch(int array[], int x, int low, int high);

private slots:
    void on_GenerateDatasetpb_clicked();

    void on_NormalSearchpb_clicked();

    void on_BinarySearchpb_clicked();

    void on_STLSortpb_clicked();

private:
    Ui::MainWindow *ui;
    bool DataSetGenerated = false;
    bool sorted = false;
    QString SearchType;
    int arrsize;
    int *arr = new int[arrsize];


};
#endif // MAINWINDOW_H
//hi
