QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminpage.cpp \
    adminsignup.cpp \
    confirm.cpp \
    firstpage.cpp \
    idcreator.cpp \
    insight.cpp \
    kathmandu.cpp \
    main.cpp \
    publish.cpp \
    setup.cpp \
    start.cpp \
    votektm.cpp \
    voteme.cpp \
    voterid.cpp \
    voterwindow.cpp

HEADERS += \
    admin.h \
    adminpage.h \
    adminsignup.h \
    confirm.h \
    firstpage.h \
    idcreator.h \
    insight.h \
    kathmandu.h \
    publish.h \
    setup.h \
    start.h \
    votektm.h \
    voteme.h \
    voterid.h \
    voterwindow.h

FORMS += \
    admin.ui \
    adminpage.ui \
    adminsignup.ui \
    confirm.ui \
    firstpage.ui \
    idcreator.ui \
    insight.ui \
    kathmandu.ui \
    publish.ui \
    setup.ui \
    start.ui \
    votektm.ui \
    voteme.ui \
    voterid.ui \
    voterwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
