TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Negative_Log_Gamma.cpp \
        main.cpp
INCLUDEPATH += D:\opencv\opencv-build-QtCreator\include \
               D:\opencv\opencv-build-QtCreator\include\opencv2
LIBS += D:\opencv\opencv-build-QtCreator\x64\mingw\lib\libopencv_*

HEADERS += \
    Negative_Log_Gamma.hpp
