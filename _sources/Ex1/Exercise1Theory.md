
# From Quantum to Classical Mechanics: The Example of Forces


Later in the course, you will learn that in *Molecular Dynamics*,
thermodynamic properties of a system are determined by propagating it in
time. This propagation is done by evaluating the forces acting on the
nuclei, which are usually considered to be classical particles. The
nuclei are then moved according to the forces which act on them. This
*clamped nuclei* approximation is also at the base of the geometry
optimisation procedures in electronic structure theory, as discussed in
the course 'Introduction to Electronic Structure Methods'. Analogously,
in clamped-nuclei first-principles molecular dynamics, the information
on the forces is obtained from the electronic structure of the system by
solving the time-independent Schrödinger equation.

In classical mechanics, the forces acting on a system can be evaluated
from: 

$$ F(\mathbf{q}) = -\nabla E(\mathbf{q}).
$$ (forces)

 The link with the
time-independent Schrödinger equation is based on the Hellmann-Feynman
theorem: 

$$\begin{aligned}
\frac{\mathrm{d}E}{\mathrm{d}\lambda} = \left<{\Psi_\lambda \left| \frac{\mathrm{d}\hat{\mathrm{H}}(\lambda)}{\mathrm{d}\lambda} \right| \Psi_\lambda} \right>,\end{aligned}$$ (hellmanfeynman)

where $\lambda$ is some parameter on which the Hamiltonian, and thus the
wavefunction, parametrically depends. By considering the Hamiltonian of
a system with $N$ electrons and $M$ nuclei within the Born-Oppenheimer
approximation, the forces are easily evaluated from the Hellmann-Feynman
theorem. 

The Hamiltonian reads: 

$$
\begin{aligned}
\mathrm{\hat{H}} = \mathrm{\hat{T}} + \mathrm{\hat{V}_{ee}} + \sum_{I=1}^M\sum_{i=1}^N \frac{Z_I}{\left|\mathbf{r}_i -\mathbf{R}_I\right|}
                  + \sum_{I=1}^M\sum_{J\ne I}^M \frac{Z_I Z_J}{\left|\mathbf{R}_I -\mathbf{R}_J \right|},
\end{aligned}
$$ (hamiltonian)

where $\mathrm{\hat{T}}$ is the kinetic energy operator,
$\mathrm{\hat{V}_{ee}}$ is the operator that mediates electron-electron
interactions, and captial and lower case letters denote nuclear and electronic indices respectively. In cartesian coordinates, the forces
acting on the x-component $\mathbf{X}_I$ of nucleus $I$ are:

$$
\begin{aligned}
\mathbf{F}_{\mathbf{X}_I} = -\left<{\Psi \left| \frac{\mathrm{d}\hat{\mathrm{H}}}{\mathrm{d}\mathbf{X}_I} \right| \Psi} \right>.
\end{aligned}
$$ (forces_x)

Insertion into {eq}`hellmanfeynman` yields: 

$$ 
\begin{aligned}
\mathbf{F}_{\mathbf{X}_I} = -Z_I \int \frac{\mathbf{x}-\mathbf{X}_I}{\left|\mathbf{r}-\mathbf{R}_I\right|^3}\rho(\mathbf{r}) \mathrm{d}\mathbf{r}
                          - \sum_{J \ne I}^M Z_I Z_J \frac{\mathbf{X}_J -\mathbf{X}_I}{\left| \mathbf{R}_J -\mathbf{R}_I \right|^3}.
\end{aligned}
$$ (forces_x_hf)

The forces on the nuclei are thus easily derived from the electron
density $\rho(\mathbf{r})$ using an analytical expression. In *classical
molecular dynamics*, the forces are not evaluated from the electron
density, but are fully parametrised instead.

# Statistical Approaches to Numerical Estimation


Monte Carlo (MC) methods are a broad class of computational algorithms
which rely on repeated random sampling to obtain the distribution of an
unknown, often probabilistic entity. They are particularly useful for
problems in which it is difficult (or impossible) to obtain a
closed-form expression, or to apply a deterministic algorithm. A more
detailed discussion of MC methods will follow in the lecture course, but
here we intend to introduce the topic with a practical example.

One of the simplest yet intuitive examples of an MC method is to
estimate the value of $\pi$ through numerical integration. This exercise
will focus on the importance of sampling and maintaining a uniform
distribution in the choice of sampling points. Since MC methods rely
heavily on uniform randomly distributed numbers, there is a detailed
discussion of pseudo-random number generators (PRNGs) in {doc}`prng`


```{figure} ../images/Pi_estimation.svg
---
height: 200px
name: pi-estimation
---
Schematic representation of modifying the l/d ratio. This ratio in part determines the accuracy of the $\pi$ estimation.
```

## Numerical Estimation of $\pi$

Consider a circle of diameter $d$, sitting at the centre of a square of
length $l$ as depicted in {numref}`pi-estimation`. If points (x,y) are randomly distributed
within the square and those which fall within the circle versus the
square are counted, numerical integration is effectively being performed
*via* the MC method. The area ratio of the circle to the square thus
provides a route to estimate $\pi$ explicitly. It is worthwhile to note
that in order to obtain an accurate approximation of $\pi$, the randomly
generated coordinates must be uniformly distributed across the entire
square to prevent bias. In addition, a large enough number of sample
points must be used to appropriately approximate the areas (and their
ratio).





