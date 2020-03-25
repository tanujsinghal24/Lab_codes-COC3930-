#include<iostream>
using namespace std;
class Pages{
	public:
	int page[100],pages_num;
	int frames[100],frames_num,curr_frame;
	int counter[100];
	int hit,fault;
	Pages(int n,int frames){
		pages_num=n;
		frames_num=frames;
		curr_frame=0;
		hit=0;
		fault=0;
		for(int i=0;i<frames_num;i++){
			counter[i]=0;
			this->frames[i]=-1;
		}
	}

	void print_state(){
		cout<<"Current Frames:---> ";
		for(int i=0;i<frames_num;i++){
			cout<<frames[i]<<" ";
		}cout<<endl;
		// cout<<"Current counter:---> ";
		// for(int i=0;i<frames_num;i++){
		// 	cout<<counter[i]<<" ";
		// }cout<<endl;
	}

	void lru(){
		cout<<"\n\n\n\n\n";
		cout<<"-----------------------------------------\n";
		cout<<"---------------LRU PAGING----------------\n";
		for(int i=0;i<frames_num;i++){
			counter[i]=0;
			frames[i]=-1;
		}
		cout<<"Intial State:-->\n";
		print_state();
		cout<<"\n\n";
		int temp=0,j,min_index=0;
		for(int i=0;i<pages_num;i++){
			cout<<"Current page: "<<page[i]<<endl;
			for(j=0,temp=0;j<frames_num;j++){
				if(curr_frame<frames_num){
					if(j>curr_frame){
						break;
					}
				}
				
				if(frames[j]==page[i]){
					int maxm=0;
					for(int k=0;k<frames_num;k++){
						if(counter[maxm]<counter[k] && frames[k]!=-1)
							maxm=counter[k];
					}
					counter[j]=maxm+1;
					cout<<"Page hit\n";
					// print_state();
					cout<<endl;
					temp=1;
					hit+=1;
					break;
				}

			}
			for(int j=0;j<frames_num;j++){
					counter[j]-=1;
			}
			if(temp==0){
				cout<<"Page FAULT\n";
				print_state();
				cout<<endl;
				fault+=1;
				if(curr_frame<frames_num){
					frames[curr_frame]=page[i];
					counter[curr_frame]=1;
					curr_frame+=1;
					
				}
				else{
					for(int i=0;i<frames_num;i++){
						if(counter[min_index]>counter[i] && frames[i]!=-1){
							min_index=i;
						}
					}
					// if()
					frames[min_index]=page[i];
					counter[min_index]=1;
					// print_state();
					cout<<endl;
				}
			}
		}
		print_state();
		cout<<endl;
		cout<<endl<<"Total number of page faults: "<<fault;
		cout<<endl<<"Total number of page hits: "<<hit<<endl;
		curr_frame=0;
	}
	

	void optimal(){
		cout<<"\n\n\n\n\n";
		cout<<"-----------------------------------------\n";
		cout<<"-------------OPTIMAL PAGING--------------\n";
		for(int i=0;i<frames_num;i++){
			counter[i]=-1;
			frames[i]=-1;
		}
		int faults=0,hits=0;
		cout<<"Intial State:-->\n";
		print_state();
		cout<<"\n\n";
		int curr_page;
		int temp,j,f=0;
		for(int i=0;i<pages_num;i++){
			curr_page=i;
			cout<<"Current page: "<<page[i]<<endl;
			
			for(int j=0;j<frames_num;j++){
				temp=0;
				if(curr_frame==0){
					frames[0]=page[i];
					curr_frame+=1;
					faults+=1;
					temp=1;
					break;
				}
				if(curr_frame<frames_num){
					if(j>curr_frame){
						break;
					}
				}
				if(frames[j]==page[i]){
					cout<<"Page HIT\n";
					temp=1; 
					f=1;
					hits+=1;
					break;
				}
			}
			if(temp==0){
				cout<<"PAGE FAULT\n\n";
				faults+=1;
				if(curr_frame<frames_num){
					frames[curr_frame]=page[i];
					curr_frame+=1;
				}
				else{
					int flag=0;
					for(int k=0;k<frames_num;k++){
						flag=0;
						for(int j=curr_page+1;j<pages_num;j++){
							if(frames[k]==page[j]){
								counter[k]=j-curr_page;
								flag=1;
								break;
							}
						}
						if(flag==0){
							counter[k]=100;
						}
					}
					int max_index=0;
					for(int k=0;k<frames_num;k++){
						if(counter[k]>counter[max_index]){
							max_index=k;
						}
					}
					frames[max_index]=page[curr_page];
					print_state();
					cout<<endl;
				}
			}
		}
		print_state();
		cout<<endl;
		cout<<endl<<"Total number of page faults: "<<faults;
		cout<<endl<<"Total number of page hits: "<<hits<<endl;
	}


};
int main(){
	int n=0,frames,arr[100];
	// cout<<"Enter number of page requests:";
	// cin>>n;
	cout<<"Enter number of frames:";
	cin>>frames;
	int t=-2;
	cout<<"Enter referenced page numbers:\n";
	while(1){
		cout<<"Enter page number:";
		cin>>t;
		if(t==-1){
			break;
		}
		arr[n]=t;
		n+=1;

	}

	Pages p(n,frames);
	for(int i=0;i<n;i++){
		p.page[i]=arr[i];
	}
	

	p.lru();
	p.optimal();
}