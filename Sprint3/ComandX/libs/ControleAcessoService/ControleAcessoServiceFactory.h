#pragma once
#include "IControleAcessoService.h"
#include "ControleAcessoServiceImpl.h"
#include "controleacessoservice_global.h"

class CONTROLEACESSOSERVICE_EXPORT ControleAcessoServiceFactory {
public:
    static IControleAcessoService* create() {
        return ControleAcessoServiceImpl::getInstance();
    }
};
