#include <iostream> 
using namespace std; 
class System_p { 
    public:
	int process_num ,burst_time,arrival_t;
}; 
int n;
int wait_time[1000], turn_around_t[1000], total_wt = 0,total_tat = 0;
void print_process(System_p p[],int i,int curr_t){
    cout << "Process num    Burst time   Arrival time  Current time\n"; 
	cout << " " << p[i].process_num << "\t\t"<< p[i].burst_time << "\t\t"<< p[i].arrival_t << "\t\t"<< curr_t << endl<<endl; 
}
void sjf_non_preemtive(System_p p[]) 
{ 
	int temp[n],tmin=1000000;  
    float avg_wt,avg_tat;
	for (int i = 0; i < n; i++){
		temp[i] = p[i].burst_time;
        if(tmin>p[i].arrival_t)
            tmin=p[i].arrival_t;
    } 
	int num_p = 0, current_time = 0, curr_min = 1000000,curr_p = 0, finish_time,f=0; 
	while (num_p != n) { 
		for (int j = 0; j < n; j++) { 
			if ((p[j].arrival_t <= current_time) )
             if((temp[j] <= curr_min) && (temp[j] > 0)) { 
				curr_min = temp[j]; 
				curr_p = j; 
				f = 1; 
			} 
		} 
        if (f == 0) { 
            if(current_time<tmin)
			    current_time=tmin;
            curr_min = 1000000;
			continue; 
		}  
        print_process(p,curr_p,current_time);
        current_time+=p[curr_p].burst_time; 
		curr_min = temp[curr_p]; 
        temp[curr_p]=0;
		if (temp[curr_p] == 0) { 
			num_p++; 
			f = 0;  
			wait_time[curr_p] = current_time - p[curr_p].arrival_t - p[curr_p].burst_time; 
			if (wait_time[curr_p] < 0) 
				wait_time[curr_p] = 0; 
		} 
        if (curr_min == 0) 
			curr_min = 1000000; 
	} 
    
	for (int i = 0; i < n; i++) 
		turn_around_t[i] = p[i].burst_time + wait_time[i]; 
    cout<<"SJF NON PREEMTIVE Final Process Table:"<<endl;
	cout << "Process num    Burst time   Arrival time   Waiting time   Turn around time\n"; 
    for (int i = 0; i < n; i++) { 
		avg_wt +=  wait_time[i]; 
		avg_tat += turn_around_t[i]; 
    }
	for (int i = 0; i < n; i++)
		cout << " " << p[i].process_num << "\t\t"<< p[i].burst_time << "\t\t"<< p[i].arrival_t << "\t\t " << wait_time[i] << "\t\t " << turn_around_t[i] << endl; 
	avg_wt/=n;
    avg_tat/=n;
    cout << "\nAverage waiting time = "<< avg_wt<<"\nAverage turn around time = "<< avg_tat<<endl; 
    cout<<"\n\n\n\n";
} 
int main() 
{ 

	System_p p[] = { { 1, 8, 0 }, { 2, 4, 1 }, 
					{ 3, 9, 2 }, { 4, 5, 3 } }; 
	n = 4; 
    // cout<<"Enter number of processes:";
    // cin>>n;
    // System_p p[n];
    // for(int i=0;i<n;i++){
    //     cout<<"Enter arrival (min value = 1) and burst time of process "<<i+1<<" :";
    //     p[i].process_num=i+1;
    //     cin>>p[i].arrival_t>>p[i].burst_time;
    // }
	sjf_non_preemtive(p); 
	return 0; 
} 
