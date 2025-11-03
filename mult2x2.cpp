#include <ap_int.h>

void mult2x2 (
    ap_int<8> A[2][2],
    ap_int<8> B[2][2],
    ap_int<16> C[2][2]
) {
    #pragma HLS INTERFACE ap_ctrl_none port=return//remove all handshakes except reset and clock
    #pragma HLS ARRAY_PARTITION variable=A complete dim=0
    #pragma HLS ARRAY_PARTITION variable=B complete dim=0
    #pragma HLS ARRAY_PARTITION variable=C complete dim=0

    #pragma HLS PIPELINE II=1
    // Matrix multiplication
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ap_int<16> sum = 0;
            for (int k = 0; k < 2; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    // Do it all at once with a lot more combinational parallel hardware:
    // out[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    // out[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    // out[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    // out[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
}
