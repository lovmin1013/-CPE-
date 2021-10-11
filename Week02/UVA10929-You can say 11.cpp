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
