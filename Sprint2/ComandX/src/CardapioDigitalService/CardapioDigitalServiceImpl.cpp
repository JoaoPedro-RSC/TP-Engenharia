#include "CardapioDigitalServiceImpl.h"
// Adicionamos o include da Fábrica aqui
#include "CardapioDigitalServiceFactory.h"

CardapioDigitalServiceImpl* CardapioDigitalServiceImpl::getInstance() {
    static CardapioDigitalServiceImpl instance;
    return &instance;
}

CardapioDigitalServiceImpl::CardapioDigitalServiceImpl(QObject *parent)
    : ICardapioDigitalService(parent) {
    // Carga estática de itens para a Sprint 1
    m_itens << ItemCardapio{101, "Refrigerante Lata", 5.00};
    m_itens << ItemCardapio{102, "Suco Natural", 8.00};
    m_itens << ItemCardapio{201, "Porção de Batata", 25.00};
    m_itens << ItemCardapio{202, "Hambúrguer", 30.00};
}

QList<ItemCardapio> CardapioDigitalServiceImpl::getItens() const {
    return m_itens;
}

bool CardapioDigitalServiceImpl::getItemPorId(int id, ItemCardapio& item) const {
    for(const auto& i : m_itens) {
        if (i.id == id) {
            item = i;
            return true;
        }
    }
    return false;
}

// =======================================================
// A IMPLEMENTAÇÃO DA FÁBRICA QUE FALTAVA VAI AQUI EMBAIXO
// =======================================================
ICardapioDigitalService* CardapioDigitalServiceFactory::create() {
    return CardapioDigitalServiceImpl::getInstance();
}
