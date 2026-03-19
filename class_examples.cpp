#include <iostream>
#include <string>
class Person{
      private:
        std::string first;
        std::string last;


      public:
       
       void printFullName() { std::cout << first <<" "<< last << std::endl; }
};

int main(){
    Person p;
    p.first = "caleb";
    p.last = "curry";

    p.printFullName();
    return 0;
}


     
