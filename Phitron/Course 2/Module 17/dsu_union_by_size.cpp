#include <bits/stdc++.h>
using namespace std;

vector<int> parent(1000, -1);
vector<int> parentSize(1000, 1);
vector<int> parentLevel(1000, 0);

int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }

    return node;
}

void dsu_union_by_size(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

void union_by_level(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (parentLevel[leaderA] > parentLevel[leaderB])
    {
        parent[leaderB] = leaderA;
    }
    else if (parentLevel[leaderB] > parentLevel[leaderA])
    {
        parent[leaderB] = leaderA;
        parentLevel[leaderA]++;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
    }

    return 0;
}