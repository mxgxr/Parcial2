#include <iostream>
#include <QImage>
#include <vector>

using namespace std;

int main()
{
    string ruta;
    int contador=0;
    vector<vector<int>>matrizRGB;

    cout << "Ingrese la ruta de la imagen a cargar: " << endl;
    cin >> ruta;

    QImage imagen(ruta.c_str());

    for(int x=0; x<imagen.width(); x++){
        for(int y=0; y<imagen.height(); y++){
            matrizRGB[contador].push_back(imagen.pixelColor(x,y).red());
            matrizRGB[contador].push_back(imagen.pixelColor(x,y).green());
            matrizRGB[contador].push_back(imagen.pixelColor(x,y).blue());
            contador++;
        }
    }


    return 0;
}
