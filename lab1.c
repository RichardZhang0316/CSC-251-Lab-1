/*
* Richard Zhang
* CSC 251
* Lab 1
* Feb 4 2024
*/
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

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

    // run this simple function call (foo) 10000 times
    gettimeofday(&start, NULL);
    for (int i = 0; i < 10000; i++) {
        foo();
    }
    gettimeofday(&end, NULL);
    // measure the total time for running the function call
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    millisecondsMeasureTime = ((seconds) * 1000 + microseconds/1000.0) + 0.5;
    printf("Time cost for running the function call foo 10000 times (unit: milliseconds): %f\n", millisecondsMeasureTime);

    // run the simple system call (getppid) 10000 times
    gettimeofday(&start, NULL);
    for (int i = 0; i < 10000; i++) {
        getppid();
    }
    gettimeofday(&end, NULL);
    // measure the total time for running the function call
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    millisecondsMeasureTime = ((seconds) * 1000 + microseconds/1000.0) + 0.5;
    printf("\nTime cost for running getppid 10000 times (unit: milliseconds): %f\n", millisecondsMeasureTime);

    // run the simple system call (getuid) 10000 times
    gettimeofday(&start, NULL);
    for (int i = 0; i < 10000; i++) {
        getuid();
    }
    gettimeofday(&end, NULL);
    // measure the total time for running the function call
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    millisecondsMeasureTime = ((seconds) * 1000 + microseconds/1000.0) + 0.5;
    printf("\nTime cost for running getuid 10000 times (unit: milliseconds): %f\n", millisecondsMeasureTime);   

    // measure getcwd(). We set the size of buffer to be 1000 to make sure it's long enough
    char* buffer = (char *)malloc(1000 * sizeof(char));
    // run the simple system call (getcwd) 10000 times
    gettimeofday(&start, NULL);
    for (int i = 0; i < 10000; i++) {
        getcwd(buffer, 1000);
    }
    gettimeofday(&end, NULL);
    // measure the total time for running the function call
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    millisecondsMeasureTime = ((seconds) * 1000 + microseconds/1000.0) + 0.5;
    printf("\nTime cost for running getcwd 10000 times (unit: milliseconds): %f\n", millisecondsMeasureTime); 

    // measure write
    const char *text = "I love computer science. ";
    int fileWriter = open("untitled.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    // error handling
    if (fileWriter == -1) {
        perror("this error happens when opening a file in the process of measuring write");
        return 1;
    }
    // run the simple system call (write) 10000 times
    gettimeofday(&start, NULL);
    for (int i = 0; i < 10000; i++) {
        write(fileWriter, text, strlen(text));
    }
    gettimeofday(&end, NULL);
    close(fileWriter);
    // measure the total time for running the function call
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    millisecondsMeasureTime = ((seconds) * 1000 + microseconds/1000.0) + 0.5;
    printf("\nTime cost for running write 10000 times (unit: milliseconds): %f\n", millisecondsMeasureTime);

    // measure read
    int fileReader = open("untitled.txt", O_RDWR | O_CREAT | O_TRUNC);
    // error handling
    if (fileReader == -1) {
        perror("this error happens when opening a file in the process of measuring read");
        return 2;
    }
    // run the simple system call (read) 10000 times
    char readText[10];
    gettimeofday(&start, NULL);
    for (int i = 0; i < 10000; i++) {
        // go back to the beginning first
        lseek(fileReader, 0, SEEK_SET);
        read(fileReader, readText, sizeof(readText));
    }
    gettimeofday(&end, NULL);
    close(fileReader);
    // measure the total time for running the function call
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    millisecondsMeasureTime = ((seconds) * 1000 + microseconds/1000.0) + 0.5;
    printf("\nTime cost for running read 10000 times (unit: milliseconds): %f\n", millisecondsMeasureTime);

    // delete the text file
    unlink("untitled.txt");
    return 0;
}