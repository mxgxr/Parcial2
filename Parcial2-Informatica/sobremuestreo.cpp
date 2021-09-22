#include "sobremuestreo.h"

Sobremuestreo::Sobremuestreo()
{
    //leer imagen
    string ruta;
    int pixel,ancho,alto,avanzar,columna;
    vector<int>filas,matrizfila;
    vector<int>vacio;
    vector<vector<int>>matrizPixelesrojos,matrizPixelesverdes,matrizPixelesazules,matrizfinal;

    cout<<"Ingresar ruta donde se encuentra la imagen"<<endl;
    cin>>ruta;

    QImage imagen(ruta.c_str());

    for (int fila=0; fila<imagen.height(); fila++){
        filas=vacio;
        for(int columna=0; columna<imagen.height(); columna++){
            filas.push_back(imagen.pixelColor(columna,fila).red());
        }
        matrizPixelesrojos.push_back(filas);
    }
    for (int fila=0; fila<imagen.height(); fila++){
        filas=vacio;
        for(int columna=0; columna<imagen.height(); columna++){
            filas.push_back(imagen.pixelColor(columna,fila).green());
        }
        matrizPixelesverdes.push_back(filas);
    }
    for (int fila=0; fila<imagen.height(); fila++){
        filas=vacio;
        for(int columna=0; columna<imagen.height(); columna++){
            filas.push_back(imagen.pixelColor(columna,fila).blue());
        }
        matrizPixelesazules.push_back(filas);
    }
    //redimensionar y almacenar en la matriz final
    alto=matrizPixelesrojos.size();
    for (int i = 0; i < alto; ++i) {
        ancho=matrizPixelesrojos[i].size();
        avanzar=12-ancho;
        avanzar=ancho/avanzar;
        columna=avanzar;
        for (int j =0; j < ancho; ++j){ //mulriplicar las colummnas
            pixel=matrizPixelesrojos[i][j];
            matrizfila.push_back(pixel);
            if(j==columna+avanzar){
                columna=j;
                matrizfila.push_back(pixel);
            }
        }
        //continuar proceso para las filas
        matrizfinal.push_back(matrizfila);
    }
}
