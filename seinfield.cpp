#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
    //cin>>t;
    t=0;
    string str;
    int ans,count,ln;
	while(++t)
	{
	   cin>>str; 
	   ln=str.length();
	   if(str[0]=='-')
	    break;
	   ans=0;
	   count=0;
	   for(i=0;i<ln;i++)
	   {
	       if(str[i]=='{')
	       {
	           if((ln-i-1)>count)
	            count++;
	           else
	           {
	               ans++;
	               count--;
	           }
	            
	       }
	       else if(str[i]=='}')
	       {
	           if(count>0)
	           {
	               count--;
	           }
	           else
	           {
	               count++;
	               ans++;
	           }
	       }
	   }
	   cout<<t<<". "<<ans<<endl;
	}
	return 0;
}

