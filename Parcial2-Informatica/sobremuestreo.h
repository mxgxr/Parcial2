#ifndef SOBREMUESTREO_H
#define SOBREMUESTREO_H
#include <iostream>
#include <vector>
#include <QImage>
#include <fstream>

using namespace std;

class Sobremuestreo
{
private:
    string ruta;
    vector<vector<int>>matrizPixelesrojos,matrizPixelesverdes,matrizPixelesazules;
public:
    Sobremuestreo(string);
    void Lectura();
    void Redimension();
};

#endif // SOBREMUESTREO_H
