#include <iostream>
#include <QImage>
#include <vector>
#include <iterator>
#include "sobremuestreo.h"

using namespace std;

vector<int> promedioColor(vector<vector<int>> &arr);

int main()
{
    string ruta;
    int contador=0, altoProm, anchoProm, cont2=0;
    vector<int>matrizRGB;
    vector<vector<int>>matrizPixeles;

    cout << "Ingrese la ruta de la imagen a cargar: " << endl;
    cin >> ruta;

    QImage imagen(ruta.c_str());


    anchoProm=imagen.width()/12;
    altoProm=imagen.height()/12;

    while(contador!=imagen.width()*imagen.height()){
        for(int x=contador; x<anchoProm; x++){
            for(int y=cont2; y<altoProm; y++){
                matrizRGB[0]=imagen.pixelColor(x,y).red();
                matrizRGB[1]=imagen.pixelColor(x,y).green();
                matrizRGB[2]=imagen.pixelColor(x,y).blue();
                matrizPixeles.push_back(matrizRGB);
                cont2++;
            }
            contador++;
            cont2=0;
        }
    }
/*
    for(int x=0; x<imagen.width(); x++){
        for(int y=0; y<imagen.height(); y++){
            matrizRGB[contador].push_back(imagen.pixelColor(x,y).red());
            matrizRGB[contador].push_back(imagen.pixelColor(x,y).green());
            matrizRGB[contador].push_back(imagen.pixelColor(x,y).blue());
            contador++;
        }
    }*/


    return 0;
}

vector<int> promedioColor(vector<vector<int>> &arr)
{
    //vector<vector<int>>::iterator k;
    //vector<int>::iterator j;
    vector<int>promRGB;
    int rojo=0, verde=0, azul=0;
    for(unsigned int k=0; k<arr.size(); k++){
        rojo+=arr[k][0];
        verde+=arr[k][1];
        azul+=arr[k][2];
    }
    rojo=rojo/arr.size();
    verde=verde/arr.size();
    azul=azul/arr.size();

    promRGB[0]=rojo;
    promRGB[1]=verde;
    promRGB[2]=azul;

    return promRGB;
}

