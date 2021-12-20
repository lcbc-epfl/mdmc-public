(prngexp)=
# Appendix: Random and Pseudo-random Numbers


Monte Carlo methods require a source of randomness. It is desirable that
these random numbers are delivered as a stream of independent $U[0,1]$
random variables. It is a necessity to generate random numbers
uniformly, such that bias is not introduced into any physical property
we wish to predict or estimate. There are two options for generating
random numbers: using a physical or pseudo-random number generator. It
would be satisfying to generate random numbers from a process that,
according to a well established understanding of physics, is truly
random. From this, our mathematical model would then match our
computational method. Devices have been built that generate random
numbers from physical processes such as radioactive particle emission,
that are thought to be truly random. Unfortunately, physical random
number generators are awkward to use in practice: simulations cannot be
rerun so generated numbers have to be non-compressively stored, and
random numbers cannot be supplied particularly fast. In contrast, a
pseudo-random number generator (PRNG) uses simple recursions and modular
arithmetic and thus are much faster. The pseudo term refers to the fact
that it is possible to observe the sequence produced by the PRNG, infer
the inner state and then predict future values. Pseudo-random number
sequences are not truly random, however they can still pass the
necessary tests for randomness. For some applications such as
cryptography it is necessary to have pseudo-random number generators for
which prediction is computationally infeasible, but Monte Carlo sampling
does not require this caveat.

Designing pseudo-random number generators is outside the scope of this
course, however, some basic examples are discussed below for your
interest. A well-known example of a PRNG is the multiple recursive
congruential generator (MRG):

 $$
 \begin{aligned}
x_i \equiv  a_1x_{i-1} + a_2x_{i-2} + \ldots + a_kx_{i-k} \pmod M,
\end{aligned}
$$

where $k \ge 1$ and $a_k \neq 0$. Another PRNG worthy of note is the
lagged Fibonacci generator (LFG) which takes the form: 

$$
\begin{aligned}
x_i \equiv x_{i-r} + x_{i-s} \pmod M ,
\end{aligned}
$$

 with carefully
chosen $r$, $s$ and $M$. The LFG is a special case because it is rather
fast. Interestingly, the optimal ratios of $i-r$ and $i-s$ have been
found to closely match the golden ratio.

There are a number of very good and thoroughly tested generators. Among
these high-quality generators, the Mersenne twister algorithm (MT19937)
of Matsumoto and Mishimura (1998) has become the most prominent.
Sometimes, however, very bad number generators are embedded in general
or specific purpose software. L'Ecuyer and Simard (2007) published very
extensive results that found many operating systems, programming
languages and computing environments to have random number generators
that failed many tests of randomness. To conclude, it is best to check
documentation to be sure that your environment or programming language
of choice implements a suitable PRNG by default.