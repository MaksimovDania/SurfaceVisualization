#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_openFile_clicked();
    void on_pushButton_visualize_clicked();
    void on_pushButton_turn_clicked();
    void on_pushButton_transfer_clicked();
    void on_pushButton_scaling_clicked();

    void on_plus_rot_x_bnt_clicked();

    void on_minus_rot_x_bnt_clicked();

    void on_plus_rot_z_bnt_3_clicked();

    void on_minus_rot_z_bnt_3_clicked();

    void on_plus_rot_y_bnt_2_clicked();

    void on_minus_rot_y_bnt_2_clicked();

    void on_pushButton_rationing_clicked();

    void on_normalize_clicked();

    void on_norm_clicked();

    void on_normalization_clicked();

    void on_plus_offset_x_bnt_clicked();

    void on_minus_offset_x_bnt_clicked();

    void on_plus_offset_y_bnt_clicked();

    void on_minus_offset_y_bnt_clicked();

    void on_plus_offset_z_bnt_4_clicked();

    void on_minus_offset_z_bnt_clicked();

    void on_plus_scale_bnt_clicked();

    void on_minus_scale_bnt_clicked();

private:
    Ui::MainWindow *ui;
    Facade _facade;

    double scaling = 0;

    double stepX = 0;
    double stepY = 0;
    double stepZ = 0;

    double angleX = 0;
    double angleY = 0;
    double angleZ = 0;

    void normalization();
    void translation();
    void rotation();
    void scale(int a);
    void reset();
    void buttonSettings(bool n);

};

#endif
