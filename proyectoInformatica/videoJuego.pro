QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animaciones.cpp \
    asteroides.cpp \
    aves.cpp \
    bonus_municion.cpp \
    cliente.cpp \
    enemigo.cpp \
    enemigoGigante.cpp \
    gameoverwindow.cpp \
    lunacreciente.cpp \
    main.cpp \
    movimientos.cpp \
    mundoterrestre.cpp \
    nubes.cpp \
    personaje.cpp \
    planeta.cpp \
    proyectil.cpp \
    score.cpp \
    ship.cpp \
    timeGame.cpp

HEADERS += \
    animaciones.h \
    asteroides.h \
    aves.h \
    bonus_municion.h \
    cliente.h \
    enemigo.h \
    enemigoGigante.h \
    gameoverwindow.h \
    lunacreciente.h \
    movimientos.h \
    mundoterrestre.h \
    nubes.h \
    personaje.h \
    planeta.h \
    proyectil.h \
    score.h \
    ship.h \
    timeGame.h

FORMS += \
    cliente.ui \
    levelcompletewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    multimedia.qrc \
    multimedia.qrc

DISTFILES += \
    multimedia/Backgrounds/BG alien 1.jpg \
    multimedia/Backgrounds/BG alien 1.jpg \
    multimedia/Backgrounds/BG alien 2.jpg \
    multimedia/Backgrounds/BG alien 2.jpg \
    multimedia/Backgrounds/BG alien 3.jpg \
    multimedia/Backgrounds/BG alien 3.jpg \
    multimedia/Backgrounds/BG alien 4.jpg \
    multimedia/Backgrounds/BG alien 4.jpg \
    multimedia/Backgrounds/BG alien 5.jpg \
    multimedia/Backgrounds/BG alien 5.jpg \
    multimedia/Backgrounds/BG apocalyptic 1.jpg \
    multimedia/Backgrounds/BG apocalyptic 1.jpg \
    multimedia/Backgrounds/BG apocalyptic 2.jpg \
    multimedia/Backgrounds/BG apocalyptic 2.jpg \
    multimedia/Backgrounds/BG apocalyptic 3.jpg \
    multimedia/Backgrounds/BG apocalyptic 3.jpg \
    multimedia/Backgrounds/BG space 1.jpg \
    multimedia/Backgrounds/BG space 1.jpg \
    multimedia/Backgrounds/BG space 2.jpg \
    multimedia/Backgrounds/BG space 2.jpg \
    multimedia/Backgrounds/BG space 3.jpg \
    multimedia/Backgrounds/BG space 3.jpg \
    multimedia/Backgrounds/BG space 4.jpg \
    multimedia/Backgrounds/BG space 4.jpg \
    multimedia/Backgrounds/BG space 5.jpg \
    multimedia/Backgrounds/BG space 5.jpg \
    multimedia/Cosmic Blaster.ttf \
    multimedia/Cosmic Blaster.ttf \
    multimedia/Sonidos/zombie_gruendo.mp3 \
    multimedia/bonus_balas.png \
    multimedia/cargar_arma.mp3 \
    multimedia/explosion1.mp3 \
    multimedia/fondo.png \
    multimedia/fondo1.jpg \
    multimedia/fondo2.png \
    multimedia/fondo3.jpg \
    multimedia/laser1.mp3 \
    multimedia/lunaCreciente.png \
    multimedia/pixmap_asteroide.png \
    multimedia/pixmap_asteroide_joven.png \
    multimedia/pixmap_asteroide_rojo.png \
    multimedia/pixmap_disparo_sol.png \
    multimedia/pixmap_nube_grade.png \
    multimedia/sorpresaAsteroides.mp3 \
    multimedia/sprite_asteroide.png \
    multimedia/suspenso1.mp3 \
    multimedia/suspensoCreciente.mp3 \
    multimedia/treasure-chest1.png \
    multimedia/zombie.mp3
