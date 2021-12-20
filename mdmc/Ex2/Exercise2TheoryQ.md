
# Theory Questions

<div class="exercise admonition" name="2ex1" style="padding: 10px">
<p class="title">Exercise 1</p>
A quantum harmonic oscillator has energy levels: $ E_n = \left(n + \frac{1}{2}\right)\hbar \omega. $ <br>
Write down the corresponding canonical partition function
$Z(N,V,T)$.  Note that in this case, the partition function forms an
infinite geometric series, and can be rewritten in terms of the
$n \rightarrow \infty$ limit of the series. From the result you
obtain, derive the expectation value of the energy. Use the limit of
the geometric series for $Z$, rather than the sum-based form.
</div>

<div class="exercise admonition" name="2ex2" style="padding: 10px">
<p class="title">Exercise 2</p>
Derive the Boltzmann distribution, {eq}`boltzmann`, from {eq}`recast_expectation_value`, using the   expectation value of the particle number in state $s$, $N_s$.
</div>

<div class="exercise admonition" name="2bex1" style="padding: 10px">
<p class="title">Bonus Exercise 1</p>
Show that, based on {eq}`thermodynamic_properties`, the canonical partition function {eq}`classical_probability` is obtained from {eq}`canonical_density_matrix` if the Hamiltonian admits an orthonormal eigenbasis $\left\{\ket{\Psi_i}\right\}$ and the commutator $\left[\hat{\mathrm{H}},\hat{\mathrm{O}}\right]$ vanishes. (There is no need to use the commutator itself, applying conditions that follow from vanishing commutators is sufficient. If you wish to provide an extended derivation in a general basis, recall that the time-independent case applies.)
</div>

<div class="exercise admonition" name="2bex2" style="padding: 10px">
<p class="title">Exercise 2</p>
Show from {eq}`density_operator` and {eq}`canonical_density_matrix` that the $p_i$ are indeed equal to $\frac{1}{Z}e^{-\beta E_i}$ for pure states, given that there exists a common eigenbasis $\left\{\ket{\Psi_i}\right\}$ to the total Hamiltonian and explain the origin of this restriction.
Explain why the density operator and the expression for the expectation value of an observable assume a general form ({eq}`canonical_density_matrix` and {eq}`thermodynamic_properties`), rather than being defined directly in terms of {eq}`canonical_density_matrix_recast` and {eq}`classical_probability`.
(You may link your answer to the assumptions made in bonus exercise 1).
</div>
