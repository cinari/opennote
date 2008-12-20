TEMPLATE = app
TARGET = OpenNote
CONFIG += qt \
    warn_on \
    debug
HEADERS = SwissKnife.h \
    DavinciTextEdit.h \
    TextEditorWindow.h \
    SubversionController.h \
    NotebookExplorer.h
SOURCES = SwissKnife.cpp \
    DavinciTextEdit.cpp \
    TextEditorWindow.cpp \
    SubversionController.cpp \
    NotebookExplorer.cpp \
    main.cpp
RESOURCES += OpenNote.qrc
build_all:!build_pass { 
    CONFIG -= build_all
    CONFIG += release
}

# install
target.path = $$[QT_INSTALL_DEMOS]/OpenNote
sources.files = $$SOURCES \
    $$HEADERS \
    $$RESOURCES \
    *.pro \
    *.html \
    *.doc \
    images
sources.path = $$[QT_INSTALL_DEMOS]/OpenNote
INSTALLS += target \
    sources
FORMS = 
QT += xml
