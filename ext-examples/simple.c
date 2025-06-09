void single_test(double *x, int n);
void array_math_test(double *x, int n, int m);
void multi_test(double **x, int n, int m);

void single_test(double *x, int n)
{
    int i;
    for (i = 0; i < n; i++)
        x[i] += i;
}

void array_math_test(double *x, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            x[i*m + j] += 10*i + j;
}

void multi_test(double **x, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            x[i][j] += 10*i + j;
}