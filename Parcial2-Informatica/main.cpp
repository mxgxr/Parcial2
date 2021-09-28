#include <iostream>
#include <QImage>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include "sobremuestreo.h"
#include "submuestreo.h"

using namespace std;

string formatoTexto(vector<vector<int>> &array);

int main()
{
    string nomImg, ruta="../Parcial2-Informatica/images";

    cout << "Ingrese el nombre de la imagen a cargar y su extension: " << endl;
    cin >> nomImg;

    ruta+=nomImg;

    QImage imagen(ruta.c_str());

    if(imagen.width()<12 and imagen.height()<12){
        Sobremuestreo uno(ruta);
        uno.Lectura();
        uno.Redimension();
    }
    else if((imagen.width()>=12 and imagen.height()>=12)){
        Submuestreo dos(imagen);
        dos.GuardarTxt();
    }
    else if(imagen.width()>=12 and imagen.height()<12){
        Submuestreo tres(imagen,1);
    }
    else if(imagen.width()<12 and imagen.height()>=12){
        Submuestreo cuatro(imagen,2);
    }

    return 0;
}




