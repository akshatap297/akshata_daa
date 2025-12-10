#include &lt;iostream&gt;
#include &lt;queue&gt;
using namespace std;
int main() {
    int s[3] = {5, 2, 8};
    string l[3] = {"Lane1", "Lane2", "Lane3"};
    int max = 0;
    for(int i = 1; i < 3; i++)
        if(s[i] > s[max])
            max = i;
    cout << "Most severe: " << l[max] << endl;
}
