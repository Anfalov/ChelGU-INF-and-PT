#include<iostream>
#include<vector>

using namespace std;

int fib(int n) {
	if (n < 2)
		return n;
	return fib(n - 1) + fib(n - 2);
}

vector<int> v(100, -1);
int fib2(int n) {
	if (v[n] == -1)
		v[n] = fib2(n - 1) + fib2(n - 2);
	return v[n];
}

int main() {
	v[0] = 0;
	v[1] = 1;
	int n;
	cin >> n;
	cout << fib2(n) << endl;

	vector<int> v2(n + 1);
	v2[0] = 0;
	if (n > 0)
		v2[1] = 1;
	for (int i = 2; i <= n; i++)
		v2[i] = v2[i - 1] + v2[i - 2];
	cout << v2[n] << endl;
}
