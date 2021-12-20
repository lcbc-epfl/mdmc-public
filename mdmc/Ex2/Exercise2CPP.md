(Ex2cpp)=
# Appendix: C++ code 
This section walks you through the writting of a simple C++ code to
answer the questions in this exercise. You can choose to write your own
code using the following procedure or use the provided incomplete C++
code.

In a directory of your choosing, create a file called ’`boltzmann.cpp`’
and open it in a text-editor. Within this file, begin by adding the
following:

    #include <iostream>
    #include <fstream>
    #include <math.h>
    #include <cstdlib>
    #include <string>

    using namespace std;

    double calculateStateOccupancy(double reducedTemperature, double stateEnergy);
    void outputToFile(double *distribution, string outputFile);

    int numberOfEnergyLevels = 0;
    double reducedTemperature = 0.0;
    double partitionFunction = 0.0;

    double *distribution;

    int main(int argc, char * argv []) {
      
      return 0;
    }

This program will calculate the Boltzmann distribution of the fictitious
system at a given temperature and degeneracy. The variables you require
to perform this calculation are `numberOfEnergyLevels`,
`reducedTemperature`, `normalise` and `distribution`.

## Parsing Command-line Arguments

The number of energy levels you wish to calculate the distribution over
(`numberOfEnergyLevels`) as well as the reduced temperature of your
system (`reducedTemperature`) will need to be passed into your main
function. This can be achieved using the following code within the main
function:

    numberOfEnergyLevels = atoi(argv[1]);
      reducedTemperature = atof(argv[2]);

## Storing and Accessing the Boltzmann Distribution

A structure to hold the distribution also needs to be created. Write the
following within your main function, once the value of
`numberOfEnergyLevels` has been set:

    distribution = new double [numberOfEnergyLevels];

This code creates an array of rational numbers of size
`numberOfEnergyLevels`. The function `new` allocates a memory block
whose purpose is to hold the contents of this array. This function also
assigns the address of the begining of this memory block to the pointer
`distribution`. For example if the array contains the values
$[0.9, 0.05, 0.03, 0.02]$, then these individual values can be accessed
via `distribution[j]` or in pointer-arithmetic by `*(distribution+j)`.
Pointers and arrays are discussed in more detail within the C++ glossary
in section [cppglossary].

## Calculating the Boltzmann Distribution

You are now ready to design the Boltzmann distribution implementation
within your main function. Enter the following code in an appropriate
place, i.e. once the array `distribution` has been allocated:

    for(int i = 0; i < numberOfEnergyLevels; i++)
     {
        // To modify. Compute distribution and partition function//
        distribution[i]=1.0;
        partitionFunction=1.0;
      }

Recall that the calculation of the Boltzmann distribution requires the
calculation of the partition function, $Z$. Hence, within this loop you
calculate the partition function.

## Outputting the Results

To finish the flow of the program, you will need to output the results
of your calculation to a file and terminate the program. This can be
achieved by calling the `outputToFile()` function. Place the following
code after the for-loop:

    outputToFile(distribution, "results.dat");
     delete [] distribution;

It is worthwhile to note that since you dynamically allocated a new
(un-managed) memory block within your program earlier, you must also
delete it once you are finished. To free the memory associated with this
array you must call `delete [] distribution`.

You will also need to provide an implementation for the function
`outputToFile()`. Enter the following code below the main function:

    void outputToFile(double *distribution, string outputFile) {
      ofstream output;
      output.open(outputFile);
        
      for (int i = 0; i < numberOfEnergyLevels; i++) {
        output << i << " " << distribution[i]/partitionFunction << "\n";
      } 
      output.close();
    }

The purpose of this function is to write the Boltzmann distribution
contained within the array `distribution` to the file specified by the
path `outputFile`. If this file does not exist, it will automatically
create it and otherwise will entirely overwrite all contents contained
therein. Writing to files is discussed further in the glossary (section
[cppglossary]). Also note that the normalisation of the Boltzmann
distribution with the partition function occurs within the writing step.

(occupancy)=
## Calculating State Occupancy 

Finally, place the following code somewhere below your main function.
You must now modify this function to complete this Boltzmann
distribution program. Hint: recall that you are using reduced
temperature.

    double calculateStateOccupancy(double reducedTemperature, int i) {
      double stateOccupancy = 0.0; 
      //Calculate the occupancy for state i
      return stateOccupancy;
    }

Note: The directive `#include <math.h>` at the begining of your code
includes the math library. This library contains the function `exp()`
which you can use to calculate $e^x$ by calling `exp(x)`.

## Compiling Your `C++` Code

To compile the program, navigate your terminal focus to the directory
which contains `boltzmann.cpp`, and type the following:

    g++ -std=c++11 boltzmann.cpp -o boltzmann.x

This will produce an executable file called `boltzmann.x` in your
current directory. You can execute this program using the following
command-line arguments:

    ./boltzmann.x numberOfEnergyLevels reducedTemperature

(gnuplot)=
## GNUPlot: Displaying Results

A convenient way to quickly graph the data contained within your results
file is to use the `gnuplot` program. Open a terminal and navigate the
terminal focus to the directory containing your results file. Enter the
command `gnuplot` to start the program.

### Plotting

Your results file only contains 2 columns thus you can simply plot the
graph directly using the following command:

    plot 'results.dat'

If however you have multiple columns from which to plot, you can use the
`using` specifier as follows:

    plot 'results.dat' using 2:3

which will plot the third column (y-axis) against the second (x-axis).
Extending this, to plot multiple graphs on one image, you can type the
following:

    plot 'results1.dat' using 1:2 title 'graph1' with lines, \

    'results2.dat' using 1:2 title 'graph2' with lines, \

    'results3.dat' using 1:2 title 'graph3' with lines

In this example each data point is connected with a straight line using
the `with lines` command. Note that `with lines` may be abbreviated as
`w l`, `using` as `u`, and `title` as `t`.

### Labelling Axes

Axis labels are added with the `set` command. The following commands
label the x-axis and y-axis respectively:

    set xlabel 'Energy Level'

    set ylabel 'Occupancy'

### Output to File

To write the graph to file with PNG format, the following commands can
be used:

    set term png

    set output 'results.png'

    replot

    set term x11

(cppglossary)=
## C++ Glossary 

### Pointers and Arrays

#### Pointers

Memory in a computer can be viewed simply as a succession of memory
cells, each one byte in size, and each with a unique address. When a
variable is declared, the memory block required to store its value is
assigned at a specific location (its memory address). Pointers are
simple structures which allow you to obtain the memory address of a
particular variable, and are declared as follows:

    type * name;

where `type` refers to the variable type this pointer is pointing to.
The memory address of a variable can then be accessed with the
address-of operator (&) as follows:

    int bar = 1000;
    int * foo = &bar;

which assigns to the pointer `foo` the address to the memory block
containing the contents of the variable `bar`. The value stored within
the memory block addressed by the pointer is accessed by using the
dereference operator (\*):

    int bar = 1000;
    int * foo = &bar;
    cout << foo << endl; //prints memory address of variable bar
    cout << *foo << endl; //dereference foo to print 1000

Finally, when you create a dynamically allocated variable using the
`new` operator, you must declare this statement with a pointer as
follows:

    Object * objectPointer = new Object;
    Object * objectArray = new Object[3];

such that when its time to free the memory associated with this
variable, you can use the `delete` operator (or `delete []` for arrays)
to act on its pointer:

    delete objectPointer;
    delete[] objectArray;

#### Arrays

The concept of an array is very much akin to that of a pointer. In C++
arrays are simply wrapped pointers which address the starting memory
block of the contents contained within the array. This is illustrated in
the following example:

    int myarray [3];
    int * arrayPointer = &myarray;
    myarray[0] = 5;
    myarray[1] = 6;
    myarray[2] = 7; // array now contains {5, 6, 7}
    cout << *(arrayPointer) << ", " << myarray[0] << endl; //prints 5, 5
    cout << *(arrayPointer+1) << ", " << myarray[1] << endl; //prints 6, 6

(writing_to_files)=
### Writing to Files 

The classes `ofstream` and `ifstream` can be used for writing and
reading files respectively. To make use of these classes you simply
include the `<iostream>` and `<fstream>` libraries. To write to files,
the following commands can be used:

    ofstream myfile;
    myfile.open("example.txt"); 
    myfile << "Writing this to file.\n";
    myfile.close(); 

Here an object of class `ofstream` is created with the name `myfile`.
Next, the function `open()` is called to create a stream to the file
`example.txt`. Characters are pushed onto this stream using the stream
insertion operator `<<` and finally the function `close()` is called to
flush the stream and release any allocated memory.