#include &lt;iostream&gt;
#include &lt;vector&gt;
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int g[n][100];     
    int w[n][100];   
    int deg[n] = {0};  
    for(int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g[u][deg[u]] = v;
        w[u][deg[u]] = weight;
        deg[u]++;
        g[v][deg[v]] = u;
        w[v][deg[v]] = weight;
        deg[v]++;
    }
    for(int i = 0; i < n; i++) {
        cout << i << ": ";
        for(int j = 0; j < deg[i]; j++) {
            cout << g[i][j] << "(" << w[i][j] << ") ";
        }
        cout << endl;
    }
    return 0;
               }
