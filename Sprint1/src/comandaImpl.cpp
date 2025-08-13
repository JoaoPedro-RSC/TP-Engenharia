#include "comandaImpl.h"

ComandaImpl::ComandaImpl(QObject* parent)
    : Comanda(parent),
      m_numeroMesa(0)
{
}

ComandaImpl::~ComandaImpl()
{
}

void ComandaImpl::setNumeroMesa(int numeroMesa)
{
    m_numeroMesa = numeroMesa;
}

int ComandaImpl::numeroMesa() const
{
    return m_numeroMesa;
}

void ComandaImpl::adicionarItem(const QString& nomeProduto, int quantidade, const QString& observacoes)
{
    Item item;
    item.nomeProduto = nomeProduto;
    item.quantidade = quantidade;
    item.observacoes = observacoes;
    m_itens.append(item);

    emit itemAdicionado(item);
}

QVector<Comanda::Item> ComandaImpl::itens() const
{
    return m_itens;
}
