# How to run the exercises

Click this [link](https://noto.epfl.ch/hub/user-redirect/git-pull?repo=https%3A%2F%2Fgithub.com%2Flcbc-epfl%2Fmdmc&urlpath=lab%2Ftree%2Fmdmc%2FEx4%2Ftoy_md.py&branch=main) to download the files for this exercise. 

Afterwards, open the terminal and type the following commands:

    python3 -m venv ~/my_venvs/mdmc
    source ~/my_venvs/mdmc/bin/activate
    pip install --upgrade pip
    pip install numba

This will take about ~5 minutes to complete.

If you want to test things, you can of course also create Python Notebooks to execute your code interactively. 

To test whether your implementation works you can run a short MD run of a box of CO2 molecules by opening the terminal, navigating to the `carbon-dioxide` folder using `cd carbon-dioxide` and then running this command. 

    ../toy_md.py -c co2.pdb -p params.txt -f force_field.txt -o traj.pdb -w co2-output.pdb

An example output should look like this. 

```
$ ../toy_md.py -c co2.pdb -p params.txt -f force_field.txt -o traj.pdb -w co2-output.pdb
There are 432 bonds
There are 216 angles
There are 648 conect
There are 648 exclusions
Step:     0 Epot   -588.570 Ekin     72.833 Etot   -515.736 T    9.01 lambda 1.00
Step:     1 Epot   -794.971 Ekin    251.656 Etot   -543.316 T   31.14 lambda 1.00
Step:     2 Epot  -1004.530 Ekin    440.865 Etot   -563.665 T   54.55 lambda 1.00
Step:     3 Epot  -1189.030 Ekin    543.860 Etot   -645.170 T   67.30 lambda 1.00
Step:     4 Epot  -1170.759 Ekin    514.693 Etot   -656.066 T   63.69 lambda 1.00
Step:     5 Epot   -949.895 Ekin    376.968 Etot   -572.926 T   46.65 lambda 1.00
Step:     6 Epot   -820.466 Ekin    204.490 Etot   -615.976 T   25.30 lambda 1.00
Step:     7 Epot   -695.645 Ekin     80.842 Etot   -614.804 T   10.00 lambda 1.00
Step:     8 Epot   -710.875 Ekin     61.903 Etot   -648.973 T    7.66 lambda 1.00
Step:     9 Epot   -795.046 Ekin    155.754 Etot   -639.292 T   19.27 lambda 1.00
```


# Questions

## Time Evolution

1.  Derive the form of $\mathbf{r}(t + \Delta t)$ in the velocity-Verlet
    {eq}`velocity-verlet`. **Hint**: solve equation  {eq}`step1` for  $\mathbf{r}(t - \Delta t)$, and use equations {eq}`step2` and  {eq}`step3`.

2.  Derive the form of $\mathbf{v}(t + \Delta t)$ in the velocity-Verlet
    {eq}`velocity-verlet`. **Hint**: recast equations  {eq}`step1` and {eq}`step2` to a
    timestep $\Delta t$ in the future, and use the result obtained  above.

3.  Implement the velocity verlet algorithm in the Toy MD program.

## Sampling Phase Space using Molecular Dynamics

1.  How does an MD program work? Describe schematically how one
    performs a molecular dynamics simulation. Point out the main
    differences between your scheme and Monte Carlo methods. 

2.  Describe a possible implementation of periodic boundary conditions and provide an implementation in `toy_md_forces` to compute the distance of two particles taking into account the perodic boundary conditions in the `distance_PBC` function (i.e a particle at the edge of the primary cell has a very short distance to the particle in the next cell). 

    With a box size of `[2,2,2]` and three points the elementwise distances between point `[0.5,0.5,0.5]` should be the same to the points `[-0.5,-0.5,-0.5]` and `[1.5,1.5,1.5]`. The distance should be `[1,1,1]`.

3.  Why are most MD and MC simulations based on periodic systems?
    Explain the main purpose of periodic boundary conditions in these schemes.

4. **Bonus** What ensemble does the code in the ToyMD program sample in? Which of the quantities linear momentum $p$ and angular momentum $L$ are conserved when running with and without periodic boundary conditions?

