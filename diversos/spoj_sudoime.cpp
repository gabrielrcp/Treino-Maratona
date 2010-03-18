#include <cstdio>
#include <cstring>

int mat[9][9];

bool vai()
{
  char v[9];

  for(int i = 0; i < 9; i++){
    memset(v, 0, sizeof v);
    for(int j = 0; j < 9; j++){
      if(v[mat[i][j]]) return false;
      v[mat[i][j]] = 1;
    }
  }
  for(int j = 0; j < 9; j++){
    memset(v, 0, sizeof v);
    for(int i = 0; i < 9; i++){
      if(v[mat[i][j]]) return false;
      v[mat[i][j]] = 1;
    }
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      memset(v, 0, sizeof v);
      for(int a = 0; a < 3; a++){
	for(int b = 0; b < 3; b++){
	  int x = mat[3*i+a][3*j+b];
	  if(v[x]) return false;
	  v[x] = 1;
	}
      }
    }
  }
  return true;
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    for(int i = 0; i < 9; i++)
      for(int j = 0; j < 9; j++){
	scanf(" %d", &mat[i][j]);
	mat[i][j]--;
      }
    printf("Instancia %d\n%s\n\n", h, (vai() ? "SIM":"NAO"));
  }
  return 0;
}
