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
};

void queue::get_size(int n){
	q= new int[n];
	size= n;
}

bool queue::under_flow(){
	return((f==-1)&&(r==-1));
}

bool queue::over_flow(){
	return(r== size-1);
}

int queue::Dque(){
	int x =-99;
	if(!under_flow()){
			x= q[f];
			if (f==r) {
					f=r=-1;
			}else{
					f++;
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
				f++;
			}
				q[++r] = ele;
	} else {
		cout<< "Queue is over flow\n";
	}
}

void queue::display(){
	// cout << "f : "<< f << '\n';
	// cout << "r : "<< r << '\n';
	// cout << "under_flow not : "<< !under_flow() << '\n';
	if (!under_flow()) {
			int i;
			for(i=f;i<=r;i++){
				cout<<"\n "<<q[i];
			}
	} else {
		cout<< "queue is empty\n";
	}

}
int main(){
		queue q1;
		int n,i;
		int tmp_value;
		cout<<"Enter the size of queue : ";
		cin>>n;
		q1.get_size(n);
		for (i = 0; i < n; i++) {
				cout<< "Enter element of "<< i+1<< " : ";
				cin>> tmp_value;
				q1.Enque(tmp_value);
		}
		q1.display();
		cout<< "\n delete: "<< q1.Dque();
		q1.display();
	return(0);
}
