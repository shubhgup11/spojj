#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
    long long int m;
    cin>>n>>m;
    int arr[n];
    long long int sum=0;
    long long int ans=0;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    i=0;
    j=0;
    while(i<=n && j!=n)
    {
        
        if(sum>m)
        {
            sum=sum-arr[j];
            j++;
        }
        else
        {
            if(ans<sum)
                ans=sum;
            if(i==n)
                break;
            sum=sum+arr[i];
            i++;
        }
    }
    cout<<ans<<endl;
	
	return 0;
}

