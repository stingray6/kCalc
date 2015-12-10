#include "classes.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

Ingr::Ingr(string n, float c, float ch, float p, float f, float s)
{
    name = n;
    cal = c;
    carb = ch;
    prot = p;
    fat = f;
    sug = s;
}

void Ingr::add()
{
    cout<<"Nazwa skˆadnika: ";
    cin>>name;

    cout<<"Energia (kcal): ";
    cin>>cal;

    cout<<"W©glowodany (g): ";
    cin>>carb;

    cout<<"Biaˆko (g): ";
    cin>>prot;

    cout<<"Tˆuszcze (g): ";
    cin>>fat;

    cout<<"Cukry (g): ";
    cin>>sug;
}

void Ingr::load(int ing_nr)
{
    fstream ingrs;
    string line;

    int ln_nr = (ing_nr-1)*6 + 1;                       //wz¢r na nr linii w pliku
    int i = 1;                                          //licznik linii w tek˜cie

    ingrs.open("ingredients.txt", ios::in);
if (!ingrs.good())
    cout<<"Nie znaleziono pliku ze skˆadnikami! Plik zostanie utworzony, je˜li dodasz jaki˜ skˆadnik..." <<endl;
    while (getline(ingrs, line))                        //odczyt danych z pliku do pamieci
    {
        if (i==ln_nr) name = line;
        if (i==ln_nr+1) cal = atof(line.c_str());
        if (i==ln_nr+2) carb = atof(line.c_str());
        if (i==ln_nr+3) prot = atof(line.c_str());
        if (i==ln_nr+4) fat = atof(line.c_str());
        if (i==ln_nr+5) sug = atof(line.c_str());
        i++;
    }
    ingrs.close();
}

void Ingr::save()
{
    fstream ingrs;
    ingrs.open("ingredients.txt", ios::out | ios::app);
    ingrs   <<name  <<endl
            <<cal   <<endl
            <<carb  <<endl
            <<prot  <<endl
            <<fat   <<endl
            <<sug   <<endl;
    ingrs.close();
}

void Ingr::show()
{
    if (name!="")
    {
        cout<<name <<endl
            <<"Energia: " <<cal <<"kcal" <<endl
            <<"W©glowodany: " <<carb <<"g" <<endl
            <<"Biaˆko: " <<prot <<"g" <<endl
            <<"Tˆuszcze: " <<fat <<"g" <<endl
            <<"Cukry: " <<sug <<"g" <<endl <<endl;
    }
}
