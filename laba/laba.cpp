﻿#include <iostream>
#include <cmath>
using namespace std;

struct complex {
    double real;
    double image;
}number1,number2;

    complex assign(double real = 1, double image = 1)
    { 
        complex number;
            number.real = real;
            number.image = image;
            return number;
    }

        void print(complex num)
    {
            cout << num.real << "+" << "(" << num.image << ")" << "i";
    }

        complex add(complex number1, complex number2)
    {
            complex summa;
            summa.real = number1.real + number2.real;
            summa.image = number1.image + number2.image;
            return summa;
    }

        complex add(complex number1, double number2)
        {
            complex summa;
            summa.real = number1.real + number2;
            summa.image = number1.image;
            return summa;
        }

        complex add(double number2, complex number1)
        {
            complex summa;
            summa.real = number1.real + number2;
            summa.image = number1.image;
            return summa;
        }

        complex raz(complex number1, complex number2)
        {
            complex raznost;
            raznost.real = number1.real - number2.real;
            raznost.image = number1.image - number2.image;
            return raznost;
        }

        complex raz(complex number1, double number2)
        {
            complex raznost;
            raznost.real = number1.real - number2;
            raznost.image = number1.image;
            return raznost;
        }

        complex raz(double number2, complex number1)
        {
            complex raznost;
            raznost.real = number1.real - number2;
            raznost.image = number1.image;
            return raznost;
        }

        complex multi(complex number1, complex number2)
        {
            complex mult;
            mult.real = (number1.real * number2.real) - (number1.image * number2.image);
            mult.image = (number1.real * number2.image + number2.real * number1.image);
            return mult;
        }

        complex multi(complex number1, double number2)
        {
            complex mult;
            mult.real = number1.real * number2;
            mult.image = number2 * number1.image;
            return mult;
        }

        complex multi(double number2, complex number1)
        {
            complex mult;
            mult.real = number1.real * number2;
            mult.image = number2 * number1.image;
            return mult;
        }

        double module(complex number)
        {
            double fab = sqrt(pow(number.real,2) + pow(number.image,2));
            return fab;
        }

void main()
{
    double real1;
    double real2;
    double image1;
    double image2;
    cout << "real1=" <<endl;
    cin >> real1;
    cout << "real2=" << endl;
    cin >> real2;
    cout << "image1=" << endl;
    cin >> image1;
    cout << "image2=" << endl;
    cin >> image2;
    number1=assign(real1, image1);
    number2=assign(real2, image2);
    cout << "complex1=" << endl;
    print(number1);
    cout << endl;
    cout << "complex2=" << endl;
    print(number2);
    cout << endl;
    complex summa = add(number1, number2);
    cout << "summa=" << endl;
    print(summa);
    cout << endl;
    complex raznost = raz(number1, number2);
    cout << "raznost=" << endl;
    print(raznost);
    cout << endl;
    complex mult = multi(number1, number2);
    cout << "multi=" << endl;
    print(mult);
    cout << endl;
    double fabs1 = module(number1);
    double fabs2 = module(number2);
    cout << "module1=" << endl;
    cout << fabs1 << endl;
    cout << "module2=" << endl;
    cout << fabs2 << endl;

    double chislo;
    cout << endl;
    cout << "vvedite chislo" << endl;
    cin >> chislo;
    cout << endl;

    complex summav1 = add(chislo, number1);
    cout << "suumav1=" << endl;
    print(summav1);
    cout << endl;
    complex raznostv1 = raz(chislo, number1);
    cout << "raznostv1=" << endl;
    print(raznostv1);
    cout << endl;
    complex multv1 = multi(chislo, number1);
    cout << "multiv1=" << endl;
    print(multv1);
    cout << endl;

    complex summav2 = add(number2, chislo);
    cout << "suumav2=" << endl;
    print(summav2);
    cout << endl;
    complex raznostv2 = raz(number2, chislo);
    cout << "raznostv2=" << endl;
    print(raznostv2);
    cout << endl;
    complex multv2 = multi(number2, chislo);
    cout << "multiv2=" << endl;
    print(multv2);
    cout << endl;
}

