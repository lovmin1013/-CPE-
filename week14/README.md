UVA11349-Symmetric Matrix:  
輸入有幾筆資料，再輸入是幾乘幾的方陣，判別此舉鎮是否為對稱矩陣。  
EX: N=3  
5 1 3  
2 0 2  
3 1 5  
```C
#include <stdio.h>
int main()
{
	int t, n;
 
	scanf("%d\n", &t);//有幾筆資料
	for(int i=1; i<=t; i++)//看幾筆資料運行幾次，外加題目要的計算標題
 	{
 		scanf(" N = %d\n", &n);//這裡很重要很重要N前面一定要有空格不然會錯
  		long long a[n*n];
  			for(int j=0; j<n*n; j++){//讀入資料
   				scanf("%lld", &a[j]);
   			}
   		int key=1;
  		int last=n*n-1;
	  	for(int k=0; k<n*n; k++){//判斷
			if(k>=last ||key==0)
	    		break;
	    	if(a[k]<0 || (a[k]!=a[last-k]))
	    		key=0;
		}
		printf("Test #%d: %s.\n", i, key ? "Symmetric" : "Non-symmetric");
 	}
}
```
UVA10193-All You Need Is Love:  
輸入有幾比，每兩行為一組。輸入要為二元數，  
並算出兩數間是否有最大公因數L。  
(L最左邊不能為0，且L不得為1)，輸入的字元要先轉換為數字。  
ASCII碼'0'=48  
```C
#include <stdio.h>
#include <string.h>
#include <math.h>
int getGCD(int a, int b)
{
	int r;
	if(a<b){
		int temp= a;
		a= b;
		b= temp;
	}
	r=a%b;
	while(r!=0){
		a= b;
		b= r;
		r= a%b;
	}
	return b;
}
int main()
{
	int n, t;
	scanf("%d",&n);
	t= n;
	
	while(t--){
		char s1[31];
		char s2[31];
		scanf("%s %s",s1, s2);
		int a=0, b=0;
		for(int i=0; i<strlen(s1); i++){
			a += (s1[i]-48)*(int)pow(2, strlen(s1)-1-i);
		}
		for(int i=0; i<strlen(s2); i++){
			b += (s2[i]-48)*(int)pow(2, strlen(s2)-1-i);
		}
		int gcd= getGCD(a, b);
		if(gcd>1) printf("Pair #%d: All you need is love!\n",n-t);
		else printf("Pair #%d: Love is not all you need!\n",n-t);
	}
	return 1;
}
```
UVA10056-What is the Probability?  
輸入有幾比，再輸入(n, p, k)->(多少人，機率，第k個)  
```C
#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		int N, k;
		double p;
		scanf("%d %lf %d\n",&N, &p, &k);
		double q= 1-p, s1, r, S;
		if(p==0) S=0.0;
		else{
			s1= pow(q,(k-1))*p;
			r= pow(q, N);
			S=s1/(1-r);
		}
		printf("%.4lf\n",S);
	}
}
```
