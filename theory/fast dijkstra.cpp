#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

const int INF = 2009000999;
int n;
vector<vector<pair<int, int>>> g;
vector<int> dist, par;
vector<char> used;

void dijkstra(int s) {
	dist[s] = 0;
	set<pair<int, int>> q;
	q.insert({ 0, s });
	for (int i = 0; i < n - 1; i++) {
		if (q.empty())
			break;
		int mni = q.begin()->second;
		q.erase(q.begin());
		used[mni] = 1;
		for (auto [to, len] : g[mni])
			if (dist[to] > dist[mni] + len) {
				if (dist[to] != INF)
					q.erase(q.find({ dist[to], to }));
				dist[to] = dist[mni] + len;
				par[to] = mni;
				q.insert({ dist[to], to });
			}
	}
}

void return_path(int f, vector<int>& path) {
	path.clear();
	while (f != -1) {
		path.push_back(f);
		f = par[f];
	}
	reverse(path.begin(), path.end());
}

int main() {
	int s, m;
	cin >> n >> m >> s;
	g.resize(n);
	dist.resize(n, INF);
	par.resize(n, -1);
	used.resize(n, 0);
	for (int i = 0; i < m; i++) {
		int a, b, len;
		cin >> a >> b >> len;
		g[a].push_back({ b, len });
		g[b].push_back({ a, len });
	}
	dijkstra(s);
	for (int d : dist)
		cout << d << " ";
}
