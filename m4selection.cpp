#include &lt;iostream&gt;
using namespace std;
int main()
 {
    int a[5] = {30,10,50,20,40}, n=5;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[j]<a[i]) 
                  swap(a[i],a[j]);
    for(int i=0;i<n;i++)
                  cout<<a[i]<<" ";
}
