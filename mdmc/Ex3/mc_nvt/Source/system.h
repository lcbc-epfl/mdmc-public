#include <stdio.h>
#define Npmax 10000

#define SQR(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define MIN(x,y) ((x)<(y)?(x):(y))

enum{EQUILIBRATION=1,PRODUCTION=2};

typedef struct
{
  double x;
  double y;
  double z;
} VECTOR;

extern double Box;    // Simulation Box Length
extern double Temp;   // Temperature
extern double Beta;   // 1/Temp

extern VECTOR Positions[Npmax];
extern int NumberOfParticles;

extern double Epsilon;   // Epsilon
extern double Sigma;     // Sigma*Sigma
extern double Mass;      // Mass Of The Molecules
extern double CutOff;    // Cut-Off Radius Of The Potenial

extern double TotalEnergy;
extern double TotalVirial;

extern double RunningEnergy;
extern double RunningVirial;

extern int NumberOfAttempts;       // number of attemps that have been performed to displace a particle
extern int NumberOfAcceptedMoves;  // number of successful attemps to displace a particle
extern double MaximumDisplacement; // maximum displacement

extern int NumberOfEquilibrationCycles;
extern int NumberOfProductionCycles;
extern int SamplingFrequency;
extern int NumberOfDisplacementsPerCycle;

void Adjust(void);
void ReadInputData(void);
void Mcmove(void);

void EnergyParticle(VECTOR pos,int i,int j,double *En,double *Vir);
void EnergySystem(void);

void Sample(int i,double En,double Vir,double *Pressure,FILE *FilePtr);
void WritePdb(FILE *FilePtr);
void Store(void);
void Lattice(void);
