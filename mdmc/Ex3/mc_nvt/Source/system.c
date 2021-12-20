#include "system.h"

double Box;    // Simulation Box Length
double Temp;   // Temperature
double Beta;   // 1/Temp

VECTOR Positions[Npmax];
int NumberOfParticles;

double TotalEnergy;
double TotalVirial;

double RunningEnergy;
double RunningVirial;

double Epsilon;   // Epsilon
double Sigma;     // Sigma
double Mass;      // Mass Of The Molecules
double CutOff;    // Cut-Off Radius Of The Potenial

int NumberOfAttempts;
int NumberOfAcceptedMoves;
double MaximumDisplacement;

int NumberOfEquilibrationCycles;
int NumberOfProductionCycles;
int SamplingFrequency;
int NumberOfDisplacementsPerCycle;

