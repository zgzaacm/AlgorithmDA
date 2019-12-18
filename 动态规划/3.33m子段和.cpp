#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100],m,n,M[100],dp[100];//默认置零 
int main(){
	cin>>m;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		dp[i]=dp[i-1]+a[i];
		//M[i-1]=dp[i] 咱也不知道这句代码是干啥的 
		int maxx=dp[i];
		for(int j=i+1;j<=n-m+i;j++){
			dp[j]=max(dp[j-1]+a[j],M[j-1]+a[j]);
			M[j-1]=maxx;
			maxx=max(maxx,dp[j]);
		}
		M[i+n-m]=maxx;
	}
	int sum=0;
	for(int i=m;i<=n;i++)sum=max(sum,dp[i]);
	cout<<sum;
	return 0;
}
