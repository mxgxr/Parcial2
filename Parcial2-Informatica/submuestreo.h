#ifndef SUBMUESTREO_H
#define SUBMUESTREO_H
#include <iostream>
#include <QImage>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

class Submuestreo
{
    vector<int>matrizRGB;
    vector<vector<int>>matrizPixeles;
public:
    Submuestreo(QImage imagen);
    void GuardarTxt();
};

#endif // SUBMUESTREO_H
