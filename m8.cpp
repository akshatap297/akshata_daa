#include <iostream>
using namespace std;

int parent[20];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void merge(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int n, e;
    int u[20], v[20], w[20];

    cout << "Enter number of locations: ";
    cin >> n;

    cout << "Enter number of corridors: ";
    cin >> e;

    cout << "Enter source destination cost:\n";
    for (int i = 0; i < e; i++)
        cin >> u[i] >> v[i] >> w[i];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int count = 0;
    int total = 0;

    cout << "\nSelected corridors:\n";

    while (count < n - 1)
    {
        int min = 9999;
        int a = -1, b = -1, k = -1;

        for (int i = 0; i < e; i++)
        {
            if (w[i] < min)
            {
                min = w[i];
                a = u[i];
                b = v[i];
                k = i;
            }
        }

        int x = find(a);
        int y = find(b);

        if (x != y)
        {
            cout << a << " - " << b << "  cost = " << min << endl;
            total += min;
            merge(x, y);
            count++;
        }

        w[k] = 9999;
    }

    cout << "\nMinimum construction cost = " << total << endl;

    return 0;
}
