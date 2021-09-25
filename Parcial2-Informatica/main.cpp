#include <iostream>
#include <QImage>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include "sobremuestreo.h"

using namespace std;

string formatoTexto(vector<vector<int>> &array);

int main()
{
    string ruta, cadena;
    int altoProm, anchoProm, xtotal=0, ytotal=0;
    ofstream fout;
    vector<int>matrizRGB;
    vector<vector<int>>matrizPixeles;
    vector<int>mRGBprom;

    cout << "Ingrese la ruta de la imagen a cargar: " << endl;
    cin >> ruta;

    Sobremuestreo uno(ruta);
    uno.Lectura();
    uno.Redimension();

    QImage imagen(ruta.c_str());

    //otro metodo
    anchoProm=imagen.width()/12;
    altoProm=imagen.height()/12;

    for(int y=0; y+altoProm<=imagen.height(); y+=altoProm){
        ytotal=(2*y+altoProm)/2;
        for(int x=0; x+anchoProm<=imagen.width(); x+=anchoProm){
            xtotal=(2*x+anchoProm)/2;
            matrizRGB.push_back(imagen.pixelColor(xtotal,ytotal).red());
            matrizRGB.push_back(imagen.pixelColor(xtotal,ytotal).green());
            matrizRGB.push_back(imagen.pixelColor(xtotal,ytotal).blue());
            matrizPixeles.push_back(matrizRGB);
            matrizRGB.clear();
        }
    }

    cadena=formatoTexto(matrizPixeles);

    //guardar en archivo

    try {
        fout.open("ImagenPixeles.txt"); //crea o abre un archivo para escritura
        if(!fout.is_open()){throw '1';}
        fout << cadena;
        fout.close();
    }
    catch (char a ) {
        if(a==1){cout << "Problema en la escritura del archivo" << endl;}
    }

    return 0;
}

string formatoTexto(vector<vector<int>> &array)
{
    string cadena="{";
    int contador=0;
    vector<vector<int>>::iterator i;
    vector<int>::iterator k;
    for(i=array.begin(); i!=array.end(); i++){
        cadena+='{';
        for(k=i->begin();k!=i->end();k++){
            cadena+=to_string(*k);
            if(contador<2){
                contador++;
                cadena+=',';
            }
        }
        cadena+='}';
        contador=0;
        if(i->back()){
            cadena+=',';
        }
    }
    cadena.pop_back();
    cadena+="};";
    return cadena;
}


