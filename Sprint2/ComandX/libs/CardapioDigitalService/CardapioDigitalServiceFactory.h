#pragma once
#include "ICardapioDigitalService.h"
#include "cardapiodigitalservice_global.h"
class CARDIAPIODIGITALSERVICE_EXPORT CardapioDigitalServiceFactory {
public: static ICardapioDigitalService* create();
};
