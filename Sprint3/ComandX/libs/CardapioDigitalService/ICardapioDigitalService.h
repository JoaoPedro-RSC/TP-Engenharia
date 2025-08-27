// libs/CardapioDigitalService/ICardapioDigitalService.h

#pragma once
#include <QObject>
#include <QList>
#include "cardapiodigitalservice_global.h"
#include <Entidades.h>

class CARDIAPIODIGITALSERVICE_EXPORT ICardapioDigitalService : public QObject {
    Q_OBJECT
public:
    // ESTA LINHA É ESSENCIAL
    explicit ICardapioDigitalService(QObject *parent = nullptr) : QObject(parent) {}

    virtual ~ICardapioDigitalService() = default;
    virtual QList<ItemCardapio> getItens() const = noexcept = 0;
    virtual bool getItemPorId(int id, ItemCardapio& item) const = 0;
};
