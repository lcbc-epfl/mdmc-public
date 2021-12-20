(theory)=
# Theory
## Solvent Models in Molecular Dynamics

The simulation of complex systems in their natural environment poses a
considerable challenge; the possibility of simulating a protein in a
cellular environment is not only constrained by the protein size itself,
but also by the large number of solvent molecules (water molecules,
ions) surrounding the biomolecular complex of interest. Since many of
the properties of any system in solution are governed by its
environment, the inclusion of solvation effects is a crucial ingredient
for any successful MD simulation (idem for MC).

### Explicit Solvent

The sheer number of water molecules surrounding a protein will
considerably increase the computational cost of a simulation, since the
simulation box has to be chosen reasonably big in order for the solvent
to properly mimick the properties of a bulk system and to prevent
interaction between the periodic images of the solute. Solvent molecules
have to be treated like the rest of the system (be it by a force field
or *first principles* methods), and are therefore referred to as an
*explicit solvent*.

The computational cost of using an explicit solvent can often be reduced
by choosing a suitable level of accuracy (*e.g.* in *ab initio* QM/MM
simulations, the chemically inert solvent molecules may be treated using
a force field). However, for larger systems that make exclusive use of
parametrised potentials, the number of molecules needed to solvate the
structure may easily overpass the number of atoms in the structure of
interest. This makes an explicit treatment prohibitively expensive due
to an exorbitantly high number of degrees of freedom that have to be
explicitly considered.

It is therefore often necessary to further simplify the description of
the system by using appropriate *implicit* solvent models instead of
explicit solvent.

### Implicit Solvent

Although an explicit description of solvent molecules is clearly
preferrable due to the natural inclusion of effects such as the
solvent's response to polarisation, bridging and hydrogen-bonding, an
implicit mean-field contribution may already capture the most important
effects of the environment (such as changes in polarisability).
Formally, the solvent contribution to the Helmholtz (or Gibbs) free
energy ($F$ and $G$, respectively) may be divided into different terms:

$$
\begin{aligned}
\Delta F_\text{sol} = \Delta F_\text{cav} + \Delta F_\text{vdW} + \Delta F_\text{ele},
\end{aligned}
$$ (free_energy_solvation)

where the energy is decomposed in components due to the formation of a
cavity in the solvent by the solute (*cav*) and the resulting van der
Waals (*vdW*) and electrostatic (*ele*) interactions. Different implicit
solvent models may account for different terms in eq. 1.
Solvent-accessible surface area models may take the entire
$\Delta F_\text{sol}$ into account, the Poisson-Boltzmann and
Generalised-Born methods model solely $\Delta F_\text{ele}$.

#### SASA: Solvent-accessible surface area models

SASA models assume the interactions between solute and solvent to be
proportional to the solute's surface area. The free energy of solvation
is described by a mean solvent potential
$V_\text{solv}^\text{SASA}(\mathbf{r}_i)$ that depends on the
atom-specific solvation energy per surface area $\sigma_i$ and the
solvent-accessible surface area (SASA$_i$) for atom $i$:

$$
\begin{aligned}
V_\text{sol}^\text{SASA} = \sum_i \sigma_i \cdot \text{SASA}_i(\mathbf{r}_i).
\end{aligned}
$$ (sasa)

Various algorithms of different accuracy exist to calculate the SASA.

#### PB: Poisson-Boltzmann

The Poisson equation relates the scalar electric potential
$\Phi(\mathbf{r})$ to the charge density $\rho(\mathbf{r})$:

$$
\begin{aligned}
\nabla \cdot \left[\epsilon(\mathbf{r})\nabla \Phi(\mathbf{r})  \right] = -\frac{\rho(\mathbf{r})}{\epsilon_0},
\end{aligned}
$$ (eqpb1)

where $\epsilon(\mathbf{r})$ is the local dielectric constant and
$\epsilon_0$ the vacuum permitivity. The solution of Poisson's equation
for the potential requires knowing the charge density distribution such
that

 $$
 \begin{aligned}
\Phi(\mathbf{r}) = \frac{1}{4\pi \epsilon_0 \epsilon(\mathbf{r})} \int \frac{\rho(\mathbf{r})}{\left|\mathbf{r}\right|} \mathrm{d}V(\mathbf{r}).
\end{aligned}
$$ (charge_density_dist)

In the case of an ionic solution (solvent), the electrostatic potential
resulting from a solvated charge density $\rho^{f}(\mathbf{r})$ (solute)
should account for electrostatic forces between solute and solvent as
well as the ions thermal motion. Assuming ions as point charges, their
concentrations is expected to follow a Boltzmann distribution at thermal
equilibrium: 

$$
c_i(\mathbf{r}) = c_i^{\infty} \cdot \text{exp}\left(-\frac{U_i(\mathbf{r})}{k_B T}\right)
$$ (conc)

where $c_i^{\infty}$ represents the concentration of the ion $i$, of
electrostatic energy $U_i(\mathbf{r})$, at a distance of infinity from
the solute (bulk concentration). $k_B$ is the Boltzmann constant and $T$
the temperature.

Considering {eq}`conc`
in {eq}`eqpb1`, one
obtains a special case of the Poisson equation, the *Poisson-Boltzmann*
(PB) equation. You will go through the derivation of the PB equation as
an exercise. The PB equation can further be linearized under the
assumption that the potential is small which yields: 

$$
\begin{aligned}
\nabla \cdot \left[\epsilon_0\epsilon(\mathbf{r})\nabla \Phi(\mathbf{r})  \right] + \rho_\text{ext}(\mathbf{r}) =  \left(\frac{q^2}{k_B T} \sum_i c_i^{\infty} z_i^2\right) \Phi(\mathbf{r})
\end{aligned}
$$ (eqpb2)

with $z_i$ the valence of the ion, $q$ is the charge of a proton and
$\rho_\text{ext}(\mathbf{r})$ is an effective density from solute and
solvent.

#### GB: The Generalised Born equation

Alternatively, the Poisson-Boltzmann equation may be solved for a charge
in the centre of an ideally spherical solute, yielding the Generalised
Born (GB) equation: 

$$
\begin{aligned}
\Delta F_\text{solv} = \frac{1}{2} \left( \frac{1}{\epsilon_\text{int}} -\frac{1}{\epsilon_\text{ext}} \right) \frac{q^2}{\alpha}.
\end{aligned}
$$ (gb)

Here, $q$ is the unit charge, the solute has radius $\alpha$ and an
internal dielectric constant $\epsilon_\text{int}$ and is embedded in a
solvent with a dielectric $\epsilon_\text{ext}$. The GB method emulates
a local pseudo-ideal solution within a non-ideal solute by varying
$\alpha$. This *effective Born radius* adjusts the local screening to
the best possible value with respect to some reference data. The
effective Born radii of all species are then used to compute GB pair
terms: 

$$
\begin{aligned}
\Delta F_\text{solv} = \frac{1}{2} \sum_{ij} \frac{\left( \frac{1}{\epsilon_\text{int}} -\frac{1}{\epsilon_\text{ext}} \right)
 q_i q_j}{\left(r_{ij}^2 +\alpha_i \alpha_j e^{-\frac{r_{ij}^2}{4\alpha_i \alpha_j}} \right)^{\frac{1}{2}} }.
 \end{aligned}
 $$ (gb_pair_terms)

## Properties from MD

The great value of MD simulation techniques is rooted in the possibility
of easily deriving a certain set of properties from a complete
trajectory. Although the visual inspection of the changes that the
system undergoes as time evolves may be intuitively helpful, other tools
are needed to properly quantify the observed changes. Appropriate
measures may be based on simple concepts such as atomic displacements up
to more involved frameworks where the power spectra of the
time-evolution of the system are considered.

### RMSD

The root-mean-square deviation (RMSD) of atomic positions is an
important measure for studying conformational differences between
superimposed structures (*e.g.* proteins). Typically, structurally
relevant parts of a system are identified, superimposed and then aligned
such that the RMSD {eq}`rmsd` is minimised. This allows for a quantification of the
average displacement of the atoms between different systems, or between
different structures (snapshots) of the same system: 

$$
\begin{aligned}
\text{RMSD}^{a-b} = \sqrt{\frac{1}{N} \sum_{i=1}^N \left(\mathbf{r}_i^a-\mathbf{r}_i^b\right)^2},
\end{aligned}
$$ (rmsd)

where $a, b$ denote different structures, and the summation runs over
all $i$ atoms of the same type up to the $N$ atoms of interest. RMSD can
be especially useful in comparing protein structures, *i.e.* between
native and partially folded conformations.

### Pressure and the virial theorem

Many chemically relevant processes take place in the isothermal-isobaric
ensemble ($NpT$). In $NpT$-simulations, the simulation cell size changes
during the course of the simulation in order to keep the pressure
constant. The pressure is in practice often calculated based on the
*virial theorem* of Clausius. The virial is defined as:

$$
\begin{aligned}
W = \sum_i^N \mathbf{q}_i \frac{\partial \mathbf{p}_i}{\partial \mathbf{q}_i},
\end{aligned}
$$ (virial_theorem)

where $\mathbf{p}$ and $\mathbf{q}$ have their obvious meanings and the
sum runs over all $i$ out of a total of $N$ atoms. According to the
virial theorem, this is equivalent to: 

$$
\begin{aligned}
W = -3Nk_BT.
\end{aligned}
$$ (virial_alt)

 The total virial of a system consists of an
ideal gas part ($-3PV$) and a contribution due to the interaction
between the particles: 

$$
\begin{aligned}
W = -3PV + \sum_{i=1}^N \sum_{j=N+1}^N r_{ij} \frac{\partial \upsilon(r_{ij})}{\partial r_{ij}},
\end{aligned}
$$ (virial)

where $f_{ij} = \frac{\partial \upsilon(r_{ij})}{\partial r_{ij}}$
denotes the forces on the ions. The resulting expression for the
pressure is simply: 

$$
\begin{aligned}
P = \frac{1}{V} \left[Nk_BT - \frac{1}{3k_BT}\sum_{i=1}^N \sum_{j=i+1}^N r_{ij} f_{ij} \right].
\end{aligned}
$$ (pressure)



# Exercises 

## Theory - Solvent Models in Molecular Dynamics

1.  Derive {eq}`eqpb2` from
    {eq}`eqpb1` by
    passing via the exponential form of the Poisson-Boltzmann equation
    {eq}`conc`.
    Give an appropriate expression for the equilibrium charge density
    $\rho_\text{ext}(\mathbf{r})$ in the Poisson-Boltzmann approach.

2.  How may the solvent environment (especially in the case of a polar
    solvent, such as dimethylformamide (DMF), and a polar
    hydrogen-bonding solvent, such as water) influence the properties
    (conformation, reactivity) of the solute? Which solvent do you
    expect to be more difficult to mimick by an implicit model, DMF or
    water?

3.  In the context of the previous questions, explain possible
    advantages and pitfalls of using an implicit solvent compared to an
    explicit treatment.

4.  **Bonus:** How expensive is the computation of the pressure in
   {eq}`pressure`, via the virial, in an MD and an MC
    algorithm, respectively?

5.  **Bonus:** Derive the ideal gas part of the virial in
    {eq}`virial`.

6.   A protein has the tendency to fold much quicker in
    implicit than in explicit solvent. Why is this? What are possible
    issues?


