#include<iostream>
#include<algorithm>
using namespace std;
int a[100],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int dp=0;
	for(int i=1;i<=n;i++)
		dp=max(dp+a[i],a[i]);
	cout<<dp;
	return 0;
}
