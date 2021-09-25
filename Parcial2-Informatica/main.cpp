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
    string ruta;

    cout << "Ingrese la ruta de la imagen a cargar: " << endl;
    cin >> ruta;

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



    return 0;
}




