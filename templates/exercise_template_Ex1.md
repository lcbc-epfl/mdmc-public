# Exercise 1

Student:  Firstname Lastname    Sciper: 000000

:::{admonition} Please use this template to submit your answers. 

If you had to modify code from the notebook, please include the modified code in your submission either as screenshot or in a 

```
\begin{lstlisting}[language=Python]
\end{lstlisting}
```


environment. 

You only need to include the code cells that you modified.

Note, that references to other parts of the documents aren't resolved in this template and will show as `??`. Check the text of the exercises on website for the reference

:::

:::{admonition} Exercise 1
:class: exercise
Prove the Hellmann-Feynman theorem 
:::

Your answer here

:::{admonition} Exercise 2 - Bonus
:class: exercise
Explain the Born-Oppenheimer approximation in your own words.  You do not have to use any equations (but you may if you wish). Take care not to make wrong generalisations
:::

Your answer here

:::{admonition} Exercise 3
:class: exercise
How can you compute $\pi$ using the ratio of points that fall within the circle (consider a full circle) and the square? 
:::

Your answer here

:::{admonition} Exercise 4
:class: exercise
Perform the $\pi$ estimation for 1000, 100000 and 1000000 trials. Take a screenshot of these estimations and include them in your report (e.g of the python plots). What happens to the accuracy of the $\pi$ estimation when going from 1000 to 1000000 trials and why?
:::

Your answer here

:::{admonition} Exercise 5
:class: exercise
What happens to the estimation of $\pi$ when the circle origin is changed? Why?
:::

Your answer here

:::{admonition} Exercise 6
:class: exercise
What happens to the accuracy of the estimation when you increase the square size, or decrease the circle size? Is there an optimal ratio between the square side ($l$) and the circle diameter ($d$)?
:::

Your answer here

:::{admonition} Exercise 7
:class: exercise
In our code we set the random seed (`r.seed()`) once in the first cell, but then it is unchanged. It means that the first time you run the MC code, the random number set as seed was used for the extraction, but then the later extractions do not start from that seed anymore. What happens if you use the same seed for the pseudo random number generator (PRNG) each time you start the MC code? And what would happen if you would use the same seed for each random number extraction? You can read up more details in [Appendix: Random and Pseudo-random Numbers](https://lcbc-epfl.github.io/mdmc-public/Ex1/prng.html). 
*Hint*: To get an idea, you can either edit the MC code, or you can also write a piece of code to check how the numbers generated depend on the seed set. 
:::

Your answer here