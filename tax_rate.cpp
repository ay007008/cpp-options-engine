#include <iostream>
using namespace  std;

int main() {
       double sales = 95000;
       const double stateTaxRate = .04;
       const double countyTaxRate = .02;

       double stateTax = sales * stateTaxRate;
       cout << "StateTax = $" << stateTax << endl;


       double countyTax = sales * countyTaxRate;
       cout << "CountyTax = $" << countyTax << endl;

       return 0;
}
