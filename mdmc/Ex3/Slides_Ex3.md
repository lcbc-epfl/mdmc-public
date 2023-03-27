---
title: Exercise Session 3
subtitle: MDMC Spring 2023
date: March 28, 2023
author: "Lorenzo Agosta, Virginia Carnevali, Simon Dürr, Sophia Johnson, Nikolaos Lempesis, Andrea Levy"
output: beamer_presentation
---

# Exercise Check-In
How did you feel during the process of completing, turning in, interviewing, and receiving the comments for Ex 1?
  
**Remember: Exercises contribute to 1/2 of final grade! We count the best 5 out of the 6 reports for your exercise grade.**

# Notebooks Reminder

- Always access the notebooks via  the rocket button on the top right of the code files and choose JupyterHub to launch [noto.epfl.ch](https://noto.epfl.ch/) 
- **Make sure to access noto this way each time you begin the exercise to ensure you have the latest version!**
		![](/data/mdmc/img_slides/Ex1/notebooks.png)
        
# Exercise Structure

- Learning goals
  - Understand importance sampling
  - Learn importance of detailed balance
  - Apply the Metropolis Monte Carlo algorithm to calculate properties of a model gas  

- Chapter in script
  - Chapter 3 - Monte Carlo Simulations  

- Resources
  - Understanding Molecular Simulation, Frenkel & Smit, 2nd Edition - Chapter 3 & Chapter 5 (extra)
  - Computer Simulation of Liquids, Allen & Tildesley, 2nd Edition - Chapter 4

# Exercise 3 - Intro & Tips

Today we'll be writing and executing Monte Carlo code. 

**Tips!**

- The theoretical part is about basic Monte Carlo simulations.  \
  Be sure to know what we mean by:
  - random sampling vs importance sampling
  - configurational space
  - transition or Markov matrix
  - detailed balance
  - Metropolis algorithm
- In the practical part we will run MC code for two systems: 
  - A photon gas in which the energy states are quantized meaning we can calculate the ensemble average of state occupancy analytically
  - A gas in which we test different ensembles (NVT vs NPT) and use the Lennard-Jones potential to describe pairwise interactions

# Exercise 3 - Intro & Tips

- Photon Gas
  - You'll need to write a loop of code to define the *estimatedOccupancy* function (read the hints and ask questions)
  - NB: *randint(0,1)* function will generate either 0 or 1. However, in our loop we need either 1 or -1
  - Recall that beta is the inverse of the product of the Boltzmann constant and simulation temperature. Varying beta is a way of varying simulation *T*

# Exercise 3 - Intro & Tips

- LJ Potential
  - Lots of helper functions to import and functions to define
  - While there is quite a bit of code to execute, the goal is to see how we incorporate the system ensemble and its interactions when generating sample configurations for MC moves


# Exercises 3 & 4 - Additional Notes

Due to the Easter Break, report 3 won't be due until at 9am on Tuesday April 25th when we hold the session for Exercise 4

![](/data/mdmc/img_slides/Ex3/april_mdmc.png) \
