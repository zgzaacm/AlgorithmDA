#include<iostream> 
#include<algorithm>
#include<cstdio>
#define maxn 100
//30 35 15 5 10 20 25
using namespace std;
int P[maxn],S[maxn][maxn],m[maxn][maxn],n;
void Print(int i,int j){
	if(i==j){cout<<"A"<<i;return ;
	}
	if(j-i>1)cout<<"(";
	Print(i,S[i][j]);
	if(j-i>1)cout<<")(";
	Print(S[i][j]+1,j);
	if(j-i>1)cout<<")";
}
int main(){
	cout<<"input n:\n";cin>>n;
	cout<<"input p:\n";
	for (int i=0;i<=n;i++)cin>>P[i];
	for(int i=1;i<=n;i++)m[i][i]=0;
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			m[i][j]=m[i][i]+m[i+1][j]+P[i-1]*P[j]*P[i];
			S[i][j]=i;
			for(int k=i+1;k<j;k++)
				if(m[i][j]>m[i][k]+m[k+1][j]+P[i-1]*P[j]*P[k]){
					m[i][j]=m[i][k]+m[k+1][j]+P[i-1]*P[j]*P[k];
					S[i][j]=k;
				}
		}
	}
	cout<<m[1][n]<<endl;
	Print(1,n);
	return 0;
}
