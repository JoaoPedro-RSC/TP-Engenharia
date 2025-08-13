#include "cardapioImpl.h"

CardapioImpl::CardapioImpl()
    : proximoCategoriaId(1), proximoProdutoId(1) {}

CardapioImpl::~CardapioImpl() = default;

void CardapioImpl::adicionarCategoria(const std::string& nome) {
    Categoria novaCategoria;
    novaCategoria.id = proximoCategoriaId++;
    novaCategoria.nome = nome;
    categorias.push_back(novaCategoria);
}

void CardapioImpl::adicionarProduto(const std::string& nome, const std::string& descricao, double preco, int categoriaId) {
    Produto novoProduto;
    novoProduto.id = proximoProdutoId++;
    novoProduto.nome = nome;
    novoProduto.descricao = descricao;
    novoProduto.preco = preco;
    novoProduto.categoriaId = categoriaId;
    produtos.push_back(novoProduto);
}

std::vector<Categoria> CardapioImpl::listarCategorias() const {
    return categorias;
}

std::vector<Produto> CardapioImpl::listarProdutosPorCategoria(int categoriaId) const {
    std::vector<Produto> resultado;
    for (const auto& p : produtos) {
        if (p.categoriaId == categoriaId) {
            resultado.push_back(p);
        }
    }
    return resultado;
}
