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
判別數字是否為9的倍數，及其深度  
(判斷:每個數相加為9的倍數)  
EX: n=99999999999999999999(21個9)  
-> 9*21=189;189/9=21; 深度+1  
-> 1+8+9=18; 18/9=2; 深度+2  
-> 1+8=9; 9/9=1; 深度+3  
```C
#include <stdio.h>
#include <string.h>
int degree(char *str)
{//計算深度
	int i;
	int multiple, D=0;
	
	 if(strlen(str) == 1 && str[0] == '9'){
	 	return 1;
	 }
	 while(strlen(str) >= 2){
	 	multiple =0;
	 	for(i=0; i<strlen(str); i++){
	 		multiple = multiple+ str[i]- '0';
	 	}
	 	if(multiple %9 == 0){
	 		D++;
	 	}
	 	sprintf(str, "%d", multiple);
	 }
	 return D;
}
int main()
{
	char n[1001]= {0};
	
	while(scanf("%s", n)){
		if(n[0]== '0' && strlen(n) == 1){
			break;
		}
		else{
			printf("%s ",n);
			
			int D= degree(n);
			if(D){
				printf("is a multiple of 9 and has 9-degree %d.", D);
			}else{
				printf("is not a multiple of 9.");
			}
			printf("\n");
		}
		memset(n, 0, sizeof(n));
		//memset 是用來對一段記憶體區塊全部設定為某個值的函式
	}
}
```
UVA10931-Parity:  
```C

```
UVA12602-Nice Licence Plates:  
```C

```
