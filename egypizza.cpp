// if the number of 1/4s is greater than no.of 3/4s and no.of 1/2's is odd
// try combining the 1/4's and 1/2's just once so that 1/2's can be used alone then after this..to an independent pizza..
// then combine 1/4 with 3/4
// then self combinantion of 1/4 an 1/2
// and then the leftovers add to one pizza each

//Test Case 
//4
//1/2
//3/4
//1/4
//1/4


#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
    cin>>t;
    string str;
    int temp,ans;
    int num12,num14,num34;
    num12=num14=num34=ans=0;
	while(t--)
	{
	    cin>>str;
	    if(str=="1/4")
	        num14++;
	    else if(str=="3/4")
    	    num34++;
    	else if(str=="1/2")
    	    num12++;
	}
	if(num14>=2 && num12%2==1 && num14>num34)
	{
	    num14=num14-2;
	    num12--;
	    ans++;
	}
	temp=min(num14,num34);
	//cout<<num14<<" "<<num12<<" "<<num34<<endl;
	num14=num14-temp;
	num34=num34-temp;
	//cout<<num14<<" "<<num12<<" "<<num34<<endl;
	ans+=temp;
	
	ans=ans+num14/4+num12/2+num34;
	if(num14%4>0)
	    ans++;
	if(num12%2>0)
	    ans++;
	ans++;
	cout<<ans<<endl;
	 
	return 0;
}

