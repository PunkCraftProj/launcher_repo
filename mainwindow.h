#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <settings.h>
#include <QtCore>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_regBtn_clicked();

    void on_startBtn_clicked();

    void on_settingsBtn_clicked();

private:
    Ui::MainWindow *ui;
    QProcess *process;
    Settings settingsDialog;
};
#endif // MAINWINDOW_H
