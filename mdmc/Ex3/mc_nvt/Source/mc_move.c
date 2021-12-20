#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "system.h"
#include "ran_uniform.h"

// attempts to displace a randomly selected particle
void Mcmove(void)
{
  double EnergyNew,VirialNew,EnergyOld,VirialOld;
  VECTOR NewPosition;
  int i;
 
  NumberOfAttempts++;

  // choose a random particle
  i=NumberOfParticles*RandomNumber();

  // calculate old energy
  EnergyParticle(Positions[i],i,0,&EnergyOld,&VirialOld);

  // give a random displacement
  NewPosition.x=Positions[i].x+(RandomNumber()-0.5)*MaximumDisplacement;
  NewPosition.y=Positions[i].y+(RandomNumber()-0.5)*MaximumDisplacement;
  NewPosition.z=Positions[i].z+(RandomNumber()-0.5)*MaximumDisplacement;

  // calculate new energy
  EnergyParticle(NewPosition,i,0,&EnergyNew,&VirialNew);
         
  if(RandomNumber()<exp(-Beta*(EnergyNew-EnergyOld)))
  {
    // accept
    NumberOfAcceptedMoves++;
    RunningEnergy+=(EnergyNew-EnergyOld);
    RunningVirial+=(VirialNew-VirialOld);

    // put particle in simulation box
/*
    if(NewPosition.x<0.0)
      NewPosition.x+=Box;
    else if(NewPosition.x>=Box)
      NewPosition.x-=Box;
            
    if(NewPosition.y<0.0)
      NewPosition.y+=Box;
    else if(NewPosition.y>=Box)
      NewPosition.y-=Box;
          
    if(NewPosition.z<0.0)
      NewPosition.z+=Box;
    else if(NewPosition.z>=Box)
      NewPosition.z-=Box;
*/

   // update new position
   Positions[i].x=NewPosition.x;
   Positions[i].y=NewPosition.y;
   Positions[i].z=NewPosition.z;
  }
}
