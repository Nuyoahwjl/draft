#include<bits/stdc++.h>
using namespace std;
set<string> S;
int main()
{
    string a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a;
    	S.insert(a);
	}
	cout<<S.size();
}