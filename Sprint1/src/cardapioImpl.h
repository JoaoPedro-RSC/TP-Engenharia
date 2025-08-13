#ifndef CARDAPIOIMPL_H
#define CARDAPIOIMPL_H

#include "cardapio.h"

class CardapioImpl : public ICardapio {
public:
    CardapioImpl();
    ~CardapioImpl() override;

    void adicionarCategoria(const std::string& nome) override;
    void adicionarProduto(const std::string& nome, const std::string& descricao, double preco, int categoriaId) override;

    std::vector<Categoria> listarCategorias() const override;
    std::vector<Produto> listarProdutosPorCategoria(int categoriaId) const override;

private:
    std::vector<Categoria> categorias;
    std::vector<Produto> produtos;
    int proximoCategoriaId;
    int proximoProdutoId;
};

#endif // CARDAPIOIMPL_H
