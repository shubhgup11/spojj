#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n,t;
	int s;
	int a,b;
	cin>>s>>n;
	int arr[n+1][s+1];
	pair<int,int> inp[n+1];
	int i,j,size;
	inp[0]=make_pair(0,0);
	for(i=1;i<=n;i++)
	{
	    cin>>a>>b;
	    inp[i]=make_pair(a,b);
	}
	
	for(i=0;i<=s;i++)
	{
	    arr[0][i]=0;
	}
	for(j=0;j<=n;j++)
	{    arr[j][0]=0;}
	for(i=1;i<=n;i++)
	{
	      size=inp[i].first;
	    for(j=1;j<=s;j++)
	    {
	        if(j<size)
	            arr[i][j]=arr[i-1][j];
	        else
	            arr[i][j]=max((inp[i].second + arr[i-1][j-size]),arr[i-1][j]);
	        
	    }
	}
	/*for(i=0;i<=n;i++)
	{
	    for(j=0;j<=s;j++)
	    {
	        cout<<arr[i][j]<<" ";
	    }
	    cout<<endl;
	}*/
	cout<<arr[n][s];
	return 0;
	
}

