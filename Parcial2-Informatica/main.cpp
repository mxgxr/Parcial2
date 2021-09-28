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
    string nomImg, ruta="../Parcial2-Informatica/images/";
    vector<vector<int>> matrizrgb;

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
        Submuestreo ancho(imagen,1);
        matrizrgb=ancho.getMatrizPixeles();
        Sobremuestreo alto(ruta);
        alto.Lectuta(matrizrgb,12,imagen.height());
        alto.Redimension();
    }
    else if(imagen.width()<12 and imagen.height()>=12){
        Submuestreo alto(imagen,2);
        alto.getMatrizPixeles();
        Sobremuestreo ancho(ruta);
        ancho.Lectuta(matrizrgb,imagen.width(),12);
        ancho.Redimension();
    }
    return 0;
}




