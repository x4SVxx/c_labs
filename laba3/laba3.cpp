#include <iostream>
using namespace std;
class vect {
private:
	double* mas;
	int size;
public:
	vect(int n)
	{
		size = n;
		mas = new double[size];
	}

	~vect()
	{
		delete[] mas;
		size = 0;
	}

	double get(int i)
	{
		return mas[i];
	}

	void set(int i, double a)
	{
		mas[i] = a;
	}

	void input()
	{
		cout << "Vvedite massiv" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << " elem " << i + 1 << "=" << endl;;
			cin >> mas[i];
			//mas[i] = rand();
		}
	}

	void print()
	{
		cout << endl;
		cout << "Massiv=" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << mas[i]<<" ";
		}
	}

	void reshala()
	{
		//cout << min << endl;
		//cout << flag << endl;
		//cout << (double)size / 2;

		if (size % 2 == 0)
		{

			double min = mas[0];
			int flag = 0;
			int flag1 = 0;
			int flag2 = 0;
			for (int i = 0; i < size; i++)
			{
				if (min > mas[i])
				{
					min = mas[i];
					flag1 = i;
				}
			}
			//cout << flag1;
			for (int i = flag1+1; i < size; i++)
			{
				if (min == mas[i])
				{
					flag2 = i;

				}
			}
			//cout << flag2;
			if (flag2!=0)
			{
				cout << "Min elem in 1 and 2 (or center) part" << endl;
			}
			else
			{
				double min = mas[0];
				for (int i = 0; i < size; i++)
				{
					if (min > mas[i])
					{
						min = mas[i];
						flag = i;
					}
				}
				//cout << flag;

				if (flag > ((size / 2) - 1))
				{
					for (int j = size / 2; j < size; j++)
					{
						int num = j;
						for (int l = j + 1; l < size; l++)
						{
							if (mas[num] > mas[l])
							{
								num = l;
							}
						}
						double temp = mas[j];
						mas[j] = mas[num];
						mas[num] = temp;
					}
				}
				else
				{
					int i = 0;
					int j = (size / 2) - 1;
					while (i < j)
					{
						double klon = mas[i];
						mas[i] = mas[j];
						mas[j] = klon;
						i = i + 1;
						j = j - 1;
					}
				}
			}
		}
		else
		{
			double kol = (double)size / 2;
			kol = kol - 0.5;
			//cout << kol;
			//double elem = size - kol;

			double min = mas[0];
			int flag = 0;
			int flag1 = 0;
			int flag2 = 0;
			for (int i = 0; i < size; i++)
			{
				if (min > mas[i])
				{
					min = mas[i];
					flag1 = i;
				}
			}
			for (int i = flag1 + 1; i < size; i++)
			{
				if (min == mas[i])
				{
					flag2 = i;
				}
			}
			if (flag2!=0)
			{
				cout << "Min elem in 1 and 2 (or center) part" << endl;
			}
			else
			{
				double min = mas[0];
				for (int i = 0; i < size; i++)
				{
					if (min > mas[i])
					{
						min = mas[i];
						flag = i;
					}
				}


				if (flag > kol)
				{
					for (int j = kol + 1; j < size; j++)
					{
						int num = j;
						for (int l = j + 1; l < size; l++)
						{
							if (mas[num] > mas[l])
							{
								num = l;
							}
						}
						double temp = mas[j];
						mas[j] = mas[num];
						mas[num] = temp;
					}
				}
				else if (flag < kol)
				{
					double kol = (double)size / 2;
					kol = kol - 0.5;
					int i = 0;
					int j = kol - 1;
					while (i < j)
					{
						double klon = mas[i];
						mas[i] = mas[j];
						mas[j] = klon;
						i = i + 1;
						j = j - 1;
					}
				}
				else if (flag == kol)
				{
					cout << endl;
					cout << "Min elem in center" << endl;
				}
			}
		}
	}

};
void main()
{
	cout << "Reshenir cherez metodi" << endl;
	int N;
	cout << "Input size" << endl;
	cin >> N;
	vect object(N);
	object.input();
	object.print();
	object.reshala();

	cout << endl;

	object.print();

	cout << endl;

	cout << "Reshenie cherez main" << endl;

	int N1;
	cout << "Input size" << endl;
	cin >> N1;
	vect obj(N1);
	obj.input();
	obj.print();

	if (N1 % 2 == 0)
	{

		double min = obj.get(0);
		int flag = 0;
		int flag1 = 0;
		int flag2 = 0;

		for (int i = 0; i < N1; i++)
		{
			if (min > obj.get(i))
			{
				min = obj.get(i);
				flag1 = i;
			}
		}
		//cout << flag1;
		for (int i = flag1 + 1; i < N1; i++)
		{
			if (min == obj.get(i))
			{
				flag2 = i;

			}
		}
		//cout << flag2;
		if (flag2 != 0)
		{
			cout << "Min elem in 1 and 2 (or center) part" << endl;
		}
		else
		{
			double min = obj.get(0);
			for (int i = 0; i < N1; i++)
			{
				if (min > obj.get(i))
				{
					min = obj.get(i);
					flag = i;
				}
			}
			//cout << flag;

			if (flag > ((N1 / 2) - 1))
			{
				for (int j = N1 / 2; j < N1; j++)
				{
					int num = j;
					for (int l = j + 1; l < N1; l++)
					{
						if (obj.get(num) > obj.get(l))
						{
							num = l;
						}
					}
					double temp = obj.get(j);
					obj.set(j, obj.get(num));
					obj.set(num, temp);
				}
			}
			else
			{
				int i = 0;
				int j = (N1 / 2) - 1;
				while (i < j)
				{
					double klon = obj.get(i);
					obj.set(i, obj.get(j));
					obj.set(j, klon);
					i = i + 1;
					j = j - 1;
				}
			}
		}
	}
	else
	{
		double kol = (double)N1 / 2;
		kol = kol - 0.5;
		//cout << kol;
		//double elem = size - kol;

		double min = obj.get(0);
		int flag = 0;
		int flag1 = 0;
		int flag2 = 0;

		for (int i = 0; i < N1; i++)
		{
			if (min > obj.get(i))
			{
				min = obj.get(i);
				flag1 = i;
			}
		}
		for (int i = flag1 + 1; i < N1; i++)
		{
			if (min == obj.get(i))
			{
				flag2 = i;
			}
		}
		if (flag2 != 0)
		{
			cout << "Min elem in 1 and 2 (or center) part" << endl;
		}
		else
		{
			double min = obj.get(0);
			for (int i = 0; i < N1; i++)
			{
				if (min > obj.get(i))
				{
					min = obj.get(i);
					flag = i;
				}
			}

			if (flag > kol)
			{
				for (int j = kol + 1; j < N1; j++)
				{
					int num = j;
					for (int l = j + 1; l < N1; l++)
					{
						if (obj.get(num) > obj.get(l))
						{
							num = l;
						}
					}
					double temp = obj.get(j);
					obj.set(j, obj.get(num));
					obj.set(num, temp);
				}
			}
			else if (flag < kol)
			{
				double kol = (double)N1 / 2;
				kol = kol - 0.5;
				int i = 0;
				int j = kol - 1;
				while (i < j)
				{
					double klon = obj.get(i);
					obj.set(i, obj.get(j));
					obj.set(j, klon);
					i = i + 1;
					j = j - 1;
				}
			}
			else if (flag == kol)
			{
				cout << endl;
				cout << "Min elem in center" << endl;
			}
		}
	}

	cout << endl;
	obj.print();
}