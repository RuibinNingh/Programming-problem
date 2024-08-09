#include<iostream>
using namespace std;
int main(){
    int b=0;
    string a;
    cin>>a;
    for (int i = 0; i < a.size(); i++)
        if (a[i]=='1')b++;
    cout<<b;
}