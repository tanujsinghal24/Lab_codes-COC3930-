import java.util.Scanner;
public class banker_algo{
    // public static int n_proc,m_res;
    public static void main(String args[]){
        int n_proc,m_res;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number of processes");
        n_proc=sc.nextInt();
        System.out.println("Enter number of resources");
        m_res=sc.nextInt();
        bank curr_bank=new bank(n_proc,m_res);
        System.out.println();
        curr_bank.inputAllocated();
        System.out.println();
        curr_bank.inputMaxi_r();
        System.out.println();
        curr_bank.inputAvailable();
        System.out.println();
        curr_bank.setNeed();
        System.out.println();
        curr_bank.print_system_state();
        System.out.println();
        // curr_bank.safety_check();
        curr_bank.res_request(1);
        sc.close();
        return;
    }
}
class bank{
    public int n_proc,m_res;
    public int request[];
    private int available[];
    private int maxi_r[][];
    private int need[][];
    private int allocated[][];
    private int work[];
    public int safe_state,unsafe_state;
    private int safe_seq[];
    private boolean finish[];
    public Scanner sc;
    public bank(int n_proc, int m_res){
        this.n_proc=n_proc;
        this.m_res=m_res;
        sc=new Scanner(System.in);
        available=new int[m_res];
        request=new int[m_res];
        maxi_r=new int[n_proc][m_res];
        need=new int[n_proc][m_res];
        allocated=new int[n_proc][m_res];
        safe_seq=new int[n_proc];
        work=new int[m_res];
        finish=new boolean[n_proc];
        for(int i=0;i<n_proc;i++){
            finish[i]=false;
        }
    }


    public void inputAvailable() {
        System.out.println("Enter Available Resources:");
        for(int i=0;i<m_res;i++){
            available[i] = sc.nextInt();
            work[i]=available[i];
        }
    }
    public void inputMaxi_r() {
        System.out.println("Enter Maximum number of Resources needed for each process:");
        for(int i=0;i<n_proc;i++){
            System.out.println("Max Resources for process "+ i + ": ");
            for(int j=0;j<m_res;j++){
                maxi_r[i][j] = sc.nextInt();
            }
        }
    }
    public void inputAllocated() {
        System.out.println("Enter allocated number of Resources needed for each process:");
        for(int i=0;i<n_proc;i++){
            System.out.println("Allocated Resources for process "+ i + ": ");
            for(int j=0;j<m_res;j++){
                allocated[i][j] = sc.nextInt();
            }
        }
    }
    public void setNeed() 
    { 
        for (int i=0;i<n_proc;i++) { 
            for (int j=0;j<m_res;j++) { 
                need[i][j]=maxi_r[i][j]-allocated[i][j]; 
                if(need[i][j]<0){
                    need[i][j]=0;
                }
            } 
        }         
    } 
    public void res_request(int proc_num){
        int temp=1;
        System.out.println("Enter needed resources:");
        for(int i=0;i<m_res;i++){
            request[i] = sc.nextInt();
        }
        for(int i=0;i<m_res;i++){
            if(need[proc_num][i]<request[i]){
                temp=0;
            }
        }
        if(temp==1){
            for(int i=0;i<m_res;i++){
                if(available[i]<request[i]){
                    temp=0;
                }
            }
            if(temp==1){
                for(int i=0;i<m_res;i++){
                    allocated[proc_num][i]+=request[i];
                    available[i]-=request[i];
                    need[proc_num][i]-=request[i];
                }
            }
        }
        this.safety_check();
    }
    
    public void printAllocated() {
        System.out.println("Allocation matrix---->\n");
        for(int i=0;i<n_proc;i++){
            System.out.print("Process "+ i + ":");
            for(int j=0;j<m_res;j++){
                System.out.print("\t"+allocated[i][j]);
            }System.out.println();
        }System.out.println();
    }
    public void printneed() {
        System.out.println("Need matrix---->\n");
        for(int i=0;i<n_proc;i++){
            System.out.print("Process "+ i + ":");
            for(int j=0;j<m_res;j++){
                System.out.print("\t"+need[i][j]);
            }System.out.println();
        }System.out.println();
    }
    public void printMaxi_r() {
        System.out.println("Maximum requirement matrix---->\n");
        for(int i=0;i<n_proc;i++){
            System.out.print("Process "+ i + ":");
            for(int j=0;j<m_res;j++){
                System.out.print("\t"+maxi_r[i][j]);
            }System.out.println();
        }System.out.println();
    }


    public void print_system_state(){
        this.printAllocated();
        this.printMaxi_r();
        System.out.println("Work ---->");
        for(int i=0;i<m_res;i++){
            System.out.print(" "+work[i]);
        }System.out.println();
        this.printneed();
    }
    

    public boolean compare(int proc){
        for(int k=0;k<m_res;k++){
            if(need[proc][k] > work[k])
                return false;
        }
        return true;
    }

    public void safety_check(){
        System.out.println("Bankers algorithm: ");
        int temp=0,curr_proc=-1,t=0;
        while(true){
            safe_state=0;
            for(int i=t;i<n_proc;i++){
                if(!finish[i] && compare(i)){
                    curr_proc=i;
                    safe_state=1;
                    safe_seq[temp] = i;
                    temp+=1;
                    break;
                }
            }
            if(temp!=n_proc){
                if(curr_proc==n_proc-1)
                    t=0;
                else{
                    t=curr_proc;
                }
            }
            if (safe_state==0){
                System.out.println("Deadlock State found");
                unsafe_state=1;
                return;
            }
            if(curr_proc!=-1)
                finish[curr_proc]=true;
            System.out.println();
            System.out.println("Process P"+curr_proc+" completed");
            System.out.print("Updated Work ---->");
            for(int i=0;i<m_res;i++){
                work[i] += allocated[curr_proc][i];
                System.out.print(" "+work[i]);
            }System.out.println();
            System.out.println();
            if(temp==n_proc){
                System.out.println("Safe State Found");
                break;
            }
        }
        System.out.print("Safe Sequence ---->");
        for(int i=0;i<n_proc;i++){
            System.out.print("  P"+safe_seq[i]);
        }System.out.println();
    }
}