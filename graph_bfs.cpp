#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct list
{
	int data;
	list *next;
};

struct graph
{
	int v;
	int e;
	list **adj;
};

graph *g = new graph;

void Create_graph(int V,int e)
{ 
	int u,v;
	list *temp;
	g->v =  V;
	g->e =  e;
	g->adj = new list*[g->v];
	for(int i=1;i<=g->v;i++)
	{	g->adj[i] = new list;
		g->adj[i]->data = i;
		g->adj[i]->next = NULL;
	}
	cout<<"Enter Edges(u->v):\n";
	for(int i=1;i<=g->e;i++)
	{
		cin>>u>>v;
		temp = new list;
		temp->data = v;
		temp->next = g->adj[u]->next;
		g->adj[u]->next = temp;
		temp = new list;
		temp->data = u;
		temp->next = g->adj[v]->next;
		g->adj[v]->next = temp;
	}
}

bool Search(stack<int>s,int v)
{
  stack<int>s1;
  while(!s.empty())
  {
    int temp = s.top();
    if(temp == v)
      return 0;
    else{
      s1.push(temp);s.pop();}
  }
  return 1;
}

void DFS(int visited[],int u)
{
	stack<int>s;
	s.push(u);
  list *temp = new list;
	while(!s.empty())
	{
			int top = s.top();
			visited[top]=1;
			s.pop();
      temp = g->adj[top];
      cout<<top<<" ";
      temp = temp->next;
			while(temp)
			{ 
        if(!visited[temp->data] && Search(s,temp->data))
  				s.push(temp->data);
  			temp = temp->next;
      }
  }
  cout<<"\n";
}

bool search(queue<int>q,int v)
{
  queue<int>q1;
  while(!q.empty())
  {
    int temp = q.front();
    if(temp == v)
      return 0;
    else{
      q1.push(temp);q.pop();}
  }
  return 1;
}
	

void BFS(int visited[],int u)
{
	queue<int>q;
	q.push(u);
	list *temp = new list;
	while(!q.empty())
	{
		int top = q.front();
		visited[top] = 1;
		q.pop();
		temp = g->adj[top];
		cout<<top<<" ";
		temp = temp->next;
		while(temp)
		{
			if(!visited[temp->data] && search(q,temp->data))
				q.push(temp->data);
			temp = temp->next;
		}
	}
	cout<<endl;
}
		 
	

void display()
{
	for(int i=1;i<=g->v;i++)
		{
			while(g->adj[i])
				{
					cout<<g->adj[i]->data<<"<->";
					g->adj[i] = g->adj[i]->next;
				}
				cout<<"NULL"<<endl;
		}
}

int main()
{
	int v,e;
	cout<<"Enter number of vertices and edges:\n";
	cin>>v>>e;
	int visited[v];
	for(int i=1;i<=v;i++)
		visited[i] = 0;
	Create_graph(v,e);
  cout<<"\n"<<"DFS is:\n";
   DFS(visited,1);
   cout<<endl;
   for(int i=1;i<=v;i++)
   	visited[i]=0;
   cout<<"BFS is\n";
   BFS(visited,1);cout<<endl;
   display();
	
  
	return 0;
}
