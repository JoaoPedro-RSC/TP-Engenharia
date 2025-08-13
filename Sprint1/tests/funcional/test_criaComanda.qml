import QtQuick 2.15
import QtTest 1.2

TestCase {
    name: "CriaComandaTests"

    Loader { id: loader; source: "../ComandX/gui/criaComanda.qml" }

    function test_createComandaMesaLivre() {
        var page = loader.item
        page.selectMesa("Mesa 01")
        compare(page.comanda.mesa, "Mesa 01")
        compare(page.mesaStatus("Mesa 01"), "Ocupada")
    }

    function test_selectMesaOcupada() {
        var page = loader.item
        page.selectMesa("Mesa 02") // já ocupada
        compare(page.currentView, "detalheComanda")
    }
}
