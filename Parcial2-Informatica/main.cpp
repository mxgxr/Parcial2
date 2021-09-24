#include <iostream>
#include <QImage>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include "sobremuestreo.h"

using namespace std;

vector<int> promedioColor(vector<vector<int>> &arr);
string formatoTexto(vector<vector<int>> &array);

int main()
{
    string ruta, cadena;
    int cont1=0, altoProm, anchoProm, cont2=0, xtotal=0, ytotal=0;
    ofstream fout;
    vector<int>matrizRGB;
    vector<vector<int>>matrizPixeles;
    vector<int>mRGBprom;

    cout << "Ingrese la ruta de la imagen a cargar: " << endl;
    cin >> ruta;

    QImage imagen(ruta.c_str());

    //otro metodo
    anchoProm=imagen.width()/12;
    altoProm=imagen.height()/12;

    for(int y=0; y+altoProm<imagen.height(); y+=altoProm){
        ytotal=(2*y+altoProm)/2;
        for(int x=0; x+anchoProm<imagen.width(); x+=anchoProm){
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



/*    while(cont1!=imagen.width()*imagen.height()){
        for(int x=cont1; x<anchoProm; x++){ //leo el pedacito de los pixeles en x
            for(int y=cont2; y<altoProm; y++){ //leo el pedacito de los pixeles en y
                matrizRGB[0]=imagen.pixelColor(x,y).red();
                matrizRGB[1]=imagen.pixelColor(x,y).green();
                matrizRGB[2]=imagen.pixelColor(x,y).blue();
                matrizPixeles.push_back(matrizRGB);
            }
            promedioColor(matrizPixeles);

        }
    }

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
    cadena+="};";
    return cadena;
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

