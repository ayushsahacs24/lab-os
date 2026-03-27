#include <stdio.h>

struct Process {
int pid;
int at; 
int bt; 
int pr; 
int ct; 
int tat; 
int wt; 
int done;
};

int main() {
int n, time = 0, completed = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
struct Process p[n];
for(int i = 0; i < n; i++) {
printf("\nProcess %d\n", i+1);
p[i].pid = i+1;
printf("Arrival Time: ");
scanf("%d", &p[i].at);
printf("Burst Time: ");
scanf("%d", &p[i].bt);
printf("Priority: ");
scanf("%d", &p[i].pr);
p[i].done = 0;
}
while(completed < n) {
    int idx = -1;
    int min_pr = 9999;
    for(int i = 0; i < n; i++) {
        if(p[i].at <= time && p[i].done == 0) {
            if(p[i].pr < min_pr) {
                min_pr = p[i].pr;
                idx = i;
            }
        }
    }
    if(idx == -1) {
        time++;
        continue;
    }
    time += p[idx].bt;
    p[idx].ct = time;
    p[idx].tat = p[idx].ct - p[idx].at;
    p[idx].wt = p[idx].tat - p[idx].bt;
    p[idx].done = 1;
    completed++;
    }
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid, p[i].at, p[i].bt, p[i].pr,
        p[i].ct, p[i].tat, p[i].wt);
    }
    return 0;
}
