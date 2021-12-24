UVA10190-Divide, But Not Quite Conquer!  
每行2個數(n,m)讀至EOF;若n可被m一直整除，  
且每次的商都要輸出，但若無法除盡(任意階段有餘數)  
則輸出Boring!  
```C
#include <stdio.h>
#include <math.h>

int main()
{
	int n, m;
	while(scanf("%d %d",&n, &m)== 2){
		if(n==0 || m==0 || m==1 || n<m) printf("Boring!\n");
		else{
			int i=0;
			while((int)pow(m,i) <= n) i++; //m的i次方
			
			//定義陣列並初始化
			int a[i];
			for(int k=0; k<i; k++) a[k]=0;
			
			int j=0;
			a[j]=n;
			while(n%m == 0){
				n= n/m;
				j++;
				a[j]= n;
			}
			if(a[i-1]== 1){
				for(int k=0; k<i-1; k++) printf("%d ",a[k]);
				printf("%d\n",a[j]);
			}
			else{
				printf("Boring!\n");
			}
		}
	}
}
```
UVA10235-Simply Emirp:  
```C

```
UVA10922-2 the 9s:  
```C

```
UVA10931-Parity:  
```C

```
UVA12602-Nice Licence Plates:  
```C

```
