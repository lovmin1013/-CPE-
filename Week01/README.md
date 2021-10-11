The 3n + 1 problem:  
在a b數字之間找出算得之最大長度  
EX:=22 若為偶數 則n=n/2; 若n為奇數 則n=3n+1  
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
