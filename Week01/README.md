UVA100-The 3n + 1 problem:  
在a b數字之間找出算得之最大長度  
EX:=22 若為偶數 則n=n/2; 若n為奇數 則n=3n+1;  
```C
#include <stdio.h>
int cyclelength(int n){
	int length=1;
	while(n!=1){
		if(n%2==0){
			n=n/2;
			length++;
		}
		else{
			n=n*3+1;
			length++;
		}
	}
	return length;
}
int main()
{
	int i,j,max;
	while(scanf("%d %d",&i,&j)!=EOF){
		max=1;
		if(i<j){
			for(int n=i; n<=j; n++){
				int len= cyclelength(n);
				if(max< len) max=len;
			}
		}
		else{
			for(int n=j; n<=i; n++){
				int len= cyclelength(n);
				if(max< len) max=len;
			}
		}
		printf("%d %d %d\n",i,j,max);
	}
}
```
UVA10783-Odd Sum:  
在[a.b]區間 算出奇數總和  
-->不只一件案例，0<=a<=b<=100  
```C
#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int a,b,sum=0;
		scanf("%d %d",&a,&b);
		for(int k=a; k<=b; k++){
			if(k%2!=0) sum+=k;
		}
		printf("Case %d: %d\n",i+1,sum);
	}
}
```
UVA11417-GCD:
算最大公因數。
EX:n=4 算GCD(1,2)+GCD(1,3)+GCD(1,4)+GCD(2,3)+GCD(2,4)+GCD(3,4)    
```C
#include <stdio.h>
int gcd(int a,int b)
{      //遞迴程式計算GCD
	if(a==0) return b;
	else return gcd(b%a, a);
}
int main()
{ 
	int i,j,n,G;
	scanf("%d",&n);
	while(n){//計算所有GCD(i,j)的總和
		G=0;
		for(i=1; i<n; i++){
			for(j=i+1; j<=n; j++){
				G = G+gcd(i, j);
			}
		}
		printf("%d\n",G);
		scanf("%d",&n);
	}
}
```
