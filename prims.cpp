#include<iostream>
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
		int f1=0,f2=0,min=99999999;
		for(int i=0;i<x;i++){
			// if(visited[i]==curr_s)
			// 	f1=1;
			if(visited[i]==j)
				f2=1;
			if(f2==1)
				return 1;
		}
		return 0;
	}
	void find_min_edge(){
		int min=9999999;
		for(int i=0;i<x;i++){
			int curr_s = visited[i];
			// cout<<"visited:"<<curr_s<<endl;
			for(int j=0;j<n;j++){
				if((mat[curr_s][j]!=0) && (marked[curr_s][j]!=1) && check_visited(j)!=1){
					if(min>mat[curr_s][j]){
						min=mat[curr_s][j];
						mi=curr_s;
						mj=j;
					}
				}
			}
		}
	}
	void prims(int start){
		int cnt=0,temp,curr_s=start,curr_e;
		visited[x]=start;
		x=1;
		while(1){
			for(int j=0;j<e+1;j++){
				find_min_edge();
				if(check_visited(mi)==1 && check_visited(mj)==1)
					continue;
				marked[mi][mj]=1;
				visited[x]=mj;
				x+=1;
                cnt+=1;
                cout<<"weight-->"<<mat[mi][mj]<<"\tedge-->"<<mi<<" , "<<mj;cout<<endl;
			}
			break;
		}
	}
};

int main(){
	graph g;
	g.create_graph();
	g.prims(1);
}