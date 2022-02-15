#include "converterdialog.h"
#include "ui_converterdialog.h"
#include "3d/tool/Converter.h"

#include <string>
#include <QMessageBox>

ConverterDialog::ConverterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConverterDialog)
{
    ui->setupUi(this);
}

ConverterDialog::~ConverterDialog()
{
    delete ui;
}

void ConverterDialog::on_btnConvert_clicked()
{
    std::string inputPath = ui->txtInput->text().toStdString();
    std::string outputPath = ui->txtOutput->text().toStdString();
    Converter converter;
    converter.convert(inputPath, outputPath);


    qDebug() << "Converted Successfully";
    QMessageBox msgBox;
    msgBox.setText("Converted Successfully.");
    msgBox.exec();

}

