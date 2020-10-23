#include <iostream>
#include <ctime>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// parameters
int MM = 0, SS = 0, D = 0;
sem_t* sem_d = new sem_t();
sem_t* sem_ss = new sem_t();
sem_t* sem_mm = new sem_t();
sem_t* sem_input = new sem_t();
int running = 0;

void* display(void* arg){
    while(true){
        // show the current display
        printf("\r");
        printf("%02d:%02d.%01d\r", MM, SS, D);
        usleep(80000);
        // enable the input thread
        sem_post(sem_input);
    } 
}

void* get_input(void* arg){
    // change the semaphore
    sem_wait(sem_input);
	while(true){
		// get the user's input
		char input;
		std::cin >> input;
		// start the stopwatch
		if(running == 0 && (input == 's' || input == 'S')){
            running = 1;
            sem_post(sem_d);
		}
		// pause the stopwatch
		if(input == 'p' || input == 'P'){
            running = 0;
		}
		// reset the stopwatch(only when in the stop mode)
		if(running == 0 && (input == 'r' || input == 'R')){
			MM = 0;
			SS = 0;
			D = 0;
		}
	}
}

void* decisecond_incrementer(void* arg){
	// change semaphore
    sem_wait(sem_d);
    while(true){
        // update D
        if(running == 1){
            usleep(99600);
            D++;
            // update SS
            if(D == 10){
                D = 0;
                sem_post(sem_ss);
            }
        }
    }
}

void* second_incrementer(void* arg){
    while(true){
        // change semaphore
        sem_wait(sem_ss);
        // update SS
        if(running == 1){
            SS++;
            // update MM
            if(SS == 60){
                SS = 0;
                sem_post(sem_mm);
            }
        }
    }
}

void* minute_incrementer(void* arg){
    while(true){
        // change semaphore
        sem_wait(sem_mm);
        // update MM
        if(running == 1){
            MM++;
            if(MM == 100)
                MM = 0;
        }
    }
}

int main() {
    // disable buffering of standard out
    setbuf(stdout, NULL);
    
    // create thread objects
    pthread_t* thread_get_input = new pthread_t();
	pthread_t* thread_ds = new pthread_t();
	pthread_t* thread_s = new pthread_t();
	pthread_t* thread_min = new pthread_t();
    pthread_t* thread_display = new pthread_t();
		
	// initialize semaphores
    sem_init(sem_d, 0, 0);
    sem_init(sem_ss, 0, 0);
    sem_init(sem_mm, 0, 0);
    sem_init(sem_input, 0, 0);
    
	// initialize the threads with the default attributes
    pthread_create(thread_display, NULL, display, NULL);
    pthread_create(thread_get_input, NULL, get_input, NULL);
	pthread_create(thread_ds, NULL, decisecond_incrementer, NULL);
	pthread_create(thread_s, NULL, second_incrementer, NULL);
	pthread_create(thread_min, NULL, minute_incrementer, NULL);
    
	// wait for the new threads to join, ignoring any return value
    pthread_join(*thread_display, NULL);
    pthread_join(*thread_get_input, NULL);
    pthread_join(*thread_ds, NULL);
    pthread_join(*thread_s, NULL);
    pthread_join(*thread_min, NULL);
    
    return 0;
}