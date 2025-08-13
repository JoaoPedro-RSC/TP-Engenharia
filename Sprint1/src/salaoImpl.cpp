#include "salaoimpl.h"

SalaoImpl::SalaoImpl(int quantidadeMesas) {
    for (int i = 1; i <= quantidadeMesas; ++i) {
        mesas[i] = Mesa{i, StatusMesa::Livre};
    }
}

SalaoImpl::~SalaoImpl() = default;

std::vector<Mesa> SalaoImpl::listarMesas() const {
    std::vector<Mesa> resultado;
    for (const auto& par : mesas) {
        resultado.push_back(par.second);
    }
    return resultado;
}

Mesa SalaoImpl::obterMesa(int numero) const {
    auto it = mesas.find(numero);
    if (it != mesas.end()) {
        return it->second;
    }
    // Caso a mesa não exista, retornar uma mesa inválida (numero 0 e status Livre)
    return Mesa{0, StatusMesa::Livre};
}

bool SalaoImpl::ocuparMesa(int numero) {
    auto it = mesas.find(numero);
    if (it != mesas.end() && it->second.status == StatusMesa::Livre) {
        it->second.status = StatusMesa::Ocupada;
        return true;
    }
    return false;
}

bool SalaoImpl::liberarMesa(int numero) {
    auto it = mesas.find(numero);
    if (it != mesas.end() && it->second.status != StatusMesa::Livre) {
        it->second.status = StatusMesa::Livre;
        return true;
    }
    return false;
}

bool SalaoImpl::solicitarFechamento(int numero) {
    auto it = mesas.find(numero);
    if (it != mesas.end() && it->second.status == StatusMesa::Ocupada) {
        it->second.status = StatusMesa::AguardandoPagamento;
        return true;
    }
    return false;
}
