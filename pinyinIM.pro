QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -std=c++11
target.path = /usr/local/iDM
INSTALLS += target


SOURCES += \
        main.cpp \
    googlepinyin/dictbuilder.cpp \
    googlepinyin/dictlist.cpp \
    googlepinyin/dicttrie.cpp \
    googlepinyin/lpicache.cpp \
    googlepinyin/matrixsearch.cpp \
    googlepinyin/mystdlib.cpp \
    googlepinyin/ngram.cpp \
    googlepinyin/pinyinime.cpp \
    googlepinyin/searchutility.cpp \
    googlepinyin/spellingtable.cpp \
    googlepinyin/spellingtrie.cpp \
    googlepinyin/splparser.cpp \
    googlepinyin/sync.cpp \
    googlepinyin/userdict.cpp \
    googlepinyin/utf16char.cpp \
    googlepinyin/utf16reader.cpp

SUBDIRS += \
    googlepinyin/googlepinyin.pro

HEADERS += \
    googlepinyin/atomdictbase.h \
    googlepinyin/dictbuilder.h \
    googlepinyin/dictdef.h \
    googlepinyin/dictlist.h \
    googlepinyin/dicttrie.h \
    googlepinyin/lpicache.h \
    googlepinyin/matrixsearch.h \
    googlepinyin/mystdlib.h \
    googlepinyin/ngram.h \
    googlepinyin/pinyinime.h \
    googlepinyin/searchutility.h \
    googlepinyin/spellingtable.h \
    googlepinyin/spellingtrie.h \
    googlepinyin/splparser.h \
    googlepinyin/sync.h \
    googlepinyin/userdict.h \
    googlepinyin/utf16char.h \
    googlepinyin/utf16reader.h

INCLUDEPATH += \
        googlepinyin \
