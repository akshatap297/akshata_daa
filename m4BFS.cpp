#include <iostream>
using namespace std;
bool bfs(int m[10][10], int n, int source, int target) 
{
    int queue[20];
    int front = 0, rear = 0;
    int visited[10] = {0};
    queue[rear++] = source;
    visited[source] = 1;
    while (front < rear)
        {
        int u = queue[front++];
        if (u == target) return true;

        for (int v = 0; v < n; v++)
            {
            if (m[u][v] == 1 && !visited[v]) 
            {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    return false;
}

int main() 
{
    int n = 5;
    int m[10][10] =
    {
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {1,1,1,0,0}
    };

    int source, target;
    cin >> source >> target;

    if (bfs(m, n, source, target))
        cout << "Lane reachable";
    else
        cout << "Lane blocked";

    return 0;
}
