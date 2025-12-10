#include &lt;
 iostream&gt;
using namespace std;

 int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++)
        cin >> A[i];
    mergeSort(A, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}
void mergeArray(int A[], int l, int mid, int r)
 {
 int p = mid - l + 1;   
    int q = r - mid;         
 int B[p], C[q];          
 // Copy A[l..mid] → B[]
    for(int i = 0; i < p; i++)
        B[i] = A[l + i];
 // Copy A[mid+1..r] → C[]
    for(int j = 0; j < q; j++)
        C[j] = A[mid + 1 + j];
 int i = 0, j = 0, k = l;
 // Merge (DESCENDING ORDER)
    while(i < p && j < q)
             {
        if(B[i] >= C[j])
     {
       A[k] = B[i];
            i++;
        } 
     else
     {
     A[k] = C[j];
            j++;
     }
        k++;
  } // Remaining elements
    while(i < p)
        A[k++] = B[i++];
    
    while(j < q)
        A[k++] = C[j++];
}
void mergeSort(int A[], int l, int r) {
    if(l < r) {
        int mid = (l + r) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, r);
        mergeArray(A, l, mid, r);
    }
}
</pre>

<pre id="codeHeap" class="hidden-code">
#include &lt;iostream&gt;
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
