#include "sobremuestreo.h"

Sobremuestreo::Sobremuestreo()
{
    ofstream escribir;
    escribir.open("../Parcial2-Informatica/archivo.txt");
    //leer imagen
    string ruta;
    int pixel,ancho,alto,limite,avanzarf,avanzarc,columna,fila;
    vector<int>filas,filanterior,matrizfila,vacio;
    vector<vector<int>>matrizPixelesrojos,matrizPixelesverdes,matrizPixelesazules;

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
    limite=12-alto;
    avanzarf=alto/limite;
    avanzarf-=1;
    fila=0;
    for (int i = 0; i <alto; i++) {
        ancho=matrizPixelesrojos[i].size();
        limite=12-ancho;
        avanzarc=ancho/limite;
        avanzarc-=1;
        columna=0;
        matrizfila=vacio;
        for(int colum=0;colum<12;colum++){
            for (int j =0; j <ancho; j++){ //mulriplicar las colummnas
                pixel=matrizPixelesrojos[i][j];
                matrizfila.insert(matrizfila.begin()+colum,pixel);
                colum++;
                if(j==columna+avanzarc){
                    columna=j+1;
                    matrizfila.insert(matrizfila.begin()+colum,pixel);
                    colum++;
                }
            }
        }
        for(size_t columna=0; columna<matrizfila.size(); columna++){
            escribir<<matrizfila[columna]<<",";
        }
        if(i==fila+avanzarf){
            fila=i+1;
            escribir<<endl;
            for(size_t columna=0; columna<matrizfila.size(); columna++){
                escribir<<matrizfila[columna]<<",";
            }
        }
        escribir<<endl;
        //Sobremuestreo exitoso, replicar para la matriz de pixeles verdes y azules para tener la imagen lista para visualizar
    }
    for (size_t fila=0; fila<matrizPixelesrojos.size(); fila++){
        for(size_t columna=0; columna<matrizPixelesrojos[fila].size(); columna++){
            cout<<matrizPixelesrojos[fila][columna]<<",";
        }
        cout<<endl;
    }
}
