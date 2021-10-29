UVA11332-Summing Digits:  
給予一串數字，算出要求之數字(若各數字相加之後仍大於10，就持續累加)  
(字串or每次%10再更新)  
EX:n=1234567892   
-->f(n)= 1+2+3+4+5+6+7+8+9+2=47(>10)  
-->f(f(n))= 4+7=11(>10)  
-->f(f(f(n)))= 1-1=2  
```C
#include <stdio.h>
int main()
{
	int n,s;
	scanf("%d",&n);
	while(n){
		while(n>9){
			s=0;
			while(n){//當n還!=0,繼續進行
				s+=n%10;//取出個位數字進行加總
				n/=10;//並丟棄
			}
			n=s;
		}
		printf("%d\n",n);
		scanf("%d",&n);
	}
}
```
UVA1225-Digit Counting:  
給予數字，計算每個數字出現的次數(有多組資料)  
EX:n=13，12345678910111213  
(從0-9) -->162211111  
```C
#include <stdio.h>
int main()
{
    int tst, i, j, k;
    scanf("%d", &tst);//有幾筆
    while(tst--)
    {
        int n, ara[10];
        for(i=0; i<10; i++) ara[i]=0;//設置一個空陣列
        scanf("%d", &n);讀取數字
        for(i=1; i<=n; i++)
        {
            j = i;
            while(j!=0)
            {
                k=j%10;
                ara[k]++;
                j/=10;
            }
        }
        for(i=0; i<9; i++) printf("%d ", ara[i]);
        printf("%d\n", ara[9]);
    }
}
```
```C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char list[50]="";
	int t,n;
	
	scanf("%d",&t);
	while(t--){
		for(int i=0; i<50; i++){
			list[i]='\0';
		}
		scanf("%d",&n);
		
		for(int i=1; i<=n; i++){
			char ss[3];
			int r= sprintf(ss, "%d", i);
			strcat(list, ss);
			//將A字串加到B字串後面，A字串值保持不變，B字串變長
		}
		
		int count[10]={0};//建立數字次數陣列
		for(int i=0; i<strlen(list); i++){
			int index= list[i]-'0';
			count[index]++;//累加
		}
		
		for(int i=0; i<10; i++){
			printf("%d ",count[i]);
		}
		printf("\n");
	}
}
```
UVA272-TeX Quotes:  
輸入一串文字，將普通的雙引號（"），轉成有方向性的雙引號，而其它文字則不變。  
 每一組雙引號的第一個 " 必須用兩個 ` 字元（就是 `` ）來代替  
 每一組雙引號的第二個 " 必須用兩個 ' 字元（ 就是 ''）來代替  
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char c;//輸入字元
	int flag=1;//設第一個"，flag=1 
	while((c=getchar())!=EOF){
		if(c=='"'){
			if(flag){
				printf("``");
			}
			else{
				printf("''");
			}
			flag= !flag;
		}
		else{
			printf("%c",c);
		}
	}
}
```
UVA10008-What's Cryptanalysis?:(密碼翻譯)  
多筆資料，給多行字串  
統計各個字幕之出現次數(小寫要轉換為大寫)  
並依出現次數進行排序，若遇相同則依字元大小排列(ABC...Z)  
```C
#include <Stdio.h>
#include <stdlib.h>
#include <String.h>

int main()
{
	char line[100];
	int count[26]={0};
	int n;
	
	scanf("%d ", &n);

	for(int i=0; i<n; i++)
 	{
  		fgets(line,100,stdin);
	
    	for(int j=0; j<strlen(line); j++)
    	{
   		if(line[j]>='a' && line[j]<='z')
   			line[j]-=32;   
   		if(line[j]>='A' && line[j]<='Z') 
   			count[line[j]-'A']++;
    	}
    }
   
    for(int i=0; i<26; i++)//找出出現最多次數
    {
    	int max=0;
		for(int j=0; j<26; j++)
		{
			if(count[j]>count[max]) max=j;
		}
		if(count[max]!=0) 
			printf("%c %d\n",max+'A', count[max]);
		count[max]=0;
	}
}
```
UVA10221-Satellites:  
計算出2顆衛星的距離(直線距離、弧長)。  

```C
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	double s,a;
	char c[5];
	//輸入衛星地面高度 運行角度 單位
	while(scanf("%lf %lf %s",&s,&a,c) !=EOF){
		if(strcmp(c,"min")==0) a/=60;
		//60分=1度
		if(a>180) a= 360-a;
		//超過180度，360-度數
		double ang= a*M_PI/180.0;
		//角度換算成徑度量
		double chord= 2.0*(s+6440.0)*sin(ang/2.0);
		//計算弦長
		double arc= ang*(s+6440.0);
		//計算弧長
		printf("%.6lf %.6lf\n",arc, chord);
	}
}
```
UVa10929-You Can Say 11:  
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
