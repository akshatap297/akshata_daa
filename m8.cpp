// Algorithm: Kruskal’s (Minimum Spanning Tree) | Data Structures: Graph, Array, Disjoint Set
#include <iostream>
using namespace std;

int parent[20];

int findSet(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int n, e;
    int u[20], v[20], cost[20];

    cout << "Enter number of industrial locations: ";
    cin >> n;

    cout << "Enter number of possible corridors: ";
    cin >> e;

    cout << "Enter source destination and construction cost:\n";
    for (int i = 0; i < e; i++)
        cin >> u[i] >> v[i] >> cost[i];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int edgesUsed = 0;
    int totalCost = 0;

    cout << "\nDedicated Industrial Transport Corridors:\n";

    while (edgesUsed < n - 1)
    {
        int min = 9999;
        int a = -1, b = -1, pos = -1;

        for (int i = 0; i < e; i++)
        {
            if (cost[i] < min)
            {
                min = cost[i];
                a = u[i];
                b = v[i];
                pos = i;
            }
        }

        int x = findSet(a);
        int y = findSet(b);

        if (x != y)
        {
            cout << a << " - " << b << "  Cost = " << min << endl;
            totalCost += min;
            unionSet(x, y);
            edgesUsed++;
        }

        cost[pos] = 9999;
    }

    cout << "\nMinimum infrastructure cost = " << totalCost << endl;
    cout << "Heavy vehicles restricted to these corridors only.\n";

    return 0;
}
