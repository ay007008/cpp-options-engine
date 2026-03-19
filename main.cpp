#include <iostream>
#include "divide.h"

int main() {
    try {
        double result = divide(10.0, 2.0);
        std::cout << "Result: " << result << std::endl;
        
        // This will throw an exception
        result = divide(10.0, 0.0);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
