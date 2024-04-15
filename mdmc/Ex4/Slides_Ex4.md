---
title: Exercise Session 4
subtitle: MDMC Spring 2024
date: April 16, 2024
author: "Vladislav Slama, Simon Dürr, Sophia Johnson, Nikolaos Lempesis, Andrea Levy"
output: beamer_presentation
---

# Reports Reminder

- We encourage you to work together, but the content in your report should be original
- If you use an image or wording from an external source please cite it correctly 
        
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
  
N.B.: Question 8 is no longer a bonus question in case you worked on Ex4 earlier this semester

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
