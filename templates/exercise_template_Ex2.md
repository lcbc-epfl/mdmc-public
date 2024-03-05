# Exercise 2

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
A quantum harmonic oscillator has energy levels: $ E_n = \left(n + \frac{1}{2}\right)\hbar \omega$.<br>
Write down the corresponding canonical partition function
$Z(N,V,T)$.  Note that in this case, the partition function forms an
infinite geometric series, and can be rewritten in terms of the
$n \rightarrow \infty$ limit of the series.<p>
From the result you obtain, derive the expectation value of the energy.
Use the limit of the geometric series for $Z$, rather than the sum-based form.
:::

Your answer here

:::{admonition} Exercise 2- Bonus
:class: exercise
Show that, based on {eq}`thermodynamic_properties`, the canonical partition function {eq}`classical_probability` is obtained from {eq}`canonical_density_matrix` if the Hamiltonian admits an orthonormal eigenbasis $\left\{\ket{\Psi_i}\right\}$ and the commutator $\left[\hat{\mathrm{H}},\hat{\mathrm{O}}\right]$ vanishes. (There is no need to use the commutator itself, applying conditions that follow from vanishing commutators is sufficient.)
:::

Your answer here

:::{admonition} Exercise 3 - Bonus
:class: exercise
Show from {eq}`density_operator` and {eq}`canonical_density_matrix` that the $p_i$ are indeed equal to $\frac{1}{Z}e^{-\beta E_i}$ for pure states, given that there exists a common eigenbasis $\left\{\ket{\Psi_i}\right\}$ to the total Hamiltonian and explain the origin of this restriction.
Explain why the density operator and the expression for the expectation value of an observable assume a general form ({eq}`canonical_density_matrix` and {eq}`thermodynamic_properties`), rather than being defined directly in terms of {eq}`canonical_density_matrix_recast` and {eq}`classical_probability`.
(You may link your answer to the assumptions made in the previous question).
:::

Your answer here

:::{admonition} Exercise 4
:class: exercise
Derive the Boltzmann distribution, {eq}`boltzmann`, from {eq}`recast_expectation_value`, using the   expectation value of the particle number in state $s$, $N_s$, as observable.
*Hint*: It may be useful to remember that the ensamble average in {eq}`recast_expectation_value` can be always expressed also as the probability of being in that state, times their value: $\left< O_s \right> = p_s O_s$.
:::

Your answer here

:::{admonition} Exercise 5
:class: exercise
 Modify the code below to calculate the occupancy of each state within the harmonic oscillator system.
Present the entire code file within your report and comment upon the main features using `#`.
Consider different (**reduced**) temperatures, 0.5, 1, 2 and 3, and energy levels set to 10 (recall $\epsilon = 1$).
You will implement different `StateOccupancy()` functions, correspondng to different degeneracies. Note that in the $(s + N)$ degeneracy, $s$ is
    the index of the energy level, and its degeneracy is $(s + N)$, where $N$ assumes values $0,1,2$ in this Exercise.
:::

Your answer here

:::{admonition} Exercise 6
:class: exercise
What do you note as the temperature is increased in terms of state occupancy? Does it make sense physically?
:::

Your answer here

:::{admonition} Exercise 7
:class: exercise
Compare different degeneracies (no degeneracy, $s+1$, and $s+2$) for different reduced temperatures. What can you infer?
:::

Your answer here

:::{admonition} Exercise 8
:class: exercise
Modify your program such that the state occupancy and partition
function are calculated for a linear rotor with moment of inertia $I$ (copy your code in the cell below, and adapt it for the linear rotor case. Present also this code within your report). Compare your results at different temperatures with the approximate result {eq}`approximateresult`. 
   
*Hint*: considering more than four reduced temperatures can be a good idea, you can easily obtain evenly spaced numbers over a specified interval using the numpy function `np.linspace(start, stop, number_of_points)`. 
Note that if the higher temperatures considered are far from the highest temperature which was considered so far, more energy levels may become accessible to the system, and you should keep them into account.
    
Is this an approximated result for which temperature limit?


$$
Z = \frac{2I}{\beta\hbar^2}
$$ (approximateresult)

using

$$
\frac{I}{\hbar^2} = 1.
$$

Note that the energy levels of a linear rotor are:

$$
U = J(J+1)\frac{\hbar^2}{2I}
$$

with $J= 0, 1, 2, \dots, \infty$ and the degeneracy of level J is $2J +1$.
:::

Your answer here