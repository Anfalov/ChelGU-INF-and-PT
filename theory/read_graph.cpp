#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{  
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		//g[b].push_back(a);
	}
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << g[i].size() << " ";
		sort(g[i].begin(), g[i].end());
		for (int x : g[i])
			cout << x + 1 << " ";
		cout << endl;
	}

}
