#include <stdio.h>
struct p
{
    int at, wt, bt, rt, tat, ct;
};

void main()
{
    int count = 0, n = 5, j = 0, sm;
    struct p p1[5];
    struct p temp;

    p1[0].at = 2;
    p1[0].bt = p1[0].rt = 1;
    p1[1].at = 1;
    p1[1].bt = p1[1].rt = 5;
    p1[2].at = 4;
    p1[2].bt = p1[2].rt = 1;
    p1[3].at = 0;
    p1[3].bt = p1[3].rt = 6;
    p1[4].at = 2;
    p1[4].bt = p1[4].bt = 3;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (p1[j].at > p1[j + 1].at)
            {
                temp = p1[j];
                p1[j] = p1[j + 1];
                p1[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("process no:%d AT: %d BT: %d\n", i, p1[i].at, p1[i].bt);
    }

    for (int i = 0; count != n; i++) // CPU time
    {
        if (p1[j].rt != 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p1[k].at < i && p1[k].bt < p1[j].bt && p1[k].rt != 0)
                    j = k;
            }
            p1[j].rt--;
        }
        else
        {
            count++;
            p1[j].ct = i;
            p1[j].tat = p1[j].ct - p1[j].at;
            p1[j].wt = p1[j].tat - p1[j].bt;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("process no:%d AT: %d BT: %d CT: %d TAT: %d WT: %d\n", i, p1[i].at, p1[i].bt, p1[i].ct, p1[i].tat, p1[i].wt);
    }
}
