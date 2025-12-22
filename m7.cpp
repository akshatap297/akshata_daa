// Algorithm: Greedy Scheduling + BFS | Data Structures: Array, Queue, Fenwick Tree
#include <iostream>
using namespace std;

int timeSlot[25];     // 0 = peak, 1 = off-peak
int BIT[25];          // Fenwick Tree
int q[20];
int front = 0, rear = -1;

/* Fenwick Tree functions */
void update(int i, int val)
{
    while (i <= 24)
    {
        BIT[i] += val;
        i += (i & -i);
    }
}

int getSum(int i)
{
    int s = 0;
    while (i > 0)
    {
        s += BIT[i];
        i -= (i & -i);
    }
    return s;
}

/* Queue operations */
void enqueue(int x)
{
    q[++rear] = x;
}

int dequeue()
{
    return q[front++];
}

int main()
{
    int vehicles;

    cout << "Enter number of industrial vehicles: ";
    cin >> vehicles;

    cout << "Enter 24 time slots (0 = peak, 1 = off-peak):\n";
    for (int i = 1; i <= 24; i++)
    {
        cin >> timeSlot[i];
        if (timeSlot[i] == 1)
            update(i, 1);
    }

    for (int i = 1; i <= vehicles; i++)
        enqueue(i);

    cout << "\nVehicle Scheduling:\n";

    while (front <= rear)
    {
        int v = dequeue();

        for (int t = 1; t <= 24; t++)
        {
            if (getSum(t) - getSum(t - 1) == 1)
            {
                cout << "Vehicle " << v << " allowed at hour " << t << endl;
                update(t, -1);
                break;
            }
        }
    }

    cout << "\nAll industrial vehicles scheduled during off-peak hours.\n";
    return 0;
}
