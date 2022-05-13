#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define INF 1000000000

int n;
vector<vector<int>> dist;

bool check(int ni, int nj)
{
	return ni >= 0 && nj >= 0 && ni < n && nj < n;
}

vector<pair<int, int>> neigh(int i, int j)
{
	vector<pair<int, int>> res, steps = { {1, 2}, {2, 1},
	{-1, -2}, {-2, -1}, {1, -2}, {-1, 2}, {2, -1}, {-2, 1} };
	for (auto step : steps)
		if (check(i + step.first, j + step.second))
			res.push_back({ i + step.first, j + step.second });
	return res;
}

void bfs(int si, int sj) {
	queue<pair<int, int>> q;
	q.push({ si, sj });
	dist[si][sj] = 0;
	while (q.size()) {
		auto [vi, vj] = q.front();
		q.pop();
		for (auto [toi, toj]: neigh(vi, vj))
			if (dist[toi][toj] == INF) {
				dist[toi][toj] =
					dist[vi][vj] + 1;
				q.push({ toi, toj });
			}
	}
}
int main() {
	cin >> n;
	dist.resize(n, vector<int>(n, INF));
	int si, sj, fi, fj;
	cin >> si >> sj >> fi >> fj;
	si--; sj--;
	fi--; fj--;
	bfs(si, sj);
	cout << dist[fi][fj];
}
