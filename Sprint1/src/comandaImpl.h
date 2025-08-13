#ifndef COMANDAIMPL_H
#define COMANDAIMPL_H

#include "comanda.h"

class ComandaImpl : public Comanda
{
    Q_OBJECT
public:
    explicit ComandaImpl(QObject* parent = nullptr);
    ~ComandaImpl() override;

    void setNumeroMesa(int numeroMesa) override;
    int numeroMesa() const override;

    void adicionarItem(const QString& nomeProduto, int quantidade, const QString& observacoes) override;
    QVector<Item> itens() const override;

private:
    int m_numeroMesa;
    QVector<Item> m_itens;
};

#endif // COMANDAIMPL_H
