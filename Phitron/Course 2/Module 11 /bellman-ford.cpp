#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 10;
#define INF 1e9 + 10
vector<pair<pii, int>> graph;
int d[N];
int n, m;

void bellman_ford(int src)
{
    for (int i = 1; i <= n; ++i)
    {
        d[i] = INF;
    }

    d[src] = 0;
    /// relaxation edges for n - 1 times
    for (int i = 1; i < n; ++i)
    {
        for (auto edge : graph)
        {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;

            if (d[u] != INF && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({{u, v}, w});
    }

    bellman_ford(1);
    for (int i = 1; i <= n; ++i)
    {
        cout << d[i] << ' ';
    }

    return 0;
}