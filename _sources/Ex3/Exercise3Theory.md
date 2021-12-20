
# Theory
## Monte Carlo and the Importance of Importance Sampling


In the last exercise session, you applied the simplest Monte Carlo
technique - a *random sampling* technique - to find the value of $\pi$.
A generalisation of such a Monte Carlo scheme is, however, less than
straightforward. Imagine you are interested in a microcanonical
observable average: 

$$
\begin{aligned}
\left<O\right> = \frac{\int_\Gamma O(\Gamma)e^{-\beta E(\Gamma)} \mathrm{d}\Gamma}{\int_\Gamma e^{-\beta E(\Gamma)} \mathrm{d}\Gamma} .
\end{aligned}
$$ (microcanonical_average)

If such an integral were to be obtained from numerical quadrature
procedures, with a suitably fine mesh with $M$ points along each degree
of freedom, the calculation would become completely untractable all too
quickly, since the procedure scales as $O(M^{3N})$. Furthermore, such a
scheme would be associated to a large statistical error; numerical
quadratures work reasonably fine for functions that are smooth on the
scale of the mesh - but the Boltzmann factor is a highly oscillatory
quantity. The oscillatory nature of $e^{-\beta E(\Gamma)}$ will
furthermore result in many points of no importance being sampled, since
their Boltzmann factor will be vanishing. The idea behind *importance
sampling* lies in an extended sampling of regions where the Boltzmann
factor is of considerable magnitude, with fewer sampling moves
elsewhere. Very simple importance sampling schemes can be constructed,
but they fail when used on multidimensional integrals, since they
require analytical expressions for the partition function. If that were
possible, there would be little interest in performing computer
simulations - as discussed in statistical mechanics, all thermodynamic
quantities can directly be determined if an analytic expression for the
partition function is known.

## The Concept of Detailed Balance


When calculating ensemble averages, one is often not interested in the
configurational part of the partition function, but in the average
instead: 

$$
\begin{aligned}
\left<O\right> = \frac{\int O(\mathbf{q})e^{-\beta V(\mathbf{q})} \mathrm{d}\mathbf{q}}{\int e^{-\beta V(\mathbf{q})} \mathrm{d}\mathbf{q}},
\end{aligned}
$$ (ensembleaverage)

where we have restricted the expression to a configurational average,
integrating out over all momenta. One is thus left with the
*configurational* partition function, containing only the *potential*
energy in the exponent, rather than the potential and kinetic term. (You
can easily convince yourself that this is possible if the potential and
kinetic term are not coupled). Rewriting {eq}`ensembleaverage` in terms of a probability
density $\mathcal{N}(\mathbf{q})$ (*cf.* the Boltzmann distribution),
one finds: 

$$
\begin{aligned}
\left<O\right> &= \int O(\mathbf{q}) \mathcal{N}(\mathbf{q}) \mathrm{d}\mathbf{q} \\
\mathcal{N}(\mathbf{q}) &= \frac{e^{-\beta V(\mathbf{q})}}{\int e^{-\beta V(\mathbf{q})}\mathrm{d}\mathbf{q}}.
\end{aligned}
$$ (ensemble_average_boltzmann)

Therefore, an ensemble average of an observable should be accessible by
random sampling *if* this sampling can be carried out according to the
probability distribution defined in $\mathcal{N}(\mathbf{q})$. In such a
case, *on average*, the number of points generated in a volume element
$\mathrm{d}\mathbf{q}$ must be equal to $L\mathcal{N}(\mathbf{q})$,
where $L$ denotes the total number of points which are generated. One
may therefore rewrite the above expression in an approximate form:

$$
\begin{aligned}
\left<O\right> \approx \frac{1}{L} \sum_{i=1}^L n_i O(\mathbf{q}_i).
\end{aligned}
$$ (approx_ensemble_average)

The average over an observable will be given by the sum over all $L$
points $i$ that have been generated in the sampling, weighted each by
the number of occurence $n_i$ of state $O(\mathbf{q}_i)$. Still, one is
left with the problem that the points have to be generated with a
relative probability that corresponds to the Boltzmann distribution
$\mathcal{N}$.


Consider a system that is in equilibrium and where all states are
equally likely to occur. In order for the system to remain in its
equilibrium state, every move from an old state $o$ to a new state $n$
must be compensated by an inverse move. If we denote the transition
probability by $\mathcal{P}$, this implies:

 $$
 \begin{aligned}
\mathcal{P} (o \rightarrow n) = \mathcal{P} (n \rightarrow o).
\end{aligned}
$$ (transition_p)

In a system where the probability distribution is not uniform, but given
by some probability distribution $\mathcal{N}$ - such as the Boltzmann
distribution - instead, one will equivalently find: 

$$
\begin{aligned}
\mathcal{N}(o)\mathcal{P} (o \rightarrow n) = \mathcal{N}(n) \mathcal{P}(n \rightarrow o).
\end{aligned}
$$ (detailed_balance)

That is, the transition matrix $\mathcal{P}$ that governs the
probability of a step to occur must satisfy the above relation. Such a
*detailed balance* ensures that at equilibrium, every process is
equilibrated by its reverse.

## The Metropolis Algorithm

There are many possible choices for $\mathcal{P}$, with maybe the most
straightforward one brought forward by Metropolis *et al*. In the
Metropolis Monte Carlo scheme the total transition probability
$\mathcal{P}$ is expressed as a product of the probability for moving
from $o$ to $n$, $P^\prime(o \rightarrow n)$, and the probability of
accepting this trial move, $P_\text{acc}(o \rightarrow n)$, such that:

$$
\begin{aligned}
\mathcal{P} (o \rightarrow n) = P^\prime (o \rightarrow n)P_\text{acc}(o \rightarrow n).
\end{aligned}
$$ (total_transition_prob)

The transition matrix $P^\prime$ is chosen to be symmetric, such that
$P^\prime(o \rightarrow n) = P^\prime(n \rightarrow o)$. Hence when
detailed balance is maintained, the acceptance probability is:

$$
\begin{aligned}
\frac{P_\text{acc}(o \rightarrow n)}{P_\text{acc}(n \rightarrow o)} &= \frac{\mathcal{N}(n)}{\mathcal{N}(o)} \\
                &=\frac{e^{-\beta V(n)}}{e^{-\beta V(o)}} \\
                &= e^{-\beta\Delta V(n \rightarrow o)}.
                \end{aligned}
                $$ (acceptance_prob)

Many possibilities exist that account for this condition, with the
choice in the Metropolis algorithm being: 

$$
\begin{aligned}
P_\text{acc}(o \rightarrow n) =
\begin{cases}
\frac{\mathcal{N}(n)}{\mathcal{N}(o)} & \text{if}\ \mathcal{N}(n) < \mathcal{N}(o) \\
1 & \text{if}\ \mathcal{N}(n) \ge \mathcal{N}(o),
\end{cases}
\end{aligned}
$$ (metropolis_acceptance)

 where the factor $1$ in the second case is
due to $P_\text{acc}(o \rightarrow n)$ being a probability which cannot
exceed a value of $1$. The total transition matrix $\mathcal{P}$ is
then: 

$$
\begin{aligned}
\mathcal{P}(o \rightarrow n) &=
\begin{cases}
\frac{\mathcal{N}(n)}{\mathcal{N}(o)}P^\prime(o \rightarrow n) & \text{if}\ \mathcal{N}(n) < \mathcal{N}(o) \\
P^\prime(o \rightarrow n) & \text{if}\ \mathcal{N}(n) \ge \mathcal{N}(o)
\end{cases}
\end{aligned}
$$ (total_transition_matrix)

and 

$$
\begin{aligned}
\mathcal{P} (n \rightarrow o) &= 1 -\sum_{n \ne o} \mathcal{P}(o \rightarrow n).
\end{aligned}
$$ (prop_n_o)

The criterion whether or not to accept a trial move is inferred from the
above equations and the normalisation of the probability distribution:

$$
\begin{aligned}
P_\text{acc}(o \rightarrow n) &= e^{-\beta\left[ V(n) - V(o) \right]} \\
                            &< 1.
\end{aligned}
$$  (acceptance_probability_o_n)

If $V(n) < V(o)$, the
move is always accepted. However, after a move for which $V(n) > V(o)$,
a random number is generated out of a uniform distribution in the
interval $[0,1]$, such that the interval spans the same range as the
Boltzmann factor. The probability that the random number $X$ is less
than $P_\text{acc}(o \rightarrow n)$ is equal to
$P_\text{acc}(o \rightarrow n)$ itself: 

$$
\begin{aligned}
P\left(X < P_\text{acc}(o \rightarrow n)\right) = P_\text{acc}(o \rightarrow n).
\end{aligned}
$$ (prob_less_random)

The trial move is then only accepted if
$X < P_\text{acc}(o \rightarrow n)$, and rejected otherwise. This scheme
guarantees that the probability of accepting some trial move
$o \rightarrow n$ is equal to the probability
$P_\text{acc}(o \rightarrow n)$. Thus, the system moves towards an
equilibrium distribution ($P_\text{acc} = 1$ for new states lower in
energy). Once equilibrium is reached, it is ensured to retain the
equilibrium distribution ($P_\text{acc}$ according to the Boltzmann
factor). The overall acceptance probability is: 

$$
\begin{aligned}
P_\text{acc}(o \rightarrow n) &= \min \left(1,\frac{P_\text{acc}(o \rightarrow n)}{P_\text{acc}(n \rightarrow o)}\right) \\
&= \min \left(1, e^{-\beta\left[V(n) - V(o) \right]}\right),
\end{aligned}
$$ (overall_acceptance_prob)

*i.e.* the acceptance probability is 1 if the Boltzmann factor exceeds
1, and it is the Boltzmann factor itself otherwise. This guarantees that
the sampling preserves the equilibrium distribution, *i.e.* it fulfills
*detailed balance*.

(metropolis)=
## An example of a Metropolis Monte Carlo Algorithm 



### Ensemble Averages from the Metropolis Monte Carlo Algorithm

#### The Photon Gas

In this exercise you will be applying the Metropolis Monte Carlo
algorithm to calculate the state occupancy of a photon gas. The photon
gas is a gas-like collection of photons, which has many of the same
properties of a conventional gas such as pressure, temperature and
entropy. The most common example of a photon gas in equilibrium is
black-body radiation. Black-body radiation is an electromagnetic field
constructed by a superposition of plane waves of different frequencies,
with the caveat that a mode may only be excited in units of $\hbar w$.
This fact leads to the concept of photons as quanta of the
electromagnetic field, with the state of the field being specified by
the occupancy $\left<n_j\right>$ of each of the modes or, in other
words, by enumerating the number of photons with each frequency.

The ensemble average of the state occupancy $\left<n_j\right>$ of a
photon gas can be calculated analytically. Deriving the total energy of
an idealised photon gas from quantum mechanics we know that $U$ can be
written as the sum of the harmonic oscillation energies:

$$
\begin{aligned}
U= \sum_{j=1}^{N} n_j w_j \hbar = \sum_{j=1}^{N} n_j \epsilon_j,
\end{aligned}
$$ (total_energy_photongas)

where $\epsilon_j$ is the energy of state $j$, $n_j$ is the occupancy of
state $j$ ($n_j \in 0,1,2,\cdots, \infty$), $N$ is the total number of
photons and $w$ is the oscilator frequency. In this exercise, you are
going to compute the ensemble average of the occupancy
$\left<n_j\right>$. The scheme you will employ is as follows:

1.  Start with an arbitrary $n_j$.

2.  Decide to perform a trial move to randomly increase or decrease
    $n_j$ by 1.

3.  Accept the trial move with probability: 

    $$
    \begin{aligned}
    P_{acc}(o \rightarrow n)= \min \left(1, e^{-\beta(U(n)-U(o))}\right),\end{aligned}
    $$
    
    where $U(n)$ and $U(o)$ are the energies of the new and old states
    respectively.

4.  Update averages regardless of acceptance or rejection.

5.  Go to step 2).






### Configurational Sampling using the Metropolis Monte Carlo Algorithm


#### The Lennard-Jones Potential

In this exercise you will study the configuration of a collection of
gaseous particles using the Metropolis Monte Carlo algorithm. The system
includes $N$ particles within a cubic box of volume $V$ at a given
temperature $T$, in any configuration permitted by the Lennard-Jones
potential: 

$$
\begin{aligned}
U(r) = 
\begin{cases} 
4\epsilon \left[ \left(\frac{\sigma}{r}\right)^{12} - \left(\frac{\sigma}{r}\right)^6 \right] & \text{if r $\le$ r$_c$} \\
                0 & \text{if r $>$  r$_c$}. 
\end{cases}
\end{aligned}
$$ (LJpotential)

This potential traditionally has an infinite range, however, the
potential decays rapidly with separation distance and can be effectively
ignored at large $|r|$, resulting in a faster calculation. In practical
applications it is customary to establish a cutoff $r_c$ and disregard
pairwise interactions separated beyond this radius. This truncation
leads to a discontinuity in the pairwise potential energy function;
large numbers of these events are likely to spoil energy conservation
thus an improvement is to shift the potential such that the energy
continuously approaches zero at $r_c$: 

$$
\begin{aligned}
U(r) = 
\begin{cases} 
4\epsilon \left( \left[\left(\frac{\sigma}{r}\right)^{12} - \left(\frac{\sigma}{r}\right)^6\right] - \left[\left(\frac{\sigma}{r_c}\right)^{12} - \left(\frac{\sigma}{r_c}\right)^6\right]  \right) & \text{if $r \le r_c$} \\
                0 & \text{if $r > r_c$}.   
                 \end{cases}
\end{aligned}
$$ (shifted_lj)

This approach results in a potential that produces discontinuities in
the first and higher order derivatives. To compensate, switching
functions are often employed to smoothly and continuously taper the pair
potential to zero between two cutoff limits.

Truncating pair interactions systematically removes a non-trivial
contribution to the net potential energy and pressure. For interactions
that are cut but not shifted, one can approximately add the interactions
beyond $r_c$ to the total energy and pressure, assuming the radial
distribution function $g(r > r_c) \approx 1$: 

$$
\begin{aligned}
 U &= U_{pairs} + U_{tail}\\
P &= P_{pairs} + P_{tail},\end{aligned}
$$ (shift)

 where

$$
  \begin{aligned}
 U_{tail}&= \frac{8\pi N^2}{3V}\epsilon\sigma^3\left[\frac{1}{3}\left(\frac{\sigma}{r_c}\right)^9 - \left(\frac{\sigma}{r_c}\right)^3\right]\\
P_{tail}&= \frac{16\pi N^2}{3V}\epsilon\sigma^3\left[\frac{2}{3}\left(\frac{\sigma}{r_c}\right)^9 - \left(\frac{\sigma}{r_c}\right)^3\right].
\end{aligned}
$$ (u_tail_pot)

To sample configurational space using the Lennard-Jones potential, a
randomly selected particle is first randomly translated to generate a
new system configuration. Whether the new configuration is accepted
depends on the acceptance probability discussed in section
{numref}`metropolis` This procedure repeats iteratively such
that classical phase space is directly sampled and ensemble averages of
physical properties become arithmetic averages over their sampled
values.

:::{admonition} Exercise 1
:class: exercise
Show that based on the form of the Hamiltonian: 

$$
    \begin{aligned}
    \mathrm{H} = \mathrm{T}(\mathbf{p}) + \mathrm{V}(\mathbf{q}),
    \end{aligned}
$$

the partition function can be divided into a kinetic and potential part, and for an ensemble average of an observable $O(\mathbf{q})$ that depends on $\mathbf{q}$ only, one has: 
    
$$
\begin{aligned}
\left<O(\mathbf{q})\right> &= \frac{\int_\Gamma O(\Gamma)e^{-\beta E(\Gamma)} \mathrm{d}\Gamma}{\int_\Gamma e^{-\beta E(\Gamma)} \mathrm{d}\Gamma} \\
&= \frac{\int O(\mathbf{q})e^{-\beta V(\mathbf{q})} \mathrm{d}\mathbf{q}}{\int e^{-\beta V(\mathbf{q})} \mathrm{d}\mathbf{q}},
     \end{aligned}
$$
    
which is the equation you have encountred in the section on detailed balance.
:::

:::{admonition} Exercise 2
:class: exercise
In the Metropolis scheme, why is it important that
    $P^\prime$ be a symmetric matrix?
:::
