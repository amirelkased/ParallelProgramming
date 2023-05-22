//
// Created by amirelkased on 22-May-23.
// In this example, the iterations of a loop are scheduled dynamically
// across the team of threads.  A thread will perform CHUNK iterations
// at a time before being scheduled for the next CHUNK of work.
//
#include "omp.h"
#include "stdio.h"

#define CHUNKSIZE 10
#define N 100

int main() {

    int tid, nthreads = 0;
    float a[N], b[N], c[N];

    // Initialize Arrays
    for (int i = 0; i < N; ++i) {
        a[i] = b[i] = i * 1.0;
    }

    // Parallel region
#pragma omp parallel shared(a, b, c, nthreads) private(tid) default(none)
    {
        tid = omp_get_thread_num(); // Get the thread ID
        if (tid == 0) {
            nthreads = omp_get_num_threads(); // Get the total number of threads
            printf("Number of threads = %d\n", nthreads);
        }
        printf("Thread %d is Starting...\n", tid);

        // Task: Add array a and b and store the result in array c
#pragma omp for schedule(dynamic, CHUNKSIZE)
        for (int i = 0; i < N; ++i) {
            c[i] = a[i] + b[i];
            printf("Thread %d: c[%d] = %f\n", tid, i, c[i]);
        }
    }

    return 0;
}
