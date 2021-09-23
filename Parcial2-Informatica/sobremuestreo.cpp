#include "sobremuestreo.h"

Sobremuestreo::Sobremuestreo()
{
    //leer imagen
    string ruta;
    int pixel,pixelanterior,ancho,alto,limite,avanzar,columna;
    vector<int>filas,matrizfila,filanterior,vacio;
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
        limite=12-ancho;
        avanzar=ancho/limite;
        columna=limite;
        pixel=0;
        for (int j =0; j < ancho; ++j){ //mulriplicar las colummnas
            pixelanterior=pixel;
            pixel=matrizPixelesrojos[i][j];
            if(j==columna+avanzar){
                columna=j;
                if (pixel==pixelanterior){
                    matrizfila.push_back(pixel);
                }
                else{
                    matrizfila.push_back(pixelanterior);
                    matrizfila.push_back(pixel);
                }
            }
            matrizfila.push_back(pixel);
        }
        //continuar proceso para las filas
        if(i==1){
            matrizfinal.push_back(matrizfila);
            filanterior=matrizfila;
        }
        else{
            matrizfinal.push_back(matrizfila);
            if(matrizfila==filanterior){
                matrizfinal.push_back(matrizfila);
            }
        }
        //definir el numero de filas que faltan para completar la matriz 12x12

    }
}
