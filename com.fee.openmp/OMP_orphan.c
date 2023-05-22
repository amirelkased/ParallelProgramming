//
// Created by amirelkased on 22-May-23.
// Orphan is a function used for workshareing.
//
#include "omp.h"
#include "stdio.h"

#define VECLEN 100 // Vector Length

float a[VECLEN], b[VECLEN], sum = 0;

void dotProduct() {
    int tid;
    tid = omp_get_thread_num();
#pragma omp for reduction(+:sum)
    for (int i = 0; i < VECLEN; ++i) {
        sum += (a[i] * b[i]);
        printf("Thread #%d and Index #%d\n", tid, i);
    }
}

/**
 * This code calculates the dot product of two vectors using parallel processing with OpenMP.
 * It initializes two vectors of length 100 with numbers from 0 to 99 and
 * then uses parallel processing to compute the dot product by
 * summing the pairwise multiplication of the elements in each vector.
 * The computation is done in parallel using OpenMP's  omp for  construct.
 * At the end, the sum is printed to the console.
 */

int main() {

    for (int j = 0; j < VECLEN; ++j) {
        a[j] = b[j] = (float) j;
    }
    // This part called orphan function.
    // the only diff. between it and OMP_workshare
    // which for function separate from main
    // all thread works like static
#pragma omp parallel default(none)
    {
        dotProduct();
    }
    printf("Summution is %f", sum);
}