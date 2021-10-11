UVA10035-Primary Arithmetic:  
計算2個整數間的進位次數  
```C
#include <stdio.h>
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)==2){
		if(a==0 && b==0) break;
		int c=0, ans=0;
		while(a>0 || b>0){
			int a1=a%10;
			int b1=b%10;
			if(c+a1+b1>=10){
				ans++;
				c=1;
			}else c=0;
			a=a/10;
			b=b/10;
		}
		if(ans==0) printf("No carry operation.\n");
		else if(ans==1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n",ans);
	}
}
```
UVA10055-Hashmat the brave warrior:   
給予兩數，計算相差多少(不能大於2的32次方)  
```C
#include <stdio.h>
int main()
{
	long long int a,b;
	while(scanf("%lld %lld",&a,&b)!=EOF){
		if(a>b) printf("%lld\n",a-b);
		else printf("%lld\n",b-a);
		
	}
}
```
UVA10071-Back to High School Physics:  
給予兩數，算出距離(距離=速度∗時間∗倍率 ，這裡的倍率是2)  
```C
#include <stdio.h>
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF){
		printf("%d\n",2*a*b);
	}
}
```
UVA10929-You can say 11:   
給多個整數n，看其是否為11的倍數。  
判斷-->(偶數位和及奇數位和相減除11，若能整除，則為11的倍數)  
但是本題僅能使用字串來解決  
```C
#include <stdio.h>
#include <string.h>

int main()
{
	char n[11000];
	while(gets(n)!=NULL){ 
		int odd=0, even=0;
		if(n[0]=='0'&& strlen(n)==1) break;
		
		for(int i=0; i<strlen(n); i++){
			if((i+1)%2==0){
				even=even+n[i]-'0';
			}else{
				odd=odd+n[i]-'0';
			}
		}
		if((odd-even)%11==0) printf("%s is a multiple of 11.\n",n);
		else printf("%s is not a multiple of 11.\n");
	}
}
```
