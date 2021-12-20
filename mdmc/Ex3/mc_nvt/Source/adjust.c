#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "system.h"

// adjusts maximum displacement such that 50% of the
// moves will be accepted
void Adjust(void)
{
  static int Attempp=0,Naccp=0;
  double Dro,Frac;

  printf("Adjusting: %d %d\n",NumberOfAttempts,NumberOfAcceptedMoves); 
  if(NumberOfAttempts==0||Attempp>=NumberOfAttempts)
  {
    Naccp=NumberOfAcceptedMoves;
    Attempp=NumberOfAttempts;
  }
  else
  {
    Frac=(double)(NumberOfAcceptedMoves-Naccp)/((double)(NumberOfAttempts-Attempp));
    Dro=MaximumDisplacement;
    MaximumDisplacement*=fabs(Frac/0.5);

    // limit the change
    if(MaximumDisplacement/Dro>1.5) MaximumDisplacement=Dro*1.5;
    if(MaximumDisplacement/Dro<0.5) MaximumDisplacement=Dro*0.5;
    if(MaximumDisplacement>Box/4.0) MaximumDisplacement=Box/4.0;
    printf(" Max. Displ. Set To : %lf\n",MaximumDisplacement);
    printf(" (Old : %lf)\n",Dro);
    printf(" Frac. Acc.: %lf\n",Frac);
    printf(" Attempts: %d\n",NumberOfAttempts - Attempp);
    printf(" Success: %d\n",NumberOfAcceptedMoves - Naccp); 
  }
}
