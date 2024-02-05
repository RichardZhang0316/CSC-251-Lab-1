/*
* Richard Zhang
* CSC 251
* Lab 1
* Feb 4 2024
*/
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

int foo() {
    return 10;
}

int main() {
    // inititate two timeval variables to measure the time cost
    struct timeval start, end;
    // ensure our measure metrics are accurate
    long seconds, microseconds;
    // initiate the total measure time
    double millisecondsMeasureTime;

    // run this simple function call 10000 times
    gettimeofday(&start, NULL);
    for (int i = 0; i < 10000; i++) {
        foo();
    }
    gettimeofday(&end, NULL);

    // measure the total time for running the function call
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    millisecondsMeasureTime = ((seconds) * 1000 + microseconds/1000.0) + 0.5;
    printf("Time cost for running the function call 10000 times: %f", millisecondsMeasureTime);

    // run this simple system call 10000 times
    gettimeofday(&start, NULL);
    for (int i = 0; i < 10000; i++) {
        getpid();
    }
    gettimeofday(&end, NULL);

    // measure the total time for running the function call
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    millisecondsMeasureTime = ((seconds) * 1000 + microseconds/1000.0) + 0.5;
    printf("\nTime cost for running the system call 10000 times: %f\n", millisecondsMeasureTime);

    return 0;
}
