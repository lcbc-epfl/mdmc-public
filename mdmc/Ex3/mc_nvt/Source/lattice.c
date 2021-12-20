#include <math.h>
#include "system.h"


// place NumberOfParticles particles on a simple cubic
// lattice with density 'Rho'
void Lattice(void)
{
  int i,j,k,Count,N;
  double Dx,Dy,Dz,spacing;

  N=(pow(NumberOfParticles,1.0/3.0))+1;
  if (N==0) N=1;
  spacing=Box/N;
  Count=0;

  Dx=0.0;
  for(i=0;i<N;i++)
  {
    Dy=0.0;
    for(j=0;j<N;j++)
    {
      Dz=0.0;
      for(k=0;k<N;k++)
      {
        if(Count<NumberOfParticles)
        {
          Positions[Count].x=Dx;
          Positions[Count].y=Dy;
          Positions[Count].z=Dz;
          Count++;
        }
        Dz+=spacing;
      }
      Dy+=spacing;
    }
    Dx+=spacing;
  }
  printf("Initialisation on a lattice: %d particles placed\n",Count);
}

