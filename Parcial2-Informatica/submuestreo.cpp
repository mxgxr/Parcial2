#include "submuestreo.h"

Submuestreo::Submuestreo(QImage imagen)
{
    int altoProm, anchoProm, xtotal=0, ytotal=0;
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

}

void Submuestreo::GuardarTxt()
{
    ofstream fout;
    string cadena="{";
    int contador=0;
    vector<vector<int>>::iterator i;
    vector<int>::iterator k;
    for(i=matrizPixeles.begin(); i!=matrizPixeles.end(); i++){
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

    try {
        fout.open("../Parcial2-Informatica/ImagenPixeles.txt"); //crea o abre un archivo para escritura
        if(!fout.is_open()){throw '1';}
        fout << cadena;
        fout.close();
    }
    catch (char a ) {
        if(a==1){cout << "Problema en la escritura del archivo" << endl;}
    }
}
