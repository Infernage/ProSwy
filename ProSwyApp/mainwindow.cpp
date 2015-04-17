#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eventhelper.h"
#include <QSettings>
#include <QDebug>
#include <QIntValidator>
#include <QIcon>
#include <QMenu>
#include <QMessageBox>
#include <QNetworkProxyQuery>

// Static initialization
QEvent::Type MessageEvent::eType = QEvent::None;
MainWindow *MainWindow::mainWindow = NULL;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ProSwy");
    mainWindow = this;
    ui->widget->setEnabled(false);
    ui->proxyPortEdit->setValidator(new QIntValidator(0, 65535, this));

    connect(ui->newConnectionButton, SIGNAL(clicked()), this, SLOT(addConnection()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(removeConnection()));
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(selectionChanged(int)));
    connect(ui->proxyNameEdit, SIGNAL(textEdited(QString)), this, SLOT(proxyNameChanged(QString)));
    connect(ui->proxyPortEdit, SIGNAL(textEdited(QString)), this, SLOT(proxyPortChanged(QString)));
    connect(ui->usernameEdit, SIGNAL(textEdited(QString)), this, SLOT(usernameChanged(QString)));
    connect(ui->paswordEdit, SIGNAL(textEdited(QString)), this, SLOT(passwordChanged(QString)));
    connect(ui->proxyNameEdit, SIGNAL(editingFinished()), this, SLOT(proxyChanged()));
    connect(ui->proxyPortEdit, SIGNAL(editingFinished()), this, SLOT(proxyChanged()));
    connect(ui->enableBox, SIGNAL(clicked(bool)), this, SLOT(enableProxy(bool)));

    if (QSystemTrayIcon::isSystemTrayAvailable()){
        timer.setSingleShot(true);
        timer.setInterval(100);
        connect(&timer, SIGNAL(timeout()), this, SLOT(showMessage())); // Avoids some buggy messages.

        tray = new QSystemTrayIcon(QIcon(":/ui/icon.png"), this);
        tray->setToolTip("Proxy Switcher");
        QMenu *menu = new QMenu(this);
        QAction *open = new QAction("Open", menu);
        QAction *quit = new QAction("Quit", menu);
        QFont f = quit->font();
        f.setBold(true);
        quit->setFont(f);

        connect(open, SIGNAL(triggered()), this, SLOT(show()));
        connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));

        menu->addAction(open);
        menu->addSeparator();
        menu->addAction(quit);
        tray->setContextMenu(menu);
        connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                this, SLOT(trayActivation(QSystemTrayIcon::ActivationReason)));
        tray->show();
    } else{
        tray = NULL;
    }
}

MainWindow::~MainWindow()
{}

void MainWindow::closeEvent(QCloseEvent *event)
{
    hide();
    event->ignore();
}

bool MainWindow::event(QEvent *event)
{
    if (event->type() == MessageEvent::type()){
        MessageEvent *evt = (MessageEvent*) event;
        if (tray != NULL) tray->showMessage(evt->getTitle(), evt->getMessage(), evt->getIcon());
        else{
            switch (evt->getIcon()) {
            case QSystemTrayIcon::Critical:
                QMessageBox::critical(this, evt->getTitle(), evt->getMessage());
                break;
            case QSystemTrayIcon::NoIcon:
            case QSystemTrayIcon::Information:
                QMessageBox::information(this, evt->getTitle(), evt->getMessage());
                break;
            case QSystemTrayIcon::Warning:
                QMessageBox::warning(this, evt->getTitle(), evt->getMessage());
                break;
            default:
                qDebug() << "No suitable icon found!";
                qDebug() << "Title:" << evt->getTitle() << "Message:" << evt->getMessage();
                break;
            }
        }
        return true;
    } else if (event->type() == DataEvent::type()){
        DataEvent *evt = (DataEvent*) event;
        QString type = evt->getType();
        if (type == "QStringList"){
            QStringList lst = evt->getData().toStringList();
            foreach (QString s, lst) {
                ui->listWidget->addItem(s);
            }
        } else if (type == "QStringWidget"){
            QString str = evt->getData().toString();
            ui->listWidget->addItem(str);
        } else if (type == "Mark"){
            QString mark = evt->getData().toString();
            QList<QListWidgetItem *> items = ui->listWidget->findItems(mark, Qt::MatchExactly);
            if (items.size() > 0){
                QListWidgetItem *i = items.first();
                i->setText(i->text() + " - (Connected)");
                QFont f = i->font();
                f.setBold(true);
                f.setItalic(true);
                i->setFont(f);
            }
            items = ui->listWidget->findItems(last + " - (Connected)", Qt::MatchExactly);
            if (items.size() > 0){
                QListWidgetItem *i = items.first();
                i->setText(i->text().replace(" - (Connected)", ""));
                QFont f = i->font();
                f.setBold(false);
                f.setItalic(false);
                i->setFont(f);
            }
            last = mark;
        }
        return true;
    } else return QMainWindow::event(event);
}

void MainWindow::addConnection()
{
    HandlerManager::addConnection();
}

void MainWindow::removeConnection()
{
    if (!HandlerManager::removeConnection(ui->listWidget->currentItem()->text())){
        EventHelper::sendEvent(new MessageEvent("Remove failed", "Failed to remove the selected connection",
                                            QSystemTrayIcon::Warning));
    } else{
        ui->listWidget->clearSelection();
        delete ui->listWidget->item(ui->listWidget->currentRow());
        HandlerManager::save();
    }
}

void MainWindow::selectionChanged(int row)
{
    if (row < 0){
        ui->deleteButton->setEnabled(false);
        ui->widget->setEnabled(false);
        ui->enableBox->setChecked(false);
        ui->proxyNameEdit->setText("");
        ui->proxyPortEdit->setText("0");
        return;
    }
    QListWidgetItem *item = ui->listWidget->item(row);
    ui->deleteButton->setEnabled(true);
    ui->widget->setEnabled(true);
    ui->enableBox->setChecked(HandlerManager::getAttributeFor(item->text(), "ProxyEnabled").toBool());
    ui->proxyNameEdit->setEnabled(ui->enableBox->isChecked());
    ui->proxyNameEdit->setText(HandlerManager::getAttributeFor(item->text(), "ProxyHost").toString());
    ui->proxyPortEdit->setEnabled(ui->enableBox->isChecked());
    ui->proxyPortEdit->setText(QString::number(HandlerManager::getAttributeFor(item->text(),
                                                                               "ProxyPort").toULongLong()));
    ui->listWidget->clearSelection();
}

void MainWindow::proxyNameChanged(QString text)
{
    HandlerManager::setAttributeFor(ui->listWidget->currentItem()->text(), "ProxyHost", QVariant::fromValue(text));
}

void MainWindow::proxyPortChanged(QString text)
{
    HandlerManager::setAttributeFor(ui->listWidget->currentItem()->text(), "ProxyPort", QVariant::fromValue(text));
}

void MainWindow::usernameChanged(QString text)
{
#ifndef Q_OS_WIN
    HandlerManager::setAttributeFor(ui->listWidget->currentItem()->text(), "Username", QVariant::fromValue(text));
#endif
}

void MainWindow::passwordChanged(QString text)
{
#ifndef Q_OS_WIN
    HandlerManager::setAttributeFor(ui->listWidget->currentItem()->text(), "Password", QVariant::fromValue(text));
#endif
}

void MainWindow::proxyChanged()
{
    try {
        HandlerManager::refresh(ui->listWidget->currentItem()->text());
    } catch (int e) {
        EventHelper::sendEvent(new MessageEvent("Failed to change proxy",
                                            "Failed with error code" + QString::number(e)));
        qDebug() << "refreshOptions function failed with error code:" << e;
    }
}

void MainWindow::enableProxy(bool enable)
{
    HandlerManager::setAttributeFor(ui->listWidget->currentItem()->text(),
                                    "ProxyEnabled", QVariant::fromValue(enable));
    ui->proxyNameEdit->setEnabled(enable);
    ui->proxyPortEdit->setEnabled(enable);
#ifndef Q_OS_WIN
    ui->checkBox->setEnabled(enable);
#endif
    proxyChanged();
}

void MainWindow::trayActivation(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::DoubleClick:
        timer.stop();
        show();
        break;
    case QSystemTrayIcon::Trigger:
        if (!timer.isActive()) timer.start();
        break;
    default: // Do nothing
        break;
    }
}

void MainWindow::showMessage()
{
    QString ssid = HandlerManager::getSSIDConnected();
    if (ssid.isEmpty()) ssid = "Nothing";
    EventHelper::sendEvent(new MessageEvent("Status", "Connected to " + ssid));
    timer.stop();
}


MessageEvent::MessageEvent(QString title, QString message, QSystemTrayIcon::MessageIcon icon) : QEvent(type()),
    title(title), message(message), icon(icon)
{}

QEvent::Type MessageEvent::type()
{
    if (eType == QEvent::None){
        int eventid = QEvent::registerEventType(1564);
        if (eventid == -1){
            qDebug() << "FAILED TO INSTALL EVENT!";
            exit(1);
        }
        eType = static_cast<QEvent::Type>(eventid);
    }
    return eType;
}
