//uses n^3 dp solution..
// for each dp cell...it finds the minimum value it can generate... 
// for example in [0,4]...it checks against the combination of [0,0]with [1,4],[0,1]with [2,4],[0,2] with [3,4] 
//                                                                     and [0,3]with [4,4]..and stores the minimum value
// each value is calculated using the sum of the previous values and the multiplication of it prefix sums from initial till end

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void prefixsum(int prefix[],int n,int arr[])
{
    prefix[0]=0;
    for(int i=0;i<n;i++)
    {
        prefix[i+1]=(arr[i]+prefix[i]);
    }
    /*for(int i=0;i<=n;i++)
    {
        cout<<prefix[i]<<" ";
    }
    cout<<endl;*/
    
}
int getsum(int start,int end,int prefix[])
{
    return (prefix[end+1]-prefix[start])%100;
}
void func(int n,int arr[])
{
    int i,j,k;
    int prefix[n+1];
    prefixsum(prefix,n,arr);
    int dp[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            dp[i][j]=INT_MAX;
        }
    }
    dp[n-1][n-1]=0;
    for(i=0;i<n-1;i++)
    {
        dp[i][i]=0;
        dp[i][i+1]=arr[i]*arr[i+1];
    }
    
    for(i=2;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            for(k=j;k<(j+i);k++)
            {
                //cout<<"hello"<<dp[j][i+j]<<" "<<dp[j][k]<<" "<<dp[k+1][i+j]<<" "<<getsum(j,k,prefix)<<" "<<getsum(k+1,i+j,prefix)<<endl;
                dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+(getsum(j,k,prefix)*getsum(k+1,i+j,prefix)));
            }
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" "; 
        }
        cout<<endl;
    }*/
    cout<<dp[0][n-1]<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
	while(cin>>t)
	{
	    //cout<<t<<endl;
	    int arr[t];
	    for(i=0;i<t;i++)
	    {
	        cin>>arr[i];
	    }
	   // for(i=0;i<t;i++)
	   // {
	   //     cout<<arr[i]<<" ";
	   // }
	    //cout<<endl;
	    func(t,arr);
	}
	return 0;
}
