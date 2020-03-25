#include<iostream>
using namespace std;
class chopstick{
    public:
	int in_use;
};
class Philospher{
    public:
	int left;
	int right;
};
chopstick curr_forks[100];
Philospher table_p[100];

int free_philosphers = 0,state2=2;

void dinner(int curr_philospher,int n){
	
int index = curr_philospher+1;
	if(table_p[curr_philospher].left==state2 && table_p[curr_philospher].right==state2)
        cout<<"Philosopher "<<index<<" has eaten\n";
	else if(table_p[curr_philospher].left==1 && table_p[curr_philospher].right==1){
            cout<<"Philosopher "<<index<<" has eaten\n";
 			table_p[curr_philospher].left = table_p[curr_philospher].right = state2;
            int temp_side = curr_philospher-1;
            if(temp_side== -1)
                temp_side=(n-1);

            curr_forks[curr_philospher].in_use = curr_forks[temp_side].in_use = 0;
            cout<<"Philosopher "<<index<<" has released chopstick "<<index<<" and chopstick "<<temp_side+1<<"\n";
            free_philosphers++;
        }
        else if(table_p[curr_philospher].left==1 && table_p[curr_philospher].right==0){ 
                if(curr_philospher==(n-1)){
                    if(curr_forks[curr_philospher].in_use==0){
                        curr_forks[curr_philospher].in_use = table_p[curr_philospher].right = 1;
                        cout<<"Philosopher "<<curr_philospher+1<<" is thinking and has chopstick "<<curr_philospher+1<<"\n";
                    }else{
                        cout<<"Philosopher "<<curr_philospher+1<<" is thinking and needs chopstick "<<curr_philospher+1<<"\n";
                    }
                }else{
                    int temp = curr_philospher;
                    curr_philospher-=1;
 
                    if(curr_philospher== -1)
                        curr_philospher=(n-1);
                    if(curr_forks[curr_philospher].in_use == 0){
                        curr_forks[curr_philospher].in_use = table_p[temp].right = 1;
                        cout<<"Philosopher "<<temp+1<<" is thinking and has chopstick "<<curr_philospher+1<<"\n";
                    }else{
                        cout<<"Philosopher "<<temp+1<<" is thinking and needs chopstick "<<curr_philospher+1<<"\n";
                    }
                }
            }
            else if(table_p[curr_philospher].left==0){
                    if(curr_philospher==(n-1)){
                        if(curr_forks[curr_philospher-1].in_use==0){
                            curr_forks[curr_philospher-1].in_use = table_p[curr_philospher].left = 1;
                            cout<<"Philosopher "<<curr_philospher+1<<" is thinking and has chopstick "<<curr_philospher<<"\n";
                            
                        }else{
                            cout<<"Philosopher "<<curr_philospher+1<<" is thinking and needs chopstick "<<curr_philospher<<"\n";
                        }
                    }else{
                        if(curr_forks[curr_philospher].in_use == 0){
                            curr_forks[curr_philospher].in_use = table_p[curr_philospher].left = 1;
                            cout<<"Philosopher "<<curr_philospher+1<<" is thinking and has chopstick "<<curr_philospher+1<<"\n";
                        }else{
                            cout<<"Philosopher "<<curr_philospher+1<<" is thinking and needs chopstick "<<curr_philospher+1<<"\n";
                        }
                    }
        }else{}
}
 
int main(){
	int n;
	cout<<"Enter number of philosphers:";
	cin>>n;
	for(int i=0;i<n;i++)
        curr_forks[i].in_use=table_p[i].left=table_p[i].right=0;
 
	while(free_philosphers!=n){
        int i=0;
        while(i<n){
            dinner(i,n);
            i++;
        }
		cout<<"Number of philosophers who have completed dinner: "<<free_philosphers<<"\n\n";
	}
	return 0;
}