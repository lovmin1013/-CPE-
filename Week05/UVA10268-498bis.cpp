#include <stdio.h>
int main()
{
	int n, x, i, a[50000];
	while(scanf("%d",&x) !=EOF){
		//�p�G��Ū����Ĥ@��x �N�~��p��
		for(n=0;;n++){
			scanf("%d",&a[n]);
			if(getchar()=='\n') break;
			//�p�G�Y�ƫ�O����Ÿ��A�N�����Ӳժ���J�A�íp�⦹�ո��
		}
		int sum=a[0]*n;
		for(i=1; i<n; i++){
			sum= sum*x+a[i]*(n-i);
		}//�C����x �A�[�U�@��
		printf("%d\n",sum);
	}
}
