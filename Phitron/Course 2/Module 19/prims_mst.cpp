#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 1e5 + 5;
vector<pii> graph[N];
vector<bool> visited(N, false);

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class comp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

void prims(int s)
{
    priority_queue<Edge, vector<Edge>, comp> pq;
    pq.push(Edge(s, s, 0));
    vector<Edge> edgeList;

    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int u = parent.u;
        int v = parent.v;
        int w = parent.w;

        if (visited[v])
            continue;
        visited[v] = true;
        edgeList.push_back(parent);

        for (int i = 0; i < graph[v].size(); ++i)
        {
            pii children = graph[v][i];
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    return 0;
}