#include "scheduler.h"
#include "array_deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_deque.h"

// The TIME QUANTUM used by this Round Robin Simulator
#define TIME_QUANTUM 3

static void print_stats(process p);

static process **read_processes_from_file(char *filename, int *num_processes_ptr);

/**
 * DO NOT MODIFY THIS FUNCTION
 * Reads the processes from the file in the format Process_Name Process_id Arrival_time CPU_burst
 * subsequently stores the number of processes in the location pointed by num_processes_ptr
 * @return an array of process pointers read from the file
 */
static process **read_processes_from_file(char *filename, int *num_processes_ptr) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read the number of processes from the first line
    int num_processes;
    fscanf(file, "%d", &num_processes);
    *num_processes_ptr = num_processes;

    // Allocate memory for the process pointers
    process **processes = malloc(num_processes * sizeof(process *));
    if (processes == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for processes\n");
        exit(EXIT_FAILURE);
    }

    // Read each process from the file
    for (int i = 0; i < num_processes; i++) {
        process *p = malloc(sizeof(process));
        if (p == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory for process\n");
            exit(EXIT_FAILURE);
        }

        // Read the process data from the file
        char name[32];
        unsigned int pid, arrival, cpu_burst;
        fscanf(file, "%s %u %u %u", name, &pid, &arrival, &cpu_burst);
        p->name = strdup(name);
        p->pid = pid;
        p->arrival = arrival;
        p->cpu_burst = cpu_burst;

        // Initialize the other process fields to 0
        p->turnaround = 0;
        p->wait = 0;
        p->remaining_time = cpu_burst;

        processes[i] = p;
    }

    fclose(file);
    return processes;
}

int arrived_process(linked_deque* ld,process** processes,int time,int num_processes){
    while((*(processes))->arrival<=time && num_processes!=0){
        add_last_linked_deque(ld,**processes);
        processes++;
        num_processes--;
    }
    return num_processes;
}


void visualize_round_robin(char *path) {
    int num_processes;
    process **processes = read_processes_from_file(path, &num_processes);

    printf("Number of processes: %d\n", num_processes);
    printf("%-10s%-15s%-15s%-15s%-15s\n", "Process", "Arrival Time", "Burst Time", "Waiting Time", "Turnaround Time");

    linked_deque *ld = create_linked_process_deque();

    if(num_processes==0) return;

    add_first_linked_deque(ld,**(processes));
    process* current_p=ld->list->head->process;
    processes++;

    int process_in_queue=num_processes-1;
    int time=0;

    while(!is_empty_linked_deque(ld)){
        remove_first_linked_deque(ld,current_p);
        if(current_p->cpu_burst>TIME_QUANTUM){
            printf("5\n");
            current_p->cpu_burst-=3;
            time+=TIME_QUANTUM;
            printf("Time is:%d\n",time);
            if(process_in_queue==0) ;

            else{
                printf("14\n");
                process_in_queue=arrived_process(ld,processes,time,process_in_queue);
            }
            //remove_first_linked_deque(ld,current_p);
            printf("7\n");
            //printf("%d\n",get_size_linked_deque(ld));
            add_last_linked_deque(ld,*(current_p));
            printf("8\n");
            current_p=ld->list->head->process;
        }

        else if(current_p->cpu_burst<=TIME_QUANTUM){
            printf("6\n");
            time+=current_p->cpu_burst;
            printf("Time is:%d\n",time);
            if(process_in_queue==0) ;
            else{
                printf("12\n");
                process_in_queue=arrived_process(ld,processes,time,process_in_queue);
            }
            printf("9\n");
            //remove_first_linked_deque(ld,current_p);
            printf("10\n");
            print_stats(*current_p);
            if(!is_empty_linked_deque(ld)) current_p=ld->list->head->process;
            printf("11\n");
        }
    }

    // COMPLETE using the ld for storing processes as described













    // Free the allocated memory
    for (int i = 0; i < num_processes; i++) {
        free(processes[i]->name);
        free(processes[i]);
    }
    free(processes);
}



// Prints the stats for the process p to stdout
static void print_stats(process p) {
    printf("%-10s%-15d%-15d%-15d%-15d\n",
           p.name,
           p.arrival,
           p.cpu_burst,
           p.wait,
           p.turnaround);
}