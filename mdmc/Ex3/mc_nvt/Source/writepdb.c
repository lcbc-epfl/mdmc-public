#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "system.h"


void WritePdb(FILE *FilePtr)
{
  int i;
  static int Countmodel=0,Countatom=0;

  Countmodel++;

  fprintf(FilePtr,"%s\n","MODEL");

  for(i=0;i<NumberOfParticles;i++)
  {
    Countatom++;
    fprintf(FilePtr,"ATOM%7d  H%12d%8.3lf%8.3lf%8.3lf\n",
      Countatom,i,2.0*Positions[i].x,2.0*Positions[i].y,2.0*Positions[i].z);
  }
  fprintf(FilePtr,"%s\n","ENDMDL");
}

void Store(void)
{
  int i;
  FILE *FilePtr;

  FilePtr=fopen("restart.dat","w");
  fprintf(FilePtr,"%lf\n",Box);
  fprintf(FilePtr,"%d\n",NumberOfParticles);
  fprintf(FilePtr,"%lf\n",MaximumDisplacement);

  for(i=0;i<NumberOfParticles;i++)
    fprintf(FilePtr,"%lf %lf %lf\n",
      Positions[i].x,Positions[i].y,Positions[i].z);
  fclose(FilePtr);
}

