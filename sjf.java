import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
class System_p {
    public void System_p(){
        this.process_num=0;
        this.burst_time=0;
        this.arrival_t=0;
        this.visited=0;
    }
    public int process_num ,burst_time,arrival_t,visited;

}; 

public class sjf {
public static int n, total_wt = 0,total_tat = 0;
// public float alpha=0.5,tao_n=1;
public static int wait_time[], turn_around_t[];
public static double tao[]=new double[100]; 
public static void print_process(System_p pt[],int i,int curr_t){
    System.out.println("Process num    Burst time   Arrival time  Current time"); 
    System.out.println(" " + pt[i].process_num + "\t\t"+ pt[i].burst_time + "\t\t"+ pt[i].arrival_t + "\t\t"+ curr_t); 
}
public static int find_minat(System_p pt[]){
    int m=1000000;
    for(int i=0;i<sjf.n;i++){
        if(m>pt[i].arrival_t && pt[i].visited==0){
            m=pt[i].arrival_t;
        }
    }return m;
}
public static void sjf_non_preemtive(System_p p[],int calc) 
{   
    int n=sjf.n;
    int tmin=1000000; 
    double alpha=0.5,tao_n=10,tao_np1=10;
    
    int[] temp=new int[n];
    float avg_wt=0,avg_tat=0;
    for (int i = 0; i < n; i++){
        temp[i] = p[i].burst_time;
        if(tmin>p[i].arrival_t)
            tmin=p[i].arrival_t;
        p[i].visited=0;
    } 
    int num_p = 0, current_time = 0, curr_min = 1000000,curr_p = 0,f=0; 
    List<Integer> finish_time = new ArrayList<>();
    List<Integer> start_time = new ArrayList<>();
    List<Integer> curr = new ArrayList<>();
    int min=0;
    while (num_p != n) { 
        min=find_minat(p);
        for (int j = 0; j < n; j++) { 
            if ((p[j].arrival_t <= current_time) )
            if((temp[j] <= curr_min) && (temp[j] > 0)) { 
                curr_min = temp[j]; 
                curr_p = j; 
                f = 1; 
            } 
        } 
        if (f == 0) { 
            if(current_time<min)
                current_time=min;
            curr_min = 1000000;
            continue; 
        }  
        curr.add(p[curr_p].process_num);
        sjf.print_process(p,curr_p,current_time);
        start_time.add(current_time);
        p[curr_p].visited=1;
        current_time+=p[curr_p].burst_time; 
        curr_min = temp[curr_p]; 
        temp[curr_p]=0;
        finish_time.add(current_time);
        if (temp[curr_p] == 0) { 
            num_p++; 
            f = 0;  
            wait_time[curr_p] = current_time - p[curr_p].arrival_t - p[curr_p].burst_time; 
            if (wait_time[curr_p] < 0) 
                wait_time[curr_p] = 0; 
        } 
        if(current_time<min)
                current_time=min;
        if (curr_min == 0) 
            curr_min = 1000000; 
    } 
    if(calc==1){
    for (int i = 0; i < n; i++){
        turn_around_t[i] = p[i].burst_time + wait_time[i]; 
        tao_np1=tao_n*(1-alpha) + alpha*((double)p[i].burst_time);
        sjf.tao[i]=tao_np1;
        tao_n=tao_np1;
    }}
    System.out.println();
    System.out.println("Gantt Chart:");
    for (int i = 0; i < n; i++){
        int j=curr.get(i);
        int flag=0;
        if(i>0){
            if(start_time.get(i)==finish_time.get(i-1)){
                System.out.print("  P"+j+"  "+finish_time.get(i)+" ");
                flag=1;
            }
            else if(start_time.get(i)!=finish_time.get(i-1)){
                System.out.print("  Idle  "+start_time.get(i)+" ");
                flag=1;
                if(i<=n-1){
                    System.out.print("  P"+j+"  "+finish_time.get(i)+" ");
                }
            }
        }
        if(i==0||flag==0)
            System.out.print(start_time.get(i)+"  P"+j+"  "+finish_time.get(i)+" ");
    }
    System.out.println("\n\nSJF NON PREEMTIVE Final Process Table:");
    System.out.println("Process num    Predicted Burst Time   Burst time   Arrival time   Waiting time   Turn around time"); 
    for (int i = 0; i < n; i++) { 
        avg_wt +=  wait_time[i]; 
        avg_tat += turn_around_t[i]; 
    }
    for (int i = 0; i < n; i++)
        System.out.println(" "+p[i].process_num +"\t\t\t"+tao[i] +"\t\t"+p[i].burst_time +"\t\t"+ p[i].arrival_t + "\t\t " + wait_time[i] + "\t\t " + turn_around_t[i]); 
    avg_wt/=n;
    avg_tat/=n;
    System.out.println("\nAverage waiting time = "+ avg_wt+"\nAverage turn around time = "+ avg_tat); 
    System.out.println("\n\n\n");
} 

public static void sjf_non_preemtive_e(System_p p[],int calc) 
{   
    int n=sjf.n;
    int tmin=1000000; 
    double alpha=0.5,tao_n=10,tao_np1=10;
    
    int[] temp=new int[n];
    float avg_wt=0,avg_tat=0;
    for (int i = 0; i < n; i++){
        temp[i] = (int)sjf.tao[i];
        if(tmin>p[i].arrival_t)
            tmin=p[i].arrival_t;
        p[i].visited=0;
    } 
    int num_p = 0, current_time = 0, curr_min = 1000000,curr_p = 0,f=0; 
    List<Integer> finish_time = new ArrayList<>();
    List<Integer> start_time = new ArrayList<>();
    List<Integer> curr = new ArrayList<>();
    int min=0;
    while (num_p != n) { 
        min=find_minat(p);
        for (int j = 0; j < n; j++) { 
            if ((p[j].arrival_t <= current_time) )
            if((temp[j] <= curr_min) && (temp[j] > 0)) { 
                curr_min = temp[j]; 
                curr_p = j; 
                f = 1; 
            } 
        } 
        if (f == 0) { 
            if(current_time<min)
                current_time=min;
            curr_min = 1000000;
            continue; 
        }  
        curr.add(p[curr_p].process_num);
        sjf.print_process(p,curr_p,current_time);
        start_time.add(current_time);
        p[curr_p].visited=1;
        current_time+=p[curr_p].burst_time; 
        curr_min = temp[curr_p]; 
        temp[curr_p]=0;
        finish_time.add(current_time);
        if (temp[curr_p] == 0) { 
            num_p++; 
            f = 0;  
            wait_time[curr_p] = current_time - p[curr_p].arrival_t - p[curr_p].burst_time; 
            if (wait_time[curr_p] < 0) 
                wait_time[curr_p] = 0; 
        } 
        if(current_time<min)
                current_time=min;
        if (curr_min == 0) 
            curr_min = 1000000; 
    } 
    // if(calc==1){
    // for (int i = 0; i < n; i++){
    //     turn_around_t[i] = p[i].burst_time + wait_time[i]; 
    //     tao_np1=tao_n*(1-alpha) + alpha*((double)p[i].burst_time);
    //     sjf.tao[i]=tao_np1;
    //     tao_n=tao_np1;
    // }}
    System.out.println("FROM EXPONENTIAL AVERAGING");
    System.out.println("Gantt Chart:");
    for (int i = 0; i < n; i++){
        int j=curr.get(i);
        int flag=0;
        if(i>0){
            if(start_time.get(i)==finish_time.get(i-1)){
                System.out.print("  P"+j+"  "+finish_time.get(i)+" ");
                flag=1;
            }
            else if(start_time.get(i)!=finish_time.get(i-1)){
                System.out.print("  Idle  "+start_time.get(i)+" ");
                flag=1;
                if(i<=n-1){
                    System.out.print("  P"+j+"  "+finish_time.get(i)+" ");
                }
            }
        }
        if(i==0||flag==0)
            System.out.print(start_time.get(i)+"  P"+j+"  "+finish_time.get(i)+" ");
    }
    System.out.println("\n\nSJF NON PREEMTIVE Final Process Table:");
    System.out.println("Process num    Burst time   Arrival time   Waiting time   Turn around time"); 
    for (int i = 0; i < n; i++) { 
        avg_wt +=  wait_time[i]; 
        avg_tat += turn_around_t[i]; 
    }
    for (int i = 0; i < n; i++)
        System.out.println(" "+p[i].process_num +"\t\t"+p[i].burst_time +"\t\t"+ p[i].arrival_t + "\t\t " + wait_time[i] + "\t\t " + turn_around_t[i]); 
    avg_wt/=n;
    avg_tat/=n;
    System.out.println("\nAverage waiting time = "+ avg_wt+"\nAverage turn around time = "+ avg_tat); 
    System.out.println("\n\n\n");
} 

public static void sjf_preemtive(System_p p[]) 
{   
    int n=sjf.n;
	int temp[]=new int[n];  
    float avg_wt=0,avg_tat=0;
    double alpha=0.5,tao_n=10,tao_np1=10;
    double tao[]=new double[n];
    List<Integer> finish_time = new ArrayList<>();
    List<Integer> start_time = new ArrayList<>();
    List<Integer> curr = new ArrayList<>();
	for (int i = 0; i < n; i++) 
		temp[i] = p[i].burst_time; 
	int num_p = 0, current_time = 0, curr_min = 1000000,curr_p = 0,f=0; 
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
        curr.add(p[curr_p].process_num);
        sjf.print_process(p,curr_p,current_time);
        start_time.add(current_time);
        current_time++; 
        finish_time.add(current_time);
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
	for (int i = 0; i < n; i++){
        turn_around_t[i] = p[i].burst_time + wait_time[i]; 
        tao_np1=tao_n*(1-alpha) + alpha*((double)p[i].burst_time);
        tao[i]=tao_np1;
        tao_n=tao_np1;
    }
    System.out.println();
    System.out.println("Gantt Chart:");
    int current_p=-1;
    for (int i = 0; i < curr.size(); i++){
        int j=curr.get(i);
        int flag=0;
        if(i>0){
            if(start_time.get(i)==finish_time.get(i-1) && current_p!=j){
                System.out.print("  P"+j+"  ");
                current_p=j;
                flag=1;
            }
            else if(start_time.get(i)!=finish_time.get(i-1)){
                System.out.print("  Idle  "+start_time.get(i)+" ");
                flag=1;
                if(i<=n-1){
                    System.out.print("  P"+j+"  ");
                    current_p=j;
                }
            }
        }
        if(i==0||flag==0 && current_p!=j){
            System.out.print(start_time.get(i)+"  P"+j+"  ");
            current_p=j;
            // flag=1;
            for(int k=i;k<curr.size();k++){
                if(j!=curr.get(k)){
                    System.out.print(" "+finish_time.get(k-1)+" ");
                    break;
                }
            }
        }
        if(flag==1){
            for(int k=i;k<curr.size();k++){
                if(j!=curr.get(k)&&i!=0){
                    System.out.print(" "+finish_time.get(k-1)+" ");
                    break;
                }
            }
        }
    }System.out.print(" "+finish_time.get(curr.size()-1)+" ");
    System.out.println("\n\nSJF PREEMTIVE Final Process Table:");
	System.out.println("Process num    Predicted Burst Time   Burst time   Arrival time   Waiting time   Turn around time"); 
    for (int i = 0; i < n; i++) { 
		avg_wt +=  wait_time[i]; 
		avg_tat += turn_around_t[i]; 
    }
	for (int i = 0; i < n; i++)
		System.out.println(" "+p[i].process_num +"\t\t\t"+tao[i] +"\t\t"+p[i].burst_time +"\t\t"+ p[i].arrival_t + "\t\t " + wait_time[i] + "\t\t " + turn_around_t[i]); 
	avg_wt/=n;
    avg_tat/=n;
    System.out.println("\nAverage waiting time = "+ avg_wt+"\nAverage turn around time = "+ avg_tat); 
    System.out.println("\n\n\n");
} 
public static void main(String args[]) 
{   
    sjf.wait_time = new int[1000];
    sjf.turn_around_t =new int[1000];
    Scanner sc=new Scanner(System.in);

    System.out.println("Enter number of processes:");
    sjf.n=sc.nextInt();
    System_p p[] = new System_p[n];
    // System_p p1 =new System_p();
    // p[0].process_num=1;
    // System.out.print(p[0].process_num);
    for(int i=0;i<n;i++){
        System.out.println("Enter arrival and burst time of process "+(i+1)+ ":");
        p[i]=new System_p();
        p[i].process_num=i+1;
        p[i].arrival_t=sc.nextInt();
        p[i].burst_time=sc.nextInt();
    }
    // int t=1;
    // System.out.println(+"Enter Scheduling algorithm to be used(1.SJF PREEMTIVE 2.SJF non PREEMTIVE):";
    // cin>>t;
    // if(t==1)
    sjf.sjf_non_preemtive(p,1); 
    sjf.sjf_preemtive(p);
    // else if(t==2)
    //     fcfs(p);
    sjf.sjf_non_preemtive_e(p,1);
    sc.close();
} 

}