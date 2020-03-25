#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
};
struct edge{
    int start,end;
};
class graph{
    int num_nodes;
    int visited[100];
    int list_length[100];
    node **list;
    void create_node(int start,int end){
        node* new_node = new node;
        new_node->val=end;
        list_length[start]+=1;
        new_node->next=list[start]->next;
        list[start]->next=new_node;
    }
    node* list_end(node* s){
        while(s->next !=NULL)
            s=s->next;
        return s;
    }
    public:
        int temp;
        graph(int num_nodes){
            this->num_nodes=num_nodes;
            this->list=new node*[num_nodes];
            cout<<"vertices: ";
            for (int i = 1; i <= num_nodes; i++){
                cout<<i<<" ";
                node* new_node1 = new node;
                node* new_node = new node;
                new_node->next=NULL;
                new_node->val=i;
                list[i] = new_node;
                list_length[i]=0;
                visited[i]=0;
            }cout<<" done creating list\n";
            
        }
        void create_edges(edge e){
            create_node(e.start,e.end);
            cout<<"edge created\n";
        }
        void dfs(int start_n){
            if(list[start_n]==NULL || visited[start_n]==1)
                return;
            if(visited[start_n]!=1){
                cout<<list[start_n]->val;
                visited[start_n]=1;
            }
            temp=list[start_n]->val;
            node* t=list[start_n];
            for(int i=0 ;i <=list_length[start_n]; i++ ){
                if(t!=NULL)
                    temp=t->val;
                t=t->next;
                if(visited[temp]!=1)
                    dfs(temp);
            }
        }
        void view_vertex(int i){
            node* p = list[i];
            while (p!=NULL){
                cout<< " -> " <<p->val<< " ";
                p=p->next;
            }
            cout << endl;
        }
};

int main(){
    edge e;
    int num_nodes,num_edges;
    cout<<"Enter number of vertices: ";
    cin>>num_nodes;
    graph g(num_nodes);
    cout<<"Enter number of edges: ";
    cin>>num_edges;
    for (int i = 1; i <=num_edges; i++)
    {
        cout<<"Start vertex: ";
        cin>>e.start;
        cout<<"End Vertex: ";
        cin>>e.end;
        if(e.end<=num_nodes && e.end>0 && e.start<=num_nodes && e.start>0){
            g.create_edges(e);
            g.view_vertex(e.start);
            cout<<endl;
        }
        else{
            cout<<"Not an applicable vertex. Re-Enter vertex:\n";
            i=i-1;
        }
    }
    for(int i=1;i<=num_nodes;i++){
        g.view_vertex(i);
        cout<<endl;
    }
    cout<<"DFS"<<endl;
    for(int i=1;i<=num_nodes;i++){
        cout<<i<<"---";
        g.dfs(i);
        cout<<endl;
    }
}