#include <iostream>
#include <string>
using namespace std;

class Ingr
{
    string name;
    float cal, carb, prot, fat, sug;

public:
    Ingr(string = "", float = 0, float = 0, float = 0, float = 0, float = 0);
    void add();
    void load(int ing_nr);
    void save();
    void show();

friend class Meal;
};

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///
///############################################################################///
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///

class Meal :public Ingr
{
int d, m,y;

public:
    Meal(string = "", float = 0, float = 0, float = 0, float = 0, float = 0);
    void add(Ingr i[], int n);
    void load(Ingr i[], int n, int ml_nr);
    bool today();
    bool isday(Meal p1);
    void setday();
    void sum(Meal ml);
    void show();
};

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///
///############################################################################///
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///

class User
{
    float height, weight, activ;
    int age;
    char sex, build;
    char x;

public:
    User(float = 180, float = 75, float = 1.3, int = 25, char = 'm', char = 'm', char = '0');
    bool load();
    void add();
    void save();
    float calc();
    void show();
};
