UVA10222-Decode the Mad man:  
僅一行，包含1或以上的單字，進行轉換(讀取的字要於鍵盤位置左移兩格)  
EX:Ukd,;f --> thanks(轉換的文字都要是小寫)  
```C

```
UVA10409-Die Game:  
給予一組指令(前後左右-->北南西東)，90度轉動骰子  
=>初始: top->1, noreh->2, west->3  
```C
#include <stdio.h>
#include <string.h>
int main(){
	int n;
	while(scanf("%d",&n)){
		if(n==0) return 0;
		int top=1,bottom=6,north=2,south=5,east=4,west=3; 
		for(int i=0;i<n;i++){
			char act[10];
			scanf("%s",act);
			if(act[0]=='n'){ 
				int temp = bottom;
				bottom = north;
				north = top;
				top = south;
				south = temp;
			}
			else if(act[0]=='e'){
				int temp = bottom;
				bottom = east;
				east = top;
				top = west;
				west = temp;
			}
			else if(act[0]=='s'){
				int temp = bottom;
				bottom = south;
				south = top;
				top = north;
				north = temp;
			}
			else if(act[0]=='w'){
				int temp = bottom;
				bottom = west;
				west = top;
				top = east;
				east = temp;
			} 
		}
		printf("%d\n",top);
	}
}
```
UVA10415-Eb Alto Saxophone Player:  
輸入有幾筆，一組最多200個音符,  
輸入要為十隻手指頭各自按了幾次。  
(僅計算0變為1的次數)(ASCII碼: A-G => 65-71 a-g => 97-103)  
```C

```
