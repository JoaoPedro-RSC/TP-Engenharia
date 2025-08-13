#include "controleacesso.h"

Usuario::Usuario(const QString& nome, const QString& login, const QString& senha, Tipo tipo)
    : m_nome(nome), m_login(login), m_senha(senha), m_tipo(tipo)
{
}

QString Usuario::nome() const { return m_nome; }
QString Usuario::login() const { return m_login; }
QString Usuario::senha() const { return m_senha; }
Usuario::Tipo Usuario::tipo() const { return m_tipo; }

void Usuario::setNome(const QString& nome) { m_nome = nome; }
void Usuario::setLogin(const QString& login) { m_login = login; }
void Usuario::setSenha(const QString& senha) { m_senha = senha; }
void Usuario::setTipo(Tipo tipo) { m_tipo = tipo; }
