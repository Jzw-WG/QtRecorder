TEMPLATE = app
CONFIG += console c++11

QT += network \
      xml \
      multimedia \
      multimediawidgets \
      widgets \
      core

SOURCES += \
        FileAccess.cpp \
        Player.cpp \
        SerializationTransformer.cpp \
        main.cpp

HEADERS += \
    File.h \
    FileAccess.h \
    Player.h \
    RecorderFile.h \
    SerializationTransformer.h

