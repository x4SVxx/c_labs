﻿#include <iostream>
using namespace std;

class complex {
private:
    double real;
    double image;
   // int size;
   // complex* mas;
public:
 
    void assign(double x, double y)
    {
        real = x;
        image = y;
    }

    void print()
    {
        cout << real << "+" << "(" << image << ")" << "i";
    }

    double module()
    {
        double fab = sqrt(pow(real, 2) + pow(image, 2));
        return fab;
    }

   // void set_real(double x) {
   //     real = x;
   // }
  //  void set_image(double y) {
   //     image = y;
  //  }
    double get_real() {
        return real;
    }
    double get_image() {
        return image;
    }

    void add(complex number1, complex number2)
    {
        real = number1.real + number2.real;
        image = number1.image + number2.image;
    }

    void raz(complex number1, complex number2)
    {
        real = number1.real - number2.real;
        image = number1.image - number2.image;
    }

    void multi(complex number1, complex number2)
    {
        real = (number1.real * number2.real) - (number1.image * number2.image);
        image = (number1.real * number2.image + number2.real * number1.image);
    }

    void add(complex number1, double chislo)
    {
        real = number1.real + chislo;
        image = number1.image;
    }

    void raz(complex number1, double chislo)
    {
        real = number1.real - chislo;
        image = number1.image - chislo;
    }
    
    void multi(complex number1, double chislo)
    {
        real = number1.real * chislo;
        image = chislo * number1.image;
    }

    complex(double real, double image)
    {
        this->real = real;
        this->image = image;
    }

    complex()
    {
        real = 1;
        image = 1;
    }

  //  complex(double x, double y) :real(x), image(y) {}

  //  complex(int n)
  //  {
   //     size = n;
  //      mas = new complex[size];
  //  }
   // ~complex()
   // {
  //      delete[] mas; size = 0;
  //  }

    /*   void intput()
    {
        cout << "Massive" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "input real part " << i + 1 << endl;
            cin >> mas[i].real;
            cout << "input image part " << i + 1 << endl;
            cin >> mas[i].image;
        }
    }
   /*     void printt()
    {
        cout << "Massive=" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "complex" << i + 1 << "=" << endl;
            cout << mas[i].real << "+" << mas[i].image << "(" << "i" << ")";
            cout << endl;
        }
    }
    

    double reshenier(complex* mas1, int i)
    {
        return mas1[i].real;
    }

    double resheniei(complex* mas1, int i)
    {
        return mas1[i].image;
    }
    */
    void reshenie(complex* mas, int size)
    {
        for (int i = 0; i < size; i++)
        {
            int num = i;
            for (int j = i + 1; j < size; j++)
            {
                if (mas[num].real > mas[j].real)
                {
                    num = j;
                }
            }
            double temp1 = mas[i].real;
            double temp2 = mas[i].image;
            mas[i].image = mas[num].image;
            mas[i].real = mas[num].real;
            mas[num].real = temp1;
            mas[num].image = temp2;
        }
    }

};

int main()
{
    cout << "Vvedite complex chisla" << endl;
    double real1;
    double real2;
    double image1;
    double image2;
    cout << "real1=" << endl;
    cin >> real1;
    cout << "real2=" << endl;
    cin >> real2;
    cout << "image1=" << endl;
    cin >> image1;
    cout << "image2=" << endl;
    cin >> image2;

    complex number1, number2;
    number1.assign(real1, image1);
    cout << "complex1=" << endl;
    number1.print();
    cout << endl;
    number2.assign(real2, image2);
    cout << "complex2=" << endl;
    number2.print();
    cout << endl;
    complex summa;
    summa.add(number1, number2);
    cout << "summa=" << endl;
    summa.print();
    cout << endl;
    complex raznost;
    raznost.raz(number1, number2);
    cout << "raznost=" << endl;
    raznost.print();
    cout << endl;
    complex mult;
    mult.multi(number1, number2);
    cout << "multi=" << endl;
    mult.print();
    cout << endl;
    double fabs1 = number1.module();
    double fabs2 = number2.module();
    cout << "module1=" << endl;
    cout << fabs1 << endl;
    cout << "module2=" << endl;
    cout << fabs2 << endl;
    cout << endl;

    cout << "Construct" << endl;
    complex nim(5, 6);
    nim.print();
    cout << endl;
    complex nom;
    nom.print();
    
    double chislo;
    cout << endl;
    cout << endl;
    cout << "vvedite chislo" << endl;
    cin >> chislo;
    cout << endl;

    complex sum1;
    sum1.add(number1, chislo);
    cout << "summa1=" << endl;
    sum1.print();
    cout << endl;
    complex sum2;
    sum2.add(number2, chislo);
    cout << "summa2=" << endl;
    sum2.print();
    cout << endl;
    complex razz1;
    razz1.raz(number1, chislo);
    cout << "raznost1=" << endl;
    razz1.print();
    cout << endl;
    complex razz2;
    razz2.raz(number2, chislo);
    cout << "raznost2=" << endl;
    razz2.print();
    cout << endl;
    complex multt1;
    multt1.multi(number1, chislo);
    cout << "multi1=" << endl;
    multt1.print();
    cout << endl;
    complex multt2;
    multt2.multi(number2, chislo);
    cout << "multi2=" << endl;
    multt2.print();
    cout << endl;
    cout << endl;

    cout << "Reshenie v main" << endl;
    cout << endl;

    cout << "Vvedite chislo massivov" << endl;
    int n;
    cin >> n;
    complex* mas;
    mas = new complex[n];

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << "Vvedite real" << endl;
        cin >> x;
        cout << "Vvedite image" << endl;
        cin >> y;
        mas[i].assign(x, y);
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "massive=" << endl;
        mas[i].print();
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        int num = i;
        for (int j = i + 1; j < n; j++)
        {
            if (mas[num].get_real() > mas[j].get_real())
            {
                num = j;
            }
        }
        double temp1 = mas[i].get_real();
        double temp2 = mas[i].get_image();
        mas[i].assign(mas[num].get_real(), mas[num].get_image());
        mas[num].assign(temp1, temp2);
    }
    
    cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << "complex" << i + 1 << "=" << endl;
        mas[i].print();
        cout << endl;
    }


    cout << "Reshenie cherez metodi" << endl;
    cout << endl;

    cout << "Vvedite chislo massivov" << endl;
    int n1;
    cin >> n1;
    complex* mas1;
    mas1 = new complex[n1];

    for (int i = 0; i < n1; i++)
    {
        double x, y;
        cout << "input real part " << i + 1 << endl;
        cin >> x;
        cout << "input image part " << i + 1 << endl;
        cin >> y;
        mas1[i].assign(x,y);
        cout << endl;
    }

    for (int i = 0; i < n1; i++)
    {
        cout << "complex" << i + 1 << "=" << endl;
        mas1[i].print();
        cout << endl;
    }

    cout << endl;

   /* for (int i = 0; i < n1; i++)
    {
        int num = i;
        for (int j = i + 1; j < n1; j++)
        {
            double sr1 = resh.reshenier(mas1, num);
            double sr2 = resh.reshenier(mas1, j);
            if (sr1 > sr2)
            {
                num = j;
            }
        }
        double temp1 = resh.reshenier(mas1, i);
        double temp2 = resh.resheniei(mas1, i);
        mas1[i].image = resh.resheniei(mas1, num);
        mas1[i].real = resh.reshenier(mas1, num);
        mas1[num].real = temp1;
        mas1[num].image = temp2;
    }
*/
    complex resh;
    resh.reshenie(mas1, n1);
    for (int i = 0; i < n1; i++)
    {
        cout << "complex" << i + 1 << "=" << endl;
        mas1[i].print();
        cout << endl;
    }
}
