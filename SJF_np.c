#include<stdio.h>

int main(){
    int n,i,time=0,completed=0;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    int arrival_time[n],burst_time[n],waiting_time[n];
    int turnaround_time[n],response_time[n];
    int process_id[n],start_time[n],completion_time[n];

    for(i=0;i<n;i++){
        process_id[i]=i+1;

        printf("Enter the arrival time for Process %d: ",i+1);
        scanf("%d",&arrival_time[i]);

        printf("Enter the burst time for Process %d: ",i+1);
        scanf("%d",&burst_time[i]);

        completion_time[i]=0;
    }

    while(completed<n){

        int idx=-1;
        int min=9999;

        for(i=0;i<n;i++){
            if(arrival_time[i]<=time && completion_time[i]==0 && burst_time[i]<min){
                min=burst_time[i];
                idx=i;
            }
        }

        if(idx!=-1){

            start_time[idx]=time;
            completion_time[idx]=start_time[idx]+burst_time[idx];

            turnaround_time[idx]=completion_time[idx]-arrival_time[idx];
            waiting_time[idx]=turnaround_time[idx]-burst_time[idx];
            response_time[idx]=start_time[idx]-arrival_time[idx];

            time=completion_time[idx];

            completed++;
        }
        else{
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tWT\tCT\tTAT\tRT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        process_id[i],
        arrival_time[i],
        burst_time[i],
        waiting_time[i],
        completion_time[i],
        turnaround_time[i],
        response_time[i]);
    }

    return 0;
}