#ifndef SALAOIMPL_H
#define SALAOIMPL_H

#include "salao.h"
#include <unordered_map>

class SalaoImpl : public ISalao {
public:
    SalaoImpl(int quantidadeMesas);
    ~SalaoImpl() override;

    std::vector<Mesa> listarMesas() const override;
    Mesa obterMesa(int numero) const override;

    bool ocuparMesa(int numero) override;
    bool liberarMesa(int numero) override;
    bool solicitarFechamento(int numero) override;

private:
    std::unordered_map<int, Mesa> mesas;
};

#endif // SALAOIMPL_H
