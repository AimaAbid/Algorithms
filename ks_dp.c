#include <stdio.h>
int max(int num1, int num2);

int main()
{
    int p[5] = {0, 1, 2, 5, 6};
    int wt[5] = {0, 2, 3, 4, 5};
    int m = 8, n = 4;
    int k[5][9];

    // int p[5] = {0, 1, 2, 3, 7};
    // int wt[5] = {0, 1, 4, 6, 8};
    // int m = 8, n = 4;
    // int k[5][9];

    int i, w, j;

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;

            else if (wt[i] <= w)
            {
                k[i][w] = max(p[i] + k[i - 1][w - wt[i]], k[i - 1][w]);
            }

            else
                k[i][w] = k[i - 1][w];
        }
    }

    printf("%d\n", k[n][m]);

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            printf("%d\t", k[i][j]);
        }
        printf("\n");
    }

    // To print the items taken and left

    i = n, j = m;

    while (i > 0 || j > 0)
    {
        if (k[i][j] == k[i - 1][j])
        {
            printf("%d = 0\n", i);
            i--;
        }

        else
        {
            printf("%d =1\n", i);

            j = j - wt[i];
            i--;
        }
    }
    return 0;
}

int max(int num1, int num2)
{
    return (num1 >= num2) ? num1 : num2;
}