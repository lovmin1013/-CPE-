UVA10041-Vito's Family:  
先輸入有幾筆資料，接著輸入有幾個親戚，分別住在哪裡。  
先將位置由小排到大，再找出中位數，算出其與個數差(絕對值)的和。    
```C
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, r, mid;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&r);
		int a[r];
		for(int i=0; i<r; i++){
			scanf("%d",&a[i]);
		}
		for(int i=0; i<r; i++){//泡泡排序(由小到大)
			for(int j=0; j<r-i-1; j++){
				if(a[j]>a[j+1]){
					int temp= a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		mid=a[r/2];//算出中位數
		int ans=0;
		for(int i=0; i<r; i++){
			ans= ans+abs(mid-a[i]);//取絕對值
		}
		printf("%d\n",ans);
	}
}
```
