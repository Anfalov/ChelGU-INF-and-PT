#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int INF = 1e9;
int n;
vector<vector<pair<int, int>>> g;
vector<int>dist, par;
vector<char>used;
void dijkstra(int s)
{
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int mn = INF, mni = -1;
        for(int j=0; j<n; j++)
            if (!used[j] && dist[j] < mn)
            {
                mn = dist[j];
                mni = j;
            }
        if (mn == INF)
            break;
        used[mni] = 1;
        for (auto [to, len] : g[mni])
        {
            if (dist[to] > dist[mni] + len)
            {
                dist[to] = dist[mni] + len;
                par[to] = mni;
            }
        }
    }
}
void return_path(int f, vector<int>& path)
{
    path.clear();
    while (f != -1)
    {
        path.push_back(f);
        f = par[f];

    }
    reverse(path.begin(), path.end());
}
int main()
{
    int s, f;
    cin >> n>>s >> f;
    g.resize(n);
    dist.resize(n, INF);
    par.resize(n, -1);
    used.resize(n, 0);
    for(int i=0; i<n; i++)
        for (int j = 0; j < n; j++)
        {
            int len;
            cin >> len;
            if (len != -1)
                g[i].push_back({ j, len });
        }
    s--; f--;
    dijkstra(s);
    if (dist[f] == INF)
        cout << -1;
    else
    { 
        vector<int>path;
        return_path(f, path);
        for (int p : path)
            cout << p + 1 << " ";
    }
      
}
