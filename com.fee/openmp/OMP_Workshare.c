//
// Created by amirelkased on 22-May-23.
// In this example, the iterations of a loop are scheduled dynamically
// across the team of threads.  A thread will perform CHUNK iterations
// at a time before being scheduled for the next CHUNK of work.
//
#include "omp.h"
#include "stdio.h"

#define CHUNKSIZE 5
#define N 100

int main() {

    int tid, nthreads = 0;
    float a[N], b[N], c[N];
    int chunk = 10;
    // Initialize Arrays
    for (int i = 0; i < N; ++i) {
        a[i] = b[i] = (float) i;
    }

    // Parallel region
#pragma omp parallel shared(a, b, c, nthreads, chunk) private(tid) default(none)
    {
        tid = omp_get_thread_num(); // Get the thread ID
        if (tid == 0) {
            nthreads = omp_get_num_threads(); // Get the total number of threads
            printf("Number of threads = %d\n", nthreads);
        }
        printf("Thread %d is Starting...\n", tid);

        // Task: Add array a and b and store the result in array c
        /**
         * At static schedule all threads works with the chunk size
         * then faster thread can take more jobs.
         * for concise each thread work at least one job.
         *
         *
         * At Dynamic schedule threads work in random manner
         * or faster thread is worker and this is schedule is not deterministics.
         * it is normal to found thread doesn't work anytime.
         */
#pragma omp for schedule(static, chunk)
        for (int i = 0; i < N; ++i) {
            c[i] = a[i] + b[i];
            printf("Thread %d: c[%d] = %f\n", tid, i, c[i]);
        }
    }

    return 0;
}
