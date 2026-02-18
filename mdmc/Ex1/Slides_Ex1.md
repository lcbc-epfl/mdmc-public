---
title: Exercise Session 1
subtitle: MDMC Spring 2026
date: February 24, 2026
author: "Thibault Kläy, Amina Menhour, Alice Piantavigna, Evan Vasey, Qihao Zhang"
output: beamer_presentation
---

# Exercise General Information
- Practical exercises every other week in BCH 1113
    - 2 hours to work on your own and with support from TAs
- Reports
    - For each exercise, report answering the questions
    - We provide you templates (google doc/overleaf)
    
![](/data/mdmc/img_slides/Ex1/screenshot-template.png) \
    
# Exercise General Information    
- Report Submission
    - `pdf` document answering the questions and relevant output
    - Due date is usually of one week, till the next lecture (check Moodle!) 
    - Detailed feedback via Moodle after the interview
        - No grade
        - Overall comment and detailed correction of the exercises
- Interviews during next exercise session are about 10-15 minutes
    - Test your understanding of the exercise
    - Good occasion to discuss your doubts and questions
    - We will release the schedule ahead of the session so you know when and with whom you will interview - you need to email us to reschedule if you can't make it to your allocated time 
    - If you don't come to your interview and don't have a proper justification (medical certificate), **your grade for that report will be 0**

**Exercises contribute to 1/2 of final grade! We count the best 5 out of the 6 reports for your exercise grade.**

# Exercise structure

![](/data/mdmc/img_slides/Ex1/learning_goals.png) \


# Resource Platforms

The following resources will be used to access and complete the exercises (more details later):

- [Moodle page](https://moodle.epfl.ch/course/view.php?id=10441)
    - Access exercise notebook
    - Turn in reports
    - Ask questions on the forum
- [Exercise website: **https://lcbc-epfl.github.io/mdmc-public/**](https://lcbc-epfl.github.io/mdmc-public/intro.html)
    - Access jupyter notebooks on Noto
    - Access to public github repository to raise issues for fixes/improvements to the exercises
    - Read theory and questions
- [Noto](https://noto.epfl.ch/)
    - Run and edit code blocks
    - Please note, for the most recent updates to the exercises you must access noto from the exercise website directly

# Computer environment

- We will use a virtual environment that you can directly launch from the [exercise website](https://lcbc-epfl.github.io/mdmc-public/intro.html)
- Click the rocket button on the top right of the code files and choose JupyterHub to launch [noto.epfl.ch](https://noto.epfl.ch/) 
- **Make sure to access noto this way each time you begin the exercise to ensure you have the latest version!**
		![](/data/mdmc/img_slides/Ex1/notebooks.png)

# Computer environment

- On [noto.epfl.ch](https://noto.epfl.ch/) your work will be saved on your EPFL storage
- Make sure to always activate (top right) the `Computational Chemistry` kernel
		![](/data/mdmc/img_slides/Ex1/kernel.png)

# Jupyter notebooks

- `.ipynb` files organized in cells
	- Markdown (text)
	- Code 

- Run a code cell by pressing `Play` button (or `Ctrl`+`Enter`)
![](/data/mdmc/img_slides/Ex1/jn_1.png) \

# Jupyter notebooks
- `.ipynb` files organized in cells
	- Markdown (text)
	- Code 

- Run a code cell by pressing `Play` button (or `Ctrl`+`Enter`)
![](/data/mdmc/img_slides/Ex1/jn_2.png) \

# Exercise 1 - Intro & Tips

Today we'll be building a tool to estimate the value of $\pi$ through a random sampling method (akin to Monte Carlo methods). The focus of the exercise is to get a better sense of how we can implement random sampling for numerical integration.

**Tips!**

- There is a small portion linking quantum ideas to classical mechanics. Please let us know if you need additional support regarding the notation/formalisms here.
- It may be a good idea to start from the practical part, to get familiar with the environment and ask us questions
- Places where you need to modify the code blocks should be noted with comments in the code with something like
*## Begin code to modify ##*

# Using Noto

What you should do if Noto doesn't work:

- Most importantly, **do not be a deadline fighter! Do it earlier!**
- Check whether you're working with the correct environment and import the modules correctly
- Try a different browser (Chrome, Firefox recommended)
- Refreshing the page after deleting the browser cache
- Conclude what you have done and what the problem is in detail (don't just mention 'it didn't work') and write to us TAs as soon as possible
- Contact noto support: noto-support@groupes.epfl.ch

# Questions ?

Questions on the exercises (or the theory) outside exercise hours or problems with the reports? You can always contact us  

- [**Moodle Forum**](https://moodle.epfl.ch/mod/forum/view.php?id=1193419), preferred way of communication since everyone can see the questions (and answer!)
- Email us, always better to include multiple of us to get an answer faster
    - thibault.klay@epfl.ch
    - amina.menhour@epfl.ch
    - alice.piantavigna@epfl.ch
    - evan.vasey@epfl.ch
    - qihao.zhang@epfl.ch
- At least one of us will always try to be present during lectures, feel free to ask us questions before/after the lecture or during the break!
