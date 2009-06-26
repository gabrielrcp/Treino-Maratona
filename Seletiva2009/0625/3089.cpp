#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#define MAX 100010

int r, c;
char final[30][100];
char msg[MAX];
char temp[MAX];

//2 = left, 3 = center, 4 = right, 5 = fulljust
char alinha;
int spc;
bool nova;
int lat;
bool imprimi;

bool vai()
{
  alinha = 2;
  spc = 0;
  nova = true;
  lat = -1;
  int j = 0;


  for(int i = 0; msg[i] != '\0'; i++){
    if(msg[i] == '[')
      switch(msg[i+1]){
      case '[':
	temp[j++] = '[';
	i++;
	break;
      case 'j':
      case 'J':
	if((msg[i+2] != 'l' && msg[i+2] == 'L') ||
	   (msg[i+3] < '2' || msg[i+3] > '5') ||
	   (msg[i+4] != ']') ){
	  printf("BAD TAG\n");
	  return false;
	}
	imprime();
	//confere tag conflict
	alinha = msg[i+3] - '0';
	break;
      case '/':
	break;
      case 's':
      case 'S':
	break;
      case 'n':
	break;
      default:
      }
    if(msg[i] == '['){
      if(msg[i+1] == '[')
	temp[j++] = '[';
      else{
	printf("BAD TAG\n");
	return false;
      }
    }
  }
}


int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    printf("%d\n", h);
    scanf(" %d %d", &r, &c);
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
	final[i][j] = ' ';

    gets(msg);

    if(vai())
      for(int i = 0; i < r; i++){
	for(int j = 0; j < c; j++)
	  putchar(final[i][j]);
	putchar('\n');
      }
  }
  return 0;
}

