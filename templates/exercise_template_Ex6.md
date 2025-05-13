# Exercise 6

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

:::{admonition} Exercise 1 - Bonus
:class: exercise
Derive {eq}`eqpb2` from {eq}`eqpb1` by passing via the exponential form of the Poisson-Boltzmann equation {eq}`conc`.    Give an appropriate expression for the equilibrium charge density  $\rho_\text{ext}(\mathbf{r})$ in the Poisson-Boltzmann approach.
:::

Your answer here

:::{admonition} Exercise 2
:class: exercise
How may the solvent environment (especially in the case of a polar
    solvent, such as dimethylformamide (DMF), and a polar
    hydrogen-bonding solvent, such as water) influence the properties
    (conformation, reactivity) of the solute? Which solvent do you
    expect to be more difficult to mimic by an implicit model, DMF or
    water?
:::

Your answer here

:::{admonition} Exercise 3
:class: exercise
In the context of the previous questions, explain possible advantages and pitfalls of using an implicit solvent compared to an explicit treatment.
:::

Your answer here

:::{admonition} Exercise 4
:class: exercise
A protein has the tendency to fold much quicker in implicit than in explicit solvent. Why is this? What are possible issues?
:::

Your answer here

:::{admonition} Exercise 5 - Bonus
:class: exercise
Is the computation of the pressure in
   {eq}`pressure`, via the virial, more expensive in an MD and an MC
    algorithm? And why?
:::

Your answer here

:::{admonition} Exercise 6 - Bonus
:class: exercise
Derive the ideal gas part of the virial in {eq}`virial` using {eq}`virial_alt`.
:::

Your answer here

:::{admonition} Exercise 7
:class: exercise
 Follow the instructions in this file and run the folding simulation. 
Calculate the correct number of steps for the simulations to run 50 ps of heating and 20 ns of dynamics and report those numbers in your report. These sections are marked in the following with `#CHANGE HERE`. 
:::

Your answer here

:::{admonition} Exercise 8
:class: exercise
Include an image of the starting structure in your report. Are there any residues which  would contribute to the instability of the starting structure in its current conformation, why? 
:::

Your answer here

:::{admonition} Exercise 9
:class: exercise
What type of structure is the folded Trp-cage miniprotein? List the main components contributing to this structure, including the residues which are responsible for their formation.
:::

Your answer here

:::{admonition} Exercise 10
:class: exercise
Explain the RMSD and RMSF plots.  Does the trajectory reach the same conformation as the experimental structure?
Which metric is more useful for the problem at hand? <b>Bonus:</b>  Provide a use case for the other metric. 
:::

Your answer here

:::{admonition} Exercise 11
:class: exercise
 Include the hbond graph in your report, and explain the observed trend with reference to the structural components of the Trp-cage miniprotein ?
:::

Your answer here

:::{admonition} Exercise 12
:class: exercise
Perform the Q1 and Q2 analysis explained below and provide the graph of the number of contacts. Can you infer at which interval (in nanoseconds) the secondary structure forms?
:::

Your answer here

:::{admonition} Exercise 13
:class: exercise
Why is it useful to constrain bond lengths for larger MD simulations (typically with the SHAKE algorithm)? Which bonds would you typically constrain in such a scenario, and why?
:::

Your answer here

:::{admonition} Exercise 14 - Bonus
:class: exercise
Which properties do you need to take into account in order to select an appropriate timestep for your MD simulation? Are there any other reasons you might wish to reduce or increase this timestep?
:::

Your answer here

:::{admonition} Exercise 15 - Bonus
:class: exercise
Is it better to sample 2 x 10 ns from the same starting structure or 1 x 20 ns in order to explore conformational space efficiently? 
:::

Your answer here