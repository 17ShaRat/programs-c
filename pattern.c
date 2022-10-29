#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
	int count=-1;
    
    int p;
    for(int i=n; i>=1; i--)
    {
			count++;
        for(int j=n; j>=i; j--)
        {
            printf("%d ", j);
			if(j==i)
			{
				p=2*j-3;
				for(int k=0;k<p;k++)
					printf("%d ",j);
			}
			if(j==i)
			{
				for(int b=n-count;b<=n; b++)
					if(b!=1)	printf("%d ",b);
        	}
		}
        printf("\n");
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=n; j>=i; j--)
        {
            printf("%d ", j);
		if(j==i)
			{
				p=2*j-3;
				for(int k=0;k<p;k++)
					printf("%d ",j);
			}
		if(j==i)
			for(int a=j;a<=n;a++)
				printf("%d ", a);

        }
        printf("\n");
    }
}

