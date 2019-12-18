#include<iostream>
#include<algorithm>
using namespace std;
int s[100][100],m,n;
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++)s[i][0]=0;
	for(int i=1;i<=n;i++)s[0][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
			s[i][j]=s[i][j]+s[i][j-1]+s[i-1][j]-s[i-1][j-1];
		}
	int maxx=s[1][1];
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
	{
		int dp=0;
		for(int k=1;k<=n;k++){
			int num=s[j][k]-s[j][k-1]-s[i][k]+s[i][k-1];
			dp=max(dp+num,num);
		}
		maxx=max(maxx,dp);
	}
	cout<<maxx<<endl;
	return 0; 
}
