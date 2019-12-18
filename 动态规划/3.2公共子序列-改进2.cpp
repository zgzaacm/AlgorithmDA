#include<iostream> 
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
string X,Y;
int c[105][105];
void Print(int x,int y){
	if(x==-1||y==-1)return ;
	if(X[x]==Y[y]){ 
		Print(x-1,y-1);
		cout<<X[x];
	}
	else if(c[x][y]==c[x][y-1])
		Print(x,y-1);
	else
		Print(x-1,y);
}
int main(){
	cin>>X>>Y;
	int nx=X.length(),ny=Y.length();
	for(int i=0;i<=nx;i++)c[i][0]=0;
	for(int i=0;i<=ny;i++)c[0][i]=0;
	for(int i=1;i<=nx;i++){
		for(int j=1;j<=ny;j++)
			c[i][j]=X[i]==Y[j]?(c[i-1][j-1]+1):max(c[i-1][j],c[i][j-1]);
	}
	cout<<c[nx][ny]<<endl;
	Print(nx-1,ny-1);
	return 0;
}
