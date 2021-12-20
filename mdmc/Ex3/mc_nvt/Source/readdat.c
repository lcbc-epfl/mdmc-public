#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "system.h"
#include <time.h>
#include "ran_uniform.h"

void ReadInputData(void)
{
  int Ibeg,i;
  double Boxf,Rhof,Rho;
  FILE *FilePtr;

  FilePtr=fopen("input","r");
  fscanf(FilePtr,"%*s %*s %*s %*s\n");
  fscanf(FilePtr,"%d %d %d %d",&Ibeg,&NumberOfEquilibrationCycles,&NumberOfProductionCycles,&SamplingFrequency);
  fscanf(FilePtr,"%*s\n");
  fscanf(FilePtr,"%lf\n",&MaximumDisplacement);
  fscanf(FilePtr,"%*s\n");
  fscanf(FilePtr,"%d\n",&NumberOfDisplacementsPerCycle);
  fscanf(FilePtr,"%*s %*s %*s\n");
  fscanf(FilePtr,"%d %lf %lf\n",&NumberOfParticles,&Temp,&Rho);
  fscanf(FilePtr,"%*s %*s %*s %*s\n");
  fscanf(FilePtr,"%lf %lf %lf %lf\n",&Epsilon,&Sigma,&Mass,&CutOff);
  fclose(FilePtr);

  // initialize the random number generator with the system time
  InitializeRandomNumberGenerator(time(0l));

  if(NumberOfParticles>Npmax)
  {
    printf("Error: number of particles too large\n");
    exit(1);
  }

  Box=pow(NumberOfParticles/Rho,1.0/3.0);

  // read/generate configuration
  if(Ibeg==0)
  {
    // generate configuration from lattice
    Lattice();
  }
  else
  {
    printf(" Read confs from disk\n");
    FilePtr=fopen("restart.dat","r");
    fscanf(FilePtr,"%lf\n",&Boxf);
    fscanf(FilePtr,"%d\n",&NumberOfParticles);
    fscanf(FilePtr,"%lf\n",&MaximumDisplacement);
    Rhof=NumberOfParticles/CUBE(Boxf);
    if(fabs(Boxf-Box)>1.0e-6)
      printf("%lf %lf\n",Rho,Rhof);
    for(i=0;i<NumberOfParticles;i++)
    {
      fscanf(FilePtr,"%lf %lf %lf\n",&Positions[i].x,&Positions[i].y,&Positions[i].z);
      Positions[i].x*=Box/Boxf;
      Positions[i].y*=Box/Boxf;
      Positions[i].z*=Box/Boxf;
    }
    fclose(FilePtr);
  }

  // write input data

  printf("  Number Of Equilibration Cycles             : %d\n",NumberOfEquilibrationCycles);
  printf("  Number Of Production Cycles                : %d\n",NumberOfProductionCycles);
  printf("  Sample Frequency                           : %d\n",SamplingFrequency);
  printf("  Number Of Att. To Displ. A Part. Per Cycle : %d\n",NumberOfDisplacementsPerCycle);
  printf("  Maximum Displacement                       : %lf\n",MaximumDisplacement);
  printf("  Number Of Particles                        : %d\n",NumberOfParticles);
  printf("  Temperature                                : %lf\n",Temp);
  printf("  Density                                    : %lf\n",Rho);
  printf("  Box Length                                 : %lf\n",Box);
  printf("  Model Parameters\n");
  printf("    Sigma                                    : %lf\n",Sigma);
  printf("    Epsilon                                  : %lf\n",Epsilon);
  printf("    Mass                                     : %lf\n",Mass);
  printf("    CutOff                                   : %lf\n",CutOff);

  // calculate parameters:
  Beta=1.0/Temp;
      
  // calculate Cut-off radius potential

  CutOff=MIN(CutOff,0.5*Box);
}
