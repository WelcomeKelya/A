#include <stdio.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
};

void calculateWaitingTime(struct Process processes[], int n, int waitingTime[]) {
    int total = 0;
    waitingTime[0] = 0;

    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
        total += waitingTime[i];
    }
}

void calculateTurnaroundTime(struct Process processes[], int n, int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = processes[i].burstTime + waitingTime[i];
    }
}

void calculateAverageTime(struct Process processes[], int n) {
    int waitingTime[n], turnaroundTime[n];

    calculateWaitingTime(processes, n, waitingTime);
    calculateTurnaroundTime(processes, n, waitingTime, turnaroundTime);

    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("Process\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, waitingTime[i], turnaroundTime[i]);
    }

    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

void FCFS(struct Process processes[], int n) {
    calculateAverageTime(processes, n);
}

int main() {
    int n;
    printf("Enter the number fo Processes:-");
    scanf("%d",&n);
    struct Process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].id=i+1;
        printf("Enter the At and Bt of P%d Process:-",p[i].id);
        scanf("%d %d",&p[i].arrivalTime,&p[i].burstTime);
    }
    

    FCFS(p, n);

    return 0;
}
