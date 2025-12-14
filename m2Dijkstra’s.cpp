#include <iostream>
using namespace std;
#define MAXN 100
#define INF 1e9

int main() {
    int n, m;
    cin >> n >> m;
    int cost[MAXN][MAXN];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = INF;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
        cost[v][u] = w; 
    }
    int source;
    cin >> source;
    int dist[MAXN];
    int visited[MAXN] = {0};
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[source] = 0;  
    for (int count = 0; count < n; count++)
        {
        int u = -1;
        int minDist = INF; 
        for (int i = 0; i < n; i++)
            {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) 
          break; 
        visited[u] = 1;
        for (int v = 0; v < n; v++) 
        {
            if (!visited[v] && cost[u][v] != INF)
            {
                if (dist[u] + cost[u][v] < dist[v])
                    dist[v] = dist[u] + cost[u][v];
            }
        }
    }   
    for (int i = 0; i < n; i++)
        cout << "Distance to " << i << ": " << dist[i] << endl;
    return 0;
}
