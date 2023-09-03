#include <bits/stdc++.h>
using namespace std;

int n, e;
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

bool cmp(Edge a, Edge b)
{
    return a.w > b.w;
}

int main()
{
    cin >> n >> e;
    vector<Edge> graph;
    vector<Edge> ans;

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back(Edge(u, v, w));
    }

    sort(graph.begin(), graph.end(), cmp);

    for (Edge val : graph)
    {
    }

    return 0;
}

/*
----------
Testcase 1
----------

Input:
7 11
1 2 5
1 3 7
3 2 9
3 5 8
5 6 5
3 6 7
2 4 6
2 6 15
4 6 8
4 7 11
6 7 9

Output:
1 2 5
5 6 5
2 4 6
1 3 7
3 6 7
6 7 9

*/