// Structs to hold variables/parameters. This way, we can include what would otherwise have to be
// function arguments conditionally in the structs (such as OpenCL variables/structs) yet retain
// the same signature for rendering functions etc.

// This struct holds image parameters/variables
typedef struct {
	unsigned xRes;			// x axis (horiz.) resolution
	unsigned yRes;			// y axis (vert.) resolution

	double xMin;		// lower and upper image boundaries,
	double xMax;		// in "fractal coordinates", ie, the
	double yMin;		// complex plane.
	double yMax;

	unsigned maxIters;		// max iteration count before a pixel
							// is considered converged. Changes with zoom.

	float * pixels;	// array of r,g,b colour values in [0.0,1.0].

	int gaussianBlur;	// 1 or 0, for gaussian blur or not.

	int zoomSteps;		// number of interpolated frames to render in SmoothZoom function

	double colourPeriod;	// Number of diverging iterations in colour cycle.

} imageStruct;



// This struct holds variables needed for rendering the image
typedef struct {
	GLFWwindow *window;

	int updateTex;		// if this is 0, don't update the GL texture.
	                  // Used in high-resolution render, as we can't
	                  // draw it to screen.
#ifdef WITHOPENCL
	cl_command_queue queue;
	cl_context contextCL;
	cl_kernel renderMandelbrotKernel;
	cl_kernel gaussianBlurKernel;
	cl_kernel gaussianBlurKernel2;
	cl_mem pixelsDevice;
	cl_mem pixelsTex;
	size_t globalSize;
	size_t localSize;
	int glclInterop;
	size_t deviceMaxAlloc;
#endif

} renderStruct;
