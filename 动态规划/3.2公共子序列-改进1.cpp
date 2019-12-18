#include<iostream> 
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
string X,Y;
int c[105];
int main(){
	cin>>X>>Y;
	int nx=X.length(),ny=Y.length(),now,result;
	c[0]=0;
	for(int i=1;i<=nx;i++){
		now=0;
		for(int j=1;j<=ny;j++){
			result=X[i]==Y[j]?(now+1):(max(c[j],c[j-1]));
			now=c[j];
			c[j]=result;
		}
	}
	cout<<c[ny];
	return 0;
}
