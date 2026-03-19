#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double r;
    double pi = 3.142;

    cout << "Enter the value of the radius" << endl;
    cin >> r ;
    
    double radiusSquared = pow(r,2);
    double areaOfCircle = (pi * radiusSquared);
    cout << "The value of the area is : " << areaOfCircle << endl;

    return 0;
}
