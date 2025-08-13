// login_window.h
#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QWidget>
#include "controleacesso/controleacesso.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    explicit LoginWindow(IControleAcesso* controle, QWidget* parent = nullptr);
    ~LoginWindow();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::LoginWindow* ui;
    IControleAcesso* controleAcesso;
};

#endif // LOGIN_WINDOW_H
