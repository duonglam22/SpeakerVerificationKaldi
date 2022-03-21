QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

LIBS += -lstdc++fs

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MainProcess.cpp \
    enroll.cpp \
    extension/feat/ShiftingOnlineGenericBaseFeature.cpp \
    extension/feat/online-feature.cc \
    extractFeatures.cpp \
    messagereceiver.cpp \
    messages/VoiceRegisterMessage.grpc.pb.cc \
    messages/VoiceRegisterMessage.pb.cc \
    processregister.cpp


HEADERS += \
    enroll.h \
    extension/feat/ShiftingOnlineFeatureItf.h \
    extension/feat/ShiftingOnlineGenericBaseFeature.h \
    extension/feat/online-feature.h \
    messagereceiver.h \
    messages/VoiceRegisterMessage.grpc.pb.h \
    messages/VoiceRegisterMessage.pb.h \
    processregister.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#unix:!macx: LIBS += -L$$PWD/usr/local/lib/ -lfvad
#INCLUDEPATH += $$PWD/usr/local/include
#DEPENDPATH += $$PWD/usr/local/include

unix:!macx: LIBS += -L$$PWD/../../kaldi/src/lib/ -lkaldi-feat

INCLUDEPATH += $$PWD/../../kaldi/src/
DEPENDPATH += $$PWD/../../kaldi/src/


unix:!macx: LIBS += -L$$PWD/../../kaldi/src/lib/ -lkaldi-base

INCLUDEPATH += $$PWD/../../kaldi/src/
DEPENDPATH += $$PWD/../../kaldi/src/

unix:!macx: LIBS += -L$$PWD/../../kaldi/src/lib/ -lkaldi-transform

INCLUDEPATH += $$PWD/../../kaldi/src
DEPENDPATH += $$PWD/../../kaldi/src

unix:!macx: LIBS += -L$$PWD/../../kaldi/src/lib/ -lkaldi-util

INCLUDEPATH += $$PWD/../../kaldi/src/lib
DEPENDPATH += $$PWD/../../kaldi/src/lib

unix:!macx: LIBS += -L$$PWD/../../kaldi/src/lib/ -lkaldi-matrix

INCLUDEPATH += $$PWD/../../kaldi/src/lib
DEPENDPATH += $$PWD/../../kaldi/src/lib

unix:!macx: LIBS += -L$$PWD/../../kaldi/src/lib/ -lkaldi-gmm

INCLUDEPATH += $$PWD/../../kaldi/src/lib
DEPENDPATH += $$PWD/../../kaldi/src/lib

unix:!macx: LIBS += -L$$PWD/../../kaldi/src/lib/ -lkaldi-hmm

INCLUDEPATH += $$PWD/../../kaldi/src/lib
DEPENDPATH += $$PWD/../../kaldi/src/lib

unix:!macx: LIBS += -L$$PWD/../../kaldi/src/ivector/ -lkaldi-ivector

INCLUDEPATH += $$PWD/../../kaldi/src/ivector
DEPENDPATH += $$PWD/../../kaldi/src/ivector

unix:!macx: LIBS += -L$$PWD/../../../../../../../usr/local/lib/ -lfvad

INCLUDEPATH += $$PWD/../../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../../usr/local/include


##grpc
unix:!macx: LIBS += -L$$PWD/../../../../../.local/lib/ -lprotobuf

INCLUDEPATH += $$PWD/../../../../../.local/include
DEPENDPATH += $$PWD/../../../../../.local/include

unix:!macx: LIBS += -L$$PWD/../../../../../.local/lib/ -lgrpc++

INCLUDEPATH += $$PWD/../../../../../.local/include
DEPENDPATH += $$PWD/../../../../../.local/include

unix:!macx: LIBS += -L$$PWD/../../../../../.local/lib/ -lgrpc

INCLUDEPATH += $$PWD/../../../../../.local/include
DEPENDPATH += $$PWD/../../../../../.local/include

