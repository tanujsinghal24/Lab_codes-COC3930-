#include<iostream>
using namespace std;
int sort(int *arr,int n,int head){
    int temp=0,head_loc=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
        if(arr[i]==head){
            head_loc=i;
        }
    }
    return head_loc;
}
void scan(int* x,int n,int head){
    cout<<"\n\nSCAN\n\n";
    int arr[n+3];
    for(int i=0;i<n;i++){
        arr[i]=x[i];
    }
    int cnt=0,flag=0;
    arr[n]=head;++n;
    arr[n]=0;++n;
    arr[n]=200;++n;
    int head_loc=sort(arr,n,head);
    cout<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]==head)
            head_loc=i;
        cout<<arr[i]<<"\t";
    }cout<<endl;
    cout<<"head-->"<<arr[head_loc]<<endl;
    for(int i=head_loc;i>=0 && i<n;){
        cout<<"Visited-->"<<arr[i]<<endl;
        if(arr[i]!=head)
            cnt+=abs(arr[i]-arr[i-1]);
        if(i==0 && flag==0){
            i=head_loc+1;
            flag=1;
        }
       if(flag==0)
           i--;
       else
           i++;
    }
    cout<<endl<<"Head Movement--->"<<cnt<<endl<<endl;
}
void look(int* x,int n,int head){
    cout<<"\n\nLOOK\n\n";
    int arr[n+3];
    for(int i=0;i<n;i++){
        arr[i]=x[i];
    }
    int cnt=0,flag=0;
    arr[n]=head;++n;
    // arr[n]=0;++n;
    // arr[n]=200;++n;
    int head_loc=sort(arr,n,head);
    cout<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]==head)
            head_loc=i;
        cout<<arr[i]<<"\t";
    }cout<<endl;
    cout<<"head-->"<<arr[head_loc]<<endl;
    for(int i=head_loc;i>=0 && i<n;){
        cout<<"Visited-->"<<arr[i]<<endl;
        if(arr[i]!=head)
            cnt+=abs(arr[i]-arr[i-1]);
        if(i==0 && flag==0){
            i=head_loc+1;
            flag=1;
        }
       if(flag==0)
           i--;
       else
           i++;
    }
    cout<<endl<<"Head Movement--->"<<cnt<<endl<<endl;
}
void cscan(int* x,int n,int head){
    cout<<"\n\nCSCAN\n\n";
    int arr[n+3];
    for(int i=0;i<n;i++){
        arr[i]=x[i];
    }
    int cnt=0,flag=0;
    arr[n]=head;++n;
    arr[n]=0;++n;
    arr[n]=200;++n;
    int head_loc=sort(arr,n,head);
    cout<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]==head)
            head_loc=i;
        cout<<arr[i]<<"\t";
    }cout<<endl;
    cout<<"head-->"<<arr[head_loc]<<endl;
    for(int i=head_loc;i>=0 && i<=n;){
        cout<<"Visited-->"<<arr[i]<<endl;
        // if(arr[i]!=head)
            cnt+=abs(arr[i]-arr[i-1]);
        if(flag==0)
           i++;
        if(flag==1){
            if(arr[i+1]!=head)
                i++;
            else
                break;
        }
        if(i==n){
            i=0;
            flag=1;
        }
    }
    cout<<endl<<"Head Movement--->"<<cnt<<endl<<endl;
}
void clook(int* x,int n,int head){
    cout<<"\n\nCLOOK\n\n";
    int arr[n+3];
    for(int i=0;i<n;i++){
        arr[i]=x[i];
    }
    int cnt=0,flag=0;
    arr[n]=head;++n;
    // arr[n]=0;++n;
    // arr[n]=200;++n;
    int head_loc=sort(arr,n,head);
    cout<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]==head)
            head_loc=i;
        cout<<arr[i]<<"\t";
    }cout<<endl;
    cout<<"head-->"<<arr[head_loc]<<endl;
    for(int i=head_loc;i>=0 && i<=n;){
        cout<<"Visited-->"<<arr[i]<<endl;
        if(arr[i]!=head)
            cnt+=abs(arr[i]-arr[i-1]);
        if(flag==0)
           i++;
        if(flag==1){
            if(arr[i+1]!=head)
                i++;
            else
                break;
        }
        if(i==n){
            i=0;
            flag=1;
        }
    }
    cout<<endl<<"Head Movement--->"<<cnt<<endl<<endl;
}
int sstf_min(int* arr,int n,int diff,int* mark){
    int t[n],min=10000;
    for(int i=0;i<n;i++){
        t[i]=abs(arr[i]-diff);
    }
    int j=0;
    for(int i=0;i<n;i++){
        if(min>t[i] && mark[i]!=1 && t[i]!=0){
            min=t[i];
            j=i;
        }
        if(i==n-1){
            mark[j]=1;
            min=arr[j];
        }
    }
    return min;
}
void sstf(int* x,int n,int head){
    cout<<"\n\nSSTF\n\n";
    int arr[n+3],t[n+3],mark[n+3];
    for(int i=0;i<n;i++){
        arr[i]=x[i];
        mark[i]=0;
    }
    int cnt=0,flag=0;
    arr[n]=head;++n;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }cout<<endl;
    int min;
    cout<<"Visited-->"<<53<<endl;
    mark[n]=1;
    for(int i=0;i<n-1;i++){
        min=sstf_min(arr,n-1,head,mark);
        cout<<"Visited-->"<<min<<endl;
        cnt+=abs(min-head);
        head=min;
        
    }
    cout<<endl<<"Head Movement--->"<<cnt<<endl<<endl;
}
int main(){
    int arr[100],n,head,temp;
    cout<<"Enter starting head:";
    cin>>head;
    cout<<"Enter number of locations to be visited:";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp!=head)
            arr[i]=temp;
        else
            n--;
    }
    scan(arr,n,head);
    cscan(arr,n,head);
    look(arr,n,head);
    clook(arr,n,head);
    sstf(arr,n,head);
}