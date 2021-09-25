#include "sobremuestreo.h"

Sobremuestreo::Sobremuestreo(string rut)
{
    ruta=rut;
}
void Sobremuestreo::Lectura(){

    //leer imagen
    vector<int>filas,vacio;
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
}
void Sobremuestreo::Redimension(){

    ofstream escribir;
    escribir.open("../Parcial2-Informatica/ImagenPixeles.txt");
    escribir<<"{";

    int pixelrojo,pixelverde,pixelazul,ancho,alto,limiteAL,limiteAN,avanzarf,avanzarc,columna,fila,cont1,cont2;
    vector<int> matrizfilaR,matrizfilaG,matrizfilaB,vacio;

    //redimensionar y almacenar la matriz final en el archivo
    alto=matrizPixelesrojos.size();
    limiteAL=12-alto;
    avanzarf=alto/limiteAL;
    avanzarf-=1;
    fila=0;
    cont2=0;
    for (int i = 0; i <alto; i++) {
        cont1=0;
        ancho=matrizPixelesrojos[i].size();
        limiteAN=12-ancho;
        avanzarc=ancho/limiteAN;
        avanzarc-=1;
        columna=0;
        matrizfilaR=vacio;
        matrizfilaG=vacio;
        matrizfilaB=vacio;
        for(int colum=0;colum<12;colum++){
             for (int j =0; j <ancho; j++){ //mulriplicar las colummnas
                     pixelrojo=matrizPixelesrojos[i][j];
                     pixelverde=matrizPixelesverdes[i][j];
                     pixelazul=matrizPixelesazules[i][j];
                     matrizfilaR.insert(matrizfilaR.begin()+colum,pixelrojo);
                     matrizfilaG.insert(matrizfilaG.begin()+colum,pixelverde);
                     matrizfilaB.insert(matrizfilaB.begin()+colum,pixelazul);
                     colum++;
                     if(j==columna+avanzarc){
                            cont1++;
                            if(cont1<=limiteAN){
                            columna=j+1;
                            matrizfilaR.insert(matrizfilaR.begin()+colum,pixelrojo);
                            matrizfilaG.insert(matrizfilaG.begin()+colum,pixelverde);
                            matrizfilaB.insert(matrizfilaB.begin()+colum,pixelazul);
                            colum++;
                            }
                        }
                    }
                }
            for(size_t columna=0; columna<matrizfilaR.size(); columna++){
                escribir<<"{";
                escribir<<matrizfilaR[columna]<<",";
                escribir<<matrizfilaG[columna]<<",";
                escribir<<matrizfilaB[columna]<<",";
                escribir<<"}";
                escribir<<",";
            }
            if(i==fila+avanzarf){
                cont2++;
                if(cont2<=limiteAL){
                fila=i+1;
                escribir<<endl;
                for(size_t columna=0; columna<matrizfilaR.size(); columna++){
                    escribir<<"{";
                    escribir<<matrizfilaR[columna]<<",";
                    escribir<<matrizfilaG[columna]<<",";
                    escribir<<matrizfilaB[columna]<<",";
                    escribir<<"}";
                    escribir<<",";
                 }
                }
            }
            escribir<<endl;
            //Sobremuestreo exitoso

    }
    escribir<<"}";
    escribir<<";";
    escribir.close();
}
