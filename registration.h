#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_registrationBtn_clicked();
    void getReplyFinished();
    void readyReadReply();

private:
    Ui::Registration *ui;
    QNetworkReply *reply;
};

#endif // REGISTRATION_H
