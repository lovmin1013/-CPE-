UVA11063-B2-Sequence:  
判斷陣列是否為B2-squence  
條件1--> 1<=b1<b2<b3... 條件2-->b[i]+b[j]如有相同則不是B2-squence  
注意:要多印一個空白行  
```C
#include <stdio.h>
int main()
{
	int n,m=1;
	while(scanf("%d",&n)!=EOF){
		int b[n],yes=0;//yes=1則不是B2
		scanf("%d",&b[0]);
		//檢查b[i]>1 b[i]>b[i-1]
		for(int i=1; i<n; i++){
			scanf("%d",&b[i]);
			if(b[i]<=b[i-1]||b[0]<1){
				yes=1;
			}
		}
		//計算建立陣列儲存 b[i]+b[j],i<=j
		int a[(n+1)*n/2];//底*高/2
		int k=0;
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				a[k]=b[i]+b[j];
				k++;
			}
		}
		//檢查a[]是否有相同的值
		for(int i=0; i<k; i++){
			for(int j=i+1; j<k; j++){
				if(a[i]==a[j]){
					yes=1;
				}
			}
		}

		if(yes==1) printf("Case #%d: It is not a B2-Sequence.\n",m);
		else printf("Case #%d: It is a B2-Sequence.\n",m);
		m++;
		printf("\n");
	}
}
```
![123](https://user-images.githubusercontent.com/79676872/138385760-362ea874-12c3-45d0-a127-34883654709b.png)
![456](https://user-images.githubusercontent.com/79676872/138385765-34613f10-975b-413f-919e-ed33895940a3.png)  
UVA11764-Jumping Mario: 
有多組案例，給予一筆資料表示牆之高度  
計算其向上/下各跳了幾次  
```C
#include <stdio.h>
int main()
{
	int T, n, t=1;
	scanf("%d",&T);//案例有幾筆資料

	while(T--){//讀取案例
		int up=0,down=0;
		scanf("%d",&n);
		int H[n];//圍牆數
		for(int i=0; i<n; i++){
			scanf("%d",&H[i]);
		}//圍牆高度陣列
		for(int i=0; i<n-1; i++){
			if(H[i]>H[i+1]) down++;
			if(H[i]<H[i+1]) up++;
		}//若高度相等則不列入計算
		printf("Case %d: %d %d\n",t,up,down);
		t++;//更新項次
	}
}
```
UVA12019-Doom's Day Algorithm:  
世界末日計算法-->2011年的4/4,6/6,8/8,10/10,12/12都是禮拜一  
給予多組日期，計算在2011年所要求的日期分別是星期幾  
```C
#include <stdio.h>
//每個月各多少天
int monthdays[]={31,28,31,30,31,30,31,31,30,31,30,31};
char name[][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday",};
int dooms[7]={1,94,157,220,283,346,365};// 1/1,4/4,6/6,8/8,10/10,12/12,12/31
int doomweek=1;

int compdays(int m, int d)
{
	int days=0;
	for(int i=0; i<m-1; i++){
		days += monthdays[i];
	}
	days+=d;
	return days;
}
int main()
{
	int n, m, d;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&m,&d);
		int xdays;
		int tdays=compdays(m,d);
		//若日期在4/4前
		if(tdays>dooms[0] && tdays<=dooms[1]){
			xdays= dooms[1]-tdays;
			xdays= 7-xdays%7+doomweek;
			printf("%s\n",name[xdays%7]);
			continue;
		}
		for(int i=1; i<6; i++){//4/4後
			if(tdays>dooms[i] && tdays<=dooms[i+1]){
				int xdays= (tdays-dooms[i]+doomweek)%7;
				printf("%s\n",name[xdays%7]);
				continue;
			}
		}
	}
}
```
