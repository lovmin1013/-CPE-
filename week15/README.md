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
UVA10235-Simply Emirp:(判斷質數)  
先判斷n是否為質數，若是的話再看n的倒數是否也為質數  
(但若倒數與原本數字一樣則僅為質數)  
有三種結果:  
-> 2者都是 為emirp  
-> 僅n是 為prime  
-> 皆不是 為not prime  
```C
#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	while(scanf("%d",&n) !=EOF){
		int c=0, a=n, d=0, m=0;
		while(a>0){
			m= m*10+a%10;
			a/=10;
		}
		for(int i=1; i<n; i++){
			if(n%i==0) c++;
		}
		for(int i=1; i<m; i++){
			if(m%i==0) d++;
		}
		if(c==1 && d==1 && n!=m) printf("%d is emirp.\n", n);
		else if(c!=1) printf("%d is not prime.\n", n);
		else printf("%d is prime.\n", n);
	}
}
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
		//memset(字串, 預設值, 長度) <- 在<string.h>裡
	}
}
```
UVA10931-Parity:  
將n轉為二進制，將各"數字"相加  
EX: 21
-> 21/2=10...1;   
-> 10/2= 5...0;  
-> 5/2 = 2...1;  
-> 2/2 = 1...0;  
-> 1/2 = 0...1;  
->->->-> 21 = 10101  
```C
#include <stdio.h>
int main()
{
    long long int n;
    int i,c,b[1000];
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
        break;
        i=0;
        while(n!=0)
        {
            b[i]=n%2;
            n/=2;
            i++;
        }
        c=0;
        printf("The parity of ");
        for(i=i-1;i>=0;i--)
        {
            printf("%d",b[i]);
            if(b[i]==1)
            c++;
        }
        printf(" is %d (mod 2).\n",c);

    }
}
```
UVA12602-Nice Licence Plates:  
輸入有幾比，車牌前三字母換算為數字，  
減掉後面四位數字取絕對值  
若<100 輸出nice 反之則 not nice  
```C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int n;
	char str[10];
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		int pa=0;
		for(int i=0; i<3; i++){
			pa += (str[i]-65)*(int)pow(26, 2-i);
		}
		int pn=0;
		for(int i=4; i<=7; i++){
			pn += (str[i]-48)*(int)pow(10, 7-i);
		}
		int diff;
		diff= abs(pn-pa);
		
		if(diff<=100) printf("nice\n");
		else printf("not nice\n");
	}
}
```
