# How to run the exercises
Access the NVE version of the code using this [link](https://noto.epfl.ch/hub/user-redirect/git-pull?repo=https%3A%2F%2Fgithub.com%2Flcbc-epfl%2Fmdmc&urlpath=lab%2Ftree%2Fmdmc%2FEx5%2Ftoy_md.py&branch=main) and activate the virtual environment in the terminal again. 

    source ~/my_venvs/mdmc/bin/activate

Now you can proceed to modify and run the code files. 

# Exercises

## MD Initialization and Temperature

1. Implement the initialization described in the Theory section in our ToyMD code in `toy_md.py` in the section `##INITIALIZATION HERE##`. For this you should pick random velocities using `r.random()` which will produce random numbers between `0` and `1`. You need to shift this random gaussian distribution appropriately and then multiply it such that the width of the velocity distribution matches the kinetic energy at the target temperature. Use the variables `masses[i]` for the mass of particle `i` and Boltzmanns constant `0.0831415`. Remember that for each degree of freedom (e.g velocity in x direction) {eq}`equipart_x` holds.

2. Implement the Berendsen thermostat in the `toy_md.py` and `toy_md_integrate.py` (change the `compute_lambda_T` function) files. 

3. A better thermostat is the Andersen thermostat. It can be implemented as follows. Describe what problems this thermostat will present to us e.g for sampling of diffusion coefficients. What advantage does this thermostat have compared to the Berendsen thermostat?

``` python
#Andersen Thermostat
for i in range(N_part): # Loop over all particles
    if (r.random()<float(md_params["nu-T"])*float(md_params['time-step']): # pick random particles according to nu
        sd=np.sqrt(0.0831415*float(md_params['temperature'])/masses[i])  # Velocity distribution at target temperature
        velocities[i]=(np.random.rand(3)-0.5)*sd # set new random velocities
```





## Force field

Now we can run a MD simulation in our desired NVT ensemble using our code on simple systems. Let's simulate a box of CO2 molecules. 

Investigate the `force_field.txt` file in the `carbon-dioxide` folder and then run a short molecular dynamics simulation using the following parameters:

```
number-of-steps  2000 # Number of integration time steps
time-step        0.001  # Integration time step (picoseconds)
temperature      50  # Simulation temperature
tau-T            0.05 # Temperature coupling time (picoseconds)
output-frequency  10   # Store coordinates every N steps

```

The simulation is run using 

    path/to/toy_md.py -c co2.pdb -p params.txt -f force_field.txt -o co2-traj.pdb -w co2-final.pdb

where `co2-traj.pdb` is a trajectory written each `output-frequency` steps and `co2-final.pdb` is the final geometry after the simulation has run the specified number of steps. 

Open the resulting trajectory in VMD and plot the bond distance of a C-O bond. What to you observe?

(vmd)=
:::{admonition,dropdown,tip} How to open trajectory in VMD and plot the distance

To open a trajectory or structure in VMD, navigate your terminal to the
file of interest (using the `cd` command) and type the following command:

    vmd name_of_file.pdb

You can explore the system by holding your left mouse button and moving.
You can translate the system by pressing `T` or selecting
`Mouse \rightarrow Translate Mode` in the VMD Main panel. Rotation and
scaling can be performed from this menu as well, or you can just type
`r` and `s` respectively. To change the centre of the viewport (*i.e*
the position about which geometry operations occur), press `c` and
select a particle to move the centre to.

To view the trajectory as a movie, press the play button from the VMD
Main panel, or manually move the counter bar to scroll through the
trajectory. Experiment with the buttons on this panel to become more
comfortable - you will need this program for the following exercises.

**Changing the Drawing Mode**

Click on `Graphics` in the VMD Main panel, and go to
`Representations...`. On the `Draw style` tab, select `ColourID` from
the `Colouring Method` drop-down box, and select a colour of your
choosing. Next, select `CPK` from the `Drawing Method` drop-down box,
and change `Sphere Scale` to 0.1 and `Sphere Resolution` to 20. Click
`Apply` and close the `Graphical Representations` window.

**Changing the Viewport Background**

Click on the `Graphics` item in the VMD Main panel, and select the
`Colours...` option. Next, click on the `Display` item within the
`Categories` list, and select `Background`. Change the background of the
viewport to `8 white`. Close the `Colour Controls` window.

**Rendering and Saving**

To save a snapshot of the current frame, go to `File` in the VMD Main
panel, and click the `Render...` option. Change the filename to
something meaningful, and click `Start Rendering`. The mac program
`Preview` will immediately open, and from there you can export the
snapshot as a `.png` image.

:::

4. Visualize the radial distribution function. What do you observe. **Bonus:** What would you observe for a heterogenous system?  


## Timestep and coupling

1. Test the influence of the coupling parameter $\tau$ and timestep $dt$. Test 3 different settings of $\tau$ and $dt$ and describe what you observe.



