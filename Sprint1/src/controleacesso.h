#ifndef CONTROLEACESSO_H
#define CONTROLEACESSO_H

#include <QObject>
#include <QString>
#include <QVector>

class Usuario
{
public:
    enum Tipo { Garcom, Administrador };

    Usuario() = default;
    Usuario(const QString& nome, const QString& login, const QString& senha, Tipo tipo);

    QString nome() const;
    QString login() const;
    QString senha() const;
    Tipo tipo() const;

    void setNome(const QString& nome);
    void setLogin(const QString& login);
    void setSenha(const QString& senha);
    void setTipo(Tipo tipo);

private:
    QString m_nome;
    QString m_login;
    QString m_senha;
    Tipo m_tipo;
};

class ControleAcesso : public QObject
{
    Q_OBJECT
public:
    explicit ControleAcesso(QObject* parent = nullptr);
    virtual ~ControleAcesso() = default;

    virtual bool login(const QString& login, const QString& senha) = 0;
    virtual void logout() = 0;
    virtual QVector<Usuario> usuariosLogados() const = 0;

signals:
    void loginSucesso(const Usuario& usuario);
    void loginFalhou(const QString& motivo);
    void logoutRealizado();
};

#endif // CONTROLEACESSO_H
