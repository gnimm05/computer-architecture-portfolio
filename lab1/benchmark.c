#include <stdio.h>
#include <stdlib.h>

// Define the size of the arrays
#define SIZE 50000

// Declare arrays
int A[SIZE];
int B[SIZE];
// C needs to hold large sums
long long C[SIZE];

int main() {
    // expected checksum value to verify our computation
    const long long expected_checksum = 41667916675000LL;
    long long computed_checksum = 0;
    int i, j;

    // initialize the input arrays A, B, and C
    for (i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = SIZE - i;
        C[i] = 0;
    }


    // For each element 'i' in the arrays, we calculate C[i].
    // C[i] is the sum of all elements in array B from index 0 up to and including the index A[i].
    for (i = 0; i < SIZE; i++) {
        long long sum = 0; // Use a temporary sum 
        for (j = 0; j <= A[i]; j++) { 
            sum += B[j];
        }
        C[i] = sum;
    }
    // sum all elements of the resulting array C.
    // acts as a checksum.
    for (i = 0; i < SIZE; i++) {
        computed_checksum += C[i];
    }

    // Print the computed checksum
    printf("Computed checksum: %lld\n", computed_checksum);

    // Compare the computed checksum against the expected value.
    if (computed_checksum != expected_checksum) {
        printf("Error: Checksum does not match the expected value!\n");
        return 1; 
    }

    
    return 0;
}