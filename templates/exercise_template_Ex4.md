# Exercise 4

Student:  Firstname Lastname    Sciper: 000000

:::{admonition} Please use this template to submit your answers. 

If you had to modify code from the notebook, please include the modified code in your submission either as screenshot or in a 

```
\begin{lstlisting}[language=Python]
\end{lstlisting}
```


environment. 

You only need to include the code cells that you modified.

Note, that references to other parts of the documents aren't resolved in this template and will show as `??`. Check the text of the exercises on website for the reference

:::

:::{admonition} Exercise 1
:class: exercise
Derive the form of $\mathbf{r}(t + \Delta t)$ in the velocity-Verlet
    {eq}`velocity-verlet`. **Hint**: solve equation  {eq}`step1` for  $\mathbf{r}(t - \Delta t)$, and use equations {eq}`step2` and  {eq}`step3`.
:::

Your answer here

:::{admonition} Exercise 2
:class: exercise
Derive the form of $\mathbf{v}(t + \Delta t)$ in the velocity-Verlet  {eq}`velocity-verlet`. **Hint**: recast equations  {eq}`step1` and {eq}`step2` to a  timestep $\Delta t$ in the future, and use the result obtained  above.   
:::

Your answer here

:::{admonition} Exercise 3
:class: exercise
How does an MD program work? Describe schematically (either describe steps in words thoroughly and/or provide an annotated sketch of the steps) what are the main steps to perform a molecular dynamics simulation from start to finish. Point out the main
    differences between your scheme and Monte Carlo methods. 
:::

Your answer here

:::{admonition} Exercise 4
:class: exercise
Implement the velocity verlet algorithm in the Toy MD program (`toy_md.py`).
:::

Your answer here

:::{admonition} Exercise 5
:class: exercise
Why are most MD and MC simulations based on periodic systems? Explain the main purpose of periodic boundary conditions in these schemes.
:::

Your answer here

:::{admonition} Exercise 6
:class: exercise
Describe a possible implementation of periodic boundary conditions and provide an implementation in `toy_md_forces.py` to compute the distance of two particles taking into account the perodic boundary conditions in the `distance_PBC` function (i.e a particle at the edge of the primary cell has a very short distance to the particle in the next cell). 
    
With a box size of `[2,2,2]` and three points the elementwise distances between point `[0.5,0.5,0.5]` should be the same to the points `[-0.5,-0.5,-0.5]` and `[1.5,1.5,1.5]`. The distance should be `[1,1,1]`.
:::

Your answer here

:::{admonition} Exercise 7 - Bonus
:class: exercise
What ensemble does the code in the ToyMD program sample in? Which of the quantities linear momentum $p$ and angular momentum $L$ are conserved when running with and without periodic boundary conditions?
:::

Your answer here

:::{admonition} Exercise 8
:class: exercise
What do you observe during the trajectory? Try to relate what you see with the parameters set for the simulation (i.e. simulation length, time step, temperature). Explain the changes, if any, you observe in the simulation if you change one or two of those parameters (note: you will need to delete your traj.pdb 
:::

Your answer here