# Exercise 3

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
Show that if the Hamiltonian of a system can be written as: $ H = T(\mathbf{p}) + V(\mathbf{q})$, 
i.e. if the kinetic and potential energy can be decoupled, then the partition function can be divided into a kinetic and potential part. Derive {eq}`ensembleaverage` for an ensemble average of an observable $O(\mathbf{q})$, which depends only on $\mathbf{q}$.
:::

Your answer here

:::{admonition} Exercise 2 - Bonus
:class: exercise
Why is it important that $P'$ is a symmetric matrix?
:::

Your answer here

:::{admonition} Exercise 3
:class: exercise
To express the occupation of our ensemble of harmonic ascillators, we will use a list where each item is the number of particle in the corresponding level. For example occupancy[0]=10 means that there are 10 particles in the ground state (level 0)
Create a function that calculates the energy of an occupancy list using the hints provided.
:::

Your answer here

:::{admonition} Exercise 4
:class: exercise
Make modifications in the code, right after the commented section `MODIFICATION ... END MODIFICATION`. Include the entire code within your report and comment upon the part that you wrote.
:::

Your answer here

:::{admonition} Exercise 5
:class: exercise
How can this scheme retain detailed balance when $N_i = 0$? Note that $N_i$  cannot be negative.
:::

Your answer here

:::{admonition} Exercise 6 - Bonus
:class: exercise
Bonus: Why do we add these lines in our code:
        if final_level > levels-1:
            final_level = levels-1
How is this realted to the number of levels?
:::

Your answer here

:::{admonition} Exercise 7
:class: exercise
Using your code, plot the average occupancy. 
Do it for two different temperatures and comment on your observations.
Calculate the anyltical solution with the expression in the theory above and the partition function for a harmonic oscillator.

$$
\begin{align}
    Z = \frac{e^{\frac12 \beta \hbar \omega}}{e^{\beta \hbar \omega}-1}
\end{align}
$$

Plot your calculated values versus those from the analytical solution (two curves in the same plot) and include your curve in your report (you will include 2 plts, one for each temperature chosen).

Now, do the same process with 3 or more values for numberOfIterations.
What is the influence of the number of MC iterations on the estimated result vs the analytical one? Why? Justify in words and include supporting plots.

Note: this question requires more time, you need to clearly justify your statements.
:::

Your answer here

:::{admonition} Exercise 8
:class: exercise
 Why does ignoring rejected moves lead to erroneous results? *Hint*: define $P'(o \rightarrow o)$ (*i.e*  the probability that you stay in the old configuration) and recall that the transition probability $P'$ is normalised.
:::

Your answer here

:::{admonition} Exercise 9 - Bonus
:class: exercise
Based on your comprehension of the exercise, what do you think is the influence of the number of partciples?
:::

Your answer here

:::{admonition} Exercise 8
:class: exercise
Perform a simulation at $T = 2.0$ and $\rho \in [0.05, 0.5, 2, 10.0]$. What do you observe?
:::

Your answer here

:::{admonition} Exercise 9
:class: exercise
The program produces a trajectory. Look at it and explain the behavior of the system over time for $\rho$ 0.85
:::

Your answer here

:::{admonition} Exercise 10
:class: exercise
Instead of performing a trial move in which only one particle is displaced, one can do a trial move in which more particles are
 displaced simultaneously. You can find below a modified version of the code, where for each step `nParticlesMove` are displaced. 
From the given code, explain how a trial move is now performed and what changes with respect to the previous case. 
    
*Hint*: It can be helpful to perform different tests, e.g. using `nParticlesMove = nPart` or, for example, `nParticlesMove = nPart/2`. Describe the changes you see in the energies and the trajectories in this new version of the code. 
:::

Your answer here

:::{admonition} Exercise 11 - Bonus
:class: exercise
The code to sample the NPT ensemble is provided below. What needs to be changed in the code to sample from the isothermic-isobaric ensemble (NpT) instead of the microcanonical ensemble (NVT)?
:::

Your answer here