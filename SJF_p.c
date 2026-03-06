#include<stdio.h>

int main(){

    int n,i,time=0,completed=0;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    int arrival_time[n],burst_time[n],remaining_time[n];
    int waiting_time[n],turnaround_time[n],response_time[n];
    int completion_time[n],start_time[n],process_id[n];

    for(i=0;i<n;i++){
        process_id[i]=i+1;

        printf("Enter arrival time for Process %d: ",i+1);
        scanf("%d",&arrival_time[i]);

        printf("Enter burst time for Process %d: ",i+1);
        scanf("%d",&burst_time[i]);

        remaining_time[i]=burst_time[i];
        start_time[i]=-1;
    }

    while(completed<n){

        int idx=-1;
        int min=9999;

        for(i=0;i<n;i++){
            if(arrival_time[i]<=time && remaining_time[i]>0 && remaining_time[i]<min){
                min=remaining_time[i];
                idx=i;
            }
        }

        if(idx!=-1){

            if(start_time[idx]==-1){
                start_time[idx]=time;
            }

            remaining_time[idx]--;
            time++;

            if(remaining_time[idx]==0){

                completion_time[idx]=time;
                turnaround_time[idx]=completion_time[idx]-arrival_time[idx];
                waiting_time[idx]=turnaround_time[idx]-burst_time[idx];
                response_time[idx]=start_time[idx]-arrival_time[idx];

                completed++;
            }

        } else{
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        process_id[i],
        arrival_time[i],
        burst_time[i],
        completion_time[i],
        turnaround_time[i],
        waiting_time[i],
        response_time[i]);
    }

    return 0;
}