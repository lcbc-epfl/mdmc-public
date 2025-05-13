---
title: Exercise Session 6
subtitle: MDMC Spring 2025
date: May 13, 2025
author: "Evan Vasey, Thibault Kläy, Qihao Zhang, Salomé Guilbert, Sophia Johnson, Andrea Levy"
output: beamer_presentation
---

# Reminders

- Today is the *final* exercise session - optional report (only best 5 out of 6 graded)

- No interview for report of Ex6

- **Extended deadline** for this report: Sunday June 29th at 23h59

- Even if you decide to not do the report, read the theory and the exercise! Important knowledge to better understand MD (possibly useful for the exam!)

- Important Dates:
  - Q&A Session and mock exam on Tuesday May 20th in lecture classroom -- send us your questions on moodle in advance!
  - Written exam on Tuesay May 27th in lecure classroom

# Written exam - information

- 1 page of summary notes will be permitted during the exam (1 A4 size paper, front and back)

- Calculators will be permitted during the exam, but not necessary

- No other electronic device allowed

- We will provide paper to write your answers


# Exercise 6 - Reminders

- **Note** This tutorial should be run on **gnoto** JupyterHub and not on noto JupyterHub. This is because we will use GPU-accelerated techniques to speed up the simulations.

- To this end, please use the following link instead of the usual rocket button: [gnoto link](https://gnoto.epfl.ch/hub/user-redirect/git-pull?repo=https%3A//github.com/lcbc-epfl/mdmc-public&urlpath=lab/tree/mdmc-public/mdmc/Ex6/TRP_Cage.ipynb&branch=main)

- **Select** the correct kernel for this exercise `CH-351`

![](/data/mdmc/img_slides/Ex6/gnoto.png)\

# Exercise 6 - Set up gnoto

- **Select** the correct kernel for this exercise `CH-351`

![](/data/mdmc/img_slides/Ex6/gnoto_kernel.png){width=30%} \


# Exercise 6 - Learning Goals

![](/data/mdmc/img_slides/Ex6/learning_goals.png) \

# Exercise 6 - Context

Today you will perform a MD simulation of a Trp-cahe miniprotein

- Smallest protein to display two state folding properties, ideal candidate for computational folding simulations

- Folding dynamics of this protein with explicitly defined water molecules (see Theory section for details) is a lengthy and computationally costly process. We will use of an implicit solvent model to reduce computational cost and still include, in approximate detail, the effects of water solvation.

- You will replicate the work of [Simmerling et. al. in 2002](https://pubs.acs.org/doi/10.1021/ja0273851)

![](/data/mdmc/img_slides/Ex6/trp-cage_study.png){width=90%} \

# Exercise 6 - Analysis

The analysis of the MD trajectories:

- You will look at different properties during the simulation, comparing to the experimental structure (PDB 1L2Y)

![](/data/mdmc/img_slides/Ex6/trp-cage_end.png) \

