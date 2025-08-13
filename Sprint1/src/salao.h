#ifndef SALAO_H
#define SALAO_H

#include <vector>
#include <string>

enum class StatusMesa {
    Livre,
    Ocupada,
    AguardandoPagamento
};

struct Mesa {
    int numero;
    StatusMesa status;
};

class ISalao {
public:
    virtual ~ISalao() = default;

    virtual std::vector<Mesa> listarMesas() const = 0;
    virtual Mesa obterMesa(int numero) const = 0;

    virtual bool ocuparMesa(int numero) = 0;
    virtual bool liberarMesa(int numero) = 0;
    virtual bool solicitarFechamento(int numero) = 0;
};

#endif // SALAO_H
