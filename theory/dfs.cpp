#include<vector>
#include<iostream>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<char> used;

void dfs(int v)
{
	used[v] = 1;
	for (int to : g[v])
		if (!used[to])
			dfs(to);
}

int main()
{
	cin >> n >> m;
	g.resize(n);
	used.resize(n, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int s, f;
	cin >> s >> f;
	s--; f--;
	dfs(s);
	if (used[f])
		cout << "We have path from " << s + 1 << " to " << f + 1 << endl;
	else
		cout << "We have not path from " << s + 1 << " to " << f + 1 << endl;
}
