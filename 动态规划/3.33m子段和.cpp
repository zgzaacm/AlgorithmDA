#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100],m,M[100],dp[10][100];
int main(){
	cin>>m;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)dp[i][0]=0;
	for(int i=0;i<n;i++)dp[0][i]=0;
	memset(M,M+n,0);
	for(int i=1;i<=m;i++)
		for(int j=i;j<=n-(m-i);j++)
		//j>i一定要加  
		if(j>i){
			dp[i][j]=max(dp[i][j-1]+a[j],M[j]+a[j]);
			M[j]=max(M[j-1],dp[i][j]);
		}
	cout<<dp[m][n];
	return 0;
}
