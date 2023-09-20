# reader-writer-lock-implementation

This project is an implementation of a reader/writer lock using semaphores to ensure that neither the readers nor the writers starve. The reader/writer problem is presented in section 31.5 of the textbook, along with a reader/writer lock that starves writers. The goal of this project is to design and implement a reader/writer lock that does not starve either readers or writers.

## Project Requirements

The project requires the following components:

1. **Implementation of Non-Starving Reader/Writer Lock**: You need to implement a reader/writer lock using semaphores that ensures neither the readers nor the writers starve.

2. **Main C Program**: Write the main C program that uses the implemented reader/writer locks to demonstrate their functionality.

3. **Test Scenarios**: Develop a set of input scenarios that showcase the behavior of your non-starving lock compared to a starving lock. These scenarios should test the correctness of your reader/writer lock and ensure that writers are not starved.

## Files in the Project

The project consists of the following files:

- `readerwriter.c`: This C program implements the non-starving reader/writer locks using semaphores. It contains the logic for readers and writers to acquire and release locks.

- `main.c`: The main program that utilizes the reader/writer locks to demonstrate their functionality. You can use this program to simulate readers and writers accessing a resource.

- `scenarios.txt`: An input file that contains test scenarios to evaluate your lock's behavior. Each scenario represents a sequence of reader (`r`) and writer (`w`) arrivals. These scenarios are designed to ensure that writers do not starve.

- `newthread.h`: A header file that contains declarations for thread-related functions and structures. It is used in the main program.

- `testthread.h`: Another header file that includes declarations and definitions related to threads and semaphores. It is used in the implementation of the reader/writer lock.

- `Makefile`: A Makefile for easy compilation of the project. The target executable is named `rwmain`.

- `README.md`: The readme file you are currently reading, which provides an overview of the project and its components.

## Running the Project

1. Compile the project by running `make` in the project directory. This command will generate the `rwmain` executable.

2. Execute the program by running `./rwmain`. It will read the test scenarios from the `scenarios.txt` file and simulate reader and writer behavior based on these scenarios.

