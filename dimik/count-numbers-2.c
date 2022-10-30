#include <stdio.h>

int main(void)
{
	int T;
	char c;
	int word = 1;
	scanf("%d\n", &T);
	for(int i=0; i<T; i++)
	{
		word = 1;
		while((c=getchar())!='\n')
		{
			if(c==32)
				word++;
		}				
		printf("%d\n", word);
		
	}		
	return 0;
}


