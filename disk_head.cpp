#include<iostream>
using namespace std;
void fcfs(int* arr,int n,int head){
	int x[n],cnt=0;
	for(int i=0;i<n;i++){
		x[i]=arr[i];
	}
	for(int i=0;i<n;i++){
		cnt+=abs(arr[i]-head);
		cout<<arr[i];
		head=arr[i];
	}
	cout<<endl;
	cout<<cnt;
}
int sstf_min(int* x,int n,int* mark,int head){
	int min=100000,j=0;
	for(int i=0;i<n;i++){
		if(mark[i]!=1 && min>abs(x[i]-head)){
			min=abs(x[i]-head);
			j=i;
		}
		if(i==n-1){
			mark[j]=1;
			min=x[j];
		}
	}
	return min;
}
void sstf(int* arr,int n,int head){
	int x[n+3],cnt=0,min,mark[n];
	for(int i=0;i<n;i++){
		x[i]=arr[i];
		mark[i]=0;
	}
	for(int i=0;i<n;i++){
		min=sstf_min(x,n,mark,head);
		cnt+=abs(min-head);
		head=min;
	}
	cout<<cnt<<endl;
}
int sstf_min(int* x,int n,int* mark,int head){
	int min=100000,j=0;
	for(int i=0;i<n;i++){
		if(mark[i]!=1 && min>abs(x[i]-head)){
			min=abs(x[i]-head);
			j=i;
		}
		if(i==n-1){
			mark[j]=1;
			min=x[j];
		}
	}
	return min;
}
void sstf(int* arr,int n,int head){
	int x[n+3],cnt=0,min,mark[n];
	for(int i=0;i<n;i++){
		x[i]=arr[i];
		mark[i]=0;
	}
	for(int i=0;i<n;i++){
		min=sstf_min(x,n,mark,head);
		cnt+=abs(min-head);
		head=min;
	}
	cout<<cnt<<endl;
}
int main(){
	int head,n;
	cout<<"Enter head\n";
	cin>>head;
	cout<<"Enter number of positions to be visited:";
	cin>>n;
	int arr[n+3];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	fcfs(arr,n,head);
	sstf(arr,n,head);
}