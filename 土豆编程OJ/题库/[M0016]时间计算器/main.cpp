#include<iostream>
using namespace std;
int main() {
	long long int ms;
	cin>>ms;
	if(ms/1000/60/60<10){
		cout<<0<<ms/1000/60/60;
	}
	else{
		cout<<ms/1000/60/60;
	}
	cout<<':';
	if(ms/1000/60%60<10){
		cout<<0<<ms/1000/60%60;
	}
	else{
		cout<<ms/1000/60%60;
	}
	cout<<':';
	if(ms/1000%60<10){
		cout<<0<<ms/1000%60;
	}
	else{
		cout<<ms/1000%60;
	}
	cout<<'.';
	if(ms%1000<1){
		cout<<"000";
	}
	else if(ms%1000<10){
		cout<<"00"<<ms%1000;
	}
	else if(ms%1000<100){
		cout<<0<<ms%1000;
	}
	else{
		cout<<ms%1000;;
	}
	return 0;
}
