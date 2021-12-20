
# Appendix: Photon C++ Program

Begin by creating a photon.cpp file and enter the following code:

``` c++
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <math.h>

using namespace std;

mt19937 mt_rand;

double random(double lower, double upper) {
    uniform_real_distribution<double> dist(lower, upper);
    return dist(mt_rand);
}

int main(int argc, char * argv []) {

  int numberOfIterations = atoi(argv[1]);
  double beta = atof(argv[2]);
  int seed = time(nullptr);
  mt_rand.seed(globalSeed); 

  int trialnj = 1;
  int currentnj = 1;
  int njsum = 0;
  int numStatesVisited = 0;

  /***** MODIFICATION *****  

  Metropolis algorithm implementation to calculate <n_j>
  Tasks:
  1) Loop from int i = 0 to numberOfiterations
  2) Call random(0, 1) to perform a trial move to randomly increase
     or decrease trialnj by 1.
     Hint: use trialnj = currentnj + 1;
  3) Test if trialnj < 0, if it is, force it to be 0
  4) Accept the trial move with probability defined in section 3.4.3
     Note: Accepting the trial move means updating current sample (currentnj)
     with the new move (trialnj);
  5) sum currentnj and increase numStatesVisited by 1

  *** END MODIFICATION ***/

  double estimatedOccupancy = (double) njsum/numStatesVisited;

  cout << "Average Occupancy: " << estimatedOccupancy << endl;
  cout << "Theoretical Value: " << ( 1 / (exp(beta) - 1)) << endl; 
  cout << "Relative Error: " << fabs((exp(beta) - 1.0) * (( sum / count ) - 
    (1.0 / (exp(beta) - 1.0))));
  return 0;
}
}
```

Here, your task is to implement the Metropolis Monte Carlo algorithm to
estimate the ensemble average of state occupancy, $\left<n_j\right>$.
The code is commented thoroughly to provide you with hints. You can call
the function `exp(x)` to calculate exponentials and the function
`random(min, max)` to create a uniformly distributed rational number
between `min` and `max`. Finally, the operators `++` and `-``-` provide
a shorthand for incrementing and decrementing a variable by 1 as
follows: `numStatesVisited++;`.

## Compiling Your `C++` Code

To compile the photon gas program, navigate your terminal focus to the
directory which contains `photon.cpp` and type the following:

    g++ -std=c++11 photon.cpp -o photon.x

This will produce an executable file called `photon.x` in your current
directory. You can execute this program using the following command-line
arguments:

    ./photon.x numberOfIterations betaValue