#include &lt;iostream&gt;
#include &lt;queue&gt;
using namespace std;
int main() {
    string cars[3] = {"CAR1", "CAR2", "CAR3"};
    int front = 0;  
    int rear = 3; 
while (front < rear) {
        cout << "Processing " << cars[front] << endl;
        front++;  // remove car from queue
    }

    return 0;
}
