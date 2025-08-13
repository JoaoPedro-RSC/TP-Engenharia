import QtQuick 2.15
import QtTest 1.2

TestCase {
    name: "SalaoTests"

    Loader { id: loader; source: "../ComandX/gui/salao.qml" }

    function test_viewTableStatus() {
        var page = loader.item
        verify(page.mesas.length > 0)
        compare(page.mesas[0].status, "Livre") // exemplo de status
    }
}
