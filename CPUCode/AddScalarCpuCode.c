/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 7      Example: 1      Name: Add scalar
 * MaxFile Name: AddScalar
 * Summary:
 *        Example showing the use of scalar inputs.
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

void generateData(int size, float *dataIn)
{
	for (int i = 0; i < size; i++)
		dataIn[i]  = i;
}

void AddScalarCPU(int size, float scalarIn, float *dataIn, float *dataOut)
{
	for (int i = 0; i < size; i++)
		dataOut[i] = dataIn[i] + scalarIn;
}

int check(int size, float *dataOut, float *expected) {
	int status = 0;
	for (int i = 0; i < size; i++)
		if (dataOut[i] != expected[i]) {
			fprintf(stderr, "Output data @ %d = %f (expected %f)\n",
				i, dataOut[i], expected[i]);
			status = 1;
		}
	return status;
}

int main()
{
	const int size = 8, size_In = 8;
	int sizeBytes = size * sizeof(float);
	float *dataIn   = malloc(sizeBytes);
	float *dataOut  = malloc(sizeBytes);
	float *expected = malloc(sizeBytes);
	float scalarIn  = 5.0;

	generateData(size, dataIn);

	printf("Setting scalar and running DFE.\n");
	AddScalar(size, scalarIn, dataIn, dataOut);

	//AddScalarCPU(size, scalarIn, dataIn, expected);

	//int status = check(size, dataOut, expected);
	//if (status)
		//printf("Test failed.\n");
	//else
		//printf("Test passed OK!\n");
    
    for (int i = 0; i<8; i++) {
	    printf("%f\n", dataOut[i]);
	}
	return 0;
}