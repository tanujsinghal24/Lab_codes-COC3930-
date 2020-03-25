#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class graph{
public:
	int mat[100][100],marked[100][100],visited[100];
	int v,e,n,x,mi,mj;
	void initialize_graph(){
		x=0;
		for(int i=0;i<n;i++){
			visited[i]=0;
			for(int j=0;j<n;j++){
				mat[i][j]=0;
				marked[i][j]=0;
			}
		}
	}
	void create_egde(int start,int end,int weight){
		mat[start][end]=weight;
	}
	void create_double_egde(int start,int end,int weight){
		mat[start][end]=weight;
		mat[end][start]=weight;
	}
	void create_graph(){
		int temp,start,end,weight;
		cout<<"Enter number of vertices:";cin>>v;
		n=v;
		cout<<"Enter number of edges:";cin>>e;
		initialize_graph();
		for(int i=0;i<e;i++){
			cout<<"Enter edge (start,end,weight):";
			cin>>start>>end>>weight;
			if(start>=n || start<0 || end>=n || end<0 || weight==0){
				cout<<"Error\n";
				i--;
				continue;
			}
			create_double_egde(start,end,weight);
		}cout<<endl;
	}
	int check_visited(int j){
		for(int i=0;i<x;i++){
			if(visited[i]==j)
				return 1;
		}return 0;
	}
	int check_circuit(int s,int e){
		if(check_visited(s)!=1 && check_visited(e)!=1)
			return 0;
		for(int i=0;i<n;i++){
			if((mat[s][i]!=0) && i!=s && i!=e){
				if(mat[e][i]!=0 && check_visited(i)!=1){
					
				}
			}
		}return 0;
	}
	void find_min_edge(){
		int ti=0,tj=0,min=10000000;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if((mat[i][j]!=0) && (marked[i][j]!=1) && ((check_visited(j)!=1 || check_visited(i)!=1) || check_circuit(i,j)!=1)){
					if(min>mat[i][j]){
						min=mat[i][j];
						ti=i;tj=j;
					}
				}
			}
		mi=ti;
		mj=tj;
		}
	}
	void krukshals(){
		int temp;
		for(int i=0;i<e;i++){
			find_min_edge();
			if(marked[mi][mj]!=1)
				cout<<"weight-->"<<mat[mi][mj]<<"\tedge-->"<<mi<<" , "<<mj;cout<<endl;
			marked[mi][mj]=1;
			marked[mj][mi]=1;
			if(check_visited(mi)==1 && check_visited(mj)==1)
				continue;
			if(check_visited(mi)!=1){
				visited[x]=mi;
				x+=1;
			}
			if(check_visited(mj)!=1){
				visited[x]=mj;
				x+=1;
			}
			
		}
	}	
};

int main(){
	graph g;
	g.create_graph();
	g.krukshals();
}