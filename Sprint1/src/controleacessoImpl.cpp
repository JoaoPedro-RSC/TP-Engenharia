#include "controleacessoimpl.h"

ControleAcessoImpl::ControleAcessoImpl(QObject* parent)
    : ControleAcesso(parent)
{
    // Exemplo: carregar usuários padrão - na prática viria de DB ou API
    m_usuariosCadastrados.append(Usuario("João", "joao", "1234", Usuario::Garcom));
    m_usuariosCadastrados.append(Usuario("Maria", "maria", "abcd", Usuario::Administrador));
}

ControleAcessoImpl::~ControleAcessoImpl()
{
}

bool ControleAcessoImpl::login(const QString& login, const QString& senha)
{
    for (const Usuario& u : m_usuariosCadastrados) {
        if (u.login() == login && u.senha() == senha) {
            if (!m_usuariosLogados.contains(u)) {
                m_usuariosLogados.append(u);
                emit loginSucesso(u);
                return true;
            }
            emit loginFalhou("Usuário já está logado");
            return false;
        }
    }
    emit loginFalhou("Login ou senha incorretos");
    return false;
}

void ControleAcessoImpl::logout()
{
    m_usuariosLogados.clear();
    emit logoutRealizado();
}

QVector<Usuario> ControleAcessoImpl::usuariosLogados() const
{
    return m_usuariosLogados;
}
