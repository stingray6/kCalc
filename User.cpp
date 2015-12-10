#include "classes.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

User::User(float h, float w, float act, int a, char s, char b, char xx)
{
    height = h;
    weight = w;
    activ = act;
    age = a;
    build = b;
    sex = s;
    x = xx;
}

bool User::load()
{
    fstream usr;
    string line;
    usr.open("user.txt", ios::in);
    if(!usr.good())
        return false;

    else
    {
        int i = 1;
        const char* tmp;

        while(getline(usr, line))
        {
            if (i==1) height = atof(line.c_str());
            if (i==2) weight = atof(line.c_str());
            if (i==3) age = atoi(line.c_str());
            if (i==4)
            {
                tmp = line.c_str();
                sex = *tmp;
            }
            if (i==5)
            {
                tmp = line.c_str();
                build = *tmp;
            }
            if (i==6) activ = atof(line.c_str());
            i++;
        }
        usr.close();
        return true;
    }
}

void User::add()
{
    cout<<"Wzrost (cm): ";
    do
    {
    cin>>height;
    if (height<=0 || height>250)
        cout<<"Bˆ¥d! Spr¢buj ponownie..." <<endl;
    } while (height<=0 || height>250);
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    cout<<"Waga (kg): ";
    do
    {
    cin>>weight;
        if (weight<=0 || weight>300)
        cout<<"Bˆ¥d! Spr¢buj ponownie..." <<endl;
    } while (weight<=0 || weight>300);

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    cout<<"Wiek: ";
    do
    {
    cin>>age;
        if (age<=0 || age>150)
        cout<<"Bˆ¥d! Spr¢buj ponownie..." <<endl;
    } while (age<=0 || age>150);

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    cout<<"Pˆe† <M/K>: ";

    do
    {
        sex = getch();
        if (!(sex=='M' || sex=='m' || sex =='K' || sex=='k'))
            cout<<"Bˆ¥d! Spr¢buj ponownie..." <<endl;
    }
    while (!(sex=='M' || sex=='m' || sex =='K' || sex=='k'));
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    cout<<(char)toupper(sex) <<endl
        <<"Typ budowy:"         <<endl
        <<"\ta) ektomorficzny"  <<endl
        <<"\tb) mezomorficzny"  <<endl
        <<"\tc) endomorficzny"  <<endl;

    do
    {
        build = getch();
        if (!(build=='A' || build=='a' || build =='B' || build=='b' || build=='C' || build=='c'))
            cout<<"Bˆ¥d! Spr¢buj ponownie..." <<endl;
    }
    while(!(build=='A' || build=='a' || build =='B' || build=='b' || build=='C' || build=='c'));
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    cout<<(char)tolower(build)        <<endl
        <<"Aktywno˜† fizyczna (1-6): ";
    do
    {
        x = getch();
        if(!(x=='1' || x=='2' || x=='3' || x=='4' || x=='5' || x=='6'))
            cout<<"Bˆ¥d! Spr¢buj ponownie..." <<endl;
    }
    while (!(x=='1' || x=='2' || x=='3' || x=='4' || x=='5' || x=='6'));
    cout<<x <<endl <<"Gotowe!" <<endl<<endl;
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    switch (x)
    {
    case '1':
        activ = 1;
        break;
    case '2':
        activ = 1.1;
        break;
    case '3':
        activ = 1.2;
        break;
    case '4':
        activ = 1.3;
        break;
    case '5':
        activ = 1.4;
        break;
    case '6':
        activ = 1.5;
        break;
    default:
        break;
    }
}
void User::save()
{
    fstream usr;
    string line;
    usr.open("user.txt", ios::out);
    usr<<height <<endl
       <<weight <<endl
       <<age <<endl
       <<sex <<endl
       <<build <<endl
       <<activ;
    usr.close();
}

void User::show()
{
    cout<<"Wzrost: " <<height <<"cm" <<endl;
    cout<<"Waga: " <<weight <<"kg" <<endl;
    cout<<"Wiek: " <<age <<endl;
    cout<<"Pˆe†: " <<sex<<endl;
    cout<<"Typ budowy:" <<build <<endl;
    cout<<"Aktywno˜† fizyczna: "<<activ<<endl;
}

float User::calc()
{
    float e;
///BMR
    if (sex == 'k' || sex == 'K')
        e = 9.99*weight + 6.25*height - 4.92*age - 161;
    else if (sex=='m' || sex=='M')
        e = 9.99*weight + 6.25*height - 4.92*age + 5;

///~TEA+EPOC
    e *= activ;

///NEAT
    if (build=='a' || build=='A')
        e += 800;
    else if (build=='b' || build=='B')
        e += 450;
    else if (build=='c' || build=='C')
        e += 300;

///TEF
    e *= 1.08;

    return e;
}
