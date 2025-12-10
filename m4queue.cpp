#include &lt;iostream&gt;
#include &lt;queue&gt;
using namespace std;
int main() {
    string cars[3] = {"KA01EV1234", "KA09AB7890", "KA55TR1122"};
    int front = 0;
    int rear = 3;
    while(front < rear) {
        cout << cars[front] << " enters lane\n";
        front++;
    }
    return 0;
}
