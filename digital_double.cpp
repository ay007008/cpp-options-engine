//Header files and Namespace
#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std ;
//Random Number Generator(Box-Muller Transform)
double GetOneGaussianByBoxMuller() {
       static mt19937 generator (random_device{}());
       static real_uniform_distribution<double> uniform dist(0.0,1.0);
       static bool has_spare = false;
       static double spare ;


       if (has_spare) {
          has_spare = false;
          return spare;
}

      has_spare = true;
      double u,v,mag;
      do {
          u = uniform_dist(generator) * 2.0 - 1.0;
          v = uniform_dist(generator) * 2.0 - 1.0;
          mag = u * u + v * v;

      }while (mag >= 1.0 || mag == 0.0);
}

       mag = sqrt(-2.0 * log(mag) / mag);
       spare = v * mag;
       return u * mag;
}
