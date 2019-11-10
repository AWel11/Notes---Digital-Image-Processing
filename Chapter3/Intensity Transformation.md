# Some Basic Intensity Transformation Functions
Intensity Transformations is an **pixel-wise** operation, its form is ```s = T(r)```  
There are three basic types of functions used frequently for image enhancement:

* **linear** (negative and identity transformations)
* **logarithmic** (log and inverse-log transformations)
* **power-law** (*n*th power and *n*th root transformations)
---
## Image Negative
$$
s = L - 1 - r
$$

Reversing the intensity levels of an image,  
it's suited for **enhancing white or gray detail embedded in dark regions**

## Log Transformations
$$
s = c log (1 + r)
$$

This transformation maps a narrow range of low intensity values in the input  
into a wider range of output levels. The opposite is true of higher values of input levels.
Described as follows:

* expand the values of dark pixels
* compress the higher-level values
## Power-Law (Gamma) Transformations
$$
s = c r^\gamma
$$

or set a offset:  $\varepsilon$

$$
s = c (r + \varepsilon)^\gamma
$$

The power-law transformation is similar to log transformation while $\gamma$ is **smaller than1**,  
so, it has the same effect as the latter.
But, when $\gamma$ is **bigger than 1**,  
it has a opposite function, which is stretch the light range and tighten the dark one.

Besides, **gamma correction** is very useful in image capture, printing, and displaying (especially in monitors)
## Piecewise-Linear Transformation Functions
It's a complementary approach to the previous three sections , and its form can be arbitrarily  
complex, which is its advantage.
There are 3 major components:
* Contrast stretching
> You can simply set the position of (r1, s1) and (r2, s2) to expand the range of intensity levels in an image differently.
* Intensity-level slicing
> Highlighting a specific range of intensities in an image often is of interest.
* Bit-plane slicing
> To choose and show a certain bit plane from Bit plane 1(the least significant) to Bit plane 8(the most significant).
