#ifndef MESA_IMPL_H
#define MESA_IMPL_H

#include "mesa.h"

class MesaImpl : public IMesa
{
    Q_OBJECT
public:
    explicit MesaImpl(int numero, QObject* parent = nullptr);
    ~MesaImpl() override;

    int numero() const override;
    bool estaOcupada() const override;
    void ocupar() override;
    void liberar() override;

private:
    int m_numero;
    bool m_ocupada;
};

#endif // MESA_IMPL_H
