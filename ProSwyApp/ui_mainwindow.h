/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QListWidget *listWidget;
    QPushButton *newConnectionButton;
    QPushButton *deleteButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *enableBox;
    QLabel *label;
    QLineEdit *proxyNameEdit;
    QLabel *label_2;
    QLineEdit *proxyPortEdit;
    QCheckBox *checkBox;
    QLabel *label_3;
    QLineEdit *usernameEdit;
    QLabel *label_4;
    QLineEdit *paswordEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(419, 244);
        MainWindow->setMinimumSize(QSize(419, 244));
        MainWindow->setMaximumSize(QSize(419, 244));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(419, 244));
        centralWidget->setMaximumSize(QSize(419, 244));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(181, 192));
        listWidget->setMaximumSize(QSize(181, 192));

        formLayout->setWidget(0, QFormLayout::SpanningRole, listWidget);

        newConnectionButton = new QPushButton(centralWidget);
        newConnectionButton->setObjectName(QStringLiteral("newConnectionButton"));
        newConnectionButton->setMinimumSize(QSize(84, 23));
        newConnectionButton->setMaximumSize(QSize(84, 23));

        formLayout->setWidget(1, QFormLayout::LabelRole, newConnectionButton);

        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setEnabled(false);
        deleteButton->setMinimumSize(QSize(91, 23));
        deleteButton->setMaximumSize(QSize(91, 23));

        formLayout->setWidget(1, QFormLayout::FieldRole, deleteButton);


        horizontalLayout->addLayout(formLayout);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(212, 226));
        widget->setMaximumSize(QSize(212, 226));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        enableBox = new QCheckBox(widget);
        enableBox->setObjectName(QStringLiteral("enableBox"));
        enableBox->setEnabled(true);

        verticalLayout->addWidget(enableBox);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 16));
        label->setMaximumSize(QSize(16777215, 16));

        verticalLayout->addWidget(label);

        proxyNameEdit = new QLineEdit(widget);
        proxyNameEdit->setObjectName(QStringLiteral("proxyNameEdit"));
        proxyNameEdit->setEnabled(false);
        proxyNameEdit->setMinimumSize(QSize(0, 20));
        proxyNameEdit->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(proxyNameEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 16));
        label_2->setMaximumSize(QSize(16777215, 16));

        verticalLayout->addWidget(label_2);

        proxyPortEdit = new QLineEdit(widget);
        proxyPortEdit->setObjectName(QStringLiteral("proxyPortEdit"));
        proxyPortEdit->setEnabled(false);
        proxyPortEdit->setMinimumSize(QSize(0, 20));
        proxyPortEdit->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(proxyPortEdit);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(false);
        checkBox->setMinimumSize(QSize(0, 16));
        checkBox->setMaximumSize(QSize(16777215, 16));

        verticalLayout->addWidget(checkBox);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 16));
        label_3->setMaximumSize(QSize(16777215, 16));

        verticalLayout->addWidget(label_3);

        usernameEdit = new QLineEdit(widget);
        usernameEdit->setObjectName(QStringLiteral("usernameEdit"));
        usernameEdit->setEnabled(false);
        usernameEdit->setMinimumSize(QSize(0, 20));
        usernameEdit->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(usernameEdit);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 16));
        label_4->setMaximumSize(QSize(16777215, 16));

        verticalLayout->addWidget(label_4);

        paswordEdit = new QLineEdit(widget);
        paswordEdit->setObjectName(QStringLiteral("paswordEdit"));
        paswordEdit->setEnabled(false);
        paswordEdit->setMinimumSize(QSize(0, 20));
        paswordEdit->setMaximumSize(QSize(16777215, 20));
        paswordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(paswordEdit);


        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        newConnectionButton->setText(QApplication::translate("MainWindow", "New connection", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        enableBox->setText(QApplication::translate("MainWindow", "Enable proxy", 0));
        label->setText(QApplication::translate("MainWindow", "Proxy name:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Proxy port:", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Autentication", 0));
        label_3->setText(QApplication::translate("MainWindow", "Username:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Password:", 0));
        paswordEdit->setInputMask(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
