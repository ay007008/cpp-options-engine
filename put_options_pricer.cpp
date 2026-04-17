#include <iostream>
#include <cmath>
#include <random>

using namespace std;

// Box-Muller transform 
double GetOneGaussianByBoxMuller() {
    static mt19937 generator(random_device{}());
    static uniform_real_distribution<double> uniform_dist(0.0, 1.0);
    static bool has_spare = false;
    static double spare;

    if (has_spare) {
        has_spare = false;
        return spare;
    }

    has_spare = true;
    double u, v, mag;
    do {
        u = uniform_dist(generator) * 2.0 - 1.0;
        v = uniform_dist(generator) * 2.0 - 1.0;
        mag = u * u + v * v;
    } while (mag >= 1.0 || mag == 0.0);

    mag = sqrt(-2.0 * log(mag) / mag);
    spare = v * mag;
    return u * mag;
}

double SimpleMonteCarloPut(double Expiry, double Strike, double Spot, 
                          double Vol, double r, unsigned long NumberOfPaths) {

    double variance = Vol * Vol * Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = Spot * exp(r * Expiry + itoCorrection);

    double thisSpot;
    double runningSum = 0;

    for (unsigned long i = 0; i < NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);

        // PUT PAYOFF: max(Strike - Spot, 0)
        double thisPayoff = Strike - thisSpot;
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;

        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiry);
    return mean;
}

#ifndef RUNNING_TESTS
int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "Enter expiry: ";
    cin >> Expiry;

    cout << "Enter strike: ";
    cin >> Strike;

    cout << "Enter spot: ";
    cin >> Spot;

    cout << "Enter vol: ";
    cin >> Vol;

    cout << "Enter r: ";
    cin >> r;

    cout << "Number of paths: ";
    cin >> NumberOfPaths;

    double result = SimpleMonteCarloPut(Expiry, Strike, Spot, Vol, r, NumberOfPaths);

    cout << "\nThe put price is: $" << result << endl;

    return 0;
}
#endif
