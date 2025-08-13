#ifndef COMANDA_H
#define COMANDA_H

#include <QObject>
#include <QString>
#include <QVector>

class Comanda : public QObject
{
    Q_OBJECT
public:
    struct Item {
        QString nomeProduto;
        int quantidade;
        QString observacoes;
    };

    explicit Comanda(QObject* parent = nullptr);
    virtual ~Comanda() = default;

    virtual void setNumeroMesa(int numeroMesa) = 0;
    virtual int numeroMesa() const = 0;

    virtual void adicionarItem(const QString& nomeProduto, int quantidade, const QString& observacoes) = 0;
    virtual QVector<Item> itens() const = 0;

signals:
    void itemAdicionado(const Item& item);

};

#endif // COMANDA_H
