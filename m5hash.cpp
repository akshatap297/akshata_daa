#include &lt;iostream&gt;
#include &lt;unordered_map&gt;
using namespace std;
int main() {
    string roads[] = {"RoadA", "RoadB"};
    int severity[] = {4, 2};

    for(int i = 0; i < 2; i++)
        cout << roads[i] << " = " << severity[i] << endl;
}
