#include <iostream>
using namespace std;

int main() {
    double c;

    cout << "Enter the value of C" << endl;
    cin >> c;

    double farenheitTemp = (1.8 * c) + 32;

    cout << "The temperature in Farenheit is: " << farenheitTemp << endl;


    return 0;
}

