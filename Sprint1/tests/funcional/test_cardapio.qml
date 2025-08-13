import QtQuick 2.15
import QtTest 1.2

TestCase {
    name: "CardapioTests"

    Loader { id: loader; source: "../ComandX/gui/cardapio.qml" }

    function test_addItemToComanda() {
        var page = loader.item
        page.selectProduto("Refrigerante")
        page.confirmAdicionar()
        compare(page.comanda.itens.includes("Refrigerante"), true)
    }
}
