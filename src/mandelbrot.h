// Mandelbrot Rendering routines. All have the same signature, so we can easily switch routine using
// function pointers.

// Compute mandelbrot set inside supplied coordinates, returned in *image. Resolution variables used to
// determine mandelbrot coordinates of each pixel.

// Optional Gaussian blur after computation, can look "nicer"
#define GAUSSIANBLUR

// Number of colour steps
#define NCOLOURS 128


// Includes
#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <immintrin.h>

#include "GaussianBlur.h"
#include "GetWallTime.h"


// Set pixels in r,g,b pointers based on final iteration value
void SetPixelColour(const int iter, const int maxIters, float mag, float *r, float *g, float *b);


// Basic routine, using CPU.
void RenderMandelbrotCPU(float *image, const int xRes, const int yRes,
                      const double xMin, const double xMax, const double yMin, const double yMax,
                      const int maxIters);

// High precision routine using GMP
void RenderMandelbrotGMPCPU(float *image, const int xRes, const int yRes,
                      const double xMin, const double xMax, const double yMin, const double yMax,
                      const int maxIters);

// AVX Vectorized
void RenderMandelbrotAVXCPU(float *image, const int xRes, const int yRes,
                      const double xMin, const double xMax, const double yMin, const double yMax,
                      const int maxIters);