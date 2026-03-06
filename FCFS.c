#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], waiting_time[n], turnaround_time[n];
    int response_time[n], start_time[n], completion_time[n], process_id[n];

    // Input
    for (i = 0; i < n; i++) {
        process_id[i] = i + 1;

        printf("Enter the arrival time for Process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);

        printf("Enter the burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Sorting based on arrival time
    for(i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arrival_time[i] > arrival_time[j]){

                int temp;

                temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;

                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = process_id[i];
                process_id[i] = process_id[j];
                process_id[j] = temp;
            }
        }
    }

    // Scheduling
    start_time[0] = arrival_time[0];
    completion_time[0] = start_time[0] + burst_time[0];

    for(i = 1; i < n; i++){
        if(completion_time[i-1] < arrival_time[i])
            start_time[i] = arrival_time[i];
        else
            start_time[i] = completion_time[i-1];

        completion_time[i] = start_time[i] + burst_time[i];
    }

    // Calculations
    for(i = 0; i < n; i++){
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        response_time[i] = start_time[i] - arrival_time[i];
    }

    // Output
    printf("\nProcess\tAT\tBT\tWT\tCT\tTAT\tRT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               process_id[i], arrival_time[i], burst_time[i],
               waiting_time[i], completion_time[i],
               turnaround_time[i], response_time[i]);
    }

    return 0;
}