

(questions)=
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

## Results analysis - Protein Modelling 

For all of the following questions, it is recommended to display
structures using two separate representations in VMD. Once you have
loaded a new protein structure or trajectory, create two new
representations by going to `Graphics→Representations` and
clicking `Create Rep`. Define one of these representations with
`Drawing Method` set to `Licorice` and the other set to `NewCartoon`.
You may also find it useful to differenciate between protein structures
by modifying the `Coloring Method` to `Molecule`.


1. Follow the instructions in {doc}`TRP_Cage_OpenMM_colab` and run the folding simulation. 
    Calculate the correct number of steps for the simulations to run 50 ps of heating and 20 ns of dynamics and report those numbers in your report. Then download the `trp_cage_gb.prmtop`, `trp_cage_gb.pdb`,`trp_cage_gb.nc` files from Google Colab.
2.  Load the `trp_cage_gb.pdb` starting structure in VMD. Include an
    image of this structure in your report. Are there any residues which
    would contribute to the instability of the starting structure in its
    current conformation, why? 

3.  What type of structure is the folded Trp-cage miniprotein? List the
    main components contributing to this structure, including the
    residues which are responsible for their formation.

4.  Load the `.prmtop` and then the `.nc` file into the same molecule in VMD. Explore the
    trajectory, and identify all important hydrogen bonds in the
    formation of any secondary structures you observe. Tabulate some of
    these hydrogen bonds in your report. Monitor an individual hydrogen
    bond involved in a secondary structure, and provide the graph of the
    hydrogen bond length over time. Can you infer at which interval (in
    nanoseconds) the secondary structure forms? **Note:** VMD always uses the first frame to determine secondary structure. If you want secondary structures elements to be correctly updated with the cartoon representation you need to go to `Graphics` , `Representation` click on the `NewCartoon` representation and then in the `Trajectory` tab you need to activate `Update selection every frame`.

5.  Perform a hydrogen bond analysis on the trajectory, and plot the moving average using {doc}`hydrogenbonds`.  Include the
    moving-average graph in your report, and explain the observed trend with reference to the structural components of the Trp-cage miniprotein.

6.  Download the experimental structure with PDB code: `1L2Y`. Align the
    trajectory to the experimental structure using the RMSD fit
    described in {numref}`rmsd`. Graph the RMSD over the course of the trajectory
    and include it in your report, and explain the fluctuations in RMSD
    over the trajectory. Does the trajectory reach the same conformation
    as the experimental structure?

7.  Why is it useful to constrain bond lengths for larger MD simulations
    (typically with the SHAKE algorithm)? Which bonds would you typically constrain in such a scenario, and why?

8.  **Bonus:** Which properties do you need to take into account in order to select an appropriate timestep for your MD simulation? Are there any other reasons you might wish to reduce or increase this timestep?
