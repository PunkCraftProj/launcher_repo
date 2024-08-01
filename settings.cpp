#include "settings.h"
#include "ui_settings.h"

#include <QString>
#include <QDebug>

Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
    setFixedSize(850, 470);

    // Установить значение по умолчанию для ramLine
    if (ui->ramLine->text().isEmpty() || ui->ramLine->text().toInt() == 0) {
        ui->ramLine->setText("8196");
    }
}

Settings::~Settings()
{
    delete ui;
}

QString Settings::getRAM() const {
    // Возвращает текстовое значение без каких либо вычислений
    return this->ui->ramLine->text();
}

void Settings::on_saveBtn_clicked()
{
    // Закрытие диалога при нажатии на кнопку save
    close();
}
