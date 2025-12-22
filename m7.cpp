#include <iostream>
using namespace std;

int timeSlot[24];      // 0 = peak, 1 = off-peak
int BIT[25];           // Fenwick Tree
int queue[20];
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

int query(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}

/* Queue operations */
void enqueue(int v)
{
    queue[++rear] = v;
}

int dequeue()
{
    return queue[front++];
}

int main()
{
    int vehicles;
    cout << "Enter number of industrial vehicles: ";
    cin >> vehicles;

    cout << "Enter time slots (0 = peak, 1 = off-peak):\n";
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
        int vehicle = dequeue();

        for (int t = 1; t <= 24; t++)
        {
            if (query(t) - query(t - 1) == 1)
            {
                cout << "Vehicle " << vehicle
                     << " allowed at hour " << t << endl;
                update(t, -1);
                break;
            }
        }
    }

    cout << "\nAll vehicles scheduled during off-peak hours.\n";
    return 0;
}
