#include &lt;iostream&gt;
#include &lt;unordered_map&gt;
using namespace std;
int main() {
    string num;
    cin >> num;

    if(num == "KA01EV1234")
        cout << "EV-Car";
    else if(num == "KA09AB7890")
        cout << "Petrol";
    else if(num == "KA55TR1122")
        cout << "Truck";
    else
        cout << "Unknown Vehicle";

    return 0;
}
