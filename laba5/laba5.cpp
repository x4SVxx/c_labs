﻿#include <iostream>
using namespace std;

class complex {
private:
    double real;
    double image;
public:

    complex(double x = 0, double y = 0)
    {
        real = x;
        image = y;
    }

    void print()
    {
        cout << real << "+" << "(" << image << ")" << "i";
    }

    double getreal()
    {
        return real;
    }

    double getimage()
    {
        return image;
    }

    void setreal(double a)
    {
        real = a;
    }

    void setimage(double b)
    {
        image = b;
    }

    friend bool operator==(const complex& a, const complex& b);
    friend bool operator>(const complex& x, const complex& y);
    friend ostream& operator<<(ostream& out, complex& a);
    friend istream& operator>>(istream& in, complex& a);
};

bool operator==(const complex& a,const complex& b)
{
    return (a.real == b.real && a.image == b.image);
}

bool operator>(const complex& x, const complex& y)
{
    return (x.real > y.real);
}

ostream& operator<<(ostream& out, complex& a)
{
    out<< a.real << "+" << "(" << a.image << ")" << "i";
    return out;
}

istream& operator>>(istream& in, complex& a)
{
    in >> a.real;
    in >> a.image;
    return in;
}

class vect {
private:
    complex* mas;
    int size;
public:

    vect(int n)
    {
        size = n;
        mas = new complex[size];
    }

    ~vect()
    {
        delete[] mas;
        size = 0;
    }

    complex get(int i)
    {
        return mas[i];
    }

    void set(int i, complex a)
    {
        mas[i] = a;
    }

    void print()
    {
        cout << endl;
        cout << "Massiv=" << endl;
        for (int i = 0; i < size; i++)
        {
            complex test = mas[i];
            test.print();
            cout << endl;
        }
    }

    void resh()
    {
        for (int i = 0; i < size; i++)
        {
            int num = i;
            for (int j = i + 1; j < size; j++)
            {
                if (mas[num] > mas[j])
                {
                    num = j;
                }
            }
            double temp1 = mas[i].getreal();
            double temp2 = mas[i].getimage();
            mas[i].setreal(mas[num].getreal());
            mas[i].setimage(mas[num].getimage());
            mas[num].setreal(temp1);
            mas[num].setimage(temp2);
        }
    }

};

int main() {

    cout << "Input size of the array 1" << endl;
    int size1;
    cin >> size1;
    vect mas1(size1);

    cout << "Input size of the array 2" << endl;
    int size2;
    cin >> size2;
    vect mas2(size2);

    complex test;
    double x, y;
    for (int i = 0; i < size1; i++)
    {
        cout << "Input elem " << i + 1 << " of the array 1" << endl;
        cout << "Vvedite real" << endl;
        cin >> x;
       // x = rand() % 11;
        cout << "Vvedite image" << endl;
        cin >> y;
       // y = rand() % 11;
        complex test(x, y);
        mas1.set(i, test);
        cout << endl;
    }
    mas1.print();

    for (int i = 0; i < size2; i++)
    {
        cout << "Input elem " << i + 1 << " of the array 2" << endl;
        //cout << "Vvedite real" << endl;
        //cin >> x;
        //x = rand() % 11;
       // cout << "Vvedite image" << endl;
        //cin >> y;
        //y = rand() % 11;
        cin >> test;
       // complex test(x, y);
        mas2.set(i, test);
        cout << endl;
    }
    //mas2.print();
    for (int i = 0; i < size2; i++)
    {
        complex N = mas2.get(i);
        cout<<N;
        cout << endl;
    }

    int flag = 0;

    if (size1 < size2)
    {
        for (int i = 0; i < size1; i++)
        {
            if (mas1.get(i) == mas2.get(i))
            {
                flag++;
            }
        }
    }
    else
    {
        for (int i = 0; i < size2; i++)
        {
            if (mas1.get(i) == mas2.get(i))
            {
                flag++;
            }
        }
    }

    cout << endl;
    cout << flag;
    cout << endl;
    cout << "Sortirovka" << endl;
    mas1.resh();
    mas2.resh();

    mas1.print();
    cout << endl;
    mas2.print();
    cout << endl;

    return 0;
}