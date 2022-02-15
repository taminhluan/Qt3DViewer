#ifndef CONVERTERDIALOG_H
#define CONVERTERDIALOG_H

#include <QDialog>

namespace Ui {
class ConverterDialog;
}

class ConverterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConverterDialog(QWidget *parent = nullptr);
    ~ConverterDialog();

private slots:
    void on_btnConvert_clicked();

private:
    Ui::ConverterDialog *ui;
};

#endif // CONVERTERDIALOG_H
