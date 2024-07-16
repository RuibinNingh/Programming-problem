#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	double freight,weight;
	cin>>freight;
	if(freight<=10*1.5){
		cout<<fixed<<setprecision(2)<<freight/1.5;
	}
	else if(freight<=20*2){
		cout<<fixed<<setprecision(2)<<freight/2;
	}
	else if(20*2<freight){
		cout<<fixed<<setprecision(2)<<freight/3;
	}
}
