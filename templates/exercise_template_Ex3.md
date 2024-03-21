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
Make modifications in the code, right after the commented section `MODIFICATION ... END MODIFICATION`. Include the entire code within your report and comment upon the part that you wrote.
:::

Your answer here

:::{admonition} Exercise 4
:class: exercise
How can this scheme retain detailed balance when $n_j = 0$? Note that $n_j$  cannot be negative.
:::

Your answer here

:::{admonition} Exercise 5
:class: exercise
Using your code, plot the photon-distribution (average occupation number as a function of $\beta\epsilon\in[0.1,2]$). 
Assume that the initial $n_j =1$ and $\epsilon_j=\epsilon$ and recalculate the with the same $\beta\epsilon$ values the analytical solution
    $$\left< N \right> = \frac{1}{e^{\beta\epsilon}-1}$$
Plot your calculated values versus those from the analytical solution and include your curve in your report. What is the influence of the number of MC iterations on the estimated result vs the analytical one? Why?
:::

Your answer here

:::{admonition} Exercise 6 - Bonus
:class: exercise
Modify the program in such a way that the averages are updated only after an accepted trial move. Why does ignoring rejected moves lead to erroneous results? *Hint*: define $P'(o \rightarrow o)$ (*i.e*  the probability that you stay in the old configuration) and recall that the transition probability $P'$ is normalised.
:::

Your answer here

:::{admonition} Exercise 7 - Bonus
:class: exercise
At which values of $\beta$ does the error you obtain when ignoring rejected moves become more pronounced? Why?
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