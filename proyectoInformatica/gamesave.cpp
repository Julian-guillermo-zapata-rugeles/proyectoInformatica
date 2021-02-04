#include "gamesave.h"

GameSave::GameSave()
{
    //Se crea una funcion para crear una carpeta llamada Partidas para windows y en caso de que ya exista no la crea de nuevo.
    system("mkdir Partidas");
}




bool GameSave::confirmarArchivo(std::string nombreArchivo)
{

    file.open("Partidas/"+nombreArchivo,std::ios::in);
     if(file.is_open()){
         return true;
     }
     else {
         return false;
     }
     file.close();

}







bool GameSave::leerInformacion(std::string nombreArchivo)
{
    qDebug()<<"buscando el usuario"<<endl;
    file.open("Partidas/"+nombreArchivo,std::ios::in);

    short int limit=10;
    short int out=0;
    while (!file.eof()){
        out+=1;
        file >> puntaje >> shoots >> level >> life_level >>timerAsteroides >>timerEnemigos >>timerGigantes;
        if(out>limit){
            qDebug()<<"limit --"<< endl;
            break;
        }
    }

    file.close();
    return false;
}






void GameSave::escribirInformacion(std::string nombreArchivo)
{
    file.open("Partidas/"+nombreArchivo,std::ios::out);
    file << puntaje <<" "<<shoots<<" "<<level <<" "<<life_level<<" "<<timerAsteroides<<" "<<timerEnemigos<<" "<<timerGigantes;
    file.close();
}







void GameSave::crearUsuario(std::string nombreArchivo)
{
    file.open("Partidas/"+nombreArchivo,std::ios::out);
    file << 0 << " "<< 10<<" "<<1<<" "<<100<<" "<<8000<<" "<<3000<<" "<<10000;
    file.close();
}
