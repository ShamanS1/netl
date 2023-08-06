#include <stdio.h>
struct node
{
    unsigned dist[20];
    unsigned from[20];
} rt[20];
int main()
{
    int costmat[20][20];
    int node, n, i, j, k, count = 0;
    printf("Enter no: of nodes:");
    scanf("%d", &node);
    printf("Enter cost matrix:");
    for (i = 0; i < node; i++)
        for (j = 0; j < node; j++)
        {
            scanf("%d", &costmat[i][j]);
            costmat[i][i] =0;
            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j;
        }
    do
    {
        count = 0;
        for (i = 0; i < node; i++)
            for (j = 0; j < node; j++)
                for (k = 0; k < node; k++)
                    if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
    } while (count != 0);
    for (i = 0; i < node; i++)
    {
        printf("\n\n For router %d\n", i + 1);
        for (j = 0; j < node; j++)
        {
            printf("\t\n node %d via %d Distance %d", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
    printf("\n\n");
}
