#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registration.h"
#include "settings.h"

#include <QProcess>
#include <QLineEdit>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , settingsDialog(this)
{
    ui->setupUi(this);
    ui->passLineLog->setEchoMode(QLineEdit::Password);
    ui->startBtn->setEnabled(false);

    QFile file("settingsLogin.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        file.close();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        QJsonObject jsonObj = jsonDoc.object();
        this->ui->dontLeaveCheck->setChecked(jsonObj["stay_logged"].toBool());
    }

    loadSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_regBtn_clicked()
{
    Registration registrationDialog;
    registrationDialog.setModal(true);
    registrationDialog.setFixedSize(300, 300);

    registrationDialog.exec();
}

void MainWindow::on_startBtn_clicked()
{
    QString RAM = settingsDialog.getRAM();

    QProcess *process = new QProcess(this);

    QString command = "cd C:/Users/qequy/Desktop/punkcraft && jre-1.8\\bin\\javaw.exe -Dos.name=\"Windows 10\" -Dos.version=10.0 -Djava.library.path=versions\\Forge_1.12.2\\natives -cp libraries\\net\\minecraftforge\\forge\\1.12.2-14.23.5.2860\\forge-1.12.2-14.23.5.2860.jar;libraries\\org\\ow2\\asm\\asm-debug-all\\5.2\\asm-debug-all-5.2.jar;libraries\\net\\minecraft\\launchwrapper\\1.12\\launchwrapper-1.12.jar;libraries\\org\\jline\\jline\\3.5.1\\jline-3.5.1.jar;libraries\\com\\typesafe\\akka\\akka-actor_2.11\\2.3.3\\akka-actor_2.11-2.3.3.jar;libraries\\com\\typesafe\\config\\1.2.1\\config-1.2.1.jar;libraries\\org\\scala-lang\\scala-actors-migration_2.11\\1.1.0\\scala-actors-migration_2.11-1.1.0.jar;libraries\\org\\scala-lang\\scala-compiler\\2.11.1\\scala-compiler-2.11.1.jar;libraries\\org\\scala-lang\\plugins\\scala-continuations-library_2.11\\1.0.2_mc\\scala-continuations-library_2.11-1.0.2_mc.jar;libraries\\org\\scala-lang\\plugins\\scala-continuations-plugin_2.11.1\\1.0.2_mc\\scala-continuations-plugin_2.11.1-1.0.2_mc.jar;libraries\\org\\scala-lang\\scala-library\\2.11.1\\scala-library-2.11.1.jar;libraries\\org\\scala-lang\\scala-parser-combinators_2.11\\1.0.1\\scala-parser-combinators_2.11-1.0.1.jar;libraries\\org\\scala-lang\\scala-reflect\\2.11.1\\scala-reflect-2.11.1.jar;libraries\\org\\scala-lang\\scala-swing_2.11\\1.0.1\\scala-swing_2.11-1.0.1.jar;libraries\\org\\scala-lang\\scala-xml_2.11\\1.0.2\\scala-xml_2.11-1.0.2.jar;libraries\\lzma\\lzma\\0.0.1\\lzma-0.0.1.jar;libraries\\java3d\\vecmath\\1.5.2\\vecmath-1.5.2.jar;libraries\\net\\sf\\trove4j\\trove4j\\3.0.3\\trove4j-3.0.3.jar;libraries\\org\\apache\\maven\\maven-artifact\\3.5.3\\maven-artifact-3.5.3.jar;libraries\\net\\sf\\jopt-simple\\jopt-simple\\5.0.3\\jopt-simple-5.0.3.jar;libraries\\org\\apache\\logging\\log4j\\log4j-api\\2.15.0\\log4j-api-2.15.0.jar;libraries\\org\\apache\\logging\\log4j\\log4j-core\\2.15.0\\log4j-core-2.15.0.jar;libraries\\org\\tlauncher\\patchy\\1.3.9\\patchy-1.3.9.jar;libraries\\oshi-project\\oshi-core\\1.1\\oshi-core-1.1.jar;libraries\\net\\java\\dev\\jna\\jna\\4.4.0\\jna-4.4.0.jar;libraries\\net\\java\\dev\\jna\\platform\\3.4.0\\platform-3.4.0.jar;libraries\\com\\ibm\\icu\\icu4j-core-mojang\\51.2\\icu4j-core-mojang-51.2.jar;libraries\\com\\paulscode\\codecjorbis\\20101023\\codecjorbis-20101023.jar;libraries\\com\\paulscode\\codecwav\\20101023\\codecwav-20101023.jar;libraries\\com\\paulscode\\libraryjavasound\\20101123\\libraryjavasound-20101123.jar;libraries\\com\\paulscode\\librarylwjglopenal\\20100824\\librarylwjglopenal-20100824.jar;libraries\\com\\paulscode\\soundsystem\\20120107\\soundsystem-20120107.jar;libraries\\io\\netty\\netty-all\\4.1.9.Final\\netty-all-4.1.9.Final.jar;libraries\\com\\google\\guava\\guava\\21.0\\guava-21.0.jar;libraries\\org\\apache\\commons\\commons-lang3\\3.5\\commons-lang3-3.5.jar;libraries\\commons-io\\commons-io\\2.5\\commons-io-2.5.jar;libraries\\commons-codec\\commons-codec\\1.10\\commons-codec-1.10.jar;libraries\\net\\java\\jinput\\jinput\\2.0.5\\jinput-2.0.5.jar;libraries\\net\\java\\jutils\\jutils\\1.0.0\\jutils-1.0.0.jar;libraries\\com\\google\\code\\gson\\gson\\2.8.0\\gson-2.8.0.jar;libraries\\org\\tlauncher\\authlib\\1.6.251\\authlib-1.6.251.jar;libraries\\com\\mojang\\realms\\1.10.22\\realms-1.10.22.jar;libraries\\org\\apache\\commons\\commons-compress\\1.8.1\\commons-compress-1.8.1.jar;libraries\\org\\apache\\httpcomponents\\httpclient\\4.3.3\\httpclient-4.3.3.jar;libraries\\commons-logging\\commons-logging\\1.1.3\\commons-logging-1.1.3.jar;libraries\\org\\apache\\httpcomponents\\httpcore\\4.3.2\\httpcore-4.3.2.jar;libraries\\it\\unimi\\dsi\\fastutil\\7.1.0\\fastutil-7.1.0.jar;libraries\\org\\apache\\logging\\log4j\\log4j-api\\2.8.1\\log4j-api-2.8.1.jar;libraries\\org\\apache\\logging\\log4j\\log4j-core\\2.8.1\\log4j-core-2.8.1.jar;libraries\\org\\lwjgl\\lwjgl\\lwjgl\\2.9.4-nightly-20150209\\lwjgl-2.9.4-nightly-20150209.jar;libraries\\org\\lwjgl\\lwjgl\\lwjgl_util\\2.9.4-nightly-20150209\\lwjgl_util-2.9.4-nightly-20150209.jar;libraries\\com\\mojang\\text2speech\\1.10.3\\text2speech-1.10.3.jar;versions\\Forge_1.12.2\\Forge_1.12.2.jar -Xmx6796M -XX:+UnlockExperimentalVMOptions -XX:+UseG1GC -XX:G1NewSizePercent=20 -XX:G1ReservePercent=20 -XX:MaxGCPauseMillis=50 -XX:G1HeapRegionSize=32M -Dfml.ignoreInvalidMinecraftCertificates=true -Dfml.ignorePatchDiscrepancies=true -Djava.net.preferIPv4Stack=true -Dminecraft.applet.TargetDirectory=%cd% -DlibraryDirectory=libraries -Dlog4j.configurationFile=assets\\log_configs\\client-1.12.xml net.minecraft.launchwrapper.Launch --username qequy --version Forge_1.12.2 --gameDir %cd% --assetsDir assets --assetIndex 1.12 --uuid dafe00a2-12ff-11ef-b069-f02f74958d22 --accessToken null --userType mojang --tweakClass net.minecraftforge.fml.common.launcher.FMLTweaker --versionType Forge --width 925 --height 530";
    QString workDir = "C:/Users/qequy/Desktop/punkcraft";
    QString program = "C:/Users/qequy/Desktop/punkcraft/jre-1.8/bin/java.exe";

    QStringList arguments;
    arguments
              << "-Dos.name=Windows 10"
              << "-Dos.version=10.0"
              << "-Djava.library.path=versions\\Forge_1.12.2\\natives"
              << "-Xmx" + RAM + "M"
              << "-cp"
              << "libraries\\net\\minecraftforge\\forge\\1.12.2-14.23.5.2860\\forge-1.12.2-14.23.5.2860.jar;"
                 "libraries\\org\\ow2\\asm\\asm-debug-all\\5.2\\asm-debug-all-5.2.jar;"
                 "libraries\\net\\minecraft\\launchwrapper\\1.12\\launchwrapper-1.12.jar;"
                 "libraries\\org\\jline\\jline\\3.5.1\\jline-3.5.1.jar;"
                 "libraries\\com\\typesafe\\akka\\akka-actor_2.11\\2.3.3\\akka-actor_2.11-2.3.3.jar;"
                 "libraries\\com\\typesafe\\config\\1.2.1\\config-1.2.1.jar;"
                 "libraries\\org\\scala-lang\\scala-actors-migration_2.11\\1.1.0\\scala-actors-migration_2.11-1.1.0.jar;"
                 "libraries\\org\\scala-lang\\scala-compiler\\2.11.1\\scala-compiler-2.11.1.jar;"
                 "libraries\\org\\scala-lang\\plugins\\scala-continuations-library_2.11\\1.0.2_mc\\scala-continuations-library_2.11-1.0.2_mc.jar;"
                 "libraries\\org\\scala-lang\\plugins\\scala-continuations-plugin_2.11.1\\1.0.2_mc\\scala-continuations-plugin_2.11.1-1.0.2_mc.jar;"
                 "libraries\\org\\scala-lang\\scala-library\\2.11.1\\scala-library-2.11.1.jar;"
                 "libraries\\org\\scala-lang\\scala-parser-combinators_2.11\\1.0.1\\scala-parser-combinators_2.11-1.0.1.jar;"
                 "libraries\\org\\scala-lang\\scala-reflect\\2.11.1\\scala-reflect-2.11.1.jar;"
                 "libraries\\org\\scala-lang\\scala-swing_2.11\\1.0.1\\scala-swing_2.11-1.0.1.jar;"
                 "libraries\\org\\scala-lang\\scala-xml_2.11\\1.0.2\\scala-xml_2.11-1.0.2.jar;"
                 "libraries\\lzma\\lzma\\0.0.1\\lzma-0.0.1.jar;"
                 "libraries\\java3d\\vecmath\\1.5.2\\vecmath-1.5.2.jar;"
                 "libraries\\net\\sf\\trove4j\\trove4j\\3.0.3\\trove4j-3.0.3.jar;"
                 "libraries\\org\\apache\\maven\\maven-artifact\\3.5.3\\maven-artifact-3.5.3.jar;"
                 "libraries\\net\\sf\\jopt-simple\\jopt-simple\\5.0.3\\jopt-simple-5.0.3.jar;"
                 "libraries\\org\\apache\\logging\\log4j\\log4j-api\\2.15.0\\log4j-api-2.15.0.jar;"
                 "libraries\\org\\apache\\logging\\log4j\\log4j-core\\2.15.0\\log4j-core-2.15.0.jar;"
                 "libraries\\org\\tlauncher\\patchy\\1.3.9\\patchy-1.3.9.jar;"
                 "libraries\\oshi-project\\oshi-core\\1.1\\oshi-core-1.1.jar;"
                 "libraries\\net\\java\\dev\\jna\\jna\\4.4.0\\jna-4.4.0.jar;"
                 "libraries\\net\\java\\dev\\jna\\platform\\3.4.0\\platform-3.4.0.jar;"
                 "libraries\\com\\ibm\\icu\\icu4j-core-mojang\\51.2\\icu4j-core-mojang-51.2.jar;"
                 "libraries\\com\\paulscode\\codecjorbis\\20101023\\codecjorbis-20101023.jar;"
                 "libraries\\com\\paulscode\\codecwav\\20101023\\codecwav-20101023.jar;"
                 "libraries\\com\\paulscode\\libraryjavasound\\20101123\\libraryjavasound-20101123.jar;"
                 "libraries\\com\\paulscode\\librarylwjglopenal\\20100824\\librarylwjglopenal-20100824.jar;"
                 "libraries\\com\\paulscode\\soundsystem\\20120107\\soundsystem-20120107.jar;"
                 "libraries\\io\\netty\\netty-all\\4.1.9.Final\\netty-all-4.1.9.Final.jar;"
                 "libraries\\com\\google\\guava\\guava\\21.0\\guava-21.0.jar;"
                 "libraries\\org\\apache\\commons\\commons-lang3\\3.5\\commons-lang3-3.5.jar;"
                 "libraries\\commons-io\\commons-io\\2.5\\commons-io-2.5.jar;"
                 "libraries\\commons-codec\\commons-codec\\1.10\\commons-codec-1.10.jar;"
                 "libraries\\net\\java\\jinput\\jinput\\2.0.5\\jinput-2.0.5.jar;"
                 "libraries\\net\\java\\jutils\\jutils\\1.0.0\\jutils-1.0.0.jar;"
                 "libraries\\com\\google\\code\\gson\\gson\\2.8.0\\gson-2.8.0.jar;"
                 "libraries\\org\\tlauncher\\authlib\\1.6.251\\authlib-1.6.251.jar;"
                 "libraries\\com\\mojang\\realms\\1.10.22\\realms-1.10.22.jar;"
                 "libraries\\org\\apache\\commons\\commons-compress\\1.8.1\\commons-compress-1.8.1.jar;"
                 "libraries\\org\\apache\\httpcomponents\\httpclient\\4.3.3\\httpclient-4.3.3.jar;"
                 "libraries\\commons-logging\\commons-logging\\1.1.3\\commons-logging-1.1.3.jar;"
                 "libraries\\org\\apache\\httpcomponents\\httpcore\\4.3.2\\httpcore-4.3.2.jar;"
                 "libraries\\it\\unimi\\dsi\\fastutil\\7.1.0\\fastutil-7.1.0.jar;"
                 "libraries\\org\\apache\\logging\\log4j\\log4j-api\\2.8.1\\log4j-api-2.8.1.jar;"
                 "libraries\\org\\apache\\logging\\log4j\\log4j-core\\2.8.1\\log4j-core-2.8.1.jar;"
                 "libraries\\org\\lwjgl\\lwjgl\\lwjgl\\2.9.4-nightly-20150209\\lwjgl-2.9.4-nightly-20150209.jar;"
                 "libraries\\org\\lwjgl\\lwjgl\\lwjgl_util\\2.9.4-nightly-20150209\\lwjgl_util-2.9.4-nightly-20150209.jar;"
                 "libraries\\com\\mojang\\text2speech\\1.10.3\\text2speech-1.10.3.jar;versions\\Forge_1.12.2\\Forge_1.12.2.jar"
              << "net.minecraft.launchwrapper.Launch"
              << "--tweakClass"
              << "net.minecraftforge.fml.common.launcher.FMLTweaker"
              << "--version"
              << "forge"
              << "--username" << "qequy"
              << "--passwd" << "pisi"
              << "--gameDir" << "."
              << "--assetsDir" << "assets"
              << "--assetIndex" << "1.12"
              << "--uuid" << "59e2b7457d3e4c829ff9e838ae35408b"
              << "--accessToken" << "null"
              << "--userType" << "mojang"
              << "--versionType" << "Forge"
              << "--height" << "480"
              << "--width" << "854"
              << "-XX:+UnlockExperimentalVMOptions"
              << "-XX:+UseG1GC"
              << "-XX:G1NewSizePercent=20"
              << "-XX:G1ReservePercent=20"
              << "-XX:MaxGCPauseMillis=50"
              << "-XX:G1HeapRegionSize=32M"
              << "-Dfml.ignoreInvalidMinecraftCertificates=true"
              << "-Dfml.ignorePatchDiscrepancies=true"
              << "-Djava.net.preferIPv4Stack=true"
              << "-Dminecraft.applet.TargetDirectory=%cd%"
              << "-DlibraryDirectory=libraries"
              << "-Dlog4j.configurationFile=assets\\log_configs\\client-1.12.xml";

    process->setWorkingDirectory(workDir);
    process->start(program, arguments);

    hide();
}

void MainWindow::on_settingsBtn_clicked()
{
    settingsDialog.setModal(true);
    settingsDialog.exec();
}

void MainWindow::loadSettings() {
    QFile file("settingsLogin.json");
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data, &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << "JSON Parse Error: " << jsonError.errorString();
        return;
    }

    QJsonObject jsonObject = jsonResponse.object();

    if (jsonObject.contains("stay_logged") && jsonObject["stay_logged"].toBool() &&
        jsonObject.contains("login") && jsonObject.contains("password")) {
        QString login = jsonObject["login"].toString();
        QString password = jsonObject["password"].toString();

        this->ui->loginLineLog->setText(login);
        this->ui->passLineLog->setText(password);
        this->ui->dontLeaveCheck->setChecked(true);

        loginUser(login, password);
    }
}

void MainWindow::loginUser(const QString &login, const QString &password) {
    QUrl url = QUrl(QString("http://95.165.135.233:5000/api/login"));
    QNetworkRequest request(url);

    QJsonObject jsonObjLogin;
    jsonObjLogin["login"] = login;
    jsonObjLogin["password"] = password;
    QJsonDocument jsonDocLogin(jsonObjLogin);

    QByteArray data = jsonDocLogin.toJson();

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    reply = manager->post(request, data);

    connect(reply, SIGNAL(finished()), this, SLOT(getReplyFinished()));
    connect(reply, SIGNAL(finished()), this, SLOT(readyReadReply()));
}

void MainWindow::on_loginBtn_clicked()
{
    QJsonObject jsonObj;
    jsonObj["stay_logged"] = this->ui->dontLeaveCheck->isChecked();
    jsonObj["login"] = this->ui->loginLineLog->text();
    jsonObj["password"] = this->ui->passLineLog->text();

    QJsonDocument jsonDoc(jsonObj);
    QFile file("settingsLogin.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDoc.toJson());
        file.close();
    }

    QString login = this->ui->loginLineLog->text();
    QString password = this->ui->passLineLog->text();

    loginUser(login, password);
}

void MainWindow::getReplyFinished() {
    reply->deleteLater();
}

void MainWindow::readyReadReply() {
    QString answer = QString::fromUtf8(reply->readAll());
    qDebug() << "Reply: " << answer;

    QJsonParseError jsonError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8(), &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << "JSON Parse Error: " << jsonError.errorString();
        this->ui->infoLabel->setText("Ошибка ответа от сервера");
    }

    QJsonObject jsonObject = jsonResponse.object();

    if (jsonObject.contains("error")) {
        QString error = jsonObject["error"].toString();
        if (error == "Invalid login or password!") {
            this->ui->infoLabel->setText("Неправильный логин или пароль");
        } else if (error == "Login and password are required!") {
            this->ui->infoLabel->setText("Введите данные");
        }
    }
    if (jsonObject.contains("message")) {
        QString message = jsonObject["message"].toString();
        if (message == "Login successful!") {
            this->ui->infoLabel->setText("Вы залогинились");
            this->ui->startBtn->setEnabled(true);
        }
    }
}
