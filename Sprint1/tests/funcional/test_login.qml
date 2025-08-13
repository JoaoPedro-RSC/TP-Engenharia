import QtQuick 2.15
import QtTest 1.2

TestCase {
    name: "LoginTests"

    Loader { id: loader; source: "../ComandX/gui/login.qml" }

    function test_loginSuccess() {
        var page = loader.item
        page.usernameField.text = "garcom1"
        page.passwordField.text = "senha123"
        page.loginButton.clicked()
        compare(page.loginStatus, true)
        compare(page.currentView, "salao") // redirecionamento
    }

    function test_loginFailure() {
        var page = loader.item
        page.usernameField.text = "garcom1"
        page.passwordField.text = "errada"
        page.loginButton.clicked()
        compare(page.loginStatus, false)
        compare(page.currentView, "login")
    }
}
