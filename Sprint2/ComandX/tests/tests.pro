QT += testlib core gui widgets

TARGET = tst_comandx
TEMPLATE = app

CONFIG += console
CONFIG -= app_bundle

SOURCES += \
    TestControleAcessoService.cpp # Nosso primeiro teste de unidade
    # Adicionaremos outros arquivos de teste aqui depois

# Path para encontrar os headers de todas as libs e do app
INCLUDEPATH += $$PWD/../app
INCLUDEPATH += $$PWD/../libs/core
INCLUDEPATH += $$PWD/../libs/ControleAcessoService
INCLUDEPATH += $$PWD/../libs/GestaoSalaoService
INCLUDEPATH += $$PWD/../libs/CardapioDigitalService
INCLUDEPATH += $$PWD/../libs/GestaoComandasService

# Path para encontrar os arquivos .dll/.so e linkar com eles
LIBS += -L$$OUT_PWD/../libs/core -lcore
LIBS += -L$$OUT_PWD/../libs/ControleAcessoService -lControleAcessoService
LIBS += -L$$OUT_PWD/../libs/GestaoSalaoService -lGestaoSalaoService
LIBS += -L$$OUT_PWD/../libs/CardapioDigitalService -lCardapioDigitalService
LIBS += -L$$OUT_PWD/../libs/GestaoComandasService -lGestaoComandasService

# Para testar a MainWindow, precisamos dos seus objetos compilados
PRE_TARGETDEPS += $$OUT_PWD/../app/libComandXApp.a
LIBS += -L$$OUT_PWD/../app -lComandXApp