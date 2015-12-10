#include "classes.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
using namespace std;

Meal::Meal(string n, float c, float ch, float p, float f, float s)
{
    struct tm* tinfo;
    time_t sec;
    sec = time(&sec);
    tinfo = localtime(&sec);

    d = tinfo -> tm_mday;
    m = tinfo -> tm_mon;
    y = tinfo -> tm_year;

    name = n;
    cal = c;
    carb = ch;
    prot = p;
    fat = f;
    sug = s;
}

void Meal::add(Ingr i[], int n)
{
    cout<<endl <<"Wybierz z poni�szej listy sk�adniki, kt�re znalaz�y si� w Twoim posi�ku: " <<endl;

    int a;                             //potrzebne do �adnego wy�wietlania listy

    if (n%3==0) a = n/3;
    else a = n/3 +1;

    int it=0;
    for (int k = 0; k < a; k++)        //wy�wietlanie sk�adnik�w podes�anych jako tablica obiekt�w
    {
        for (int l = 0; l < 3; l++)
        {
            if (((k!=a-1) || (n%3==0 || (n%3==1 && l==0) || n%3==2 && (l==0 || l==1))) && (i[it].name != ""))
            {
                cout<<it+1 <<": " ;
                cout.width(15);
                cout<<left<<i[it].name;
                if (l != 2)
                    cout<<"\t";
                it++;
            }
        }
       if (i[it].name != "") cout<<endl;
    }
    cout<<"\n0: zako�cz dodawanie" <<endl;

    fstream mls;
    int x=1;
    mls.open("meals.txt", ios::out | ios::app);
    if(!mls.good())
        cout<<"Nie uda�o si� otworzy� pliku z posi�kami! Plik zostanie utworzony, gdy dodasz sw�j posi�ek..." <<endl;

    while (x!=0)
    {
        cin>>x;
        if (x>=0 && x<=n)
        {
            for(int l = 0; l < n; l++)  //"dynamiczny switch"
            {
                if ((x == l+1) && (i[l].name != ""))
                {
                    mls<<i[l].name  <<", ";
                    cal += i[l].cal;
                    carb += i[l].carb;
                    prot += i[l].prot;
                    fat += i[l].fat;
                    sug += i[l].sug;

                    cout<<"Dodano \"" <<i[l].name <<"\" do posi�ku." <<endl;
                }
                else if (x == l+1)
                    cout<<"B��d! Spr�buj ponownie." <<endl;
            }
        }
        else cout<<"B��d! Spr�buj ponownie." <<endl;
    }

    if (cal > 0)
        mls<<endl
           <<cal <<endl
           <<carb <<endl
           <<prot <<endl
           <<fat <<endl
           <<sug <<endl
           <<d  <<endl
           <<m <<endl
           <<y <<endl;
    mls.close();

}
void Meal::load(Ingr i[], int n, int ml_nr)
{
    fstream mls;
    string line;

    int ln_nr = (ml_nr-1)*9 + 1;
    int it = 1;

    mls.open("meals.txt", ios::in);

    while (getline(mls, line))
    {
        if (it==ln_nr) name = line;
        if (it==ln_nr+1) cal = atof(line.c_str());
        if (it==ln_nr+2) carb = atof(line.c_str());
        if (it==ln_nr+3) prot = atof(line.c_str());
        if (it==ln_nr+4) fat = atof(line.c_str());
        if (it==ln_nr+5) sug = atof(line.c_str());
        if (it==ln_nr+6) d = atof(line.c_str());
        if (it==ln_nr+7) m = atof(line.c_str());
        if (it==ln_nr+8) y = atof(line.c_str());
        it++;
    }
    mls.close();
}

void Meal::setday()
{
    cout<<"Dzie�: ";
    cin>>d;
    cout<<"Miesi�c: ";
    cin>>m;
    cout<<"Rok: ";
    cin>>y;
    cout<<endl;
    m--;
    y-=1900;
}

bool Meal::isday(Meal p1)
{
    if (d==p1.d && m==p1.m && y==p1.y)
        return true;
    else
        return false;
}

void Meal::sum(Meal ml)
{
    if (ml.name != "")
        name += ml.name;
    cal += ml.cal;
    carb += ml.carb;
    prot += ml.prot;
    fat += ml.fat;
    sug += ml.sug;
}
void Meal::show()
{
    string name_n = name;
    if (name_n!="")
    name_n.erase(name_n.end()-2);

    cout<<"Dnia " <<d <<'.' <<m+1 <<'.' <<y+1900 <<" spo�y�e�: ";
    cout <<name_n <<endl
         <<"Energia: " <<cal <<"kcal" <<endl
         <<"W�glowodany: " <<carb <<"g" <<endl
         <<"Bia�ko: " <<prot <<"g" <<endl
         <<"T�uszcz: " <<fat <<"g" <<endl
         <<"Cukier: " <<sug <<"g" <<endl <<endl;
}
