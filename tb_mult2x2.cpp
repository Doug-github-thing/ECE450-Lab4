#include <stdio.h>

void mult2x2( int a[2][2], int b[2][2], int out[2][2]);

int main() {

	// Define initial test input
	int a[2][2] = { {1, 3}, {2, 4} };
	int b[2][2] = { {5, 7}, {6, 8} };
	int expected[2][2] = { {23, 31}, {34, 46} };
	int out[2][2];

	// Run it through the filter
	mult2x2(a, b, out);

	// Print the results
	for (int i=0; i<2; ++i)
		printf("[%d, %d]\n", out[i][0], out[i][1]);

	for (int i=0; i<2; ++i)
		for (int j=0; j<2; ++j)
			if (out[i][j] != expected[i][j])
				return -1;

	return 0;
}