#include <iostream>
using namespace std;

int main() {
    int flow = 0, cost = 0;

    // hardcoded simple example
    int capacity[3][3] = {
        {0, 3, 2},
        {0, 0, 2},
        {0, 0, 0}
    };

    int costMat[3][3] = {
        {0, 1, 2},
        {0, 0, 1},
        {0, 0, 0}
    };

    // send 2 units from 0 → 2 via 1
    flow = 2;
    cost = flow * (costMat[0][1] + costMat[1][2]);

    cout << "Flow = " << flow << endl;
    cout << "Cost = " << cost << endl;

    return 0;
}
