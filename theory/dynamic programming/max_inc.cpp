#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*#Для  заданного массива A[1..N]  найти   длину  M максимального
#подмассива со  строго возрастающими значениями в порядке
#возрастания индексов.

1 3 3 5 7 2 4 -> 3 (3, 5, 7)*/
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& e : v)
		cin >> e;

	int mx_len = 0, len = 1;
	for (int i = 1; i < n; i++)
		if (v[i] > v[i - 1]) {
			len++;
			mx_len = max(mx_len, len);
		}
		else
			len = 1;
	cout << mx_len << endl;

	vector<int> dp(n, 1);
	for (int i = 1; i < n; i++)
		if (v[i] > v[i - 1])
			dp[i] = dp[i - 1] + 1;
	cout << *max_element(dp.begin(), dp.end()) << endl;
}
