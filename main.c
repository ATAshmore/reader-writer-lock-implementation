#include "newthread.h"
//  CITATION: Fair Solution to the Reader-Writer-Problem with Semaphores only. H. Ballhausen, 2003
//  link: https://arxiv.org/abs/cs/0303005
//  note: could not use the original thread.h file. was having multiple argument issues and TA did not respond fast enough.
//          so used basic thread.h and semaphore.h


void main() {
    pthread_t threads[MAX_THREADS];
    int readerID = 0, writerID = 0, i = 0;

    // initialize semaphores
    sem_init(&readerLock, 0, 1);    //  reader
    sem_init(&writerLock, 0, 1);    //  writer
    sem_init(&extraLock, 0, 1);     //  make sure both don't starve. fairness

    // read scenario from file
    //  file will have one scenarios inside
    //  paste scenario you want to test from scenarioList.txt
    FILE *file = fopen("scenarios.txt", "r");
    if(file) {
        char readerOrWriter;
        while(fscanf(file, "%c", &readerOrWriter) != EOF) {
            if(readerOrWriter == 'r') {
                int* id = malloc(sizeof(int));
                *id = readerID++;
                pthread_create(&threads[i++], NULL, reader, (void*) id);
            }
            else if(readerOrWriter == 'w') {
                int* id = malloc(sizeof(int));
                *id = writerID++;
                pthread_create(&threads[i++], NULL, writer, (void*) id);
            }
        }
        fclose(file);

        // wait for all threads to finish
        for(int j = 0; j < i; j++) {
            pthread_join(threads[j], NULL);
        }
    }
    else {
        printf("Scenario file does not exist...\n");
    }

    // kill semaphores after running
    sem_destroy(&readerLock);
    sem_destroy(&writerLock);
    sem_destroy(&extraLock);

    //return 0;
}

