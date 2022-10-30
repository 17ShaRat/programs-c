#include <stdio.h>

int main(void)
{
	int T;
    int n;
    int i=0;
		scanf("%d", &T);
    while(i++<T)
    {
        int word = 1;
        char c;
        do
        {
            scanf("%d", &n);
            scanf("%c", &c);
            if(c!='\n')
                word++;
                
        }
        while(c!='\n');
				printf("%d\n", word);
    }
	return 0;
}

