# Create Random1.h file directly
cat > Random1.h << 'EOF'
#ifndef RANDOM1_H
#define RANDOM1_H

#include <random>
#include <cmath>

static std::mt19937 generator(std::random_device{}());
static std::uniform_real_distribution<double> uniform_dist(0.0, 1.0);

double GetOneRandomBySystemTime() {
    return uniform_dist(generator);
}

double GetOneGaussianByBoxMuller() {
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

#endif
EOF
