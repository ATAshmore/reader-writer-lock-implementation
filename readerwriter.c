#include "newthread.h"

//  Declare readerCount
int readerCount = 0;

//  Declare semaphores
sem_t writerLock;   //  if writing writing, no readers or writers can read/write
sem_t readerLock;   //  if reader reading, other readers can read, writer cannot write
sem_t extraLock;    //  encloses reader and writer lock so if a writer or a reader pulls up,
                    //  they can access and not starve after existing readers and writers read/write

//  provided by project description
//  simulates time for reading/writing
void reading_writing(){ 
    int x=0, i = 0, j = 0, T = rand()%30000; 
    for(i = 0; i < T; i++) 
        for(j = 0; j < T; j++)
            x=i*j; 
}

//  outline (writer-starve version) provided by lecture
void* writer(void* args){
    int writerID=*(int*)args;
    printf("Writer[%d] is created..\n", writerID);

    sem_wait(&extraLock);                                               //  wait for mutual exclusion lock before accessing writing semaphore
        sem_wait(&writerLock);                                          //  wait for writerLock before writing
            printf("\tWriter[%d] is writing\n", writerID);              //
            reading_writing();                                          //  simulate writing process time
            printf("\tWriter[%d] finished writing\n", writerID);        //
        sem_post(&writerLock);                                          //  release writing lock after writing
    sem_post(&extraLock);                                               //  release mutual exclusion lock after accessing writing semaphore

    return NULL;
}

//  outline (writer-starve version) provided by lecture
void* reader(void* args){

    int readerID=*(int*)args;
    printf("Reader[%d] is created..\n", readerID);

    sem_wait(&extraLock);                   //  wait for mutual exclusion lock before accessing reading semaphore
        sem_wait(&readerLock);              //  wait for reader lock before reading
            readerCount++;                  //  increment # of readers
            if(readerCount == 1)            //  if there is a reader don't let writer write
                sem_wait(&writerLock);      //  wait for writer lock before signaling readerlock
        sem_post(&readerLock);              //  release reader lock
    sem_post(&extraLock);                   //  release mutual exclusion lock after accessing writing semaphore

    printf("\tReader[%d] is reading\n", readerID);
    reading_writing();                      //  simulate reading process time
    printf("\tReader[%d] finished reading\n", readerID);

    sem_wait(&readerLock);                  //  wait for reader lock before reading
        readerCount--;                      //  decrement reader count
        if(readerCount == 0)                //  release writer lock if no more readers
        sem_post(&writerLock);              //  release writer locok
    sem_post(&readerLock);                  //  release reader lock after decremented reader count
    
    return NULL;
}