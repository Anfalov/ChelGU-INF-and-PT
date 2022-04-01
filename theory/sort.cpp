#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

bool comp(int a, int b)//true - если первый элемент,
{ //должен стоять перед вторым
	if (a > b)
		return true;
	else
		return false;
	// return a > b;
}

// функциональный объект - объект, который можно вызвать
// как функцию, т.е. у него определён оператор вызова ()
struct myinc {
	int operator()(int& a)
	{
		a++;
		return a;
	}
};

bool comp_matr(const vector<int> &a, const vector<int>& b)
{
	return a[0] < b[0];
}

int main()
{
	int a[10];
	sort(a, a + 10);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;

	sort(v.begin(), v.end(), comp);
	sort(v.begin(), v.end(), greater<int>());
	// Имя функции без скобок - указатель на функцию
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;

	int m;
	cin >> n >> m;
	vector<vector<int>> w(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> w[i][j];
	sort(w.begin(), w.end(), comp_matr);
	stable_sort(w.begin(), w.end(), comp_matr); // гарантирует что элементы
	// (строки матрицы) с одинаковым ключом (первым элементом матрицы)
	// останутся в том же порядке друг относительно друга
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << w[i][j] << " ";
		cout << endl;
	}

	// функциональные объекты:
	myinc q;
	int e = 1;
	q(e);
	cout << e;
}
