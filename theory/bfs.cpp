#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define INF 1000000000

int n, m;
vector<vector<int>> g;
vector<int> dist, par;

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (q.size())
	{
		int v = q.front();
		q.pop();
		for (int to: g[v])
			if (dist[to] == INF)
			{
				dist[to] = dist[v] + 1;
				par[to] = v;
				q.push(to);
			}
	}
}

void path(int f, vector<int>& pt)
{
	while (f != -1)
	{
		pt.push_back(f);
		f = par[f];
	}
	reverse(pt.begin(), pt.end());
}


int main()
{
	cin >> n >> m;
	g.resize(n);
	dist.resize(n, INF);
	par.resize(n, -1);
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
	bfs(s);
	for (int i = 0; i < n; i++)
		cout << i + 1 << " " << dist[i] << endl;
	vector<int> pt;
	path(f, pt);
	for (int i = 0; i < pt.size(); i++)
		cout << pt[i] + 1 << " ";
}
