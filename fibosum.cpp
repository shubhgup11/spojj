#include<bits/stdc++.h>
#include <iostream>
using namespace std;
const int m=1000000000+7;
vector< vector<long long int> > mul(vector< vector<long long int> > arr,vector< vector<long long int> > arr1)
{
	vector< vector<long long int> > arr2{{0,0},{0,0}};
	
	//works without %m in the internal multiplications
// 	arr2[0][0]=((arr[0][0]*arr1[0][0])%m+(arr[0][1]*arr1[1][0])%m)%m;
// 	arr2[0][1]=((arr[0][0]*arr1[0][1])%m+(arr[0][1]*arr1[1][1])%m)%m;
// 	arr2[1][0]=((arr[1][0]*arr1[0][0])%m+(arr[1][1]*arr1[1][0])%m)%m;
// 	arr2[1][1]=((arr[1][0]*arr1[0][1])%m+(arr[1][1]*arr1[1][1])%m)%m;
	
	arr2[0][0]=((arr[0][0]*arr1[0][0])+(arr[0][1]*arr1[1][0]))%m;
	arr2[0][1]=((arr[0][0]*arr1[0][1])+(arr[0][1]*arr1[1][1]))%m;
	arr2[1][0]=((arr[1][0]*arr1[0][0])+(arr[1][1]*arr1[1][0]))%m;
	arr2[1][1]=((arr[1][0]*arr1[0][1])+(arr[1][1]*arr1[1][1]))%m;
	return arr2;
}
vector< vector<long long int> > fib(int n)
{
	if(n==1)
	{
		return {{1,1},{1,0}};	
	}
	if(n%2==1)
		return mul(fib(n-1),{{1,1},{1,0}});
	else
		{
			vector< vector<long long int> > v =fib(n/2);
			return mul(v,v);
		}
}
int fibo(int n)
{
    vector< vector<long long int> > v=fib(n);

    return v[0][1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
// 	cout<<fibo(24)<<endl;
// 	cout<<fibo(48)<<endl;
// 	cout<<fibo(49)<<endl;
    cin>>t;
	while(t--)
	{
	    cin>>i>>j;
	    //cout<<fibo(7)-fibo(5)<<endl;
	    cout<<(fibo(j+2)-fibo(i+1)+m)%m<<endl;
	}
	return 0;
}

