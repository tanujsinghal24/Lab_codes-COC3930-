#include<iostream>
using namespace std;
class queue{
    public:
    int q[100],front,end;
    queue(){
        front=0;
        end=0;
        for(int i=0;i<100;i++){
            q[i]=-1;
        }
    }
    void push(int ele){
        if(end<0)
            end=0;
        q[end]=ele;
        end++;
    }
    int pop(){
        if(end<0)
            return -1;
        int temp=q[end];
        end--;
        return temp;
    }
    bool empty(){
        if(end<0)
            return true;
        return false;
    }
};
class graph{
    public:
    int n,e;
    int mat[100][100],marked[100][100],visited[100],mi,mj;
    int vert[100],vl;
    graph(){
        vl=1;
        for(int i=0;i<100;i++){
            visited[i]=0;
            for(int j=0;j<100;j++){
                mat[i][j]=0;
                marked[i][j]=0;
            }
        }
    }
    void visit_int(){
        for(int i=0;i<100;i++){
            visited[i]=0;
        }
    }
    void create_edge(int start,int end,int weight){
        mat[start][end]=weight;
    }
    void create_double_edge(int start,int end,int weight){
        mat[start][end]=weight;
        mat[end][start]=weight;
    }
    void intialize_graph(){
        int ts,te,weight;
        cout<<"Enter number of vertices"<<endl;
        cin>>n;
        cout<<"Vertices Initalized ---> ";
        for(int i=1;i<=n;i++){
            cout<<i<<"\t";
        }
        cout<<endl<<endl;
        cout<<"Enter number of edges"<<endl;
        cin>>e;
        for(int i=0;i<e;i++){
            // cout<<"Enter starting edge and end egde: ";
            cin>>ts>>te;
            weight=1;
            if(ts>0 && te<=n)
                this->create_double_edge(ts,te,weight);
            else{
                cout<<"\nwrong edge!!!Re enter\n\n";
                i--;
            }
        }
    }
    void print_graph(){
        cout<<"   \t";
        for(int i=1;i<=n;i++){
            cout<<i<<"\t";
        }cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<i<<"->\t";
            for(int j=1;j<=n;j++){
                cout<<mat[i][j]<<"\t";
            }cout<<endl;
        }
    }
    void bfs(){
        int snode;
        visit_int();
        cout<<"\nEnter Starting node:";
        cin>>snode;
        queue q;
        // cout<<snode;
        q.push(snode);
        visited[snode]=1;
        cout<<"Node-->"<<snode;
        while(!q.empty()){
            int temp=q.pop();
            for(int i=1;i<n+1;i++){
                if(mat[temp][i]==1 && visited[i]==0){
                    cout<<"\nEdge-->"<<temp<<" --- "<<i;
                    visited[i]=1;
                    q.push(i);
                }
            }
            visited[temp]=2;
        }
    }
    void dfs(int node){
        if(visited[node]==0){
            visited[node]=1;
            for(int i=1;i<n+1;i++){
                if(mat[node][i]==1 && visited[i]==0){
                    cout<<"Edge--->  "<<node<<" --- "<<i<<endl;
                    dfs(i);
                }
            }
        }
    }
    void dfs_init(){
        visit_int();
        int snode;
        cout<<"\nEnter Starting node:";
        cin>>snode;
        queue q;
        this->dfs(snode);

    }
};
int main(){
    graph g;
    g.intialize_graph();
    g.print_graph();
    g.bfs();
    g.dfs_init();
}