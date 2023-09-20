#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREADS 10000

extern sem_t writerLock;   //  if writing writing, no readers or writers can read/write
extern sem_t readerLock;   //  if reader reading, other readers can read, writer cannot write
extern sem_t extraLock;    //  encloses reader and writer lock so if a writer or a reader pulls up,
                           //  they can access and not starve after existing readers and writers read/write


void reading_writing();
void* writer(void* args);
void* reader(void* args);

#endif