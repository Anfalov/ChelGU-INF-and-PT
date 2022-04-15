#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n), v2(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
		cin >> v2[i];
	// Сравнение в лексикографическом порядке
	cout << lexicographical_compare(v.begin(), v.end(),
		v2.begin(), v2.end()) << endl;
	// Является ли один набор перестановкой другого
	cout << is_permutation(v.begin(), v.end(), v2.begin())
		<< endl;
	// Чтобы перебрать все перестановки, необходимо вначале
	// отсортировать контейнер
	sort(v.begin(), v.end());
	do {
		for (int e : v)
			cout << e << " ";
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));
	// следующая перестановка:
	// next_permutation - изменяет контейнер, переставляя
	// его элементы в лексикографически следующую перестановку
	// возвращает true, если переход был выполнен к след.
	// перестановке, и false - если переход был произведён
	// от последней к первой
	// чтобы взять следующую перестановку от конкретной
	// сортировать ничего не нужно!!!
	// prev_permutation - предыдущая перестановка
}
