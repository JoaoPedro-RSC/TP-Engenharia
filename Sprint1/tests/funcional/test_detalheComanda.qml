import QtQuick 2.15
import QtTest 1.2

TestCase {
    name: "DetalheComandaTests"

    Loader { id: loader; source: "../ComandX/gui/detalheComanda.qml" }

    function test_viewComandaDetails() {
        var page = loader.item
        verify(page.comanda.itens.length >= 0)
    }

    function test_changeOrderStatus() {
        var page = loader.item
        page.updateStatus("Pronto")
        compare(page.comanda.status, "Pronto")
    }
}
