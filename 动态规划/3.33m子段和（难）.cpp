#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000001],m,n,M[1000001],dp[1000001];//默认置零 
int main(){
	while(scanf("%d%d",&m,&n)==2){
	//memset 数组中每一个!字节！都设为一个值
	//如果想设无穷 memset(M,0x3f,sizeof(M)) 这样一定是0x3f3f3f3f 
	memset(M,0,sizeof(M));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		dp[i]=dp[i-1]+a[i];
		int maxx=dp[i];
		for(int j=i+1;j<=n-m+i;j++){
			dp[j]=max(dp[j-1]+a[j],M[j-1]+a[j]);
			M[j-1]=maxx;
			maxx=max(maxx,dp[j]);
		}
		M[i+n-m]=maxx;
	}
	//0x3f3f3f3f很大但又满足*2不会溢出的特点 
	int sum=-0x3f3f3f3f;
	for(int i=m;i<=n;i++)sum=max(sum,dp[i]);
	printf("%d\n",sum);
	}
	return 0;
}
