#include <iostream>
using namespace std;

class geom
{
protected:
    double area;
    double volume;
public:
    geom()
    {
        cout << "Constructor" << endl;
    }
    virtual double pl() = 0;

    virtual double ob() = 0;

};

class krug : public geom 
{
    double rad;
public:
    krug(double radius=0)
    {
        rad = radius;
    }
    double pl() override
    {
        area = (3.14 * rad * rad);
        return area;
    }
    double ob()
    {
        return 0;
    }
};

class pram : public geom
{protected:
    double sid1, sid2;
public:
    pram(double side1=0, double side2=0)
    {
        sid1 = side1;
        sid2 = side2;
    }
    double pl() override
    {
        area = (sid1 * sid2);
        return area;
    }
    double ob()
    {
        return 0;
    }
};

class kvad : public pram
{
public:
    kvad(double side=0)
    {
        sid1 = side;
        sid2 = side;
    }
};



class shar : public geom
{
    double rad;
public:
    shar(double radius=0)
    {
        rad = radius;
    }
    double ob() override
    {
        volume = (4 * 3.14 * rad * rad) / 3;
        return volume;
    }
    double pl()
    {
        return 0;
    }
};

class konus : public geom
{
    double rad;
    double vis;
public:
    konus(double radius=0, double high=0)
    {
        rad = radius;
        vis = high;
    }
    double ob() override
    {
        volume = (3.14 * rad * rad*vis)/3;
        return volume;
    }
    double pl()
    {
        return 0;
    }
};

int main()
{
    double rad;
    double stor;
    double sideA;
    double sideB;
    cout << "Enter the side 1 of the rectangle" << endl;
    cin >> sideA;
    cout << "Enter the side 2 of the rectangle" << endl;
    cin >> sideB;
    cout << "Enter the radius of the circle" << endl;
    cin >> rad;
    cout << "Enter the side of the square" << endl;
    cin >> stor;
    pram pr(sideA, sideB);
    krug kr(rad);
    kvad kv(stor);
    double ploshadpram = pr.pl();
    cout << "The area of a rectangle " << ploshadpram << endl;
    double ploshadkvad = kv.pl();
    cout << "The area of a square " << ploshadkvad << endl;
    double ploshadkrug = kr.pl();
    cout << "The area of a circle " << ploshadkrug << endl;

    double ostatok = ploshadpram - (ploshadkvad + ploshadkrug);
    if (ostatok >= 0)
        cout << "Remains " << ostatok << endl;
    else
        cout << "The area of a circle and square is larger than the area of a rectangle" << endl;

    cout << "Individual task" << endl;

    double radiusshar;
    double radiuskonus;
    double heightkonus;

    cout << "Enter the radius of the ball" << endl;
    cin >> radiusshar;
    if (radiusshar < 0)
    {
        cout << "Input error";
        exit(0);
    }
    shar shar(radiusshar);
    double sharvolume = shar.ob();
    cout << "The volume of the ball is equal to " << sharvolume << endl;

    cout << "Enter the radius of the cone" << endl;
    cin >> radiuskonus;
    cout << "Enter the height of the cone" << endl;
    cin >> heightkonus;
    if (radiuskonus < 0 || heightkonus < 0)
    {
        cout << "Input error";
        exit(0);
    }
    konus konus(radiuskonus, heightkonus);
    double conevalume = konus.ob();
    cout << "The volume of the cone is equal to " << conevalume << endl;
}

