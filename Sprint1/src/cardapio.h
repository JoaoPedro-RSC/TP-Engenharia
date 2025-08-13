#ifndef CARDAPIO_H
#define CARDAPIO_H

#include <vector>
#include <string>

struct Produto {
    int id;
    std::string nome;
    std::string descricao;
    double preco;
    int categoriaId;
};

struct Categoria {
    int id;
    std::string nome;
};

class ICardapio {
public:
    virtual ~ICardapio() = default;

    virtual void adicionarCategoria(const std::string& nome) = 0;
    virtual void adicionarProduto(const std::string& nome, const std::string& descricao, double preco, int categoriaId) = 0;

    virtual std::vector<Categoria> listarCategorias() const = 0;
    virtual std::vector<Produto> listarProdutosPorCategoria(int categoriaId) const = 0;
};

#endif // CARDAPIO_H
