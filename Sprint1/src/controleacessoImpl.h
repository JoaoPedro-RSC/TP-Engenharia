#ifndef CONTROLEACESSOIMPL_H
#define CONTROLEACESSOIMPL_H

#include "controleacesso.h"

class ControleAcessoImpl : public ControleAcesso
{
    Q_OBJECT
public:
    explicit ControleAcessoImpl(QObject* parent = nullptr);
    ~ControleAcessoImpl() override;

    bool login(const QString& login, const QString& senha) override;
    void logout() override;
    QVector<Usuario> usuariosLogados() const override;

private:
    QVector<Usuario> m_usuariosCadastrados;
    QVector<Usuario> m_usuariosLogados;
};

#endif // CONTROLEACESSOIMPL_H
