---
title: Exercise Session 6
subtitle: MDMC Spring 2023
date: May 16, 2023
author: "Lorenzo Agosta, Virginia Carnevali, Simon Dürr, Sophia Johnson, Nikolaos Lempesis, Andrea Levy"
output: beamer_presentation
---

# Reminders

- Last exercise session - optional report (only best 5 out of 6 graded)

- No interview for report of Ex6

- **Extended deadline** for this report: July 1st

- Even if you decide to not doing the report, read the theory and the exercise! Important knowledge to better understand MD (possibly useful for the exam!)

- Important Dates:
  - Q&A Session on Tuesday May 23rd in lecture classroom -- send us your questions in advance!
  - Written exam on Tuesay May 30th in lecure classroom


# Exercise 6 - Reminders

- The first part of the exercise should be run on **GoogleColab** and not on Noto! (free access to GPUs)

- Access GoogleColab via the usual rocket button

- Change the runtime to use a GPU ( Runtime > Change Runtyle type > select GPU)

![](/data/mdmc/img_slides/Ex6/googlecolab.png) \

# Exercise 6 - Set up Google Colab

- Uncomment the necessary cells and run the `install/import` commands (the first time you may see a warning about the notebook not being authored by Google -- Run anyway)

- This phase will install and import all necessary modules to run this exercise, be sure to run this at the beginning (it will take few minutes)

![](/data/mdmc/img_slides/Ex6/colab_setup.png){width=70%} \


# Exercise 6 - Learning Goals

![](/data/mdmc/img_slides/Ex6/learning_goals.png) \

# Exercise 6 - Context

Today you will perform a MD simulation of a Trp-cahe miniprotein

- Smallest protein to display two state folding properties, ideal candidate for computational folding simulations

- Folding dynamics of this protein with explicitly defined water molecules (see Theory section for details) is a lengthy and computationally costly process. We will use of an implicit solvent model to reduce computational cost and still include, in approximate detail, the effects of water solvation.

- You will replicate the work of [Simmerling et. al. in 2002](https://pubs.acs.org/doi/10.1021/ja0273851)

![](/data/mdmc/img_slides/Ex6/trp-cage_study.png){width=90%} \

# Exercise 6 - Analysis

The analysis of the MD you generate will be performed on Noto 

- Uplad the `archive.zip` generated on GoogleColab

- You will look at different properties during the simulation, comparing to the experimental structure (PDB 1L2Y)

![](/data/mdmc/img_slides/Ex6/trp-cage_end.png) \

