#include<bits/stdc++.h>
#include <iostream>
using namespace std;

/*void init(int n,int m,int vis[n][m])
{
    for(int i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            vis[i][j]=0;
        }
    }
}*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,i,j;
	int t,q,left,right;
    cin>>t;
    string s;
	while(t--)
	{
	    cin>>n>>m;
	    queue <pair <int,int>  > q;
	    int arr[n][m];
	    int vis[n][m];
	    //init(n,m,vis);
	    for(i=0;i<n;i++)
	    {
	        cin>>s;
	        for(j=0;j<m;j++)
	        {
	            arr[i][j]=s[j]-'0';
	            if(arr[i][j]==1)
	            {
	                q.push(make_pair(i,j));
	            }
	        }
	    }
	    pair <int,int> fro;
	   /*while(!q.empty())
	    {
	        fro=q.front();
	        left=fro.first;
	        right=fro.second;
	        cout<<left<<" "<<right<<endl;
	        q.pop();
	    }*/
	    while(!q.empty())
	    {
	        fro=q.front();
	        left=fro.first;
	        right=fro.second;
	        //cout<<left<<" "<<right<<endl;
	        if( (left+1)<n && arr[left+1][right]==0)
	        {
	            arr[left+1][right]=arr[left][right]+1;
	            q.push(make_pair(left+1,right));
	        }
	        if((right+1)<m && arr[left][right+1]==0  )
	        {
	            arr[left][right+1]=arr[left][right]+1;
	            q.push(make_pair(left,right+1));
	        }
	        if((left-1)>=0 && arr[left-1][right]==0  )
	        {
	            arr[left-1][right]=arr[left][right]+1;
	            q.push(make_pair(left-1,right));
	        }
	        if( (right-1)>=0 && arr[left][right-1]==0 )
	        {
	            arr[left][right-1]=arr[left][right]+1;
	            q.push(make_pair(left,right-1));
	        }
	        q.pop();
	    }
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            cout<<--(arr[i][j])<<" ";
	        }
	        cout<<endl;
	    }
	    
	}
	return 0;
}

