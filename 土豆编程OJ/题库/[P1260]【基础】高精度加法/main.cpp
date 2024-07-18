#include <iostream>
#include <vector>
using namespace std;
void read(string*s_a,string*s_b,vector<int>*n_a,vector<int>*n_b){//倒序输入
	for(int i=0;i<(*s_a).size();i++)(*n_a)[(*s_a).size()-i-1]=(*s_a)[i]-'0';
	for(int i=0;i<(*s_b).size();i++)(*n_b)[(*s_b).size()-i-1]=(*s_b)[i]-'0';
}
void add(vector<int>*n_a,vector<int>*n_b,vector<int>*n){
	for(int i=0;i<min((*n_a).size(),(*n_b).size());i++){
		if((*n)[i]==-1)(*n)[i]=0;
		(*n)[i]+=((*n_a)[i]+(*n_b)[i])%10;
		if((*n_a)[i]+(*n_b)[i]>=10){
			if((*n)[i+1]==-1)(*n)[i+1]=0;
			(*n)[i+1]+=((*n_a)[i]+(*n_b)[i])/10;
		}
	}
}
void print(vector<int>*n){
	for(int i=(*n).size()-1;i>=0;i--){
		if((*n)[i]!=-1){
			cout<<(*n)[i];
		}
	}
	cout<<endl;
}
int main(){
	string a,b;
	cin>>a>>b;
	vector<int>num_a(max(a.size(),b.size()),0),num_b(max(a.size(),b.size()),0),num(242,-1);
	
	read(&a,&b,&num_a,&num_b);
	add(&num_a,&num_b,&num);
	print(&num);
}
