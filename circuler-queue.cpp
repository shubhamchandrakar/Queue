#include<iostream>
#include<string.h>
using namespace std;
class queue{
	int *q;
   int size, f, r;
public:
	queue()
	{
		q=NULL;
		size=0;
		f=r= -1;
	}
	~queue()
	{
		delete q;
//		cout<<"in delete = "<<s;
		size=0;
		f = r = -1;
	}

	void get_size(int);
	void Enque(int);
	int Dque();
	bool under_flow();
	bool over_flow();
	void display();
	void last_display(){
			cout<<"last inserted "<<q[0];
		}
};

void queue::get_size(int n){
	q= new int[n];
	size= n;
}

bool queue::under_flow(){
	return((f==-1)&&(r==-1));
}

bool queue::over_flow(){
	return(f== (r+1)%size);
}

int queue::Dque(){
	int x =-99;
	if(!under_flow()){
			x= q[f];
			if (f==r) {
					f=r=-1;
			}else{
					// f++;
					f= (f+1)%size;
			}
	}else{
			cout << "Queue is under flow" << '\n';
	}
	return x;
}

void queue::Enque(int ele){
	// cout << "f : "<< f << '\n';
	// cout << "r : "<< r << '\n';
	// cout << "over_flow not : "<< !over_flow() << '\n';
	if (!over_flow()) {
			if (r==-1&& f== -1) {
				// f++;
				f = (f+1)%size;
			}
				r= (r+1)%size;
				q[r] = ele;
				// q[++r] = ele;
	} else {
		cout<< "Queue is over flow\n";
	}
}

void queue::display(){
	if (!under_flow()) {
			int i;
			int tmp_r = r;
			if (r<f)
			{ 
				for(i=f;i!=r;){
					if (i < size) {
							cout<<q[i]<<endl;
							i++;
					}
					else{
						i=0;
					}
				}
				cout<<q[i]<<endl;
			}else{
				for(i=f;i<=r;i++){
					cout<<"\n "<<q[i];
				}
			}

	} else {
		cout<< "queue is empty\n";
	}

}
int main(){
		queue q1;
		int n,i;
		// int tmp_value;
		// cout<<"Enter the size of queue : ";
		// cin>>n;
		q1.get_size(5);
		q1.Enque(10);
		q1.Enque(20);
		q1.Enque(30);
		q1.Enque(40);
		q1.Enque(50);
		q1.display();
		cout<< "\n deleted : "<< q1.Dque()<< endl;
		cout<< "\n deleted : "<< q1.Dque()<< endl;
		q1.display();
		q1.Enque(60);
		q1.display();
		q1.last_display();
	return(0);
}
