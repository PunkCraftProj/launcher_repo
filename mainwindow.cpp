#include <cstdlib>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registration.h"
#include <settings.h>

#include <QDir>
#include <QProcess>
#include <QLineEdit>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , process(new QProcess(this)) // Инициализация QProcess
{
    ui->setupUi(this);
    ui->passLineLog->setEchoMode(QLineEdit::Password);

    // Подключаем сигналы для отслеживания вывода и ошибок процесса
    connect(process, &QProcess::readyReadStandardOutput, this, [this]() {
        qDebug() << "Standard Output: " << process->readAllStandardOutput();
    });

    connect(process, &QProcess::readyReadStandardError, this, [this]() {
        qDebug() << "Standard Error: " << process->readAllStandardError();
    });
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

    QDir exeDir(QCoreApplication::applicationDirPath());
    QString workDir = exeDir.absolutePath() + "/HiTech";

    QStringList arguments;
    arguments
        << "-Djava.library.path=./versions/Forge_1.12.2/natives"
        << "-Xmx" + RAM + "M"
        << "-cp"
        << "./libraries/net/minecraftforge/forge/1.12.2-14.23.5.2860/forge-1.12.2-14.23.5.2860.jar:./libraries/org/ow2/asm/asm-debug-all/5.2/asm-debug-all-5.2.jar:./libraries/net/minecraft/launchwrapper/1.12/launchwrapper-1.12.jar:./libraries/org/jline/jline/3.5.1/jline-3.5.1.jar:./libraries/com/typesafe/akka/akka-actor_2.11/2.3.3/akka-actor_2.11-2.3.3.jar:./libraries/com/typesafe/config/1.2.1/config-1.2.1.jar:./libraries/org/scala-lang/scala-actors-migration_2.11/1.1.0/scala-actors-migration_2.11-1.1.0.jar:./libraries/org/scala-lang/scala-compiler/2.11.1/scala-compiler-2.11.1.jar:./libraries/org/scala-lang/plugins/scala-continuations-library_2.11/1.0.2_mc/scala-continuations-library_2.11-1.0.2_mc.jar:./libraries/org/scala-lang/plugins/scala-continuations-plugin_2.11.1/1.0.2_mc/scala-continuations-plugin_2.11.1-1.0.2_mc.jar:./libraries/org/scala-lang/scala-library/2.11.1/scala-library-2.11.1.jar:./libraries/org/scala-lang/scala-parser-combinators_2.11/1.0.1/scala-parser-combinators_2.11-1.0.1.jar:./libraries/org/scala-lang/scala-reflect/2.11.1/scala-reflect-2.11.1.jar:./libraries/org/scala-lang/scala-swing_2.11/1.0.1/scala-swing_2.11-1.0.1.jar:./libraries/org/scala-lang/scala-xml_2.11/1.0.2/scala-xml_2.11-1.0.2.jar:./libraries/lzma/lzma/0.0.1/lzma-0.0.1.jar:./libraries/java3d/vecmath/1.5.2/vecmath-1.5.2.jar:./libraries/net/sf/trove4j/trove4j/3.0.3/trove4j-3.0.3.jar:./libraries/org/apache/maven/maven-artifact/3.5.3/maven-artifact-3.5.3.jar:./libraries/net/sf/jopt-simple/jopt-simple/5.0.3/jopt-simple-5.0.3.jar:./libraries/org/apache/logging/log4j/log4j-api/2.15.0/log4j-api-2.15.0.jar:./libraries/org/apache/logging/log4j/log4j-core/2.15.0/log4j-core-2.15.0.jar:./libraries/org/tlauncher/patchy/1.3.9/patchy-1.3.9.jar:./libraries/oshi-project/oshi-core/1.1/oshi-core-1.1.jar:./libraries/net/java/dev/jna/jna/4.4.0/jna-4.4.0.jar:./libraries/net/java/dev/jna/platform/3.4.0/platform-3.4.0.jar:./libraries/com/ibm/icu/icu4j-core-mojang/51.2/icu4j-core-mojang-51.2.jar:./libraries/com/paulscode/codecjorbis/20101023/codecjorbis-20101023.jar:./libraries/com/paulscode/codecwav/20101023/codecwav-20101023.jar:./libraries/com/paulscode/libraryjavasound/20101123/libraryjavasound-20101123.jar:./libraries/com/paulscode/librarylwjglopenal/20100824/librarylwjglopenal-20100824.jar:./libraries/com/paulscode/soundsystem/20120107/soundsystem-20120107.jar:./libraries/io/netty/netty-all/4.1.9.Final/netty-all-4.1.9.Final.jar:./libraries/com/google/guava/guava/21.0/guava-21.0.jar:./libraries/org/apache/commons/commons-lang3/3.5/commons-lang3-3.5.jar:./libraries/commons-io/commons-io/2.5/commons-io-2.5.jar:./libraries/commons-codec/commons-codec/1.10/commons-codec-1.10.jar:./libraries/net/java/jinput/jinput/2.0.5/jinput-2.0.5.jar:./libraries/net/java/jutils/jutils/1.0.0/jutils-1.0.0.jar:./libraries/com/google/code/gson/gson/2.8.0/gson-2.8.0.jar:./libraries/org/tlauncher/authlib/1.6.251/authlib-1.6.251.jar:./libraries/com/mojang/realms/1.10.22/realms-1.10.22.jar:./libraries/org/apache/commons/commons-compress/1.8.1/commons-compress-1.8.1.jar:./libraries/org/apache/httpcomponents/httpclient/4.3.3/httpclient-4.3.3.jar:./libraries/commons-logging/commons-logging/1.1.3/commons-logging-1.1.3.jar:./libraries/org/apache/httpcomponents/httpcore/4.3.2/httpcore-4.3.2.jar:./libraries/it/unimi/dsi/fastutil/7.1.0/fastutil-7.1.0.jar:./libraries/org/apache/logging/log4j/log4j-api/2.8.1/log4j-api-2.8.1.jar:./libraries/org/apache/logging/log4j/log4j-core/2.8.1/log4j-core-2.8.1.jar:./libraries/org/lwjgl/lwjgl/lwjgl/2.9.4-nightly-20150209/lwjgl-2.9.4-nightly-20150209.jar:./libraries/org/lwjgl/lwjgl/lwjgl_util/2.9.4-nightly-20150209/lwjgl_util-2.9.4-nightly-20150209.jar:./libraries/com/mojang/text2speech/1.10.3/text2speech-1.10.3.jar:./versions/Forge_1.12.2/Forge_1.12.2.jar"
        << "-XX:+UnlockExperimentalVMOptions"
        << "-XX:+UseG1GC"
        << "-XX:G1NewSizePercent=20"
        << "-XX:G1ReservePercent=20"
        << "-XX:MaxGCPauseMillis=50"
        << "-XX:G1HeapRegionSize=32M"
        << "-Dfml.ignoreInvalidMinecraftCertificates=true"
        << "-Dfml.ignorePatchDiscrepancies=true"
        << "-Djava.net.preferIPv4Stack=true"
        << "-Dminecraft.applet.TargetDirectory=./"
        << "-DlibraryDirectory=./libraries"
        << "-Dlog4j.configurationFile=./assets/log_configs/client-1.12.xml"

        << "net.minecraft.launchwrapper.Launch"
        << "--username" << "PIVODEVAT"
        << "--version" << "Forge_1.12.2"
        << "--gameDir" << "./"
        << "--assetsDir" << "./assets"
        << "--assetIndex" << "1.12"
        << "--uuid" << "58a349b34ccf4ccb864a2a15590c312b"
        << "--accessToken" << "null"
        << "--userType" << "mojang"

        << "--tweakClass" << "net.minecraftforge.fml.common.launcher.FMLTweaker"

        << "--versionType" << "Forge"
        << "--height" << "480"
        << "--width" << "854";

    QProcess *process = new QProcess(this);
    process->setWorkingDirectory(workDir);

    // Подключение сигнала finished к слоту lambda для показа окна
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [this](int, QProcess::ExitStatus) {
        this->show();
    });

    // Скрытие окна перед запуском процесса
    this->hide();

    process->start("java", arguments);

    if (!process->waitForStarted()) {
        qDebug() << "Failed to start process";
        qDebug() << process->errorString();
        return;
    }
}

void MainWindow::on_settingsBtn_clicked()
{
    settingsDialog.setModal(true);
    settingsDialog.exec();
}
