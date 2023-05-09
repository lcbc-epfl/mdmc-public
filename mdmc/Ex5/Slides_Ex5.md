---
title: Exercise Session 5
subtitle: MDMC Spring 2023
date: May 9, 2023
author: "Lorenzo Agosta, Virginia Carnevali, Simon Dürr, Sophia Johnson, Nikolaos Lempesis, Andrea Levy"
output: beamer_presentation
---

# Reminders

- Always access the notebooks via  the rocket button on the top right of the code files and choose JupyterHub to launch [noto.epfl.ch](https://noto.epfl.ch/)

- Google Colab: For Ex 6, you need activate 3rd party permission on your EPFL Google Account. Since the activation can take some time, it is important to do it well in advance to May 16th. More information on moodle announcement from 08.05.2023.

- Important Dates:
  - Due date for Ex 5 will be next Tuesday May 16th
  - Q&A Session on Tuesday May 23rd in lecture classroom
  - Written exam on Tuesay May 30th in lecure classroom

# Exercise 5 Learning Goals

![](/data/mdmc/img_slides/Ex5/learning_goals.png) \

# Exercise 5 - Intro

Today we will re-provide you a simple Molecular Dynamics (**Toy MD**) code in python and you will edit it to run a MD simulation in the NVT ensemble.

- The theoretical part discusses the practical of relatistic MD systems:
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

- download and unzip ToyMD directory from moodle
- talk through code ideas with others, ask questions
- use terminal in noto

# Exercise 5 - ToyMD structure

`ToyMD` code is the same structure:

- main code (propagation of MD steps) in `toy_md.py` script
- additional code for specific tasks, i.e. `toy_forces.py`
- parameters for the system in separate files (`carbon-dioxide` folder)

![](/data/mdmc/img_slides/Ex4/toy_MD.png) \


# Exercise 5 - Run ToyMD

`ToyMD` is a python script, which can be run

1. via terminal
2. via jupyter notebook

Recall that you can execute a bash command, passing files as arguments to the `toy_md.py` scriot with the following structure (paths may change):

`python3 toy_md.py -c co2.pdb -p params.txt -ff force_field.txt -o traj.pdb -w co2-output.pdb`

# Exercise 5 - Thermostats

Let's look deeper into different thermostats
[Simon's Explanation of Thermostats](https://moodle.epfl.ch/course/view.php?id=10441#section-12)
