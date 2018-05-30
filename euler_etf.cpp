#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int sieve[1000000+1]={0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
	float ans=1.0;
	vector <int> v;
	for(i=2;i<=1000;i++)
	{
	    if(!sieve[i])
	    {   
	        v.push_back(i);
	        for(j=i*i;j<=1000000;j=j+i)
	        {
	            sieve[j]=1;
	        }
	    }
	}
	for(i=1001;i<=1000000;i++)
	{
	    if(!sieve[i])
	        v.push_back(i);
	}
	/*for(i=0;i<=v.size();i++)
	    cout<<v[i]<<" ";
	   cout<<endl;*/
    cin>>t;
	while(t--)
	{
	   cin>>n;
	   if(n==1)
	    {
	        cout<<n<<endl;
	        continue;
	    }
	   if(!sieve[n])
	   {
	       cout<<n-1<<endl;
	       continue;
	   }
	   ans=n;
	   for(i=0;i<v.size();i++)
	   {
	       if(v[i]*v[i]>n)
	          break;
	       if(n%v[i]==0)
	       {
	            ans=ans*(1-1/float(v[i]));
	            while(n%v[i]==0)
	            {
	                n=n/v[i];
	            }
	       }
	   }
	   if(n>1)
	   {
	       ans=ans*(1-1/(float)n);
	   }
	   cout<<ans<<endl;
	   ans=1;
	}
	return 0;
}

