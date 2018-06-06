// SImple segment tree ,store the bhighest and second highest at each node
// in the combination step,the highest of the four will be stored


#include<bits/stdc++.h>
#include <iostream>
using namespace std;
struct maka
{
    int high;
    int high2;
};
void join(maka a,maka b,maka &c)
{
    vector <int> v;
    v.push_back(a.high2);
    v.push_back(a.high);
    v.push_back(b.high);
    v.push_back(b.high2);
    sort(v.begin(),v.end());
    c.high=v[3];
    c.high2=v[2];
}
void build(int node,int start,int end,maka arr[],int input[])
{
    // for(int i=1;i<=5;i++)
    //     cout<<input[i]<<" ";
    //cout<<endl;
    if(start==end)
    {
        //cout<<start<<" "<<input[start]<<endl;
        arr[node].high=input[start];
        arr[node].high2=0;
    }
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid,arr,input);
        build(2*node+1,mid+1,end,arr,input);
        join(arr[2*node],arr[2*node+1],arr[node]);
    }
}
void update(int node,int start,int end,maka arr[],int ind,int val)
{
    if(start==end)
    {
        
        arr[node].high=val;
        arr[node].high2=0;
        return;
    }
    else
    {
        int mid=(start+end)/2;
        if(ind<=mid)
            update(2*node,start,mid,arr,ind,val);
        else
            update(2*node+1,mid+1,end,arr,ind,val);
        join(arr[2*node],arr[2*node+1],arr[node]);
    }
}
maka query(int node,int start,int end,int l,int r,maka arr[])
{
    maka a,b,c,d;
    if(end<l || start>r)
    {
        a.high2=0;
        a.high=0;
        return a;
    }
    else if(start>=l && end<=r)
    {
        return arr[node];
    }
    int mid=(start+end)/2;
    b=query(2*node,start,mid,l,r,arr);
    c=query(2*node+1,mid+1,end,l,r,arr);
    join(b,c,d);
    return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
    cin>>n;
    int input[n+1];
    maka arr[4*(n+1)];
    for(i=1;i<=n;i++)
        cin>>input[i];
    
    build(1,1,n,arr,input);
    cin>>q;
    // for(i=1;i<4*(n+1);i++)
    //     {
    //         cout<<i<<" "<<arr[i].high<<" "<<arr[i].high2<<endl;
    //     }
    char ch;
    maka ans;
    //cout<<q;
    while(q--)
    {
        cin>>ch>>i>>j;
        //cout<<ch<<i<<j;
        if(ch=='U')
            update(1,1,n,arr,i,j);
        else
        {
          ans= query(1,1,n,i,j,arr);
            cout<<ans.high+ans.high2<<endl;
        }
        // for(i=1;i<4*(t+1);i++)
        // {
        //     cout<<i<<" "<<arr[i].high<<" "<<arr[i].high2<<endl;
        // }
    }
	return 0;
}

