#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& e : v)
		cin >> e;
	sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
}
