#include "settings.h"
#include "ui_settings.h"
#include "json.h"

#include <QString>
#include <QDebug>


Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
    setFixedSize(850, 470);

    this->ui->ramLine->setText(loadJSON());
}

Settings::~Settings()
{
    delete ui;
}

QString Settings::getRAM() const {
    double ramValue = this->ui->ramLine->text().toDouble();
    double convertedRamValue = ramValue * 1.12485939;
    return QString::number(convertedRamValue, 'f', 0);
}

void Settings::on_saveBtn_clicked()
{
    saveJSON(this->ui->ramLine->text());
    close();
}
