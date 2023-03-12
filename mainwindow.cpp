#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include "filereader.h"
#include "scenedrawer.h"
#include "exception.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _facade(nullptr, nullptr)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint);
    _facade = Facade(make_shared<FileReader>(), make_shared<SceneDrawer>(ui->canvas));
    buttonSettings(false);
    normalization();
    translation();
    rotation();
    scale(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::normalization(){
    double t = ui->SpinBox_Step->text().toDouble();
    _facade.normalization(Normalization(ui->SpinBox_min->text().toDouble(), ui->SpinBox_max->text().toDouble(),t, t));
    _facade.draw();
}

void MainWindow::translation(){
    _facade.translation(stepX, stepY, stepZ);
    _facade.draw();
}




void MainWindow::rotation(){
    normalization();
    _facade.rotation(qDegreesToRadians(angleX), qDegreesToRadians(angleY), qDegreesToRadians(angleZ));
    _facade.draw();
}

void MainWindow::scale(int a){
    scaling += ui->SpinBox_3->text().toDouble() * a;
    _facade.scale(scaling, scaling, scaling);
    _facade.draw();
}

void MainWindow::on_pushButton_openFile_clicked(){
    ui->canvas->clear();
    QString FileName = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::currentPath(), "CSV Table (*csv)");
    if (FileName.isEmpty()){
        ui->error->setText("No csv file!");
        buttonSettings(false);
    } else {
        buttonSettings(true);
        ui->fileName->setText(FileName);
    }
}

void MainWindow::on_pushButton_visualize_clicked(){
    string FileName = ui->fileName->text().toStdString();
    if (FileName.empty()){
        ui->error->setText("File is not selected!");
        buttonSettings(false);
    }
    else if (ui->SpinBox_min->text().toDouble() > ui->SpinBox_max->text().toDouble())
        ui->error->setText("Incorrect data! Re-Enter");
    else {
        ui->error->setText("");
        try {
            _facade.load(FileName.data());
            normalization();
        } catch (const MemoryAllocationError *e) {
            ui->error->setText(e->what());
        } catch (const FileException *e) {
            ui->error->setText(e->what());
        }
    }
}

void MainWindow::on_pushButton_turn_clicked(){
    rotation();
}

void MainWindow::on_pushButton_transfer_clicked(){
    translation();
}

void MainWindow::on_pushButton_scaling_clicked(){
    scale(1);
}

void MainWindow::on_plus_rot_x_bnt_clicked()
{
    angleX -= ui->SpinBox_x_1->text().toDouble();
    rotation();
}


void MainWindow::on_minus_rot_x_bnt_clicked()
{
    angleX += ui->SpinBox_x_1->text().toDouble();
    rotation();
}


void MainWindow::on_plus_rot_z_bnt_3_clicked()
{
    angleZ += ui->SpinBox_x_1->text().toDouble();
    rotation();
}


void MainWindow::on_minus_rot_z_bnt_3_clicked()
{
    angleZ -= ui->SpinBox_x_1->text().toDouble();
    rotation();
}


void MainWindow::on_plus_rot_y_bnt_2_clicked()
{
    angleY += ui->SpinBox_x_1->text().toDouble();
    rotation();
}


void MainWindow::on_minus_rot_y_bnt_2_clicked()
{
    angleY -= ui->SpinBox_x_1->text().toDouble();
    rotation();
}

void MainWindow::reset() {
    stepX = 0;
    stepY = 0;
    stepZ = 0;
    scaling = 0;
    ui->SpinBox_3->setText("0.3");
    angleX = 0;
    angleY = 0;
    angleZ = 0;

}


void MainWindow::on_normalization_clicked() {
    reset();
    normalization();
    translation();
    rotation();
    scale(1);
}


void MainWindow::on_plus_offset_x_bnt_clicked() {
    stepX += ui->SpinBox_x_2->text().toDouble();
    translation();
}


void MainWindow::on_minus_offset_x_bnt_clicked()
{
    stepX -= ui->SpinBox_x_2->text().toDouble();
    translation();
}


void MainWindow::on_plus_offset_y_bnt_clicked()
{
    stepY += ui->SpinBox_y_2->text().toDouble();
    translation();
}


void MainWindow::on_minus_offset_y_bnt_clicked()
{
    stepY -= ui->SpinBox_y_2->text().toDouble();
    translation();
}


void MainWindow::on_plus_offset_z_bnt_4_clicked()
{
    stepZ += ui->SpinBox_z_2->text().toDouble();
    translation();
}


void MainWindow::on_minus_offset_z_bnt_clicked()
{
    stepZ -= ui->SpinBox_z_2->text().toDouble();
    translation();
}


void MainWindow::on_plus_scale_bnt_clicked() {
    scale(1);
}


void MainWindow::on_minus_scale_bnt_clicked()
{
    scale(-1);
}

void MainWindow::buttonSettings(bool n){
    ui->pushButton_visualize->setEnabled(n);
    ui->normalization->setEnabled(n);
    ui->plus_offset_x_bnt->setEnabled(n);
    ui->plus_offset_y_bnt->setEnabled(n);
    ui->plus_offset_z_bnt_4->setEnabled(n);
    ui->plus_rot_x_bnt->setEnabled(n);
    ui->plus_rot_y_bnt_2->setEnabled(n);
    ui->plus_rot_z_bnt_3->setEnabled(n);
    ui->plus_scale_bnt->setEnabled(n);
    ui->minus_offset_x_bnt->setEnabled(n);
    ui->minus_offset_y_bnt->setEnabled(n);
    ui->minus_offset_z_bnt->setEnabled(n);
    ui->minus_rot_x_bnt->setEnabled(n);
    ui->minus_rot_y_bnt_2->setEnabled(n);
    ui->minus_rot_z_bnt_3->setEnabled(n);
    ui->minus_scale_bnt->setEnabled(n);
    ui->SpinBox_3->setReadOnly(!n);
    ui->SpinBox_Step->setReadOnly(!n);
    ui->SpinBox_max->setReadOnly(!n);
    ui->SpinBox_min->setReadOnly(!n);
    ui->SpinBox_x_1->setReadOnly(!n);
    ui->SpinBox_x_2->setReadOnly(!n);
    ui->SpinBox_y_1->setReadOnly(!n);
    ui->SpinBox_y_2->setReadOnly(!n);
    ui->SpinBox_z_1->setReadOnly(!n);
    ui->SpinBox_z_2->setReadOnly(!n);
}
