#include <iostream>
using namespace std;
 int main()
  {
    int n;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; i++)
        cin >> h[i];
    buildHeap(h, n);
    for(int i = 0; i < n; i++)
        cout << h[i] << " ";
}
void heapify(int h[], int n, int i)
     {
    int k = i, v = h[i];
    bool heap = false;
    while(!heap && (2*k + 1) < n)
  {
     int j = 2*k + 1;
        if(j + 1 < n && h[j] < h[j+1])
            j++;
        if(v >= h[j])
            heap = true;
        else {
            h[k] = h[j];
            k = j;
        }
    }
    h[k] = v;
}
void buildHeap(int h[], int n)
     {
    for(int i = n/2; i >= 0; i--)
        heapify(h, n, i);
     }
