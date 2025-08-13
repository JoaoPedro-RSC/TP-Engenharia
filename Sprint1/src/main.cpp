#include <QApplication>
#include "controleacessoimpl.h"
#include "../gui/login_window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    IControleAcesso* controle = new ControleAcessoImpl();
    LoginWindow loginWindow(controle);
    loginWindow.show();

    return app.exec();
}
