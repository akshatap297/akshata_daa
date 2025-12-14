#include <iostream>
#include <string.h>
using namespace std;
 int main() {
    string plate;
    cin >> plate;
  
    if (plate == "MH09XY7777") 
        cout << "Use BYPASS\n";
    else if (plate == "KA01AB1234")
        cout << "Welcome to EV City\n";
    else
        cout << "Plate not recognized\n";
}
