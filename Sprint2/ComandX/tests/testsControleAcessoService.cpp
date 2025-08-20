#include <QtTest>
#include <QObject>

// Incluímos a interface e a fábrica do serviço que queremos testar
#include <IControleAcessoService.h>
#include <ControleAcessoServiceFactory.h>

class TestControleAcessoService : public QObject
{
    Q_OBJECT

public:
    TestControleAcessoService();
    ~TestControleAcessoService();

private slots:
    void testeDeAutenticacao_data();
    void testeDeAutenticacao();
};

TestControleAcessoService::TestControleAcessoService() {
    // Código de setup, se necessário
}

TestControleAcessoService::~TestControleAcessoService() {
    // Código de cleanup, se necessário
}

// Slot que provê os dados para o teste
void TestControleAcessoService::testeDeAutenticacao_data()
{
    QTest::addColumn<QString>("usuario");
    QTest::addColumn<QString>("senha");
    QTest::addColumn<bool>("resultadoEsperado");

    QTest::newRow("login correto") << "garcom" << "123" << true;
    QTest::newRow("login com casing errado") << "Garcom" << "123" << true;
    QTest::newRow("senha incorreta") << "garcom" << "senhaerrada" << false;
    QTest::newRow("usuario incorreto") << "usuariox" << "123" << false;
    QTest::newRow("ambos incorretos") << "ninguem" << "senha" << false;
}

// Slot que executa o teste
void TestControleAcessoService::testeDeAutenticacao()
{
    QFETCH(QString, usuario);
    QFETCH(QString, senha);
    QFETCH(bool, resultadoEsperado);

    // 1. Setup: Pegamos uma instância do serviço
    IControleAcessoService* servico = ControleAcessoServiceFactory::create();

    // 2. Execução: Chamamos o método que queremos testar
    bool resultadoReal = servico->autenticar(usuario, senha);
    servico->logout(); // Garante que o estado seja limpo para o próximo teste

    // 3. Verificação: Comparamos o resultado real com o esperado
    QCOMPARE(resultadoReal, resultadoEsperado);
}

// Macro que gera o main() para este arquivo de teste
QTEST_APPLESS_MAIN(TestControleAcessoService)

#include "TestControleAcessoService.moc"