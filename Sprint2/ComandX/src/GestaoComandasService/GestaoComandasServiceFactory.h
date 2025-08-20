#pragma once
#include "IGestaoComandasService.h"
#include "gestaocomandasservice_global.h"
class GESTAOCOMANDASSERVICE_EXPORT GestaoComandasServiceFactory {
public: static IGestaoComandasService* create();
};
