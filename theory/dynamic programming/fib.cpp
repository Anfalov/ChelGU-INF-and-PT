#include<vector>
#include <iostream>
#include <algorithm>

using namespace std;

// "Тупое" рекурсивное решение
int fib_rec(int n) {
	if (n < 2)
		return n;
	return fib_rec(n - 1) + fib_rec(n - 2);
}

// Ленивая динамика (Нисходящее ДП)
vector<int> f(30, -1);
int fib(int n) {
	if (f[n] == -1)
		f[n] = fib(n - 1) + fib(n - 2);
	return f[n];
}

int main()
{
	cout << fib_rec(6) << " ";
	f[0] = 0;
	f[1] = 1;
	cout << fib(6) << " ";

	// Восходящее ДП
	
	// Прямой порядок
	vector<int> f2(30);
	f2[0] = 0;
	f2[1] = 1;
	for (int i = 2; i <= 6; i++)
		f2[i] = f2[i - 1] + f2[i - 2];
	cout << f2[6] << " ";

	// Обратный порядок
	vector<int> f3(30);
	f3[0] = 0;
	f3[1] = 1;
	for (int i = 1; i < 6; i++) {
		f3[i + 1] += f3[i];
		f3[i + 2] += f3[i];
	}
	cout << f3[6] << endl;
}
