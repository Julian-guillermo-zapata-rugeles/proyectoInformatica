#ifndef GAMESAVE_H
#define GAMESAVE_H
#include "fstream"
#include <map>
#include <QDebug>

class GameSave
{
protected:
    short int puntaje;
    short int shoots;
    short int level;
    short int life_level;
    bool load;
    std::fstream file;

public:
    GameSave();
    bool confirmarArchivo(std::string);
    bool leerInformacion(std::string nombreArchivo);
    void escribirInformacion(std::string nombreArchivo);
    void crearUsuario(std::string nombreArchivo);
};

#endif // GAMESAVE_H
