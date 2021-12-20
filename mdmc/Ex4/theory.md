# Theory

## The Ergodic Hypothesis in Statistical Mechanics

The question whether some properties obtained by averaging over a
thermodynamical ensemble (the *ensemble average*) are equal to a *time
average* of said properties - *i.e.* whether a system is *ergodic* or
not - poses one of the fundamental problems of statistical mechanics.
Unfortunately, there exists no complete proof of an *ergodic theorem*
applied to thermodynamic ensembles. However, it can be shown that, if
the only constants of motion of the system are constant functions over
phase space (*i.e.* constants independent of coordinates and momenta),
then the ensemble and time averages are identical for
$t \rightarrow \infty$. Since a more general ergodic theorem has not
been proven yet, a system is usually considered ergodic as long as *all*
regions of phase space are accessible during the time $t$ for which the
system is sampled. In practice, the *ergodic hypothesis*,

$$
\begin{aligned}
\left< O \right> = \int_\Gamma \frac{1}{Z}O(\Gamma)e^{-\beta \mathrm{H}(\Gamma)} \mathrm{d}\Gamma
                 = \lim_{t \rightarrow \infty} \frac{1}{t} \int_0^\tau O(\tau) \mathrm{d}\tau,
\end{aligned}
$$ (ergodic-hypothesis)

is thus assumed - but not guaranteed - to hold.

## Sampling Phase Space using Molecular Dynamics

Under the ergodic hypothesis, a direct sampling of phase space
configurations can be replaced by a sampling of the dynamic evolution of
the system for long enough times $t$. For an $NVT$ ensemble, an
observable of a state $s$ will then be explored with a probability
corresponding to its Boltzmann weight, and for a sufficiently long $t$ -
*i.e.* for a sufficiently high occurence of all events to be
representative - the time-average over the $O(s)$ will reproduce the
ensemble average. The longer the simulation time $t$ is chosen, the
better the convergence of the time average towards the ensemble average
(it is evident that too short $t$ do not lead to a converged dynamics,
*i.e.* phase space is not properly sampled).

In this spirit, a (suitable) starting conformer of a system can be
propagated in time according to Hamilton's equations of motions:

$$
\begin{aligned}
 \frac{\mathrm{d}\mathbf{p}_i}{\mathrm{d}t} &= -\frac{\partial{H}}{\partial{\mathbf{q}_i}},\\
 \frac{\mathrm{d}\mathbf{q}_i}{\mathrm{d}t} &= \frac{\partial{H}}{\partial{\mathbf{p}_i}}.
 \end{aligned}
 $$ (hamiltoneqmotion)

This time-evolution is completely general. If the system is represented
by a set of classical point particles, the Newtonian formulation of
classical mechanics can be applied to the problem, and the particles can
be propagated by evaluating the force acting on them: 

$$
\begin{aligned}
\mathbf{F}_I &= \nabla_I E\\
&= m_I\mathbf{a}_I
\end{aligned} $$ (newtonianformulation)

 For small time steps
$\Delta t = \tau$, the particles are accelerated according to $a$ which
is determined from $\frac{\nabla_I E}{m_I}$ at $t=0$. At time $t=\tau$,
the forces and the acceleration are re-evaluated, and the system is
moved according to the updated forces that act on it. These forces may
be obtained from quantum mechanical calculations (*first principles*
dynamics, *cf.* the discussion of the Hellmann-Feynman theorem) or from
a parametrised form for $E(\mathbf{r})$ (*classical dynamics*, which
will be discussed in detail in the following lecture). Since the
evolution of the system is well-defined at every point based on the
forces acting on it, its dynamics will be *deterministic*. Given an
initial set of positions and momenta, every point ever visited by the
system at time $t$ is pre-determined. Applying this approach to
molecular systems results in either *classical* or *first-principles
molecular dynamics* (MD).




## Time Evolution

Given the potential for atomic interaction in section
{numref}`minimalFF`, the force
acting upon the $i$th atom is determined by the gradient with respect to
atomic displacements:

$$
\mathbf{F}_i = -\nabla_{\mathbf{r}_i} V \left( \mathbf{r_1}, \dots, \mathbf{r_N} \right) = - \left( \frac{\partial V}{\partial x_i}, \frac{\partial V}{\partial y_i}, \frac{\partial V}{\partial z_i} \right).
$$ (force_on_i)

Using Newton's equations of motion one can then achieve propagation of
atomic positions in time, using some time step $\Delta t$:

$$
\begin{aligned}
\mathbf{a_i}(r_i, t) &= \frac{\mathbf{F}_i(\mathbf{r})}{m_i}, \\
\mathbf{v}_i(t + \Delta t) &= \mathbf{v}_i(t) + \mathbf{a}_i(t)\Delta t, \\
\mathbf{r}_i(t + \Delta t) &= \mathbf{r}_i(t) + \mathbf{v}_i(t)\Delta t.
\end{aligned}
$$ (atomic_position_in_time)

### The Position-Verlet Algorithm

The potential energy
$U \left( \mathbf{r_1}, \dots, \mathbf{r_N} \right)$ is a function of
the positions (3N) of all atoms in the system. Due to the complicated
nature of this function and the large number of atoms typically modeled
in classical systems, there is no analytical solution to the equations
of motion, and hence these must be solved numerically. The most common
numerical solutions to integrating the equations of motion are called
finite difference methods. First, the positions, velocities and
accelerations can be approximated by a Taylor series expansion:

$$
\begin{aligned}
\mathbf{r}(t + \Delta t) &= \mathbf{r}(t) + \mathbf{v}(t)\Delta t + \frac{1}{2}\mathbf{a}(t)\Delta t^2 + \dots, \\
\mathbf{v}(t + \Delta t) &= \mathbf{v}(t) + \mathbf{a}(t)\Delta t + \frac{1}{2}\mathbf{b}(t)\Delta t^2 + \dots, \\
\mathbf{a}(t + \Delta t) &= \mathbf{a}(t) + \mathbf{b}(t)\Delta t + \dots,
\end{aligned}
$$ (taylor_exp_verlet)

where $\dots$ denotes higher order derivatives of $\mathbf{r}(t)$. One
can then propagate the position function forwards and backwards in time,
yielding: 

$$
\begin{aligned}
\mathbf{r}(t + \Delta t) &= \mathbf{r}(t) + \mathbf{v}(t)\Delta t + \frac{1}{2}\mathbf{a}(t)\Delta t^2, \\
\mathbf{r}(t - \Delta t) &= \mathbf{r}(t) - \mathbf{v}(t)\Delta t + \frac{1}{2}\mathbf{a}(t)\Delta t^2, \\
\end{aligned}
$$ (step3)

and by summing these the position-Verlet is obtained: 

$$
\mathbf{r}(t + \Delta t) = 2\mathbf{r}(t) - \mathbf{r}(t - \Delta t) + \mathbf{a}(t) \Delta t^2,
$$ (step2)

while the subtraction of the Taylor series for
$\mathbf{r}(t + \Delta t)$ and $\mathbf{r}(t - \Delta t)$ yields:

$$
\mathbf{v}(t) = \frac{\mathbf{r}(t + \Delta t) - \mathbf{r}(t - \Delta t)}{2 \Delta t}.
$$ (step1)

### The Velocity-Verlet Algorithm

The position-Verlet algorithm uses positions and accelerations at time
$t$, and the positions from time $t- \Delta t$ to calculate new
positions at time $t+\Delta t$. The position-Verlet algorithm does not
use velocities explicitly, and as such it is straightforward to
implement and requires minimal storage space. However, this form of the
Verlet algorithm is not self-starting, i.e it requires two time steps
before propagation can take place, and as such is heavily dependent on
initial starting conditions. A modification to the above is the
velocity-Verlet: 

$$
\begin{aligned}
\mathbf{r}(t + \Delta t) &= \mathbf{r}(t) + \mathbf{v}(t)\Delta t + \frac{1}{2}\mathbf{a}(t)\Delta t^2, \\
\mathbf{v}(t + \Delta t) &= \mathbf{v}(t) + \frac{1}{2} \left( \mathbf{a}(t + \Delta t) + \mathbf{a}(t) \right) \Delta t,
\end{aligned}
$$ (velocity-verlet)

which is self-starting and additionally minimises round-off errors.


## Structural Properties from MD


### Periodic Boundary Conditions

Simulating for long times $t$ ensures that the ensemble average can be
approached, however, it is impossible to sample in the limit of the
ergodic theorem $t\to\infty$. Additionally, for bulk-property
calculation it is necessary to use a sufficiently large number of
molecules to ensure that regions of phase space are sampled
representatively, such that one may be confident that the ensemble
average is properly reconstructed from the time average. In practice
there is a relatively small and finite number of molecules for which
simulation is computationally feasible, hence, compared to a macroscopic
system ($\sum N_A$ molecules), the ratio of molecules near the surface
of the simulation box is often too large to be representative.
Computational modelling of molecular systems could therefore have an
artificially imposed doping of surface effects which negatively impacts
the calcuation of any bulk property of interest. To remedy this, surface
effects can be disposed of for all system sizes if periodic boundary
conditions (PBC) are imposed. In this regime, the simulation box is
replicated through space to form an infinite lattice. When a molecule
moves during simulation its periodic images move with the exact same
displacement, thus, if a molecule leaves the central box, one of its
images will enter through the opposite face. This is illustrated in
Figure {numref}`pbc` there
are no walls at the boundary of the central box and the system has no
surface.

```{figure} ../images/pbc.svg
---
height: 400px
name: pbc
---
Simulation box and its periodic images. When a molecule leaves the
central box, it is wrapped around to the opposite side. CC by SA [Grimlock](https://commons.wikimedia.org/wiki/File:Limiteperiodicite.svg)

```

It is not necessary to store the coordinates of all images in a
simulation (this would require infinite space). When a molecule leaves
the box by crossing a boundary, attention may be switched to the
identical molecule entering from the opposite side (see Exercise). 
