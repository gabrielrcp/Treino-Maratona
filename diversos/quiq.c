#include <stdio.h>
#include <stdlib.h>


double **aloca(int n, int m)
{
  double **mat;
  int i;
  mat = (double **)malloc((n+1)*sizeof(double *));
  if(mat == NULL)
    exit(42);
  for(i=0; i<=n; i++){
    mat[i] = (double *)malloc((m+1)*sizeof(double));
    if(mat[i] == NULL)
      exit(42);
  }
  return mat;
}

void libera(double **mat, int n)
{
  int i;
  for(i=0; i<=n; i++)
    free(mat[i]);
  free(mat);
}


int main()
{
  int n, m;
  double **mat;
  int i, j;
  double soma, e;

  scanf(" %d %d" , &n, &m);

  mat = aloca(n, m);

  for(i=0; i<n; i++)
    for(j=0; j<m; j++)
      scanf(" %lf", &mat[i][j]);

  for(i=0; i<n; i++){
    mat[i][m] = 0;
    for(j=0; j<m; j++)
      mat[i][m] += mat[i][j];
  }

  for(j=0; j<=m; j++){
    mat[n][j] = 0;
    for(i=0; i<n; i++){
      mat[n][j] += mat[i][j];
    }
  }
  /*
  for(i=0; i<=n; i++){
    for(j=0; j<=m; j++)
      printf(" %2.0f", mat[i][j]);
    printf("\n");
  }
  */
/*  
  for(i=0; i<=n; i++){
    for(j=0; j<=m; j++)
      printf("%8.2f", 100.0*mat[i][j]/mat[i][m]);
    printf("\n");
  }
*/
  soma = 0;
  for(i=0; i<n; i++){
    for(j=0; j<m; j++){
      e = mat[i][m]*mat[n][j]/mat[n][m];
      /*printf("%7.2f", e);*/
      soma += (mat[i][j] - e)*(mat[i][j] - e)/e;
    }
    /*printf("\n" );*/
  }
  printf("%f\n", soma);
  libera(mat, n);
  return 0;
}
