//kCalc

#include <iostream>
#include "classes.h"
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;
int lncounter(char filename[]);
void hello();
void help();

int main()
{

    int n, nn;
    Ingr* s;
    n = lncounter("ingredients.txt")/6 + 50;
    s = new Ingr [n];                   //inicjalizacja sk�adnik�w

    Meal* p;
    nn = lncounter("meals.txt")/9 + 5;
    p = new Meal [nn];

    for (int i=0; i<n; i++)             //wczytanie sk�adnik�w do pami�ci
        s[i].load(i+1);

    for (int i=0; i<nn; i++)             //wczytanie posi�k�w do pami�ci
        p[i].load(s, n, i+1);


    char x;
    hello();

    while (x!=27)
    {
        x = getch();
        switch (x)
        {
        case '1':
        {
            Ingr ns;
            ns.add();
            ns.save();
            cout<<"Gotowe!" <<endl;

            for (int i=0; i<n; i++)             //wczytanie sk�adnik�w do pami�ci
                s[i].load(i+1);
        }
        break;
        case '2':
        {
            for (int i=0; i<n; i++)
                s[i].show();
            cout<<"Naci�nij dowolny klawisz, aby kontynuowa�..." <<endl;
            getch();
            hello();
        }
        break;
        case '3':
        {
            system("cls");
            Meal nm;
            nm.add(s, n);
            cout<<"Gotowe!" <<endl;
            hello();
            for (int i=0; i<nn; i++)             //wczytanie posi�k�w do pami�ci
                p[i].load(s, n, i+1);
        }
        break;
        case '4':
        {
            hello();
            Meal today;
            for(int i=0; i<nn; i++)
            {
                if (p[i].isday(today))
                    today.sum(p[i]);
            }
            today.show();
        }
        break;
        case '5':
        {
            system("cls");
            Meal anyday;
            anyday.setday();
            for(int i=0; i<nn; i++)
            {
                if (p[i].isday(anyday))
                    anyday.sum(p[i]);
            }
            anyday.show();
            cout<<"Naci�nij dowolny klawisz, aby kontynuowa�..." <<endl;
            getch();
            hello();
        }
        break;
        case '6':
        {
            hello();
            User u1;
            if(!u1.load())
            {
                u1.add();
                u1.save();
            }
            cout<<"Aby utrzyma� wag�, musisz dostarcza� organizmowi:\n" <<u1.calc() <<"kcal dziennie" <<endl
                <<"\tlub\n"
                <<7*u1.calc() <<"kcal tygodniowo" <<endl;
        }
        break;
        case '7':
        {
            system("cls");
            User u1;

            u1.add();
            u1.save();
            cout<<"Naci�nij dowolny klawisz, aby kontynuowa�..." <<endl;
            Sleep(400);
            hello();
        }
        break;
        case '8':
        {
            system("cls");
            help();
            getch();
            hello();
        }
        default:
            break;
        }
    }
    delete []p;
    delete []s;
    return 0;
}

int lncounter(char filename[])
{
    fstream ingrs;
    string line;

    int i = 0;

    ingrs.open(filename, ios::in);
    if (!ingrs.good())
    {
        return 0;
        ingrs.close();
    }
    else
    {
        while (getline(ingrs, line))
            i++;
        ingrs.close();

        return i;
    }
}

void hello()
{
    system("cls");
    cout<<"1: Dodaj sk�adnik do bazy" <<endl
        <<"2: Poka� zapisane sk�adniki" <<endl
        <<"3: Dodaj posi�ek" <<endl
        <<"4: Poka�, co dzi� jad�em" <<endl
        <<"5: Poka�, co jad�em dnia..." <<endl
        <<"6: Oblicz dzienne zapotrzebowanie" <<endl
        <<"7: Aktualizuj dane o u�ytkowniku" <<endl
        <<"8: Pomoc" <<endl
        <<"ESC: wyj�cie" <<endl<<endl;
}
void help()
{
    cout<<"Witaj w kCalc! Oto kilka fakt�w, kt�re pozwol� Ci zrozumie� dzia�anie \nprogramu." <<endl <<endl
        <<"Rozr��nia si� trzy typy budowy cia�a: ektomorficzny, mezomorficzny \ni endomorficzny. Ka�dy z typ�w ma inne zapotrzebowanie energetyczne," <<endl
        <<"dlatego nale�y go uwzgl�dnia� przy obliczeniach zwi�zanych \nz diet�." <<endl
        <<"ektomorfik - osoba szczup�a i wysoka, o d�ugich ko�czynach" <<endl
        <<"mezomorfik - osoba postawna i umi��niona, silna" <<endl
        <<"endomorfik - osoba przysadzista, okr�g�a" <<endl <<endl;

    cout<<"Aktywno�� fizyczna tak�e ma wp�yw na ilo�� spalanych kalorii. W tym \nprogramie mo�esz wybra� poziom aktywno�ci w skali od 1 do 6, gdzie:" <<endl
        <<"1 - brak �wicze�, siedz�cy tryb �ycia" <<endl
        <<"2-3 - �wiczenia kilka razy w tygodniu, poza tym siedz�cy tryb �ycia" <<endl
        <<"4-5 - codzienne �wiczenia i wymagaj�ca fizycznie praca" <<endl
        <<"6 - codzienne intensywne �wiczenia i praca fizyczna" <<endl<<endl
        <<"Naci�nij dowolny klawisz, aby powr�ci� do programu ";
}
