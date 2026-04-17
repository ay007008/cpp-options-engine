#include <gtest/gtest.h>
#include <cmath>

// Declare your function so the test can see it
double SimpleMonteCarloPut(double Expiry, double Strike, double Spot, 
                          double Vol, double r, unsigned long NumberOfPaths);

// 1. Extreme Moneyness: Deep Out-of-the-Money (OTM)
TEST(MonteCarloPricer, DeepOTMPut) {
    // If Spot is 200 and Strike is 50, Put should be ~0
    double price = SimpleMonteCarloPut(0.5, 50.0, 200.0, 0.2, 0.05, 100000);
    EXPECT_NEAR(price, 0.0, 0.1); 
}

// 2. Extreme Moneyness: Deep In-the-Money (ITM)
TEST(MonteCarloPricer, DeepITMPut) {
    // If Spot is 10 and Strike is 100, Put is worth ~90
    double price = SimpleMonteCarloPut(1.0, 100.0, 10.0, 0.01, 0.0, 100000);
    EXPECT_NEAR(price, 90.0, 0.5);
}

// 3. Time Decay Direction
TEST(MonteCarloPricer, TimeDecay) {
    double S = 100, K = 100, V = 0.2, r = 0.05;
    unsigned long paths = 100000;
    
    double long_time = SimpleMonteCarloPut(1.0, K, S, V, r, paths);
    double short_time = SimpleMonteCarloPut(0.1, K, S, V, r, paths);
    
    // Put price should be higher for longer duration
    EXPECT_GT(long_time, short_time);
}

// 4. Gaussian Range Check (Box-Muller)
// Since you have GetOneGaussianByBoxMuller available:
extern double GetOneGaussianByBoxMuller();
TEST(MathHelpers, BoxMullerDistribution) {
    double sum = 0;
    for(int i=0; i<1000; i++) sum += GetOneGaussianByBoxMuller();
    double mean = sum / 1000.0;
    // Mean of Standard Normal should be close to 0
    EXPECT_NEAR(mean, 0.0, 0.5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
