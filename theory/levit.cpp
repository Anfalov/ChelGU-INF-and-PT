#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

const int INF = 2009000999;
int n;
vector<vector<pair<int, int>>> g;
vector<int> dist;
vector<char> used;

void bfs(int s)
{
	deque<int> q;
	q.push_back(s);
	dist[s] = 0;
	while (q.size())
	{
		int v = q.front();
		q.pop_front();
		used[v] = 2;
		for (auto [to, len] : g[v])
			if (dist[to] > dist[v] + len) {
				dist[to] = dist[v] + len;
				if (used[to] == 0)
					q.push_back(to);
				else if (used[to] == 2)
					q.push_front(to);
				used[to] = 1;

			}
	}
}

int main() {
	int s, m;
	cin >> n >> m >> s;
	g.resize(n);
	dist.resize(n, INF);
	used.resize(n, 0);
	for (int i = 0; i < m; i++) {
		int a, b, len;
		cin >> a >> b >> len;
		g[a].push_back({ b, len });
		g[b].push_back({ a, len });
	}
	bfs(s);
	for (int d : dist)
		cout << d << " ";
}
