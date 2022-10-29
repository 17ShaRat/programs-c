#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    
    int p;
    for(int i=n; i>=1; i--)
    {
        for(int j=n,p=0; j>=i; j--,p++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=n; j>=i; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
}
