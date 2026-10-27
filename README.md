# philosophers

An implementation of the Dining Philosophers problem in C as part of the 42 curriculum, using mutexes for thread synchronization.

## Objective

Study thread synchronization when multiple threads share resources and must operate under strict time constraints.

## Features

- Thread creation and management.
- Resource synchronization using mutexes.
- Monitoring philosophers' states and lifetimes.
- Detection of simulation termination and philosopher death.
- Prevention of race conditions when accessing shared resources.

## Technologies

- C
- POSIX threads (`pthread`)
- Mutexes and thread synchronization
- Time management and concurrent programming

## Build and Run

```bash
make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]
```

## Technical Highlights

This project strengthened my understanding of multithreading, mutex-based synchronization, shared resource management, and race condition prevention. All synchronization was implemented using mutexes.

## Author

Developed as part of the 42 curriculum.
