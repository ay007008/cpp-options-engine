## 🎓 Unique Mathematical Edge
*   **Full Proof:** The complete derivation is available here: ON SUBSTACL (https://substack.com/@ayomideakinola1?utm_source=share&utm_medium=android&r=5xlptl)
CD Capitals: High-Performance Options Engine


A specialized quantitative library focused on the pricing of European Put Options using a high-performance Monte Carlo simulation framework. The core of this engine is built upon a custom mathematical derivation of asset price dynamics, optimized for computational efficiency.
🎓 Unique Mathematical Edge: Maclaurin SDE Expansion
This engine distinguishes itself from standard Black-Scholes implementations by utilizing a proprietary derivation for asset price paths.
Custom Methodology: I have derived the asset path dynamics using a Maclaurin series expansion of the Ito Stochastic Differential Equation (SDE). This approach is designed to enhance the discretization accuracy of Geometric Brownian Motion (GBM) within the simulation loop.
Mathematical Proof: The complete derivation, outlining the expansion from first principles to the final algorithmic implementation, is available in the documentation: Docs/maclaurin_sde_paper.docx



 Engine Architecture
Language: C++17
Pricing Model: Stochastic Monte Carlo Simulation.
Statistical Sampling: High-precision Box-Muller Transform for generating standard normal distributions.
Robustness: Integrated with Google Test (GTest) to ensure mathematical integrity across:
Put-Call Parity consistency.
Extreme Moneyness (Deep ITM/OTM) stability.
Time Decay (Theta) directional accuracy.
Distribution Convergence of the Gaussian generator.
🚀 Installation & Usage
Prerequisites
Compiler: g++ (GCC 9 or higher)
Dependencies: libgtest-dev (for unit testing)

Building the Pricer
To compile the production version of the engine:
g++ -O3 put_options_pricer.cpp -o options_engine

Running Unit Tests
To execute the validation suite:
g++ -std=c++17 -DRUNNING_TESTS put_options_pricer.cpp test_pricer.cpp -lgtest -lgtest_main -lpthread -o test_runner
./test_runner


