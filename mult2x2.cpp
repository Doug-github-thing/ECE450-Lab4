#include <ap_int.h>

void mult2x2(int a[2][2], int b[2][2], int out[2][2]) {

    // out[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    // out[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    // out[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    // out[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];

    Row: for (int i=0; i<2; ++i)
        Col: for (int j=0; j<2; ++j)
            Product: for (int k=0; k<2; ++k)
                out[i][j] += a[i][k]*b[k][j];
}