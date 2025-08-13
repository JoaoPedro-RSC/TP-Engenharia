// login_window.cpp
#include "login_window.h"
#include "ui_login.h"
#include <QMessageBox>

LoginWindow::LoginWindow(IControleAcesso* controle, QWidget* parent)
    : QWidget(parent), ui(new Ui::LoginWindow), controleAcesso(controle) {
    ui->setupUi(this);
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::on_btnLogin_clicked() {
    QString usuario = ui->inputUsuario->text();
    QString senha = ui->inputSenha->text();

    if (controleAcesso->autenticar(usuario.toStdString(), senha.toStdString())) {
        QMessageBox::information(this, "Sucesso", "Login efetuado!");
        // Aqui você pode abrir a próxima tela, ex: mapa do salão
    } else {
        QMessageBox::warning(this, "Erro", "Usuário ou senha inválidos.");
    }
}
