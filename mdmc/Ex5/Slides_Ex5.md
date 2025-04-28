---
title: Exercise Session 5
subtitle: MDMC Spring 2025
date: April 29, 2025
author: "Evan Vasey, Thibault Kläy, Qihao Zhang, Salomé Guilbert, Sophia Johnson, Andrea Levy"
output: beamer_presentation
---

# Reminders

- Always access the notebooks via  the rocket button on the top right of the code files and choose JupyterHub to launch [noto.epfl.ch](https://noto.epfl.ch/)

- Important Dates:
  - Due date for Ex 5 will be Tuesday May 13th
  - Q&A Session on Tuesday May 20th in lecture classroom
  - Written exam on Tuesday May 27th in lecture classroom


# Exercise 5 Learning Goals

![](/data/mdmc/img_slides/Ex5/learning_goals.png) \

# Exercise 5 - Intro

Today we will re-provide you a simple Molecular Dynamics (**Toy MD**) code in Python and you will edit it to run an MD simulation in the NVT ensemble.

- The theoretical part discusses the practical of realistic MD systems:
  - describing potential energy via force fields
  - sampling NVT (canonical) ensemble using thermostats
  - understanding pair radial distribution functions
- In the practical part you will implement:
  - system initialization code
  - thermostat schemes
  - trajectory visualizations for small systems
  - RDF plotting for homogeneous and heterogeneous systems

# Exercise 5 - Tips
Tips:

- Download and unzip ToyMD directory from Moodle: to make sure nobody starts with a buggy version of the code, we provide the correct version you should have from Ex4. Follow the instructions at the beginning of the Ex5 notebook to use that code!

# Exercise 5 - ToyMD structure

`ToyMD` code is the same structure:

- main code (propagation of MD steps) in `toy_md.py` script
- additional code for specific tasks, i.e. `toy_forces.py`
- parameters for the system in separate files (`carbon-dioxide` folder)

![](/data/mdmc/img_slides/Ex4/toy_MD.png) \


# Exercise 5 - Run ToyMD

`ToyMD` is a Python script, which can be run

1. via terminal
2. via jupyter notebook

Recall that you can execute a bash command, passing files as arguments to the `toy_md.py` script with the following structure (paths may change):

`python3 toy_md.py -c co2.pdb -p params.txt -ff force_field.txt -o traj.pdb -w co2-output.pdb`

or, alternatively, you can run the same bash command from code cells, starting with an exclamation mark (the cell will be interpreted as a bash command to execute):

`! ./toy_md.py -c co2.pdb -p params.txt -ff force_field.txt -o traj.pdb -w co2-output.pdb`


# Exercise 5 - Thermostats

Let's look deeper into different thermostats
[Simon's Explanation of Thermostats](https://moodle.epfl.ch/mod/resource/view.php?id=1206724)
