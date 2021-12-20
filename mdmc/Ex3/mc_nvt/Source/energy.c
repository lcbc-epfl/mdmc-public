#include <math.h>
#include "system.h"


// calculates the energy of particle i with particles j=jb,NumberOfparticles
void EnergyParticle(VECTOR pos,int i,int jb,double *En,double *Vir)
{
  double r2,Virij,Enij;
  double r2i,r6i;
  VECTOR dr;
  int j;

  Enij=Virij=0.0;
  for(j=jb;j<NumberOfParticles;j++)
  {
    if (j!=i)
    {
      dr.x=pos.x-Positions[j].x;
      dr.y=pos.y-Positions[j].y;
      dr.z=pos.z-Positions[j].z;

      // apply boundary conditions
      dr.x-=Box*rint(dr.x/Box);
      dr.y-=Box*rint(dr.y/Box);
      dr.z-=Box*rint(dr.z/Box);

      r2=SQR(dr.x)+SQR(dr.y)+SQR(dr.z);

      // calculate the energy
      if(r2<SQR(CutOff))
      {
        r2i=SQR(Sigma)/r2;
        r6i=CUBE(r2i);
        Enij+=4.0*Epsilon*(SQR(r6i)-r6i);

        // start modification virial
          Virij+=48.0*Epsilon*(SQR(r6i)-0.5*r6i);
        // end modification virial
      }
    }
  }
  *En=Enij;
  *Vir=Virij;
}

// calculates total system energy
void EnergySystem(void)
{
  double Eni,Viri;
  int i;

  TotalEnergy=0.0;
  TotalVirial=0.0;
  for(i=0;i<NumberOfParticles-1;i++)
  {
    EnergyParticle(Positions[i],i,i+1,&Eni,&Viri);
    TotalEnergy+=Eni;
    TotalVirial+=Viri;
  }

  // add tail-correction
  TotalEnergy+=NumberOfParticles*(8.0/3.0)*M_PI*(NumberOfParticles/CUBE(Box))*
        ((1.0/3.0)*pow(1.0/CutOff,9)-pow(1.0/CutOff,3));
}

