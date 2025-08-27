QT -= gui
TARGET = ControleAcessoService
TEMPLATE = lib

DEFINES += CONTROLEACESSOSERVICE_LIBRARY

SOURCES += \
    ControleAcessoServiceImpl.cpp

HEADERS += \
    IControleAcessoService.h \
    ControleAcessoServiceImpl.h \
    ControleAcessoServiceFactory.h \
    controleacessoservice_global.h

# --- LINHAS CRÍTICAS ABAIXO ---
# Diz ao compilador onde encontrar os cabeçalhos do 'core' (ex: Entidades.h)
INCLUDEPATH += $$PWD/../core

# Diz ao linker onde encontrar o arquivo 'core.dll' compilado
LIBS += -L$$OUT_PWD/../core -lcore
