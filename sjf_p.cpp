#include <iostream> 
using namespace std; 
class System_p { 
    public:
	int process_num ,burst_time,arrival_t;
}; 
int n;
int wait_time[1000], turn_around_t[1000], total_wt = 0,total_tat = 0;
void print_process(System_p pt[],int i,int curr_t){
    cout << "Process num    Burst time   Arrival time  Current time\n"; 
	cout << " " << pt[i].process_num << "\t\t"<< pt[i].burst_time << "\t\t"<< pt[i].arrival_t << "\t\t"<< curr_t << endl<<endl; 
}
void fcfs(System_p p[]){
    System_p ptemp[n];
    int current_time=0;float avg_wt=0,avg_tat=0,st[n],ft[n];
    for(int i=0;i<n;i++)
        ptemp[i]=p[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(ptemp[j+1].arrival_t<ptemp[j].arrival_t){
                System_p temp = ptemp[j];
                ptemp[j]=ptemp[j+1];
                ptemp[j+1]=temp;
            }
        }
    }
    current_time=ptemp[0].arrival_t;
    st[0]=current_time;
    for(int i=0;i<n;i++){
        int curr_p=i;
        if(i<n-1)
            st[i]=current_time;
        print_process(ptemp,curr_p,current_time);
        wait_time[i]= current_time - ptemp[curr_p].arrival_t;
        if (wait_time[curr_p] < 0) 
				wait_time[curr_p] = 0; 
        avg_wt+=wait_time[i];
        turn_around_t[i]=ptemp[curr_p].burst_time + wait_time[i];
        avg_tat+=turn_around_t[i];
        current_time+=ptemp[curr_p].burst_time;
        ft[i]=current_time;
    }
    cout<<"\n\nGantt Chart: "<<ptemp[0].arrival_t<<"  ";
    for (int i = 0; i < n; i++){
        if(0)
		    cout << " P" << ptemp[i].process_num << "\t"<< ptemp[i].arrival_t+turn_around_t[i];
        else
            cout << " P" << ptemp[i].process_num << "\t"<< ft[i];
    }
    cout<<"\n\n\n";
    cout<<"FCFS Final Process Table:"<<endl;
	cout << "Process num    Burst time   Arrival time   Waiting time   Turn around time\n"; 
    for (int i = 0; i < n; i++)
		cout << " " << ptemp[i].process_num << "\t\t"<< ptemp[i].burst_time << "\t\t"<< ptemp[i].arrival_t << "\t\t " << wait_time[i] << "\t\t " << turn_around_t[i] << endl; 
	avg_wt/=n;
    avg_tat/=n;
    cout << "\nAverage waiting time = "<< avg_wt<<"\nAverage turn around time = "<< avg_tat<<endl; 
    cout<<"\n\n\n\n";
}
void sjf_preemtive(System_p p[]) 
{ 
	int temp[n];  
    float avg_wt,avg_tat;
	for (int i = 0; i < n; i++) 
		temp[i] = p[i].burst_time; 
	int num_p = 0, current_time = 0, curr_min = 1000000,curr_p = 0, finish_time,f=0; 
	while (num_p != n) { 
		for (int j = 0; j < n; j++) { 
			if ((p[j].arrival_t <= current_time) )
             if((temp[j] < curr_min) && (temp[j] > 0)) { 
				curr_min = temp[j]; 
				curr_p = j; 
				f = 1; 
			} 
		} 
		if (f == 0) { 
			current_time++; 
			continue; 
		} 
        
        
        print_process(p,curr_p,current_time);
        current_time++; 
		temp[curr_p]--; 
		curr_min = temp[curr_p]; 
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
    cout<<"\n\nSJF PREEMTIVE Final Process Table:"<<endl;
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
    cout<<"Enter number of processes:";
    cin>>n;
    System_p p[n];
    for(int i=0;i<n;i++){
        cout<<"Enter arrival and burst time of process "<<i+1<<" :";
        p[i].process_num=i+1;
        cin>>p[i].arrival_t>>p[i].burst_time;
    }
    fcfs(p);
    // int t=1;
    // cout<<"Enter Scheduling algorithm to be used(1.SJF PREEMTIVE 2.FCFS):";
    // cin>>t;
    // if(t==1)
	//     sjf_preemtive(p); 
    // else if(t==2)
    //     fcfs(p);
	return 0; 
} 
