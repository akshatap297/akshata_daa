#include &lt;iostream&gt;
#include &lt;vector&gt;
#include &lt;queue&gt;
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int g[n][100];  
    int deg[n] = {0};
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][deg[u]++] = v;
        g[v][deg[v]++] = u;
    }
    int visited[n] = {0};
    int queue[1000];   
    int front = 0, rear = 0;
    int source;
    cin >> source;
   
    visited[source] = 1;
    queue[rear++] = source;
   cout << "BFS Traversal: ";
    while(front < rear) {
        int u = queue[front++];
        cout << u << " ";
        for(int i = 0; i < deg[u]; i++) {
            int v = g[u][i];
            if(!visited[v])
                          {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    return 0;
}
