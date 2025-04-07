---
title: Exercise Session 4
subtitle: MDMC Spring 2025
date: April 08, 2025
author: "Salomé Guilbert, Qihao Zhang, Thibault Kläy, Evan Vasey, Sophia Johnson, Andrea Levy"
output: beamer_presentation
---

# Reports Reminder

- We encourage you to work together, but the content in your report should be original
- If you use an image or wording from an external source please cite it correctly
- Please upload the recognizable pictures with good enough quality
- Whether we assume a lot of theoretical background, or that you are missing theoretical concepts for doing the exercises?
        
# Exercise 4 Structure

- Learning goals
    - Derive a time evolution integrator (e.g. Verlet)
    - Understand importance of periodic boundary conditions 
    - Run a molecular dynamics simulation for a small molecule ($CO_2$) 
    
- Chapter in script
  - Chapter 4 - Molecular Dynamics Simulations  

- Resources
  - Understanding Molecular Simulation, Frenkel & Smit, 2nd Edition - Chapter 3 & Chapter 5 (extra)
  - Computer Simulation of Liquids, Allen & Tildesley, 2nd Edition - Chapter 4

# Exercise 4 - Intro & Tips

Today we will provide you a simple Molecular Dynamics (**Toy MD**) code in python and you will extend it to run a MD simulation.

- The theoretical part introduces you to MD  \
  Be sure to understand what we mean by:
  - ergodicity
  - phase space sampling
  - MD propagation algorithm
  - periodic boundary conditions
- In the practical part you will implement:
  - Velocity verlet algorithm
  - Periodic boundary conditions (PBC)

# Exercise 4 - ToyMD structure

`ToyMD` code structure:

- main code (propagation of MD steps) in `toy_md.py` script
- additional code for specific tasks, i.e. `toy_forces.py`
- parameters for the system in separate files (`carbon-dioxide` folder)

![](/data/mdmc/img_slides/Ex4/toy_MD.png) \


# Exercise 4 - Run ToyMD

`ToyMD` is a python script, which can be run 

1. via terminal
2. via jupyter notebook

(see instructions in the exercise). In both cases, you will execute a bash command, passing files as arguments to the `toy_md.py` script with the following structure (paths may change):


`python3 toy_md.py -c co2.pdb -p params.txt -ff force_field.txt -o traj.pdb -w co2-output.pdb`

If you'd like to re-run the code with different parameters, please delete the previous `traj.pdb` file or rename it

# Exercises 4 & 5 - Additional Notes

Due to the Easter Break, report 4 won't be due until Tuesday April 29th when we hold the session for Exercise 5.

- 15 April: Course
- 18 - 27 April: Easter Break
- 29 April: Exercise 5 (and due date Ex4 @ 11am)
- 6 May: Course
