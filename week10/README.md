UVA10222-Decode the Mad man:  
僅一行，包含1或以上的單字，進行轉換(讀取的字要於鍵盤位置左移兩格)  
EX:Ukd,;f --> thanks(轉換的文字都要是小寫)  
```C
#include <stdio.h>
#include <string.h>

int main()
{
	char c[100000];
	
	while(gets(c)){
		for(int i=0; i<strlen(c); i++){
			switch(c[i]){
				case '2': printf("`"); break;
				case '3': printf("1"); break;
				case '4': printf("2"); break;
				case '5': printf("3"); break;
				case '6': printf("4"); break;
				case '7': printf("5"); break;
				case '8': printf("6"); break;
				case '9': printf("7"); break;
				case '0': printf("8"); break;
				case '-': printf("9"); break;
				case '=': printf("0"); break;
				
				case 'e': printf("q"); break;
				case 'r': printf("w"); break;
				case 't': printf("e"); break;
				case 'y': printf("r"); break;
				case 'u': printf("t"); break;
				case 'i': printf("y"); break;
				case 'o': printf("u"); break;
				case 'p': printf("i"); break;
				case '[': printf("o"); break;
				case ']': printf("p"); break;
				case '\\': printf("["); break;
				
				case 'd': printf("a"); break;
				case 'f': printf("s"); break;
				case 'g': printf("d"); break;
				case 'h': printf("f"); break;
				case 'j': printf("g"); break;
				case 'k': printf("h"); break;
				case 'l': printf("j"); break;
				case ';': printf("k"); break;
				case 39 : printf("l"); break; //若為 '
				
				case 'c': printf("z"); break;
				case 'v': printf("x"); break;
				case 'b': printf("c"); break;
				case 'n': printf("v"); break;
				case 'm': printf("b"); break;
				case ',': printf("n"); break;
				case '.': printf("m"); break;
				case '/': printf(","); break;

				case 'E': printf("q"); break;
				case 'R': printf("w"); break;
				case 'T': printf("e"); break;
				case 'Y': printf("r"); break;
				case 'U': printf("t"); break;
				case 'I': printf("y"); break;
				case 'O': printf("u"); break;
				case 'P': printf("i"); break;
				
				case 'D': printf("a"); break;
				case 'F': printf("s"); break;
				case 'G': printf("d"); break;
				case 'H': printf("f"); break;
				case 'J': printf("g"); break;
				case 'K': printf("h"); break;
				case 'L': printf("j"); break;
				
				case 'C': printf("z"); break;
				case 'V': printf("x"); break;
				case 'B': printf("c"); break;
				case 'N': printf("v"); break;
				case 'M': printf("b"); break;
				case ' ': printf(" "); break;
			}
		}
		printf("\n");
	}	
}
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
#include<stdio.h>
#include<string.h>

char fingering[14][12] = {  
	"c0111001111", "d0111001110",
    "e0111001100", "f0111001000",
    "g0111000000", "a0110000000",
    "b0100000000", "C0010000000",
    "D1111001110", "E1111001100",
    "F1111001000", "G1111000000",
    "A1110000000", "B1100000000"
    };

int main(){

    int Case;
    int i, j;

    scanf("%d", &Case);
    getchar();

    while(Case--){

        char Note[201] = {0};
        char current[12] = "00000000000";//當前按下的
        int count[10] = {0};

        gets(Note);

        for(i = 0; i < strlen(Note); i++){
            char next[12] = {0};//下一個音要按下的
            for(j = 0; j < 14; j++){//檢查音名
                if(Note[i] == fingering[j][0]){//判斷第一個字元
                    strcpy(next, fingering[j]);//找到就更新即將按下的指法
                    break;
                }
            }

            for(j = 1; j <= 10; j++){//計算新按下的次數
                if(current[j] == '0' && next[j] == '1'){
                    count[j - 1]++;//若有不同則++
                }
            }
            strcpy(current, next);//更新複製當前按下的狀態
        }

        printf("%d", count[0]);
        for(j = 1; j < 10; j++){
            printf(" %d", count[j]);
        }
        printf("\n");
    }
}
```
