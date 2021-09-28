#include "submuestreo.h"

Submuestreo::Submuestreo(QImage imagen, int metodo)
{
    int altoProm, anchoProm, xtotal=0, ytotal=0;
    anchoProm=imagen.width()/12;
    altoProm=imagen.height()/12;

    if (metodo==1){ //submuestreo en x
        for(int y=0; y<imagen.height(); y++){
            for(int x=0; x+anchoProm<=imagen.width(); x+=anchoProm){
                xtotal=(2*x+anchoProm)/2;
                if(imagen.pixelColor(xtotal,y).red()==255){
                    matrizRGB.push_back(imagen.pixelColor(xtotal,y).red()-5);
                }
                else{
                    matrizRGB.push_back(imagen.pixelColor(xtotal,y).red());
                }

                if(imagen.pixelColor(xtotal,y).green()==255){
                    matrizRGB.push_back(imagen.pixelColor(xtotal,y).green()-5);
                }
                else{
                    matrizRGB.push_back(imagen.pixelColor(xtotal,y).green());
                }

                if(imagen.pixelColor(xtotal,y).blue()==255){
                    matrizRGB.push_back(imagen.pixelColor(xtotal,y).blue()-5);
                }
                else{
                    matrizRGB.push_back(imagen.pixelColor(xtotal,y).blue());
                }
                matrizPixeles.push_back(matrizRGB);
                matrizRGB.clear();
            }
        }
    }
    else if (metodo==2){ //submuestreo en y
        for(int x=0; x<imagen.width(); x++){
            for(int y=0; y+altoProm<=imagen.height(); y+=altoProm){
                ytotal=(2*y+altoProm)/2;

                if(imagen.pixelColor(x,ytotal).red()==255){
                    matrizRGB.push_back(imagen.pixelColor(x,ytotal).red()-5);
                }
                else{
                    matrizRGB.push_back(imagen.pixelColor(x,ytotal).red());
                }

                if(imagen.pixelColor(x,ytotal).green()==255){
                    matrizRGB.push_back(imagen.pixelColor(x,ytotal).green()-5);
                }
                else{
                    matrizRGB.push_back(imagen.pixelColor(x,ytotal).green());
                }

                if(imagen.pixelColor(x,ytotal).blue()==255){
                    matrizRGB.push_back(imagen.pixelColor(x,ytotal).blue()-5);
                }
                else{
                    matrizRGB.push_back(imagen.pixelColor(x,ytotal).blue());
                }
                matrizPixeles.push_back(matrizRGB);
                matrizRGB.clear();
            }
        }
    }

}

Submuestreo::Submuestreo(QImage imagen)
{
    int altoProm, anchoProm, xtotal=0, ytotal=0;
    anchoProm=imagen.width()/12;
    altoProm=imagen.height()/12;

    for(int y=0; y+altoProm<=imagen.height(); y+=altoProm){
        ytotal=(2*y+altoProm)/2;
        for(int x=0; x+anchoProm<=imagen.width(); x+=anchoProm){
            xtotal=(2*x+anchoProm)/2;
            if(imagen.pixelColor(xtotal,ytotal).red()==255){
                matrizRGB.push_back(imagen.pixelColor(xtotal,ytotal).red()-5);
            }
            else{
                matrizRGB.push_back(imagen.pixelColor(xtotal,ytotal).red());
            }

            if(imagen.pixelColor(xtotal,ytotal).green()==255){
                matrizRGB.push_back(imagen.pixelColor(xtotal,ytotal).green()-5);
            }
            else{
                matrizRGB.push_back(imagen.pixelColor(xtotal,ytotal).green());
            }

            if(imagen.pixelColor(xtotal,ytotal).blue()==255){
                matrizRGB.push_back(imagen.pixelColor(xtotal,ytotal).blue()-5);
            }
            else{
                matrizRGB.push_back(imagen.pixelColor(xtotal,ytotal).blue());
            }
            matrizPixeles.push_back(matrizRGB);
            matrizRGB.clear();
        }
    }

}

vector<vector<int>> Submuestreo::getMatrizPixeles() const
{
    return matrizPixeles;
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
