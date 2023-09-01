#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
int level[N];
int visited[N];
int parents[N];

void bfs(int s)
{
    queue<int> qu;
    level[s] = 0;
    visited[s] = 1;
    parents[s] = -1;
    qu.push(s);

    while (!qu.empty())
    {
        int parent = qu.front();
        qu.pop();

        for (auto i : adjList[parent])
        {
            if (!visited[i])
                qu.push(i);
            visited[i] = true;
            level[i] = level[parent] + 1;
            parents[i] = parent;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int source, destination;
    cin >> source >> destination;

    bfs(source);
    cout << level[destination] << endl;
    vector<int> path;

    return 0;
}