#include <iostream>
#include <vector>
using namespace std;

template <class T>
void print(T mas)
{
	cout << endl;
	for (auto i = mas.begin(); i < mas.end(); i++)
		cout << *i <<" ";
	cout << endl;
}

template <class T>
void create(vector<T>& mas,int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		T test;
		cin >> test;
		mas.push_back(test);
	}
	cout << endl;
}

template <class T>
void replace(vector<T>& mas1, vector<T>& mas2)
{
	int n = mas1.size();
	for (int i = 0; i<n; i++)
		mas1.insert(mas1.begin()+i*2+1, mas2[i]);
}

int main()
{
	int n;
	cout << "Size" << endl;
	cin >> n;

	vector<double> vec1;
	create(vec1,n);
	print(vec1);

	vector<double> vec2;
	create(vec2, n);
	print(vec2);

	replace(vec1, vec2);
	print(vec1);
}
