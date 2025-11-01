#include <stdio.h>

void mult2x2( int a[2][2], int b[2][2], int out[2][2]);

/**
 * Given a pair of input vectors, returns true if the multiplier worked correctly.
 */
bool test_case( int a[2][2], int b[2][2] ) {

	printf("Testing matrix inputs a=[%d %d] b=[%d %d]\n", a[0][0],a[0][1],b[0][0],b[0][1]);
	printf("                        [%d %d]   [%d %d]\n", a[1][0],a[1][1],b[1][0],b[1][1]);

	// Take the input, run it through the filter, see if it worked.
	int actual[2][2];
	mult2x2(a, b, actual);

	// Do it manually to find out what the result is supposed to be
	int expected[2][2] = {0};
	for (int i=0; i<2; ++i)
        for (int j=0; j<2; ++j)
            for (int k=0; k<2; ++k)
                expected[i][j] += a[i][k] * b[k][j];

	// Check element-wise for FPGA design correctness
	bool correct = true;
	for (int i=0; i<2; ++i)
		for (int j=0; j<2; ++j)
			if (expected[i][j] != actual[i][j]) {
				correct=false;
				break;
			}
	if (correct==false) {
		printf("expected=[%d %d] actual=[%d %d]\n", expected[0][0],expected[0][1],actual[0][0],actual[0][1]);
		printf("         [%d %d]        [%d %d]\n", expected[1][0],expected[1][1],actual[1][0],actual[1][1]);
		return false;
	}

	printf("Test passed:\n");
	for (int i=0; i<2; ++i)
		printf("[%d, %d]\n", actual[i][0], actual[i][1]);
	return true;
}

int main() {

	// Basic function tests, edge cases
	if (!test_case((int[2][2]){ {1, 3}, {2, 4} }, (int[2][2]){ {5, 7}, {6, 8} }))
		return -1;
	if (!test_case((int[2][2]){ {1, 2}, {3, 4} }, (int[2][2]){ {1, 0}, {0, 1} }))
		return -1;
	if (!test_case((int[2][2]){ {2147483647, -2147483648}, {-2147483648, 2147483647} }, (int[2][2]){ {1, 0}, {0, 1} }))
		return -1;
	if (!test_case((int[2][2]){ {2147483650, -2147483648}, {-2147483648, 2147483647} }, (int[2][2]){ {1, 3}, {-3, 5} }))
		return -1;

	return 0;
}