#include<cstdio>

char permut[5][30];
char posi[10];
char texto[2][100];

int p[10];

char inverso[5][30];


char transforma(char c, int i)
{

  int j = (c - 'a' + p[i]) % 26;

  c = permut[i][j];

  j = c - 'a' - p[i];
  while(j < 0) j += 26;

  c = j + 'a';
  return c;

}

char inversa(char c, int i)
{

  int j = (c - 'a' + p[i]) % 26;

  c = inverso[i][j];

  j = c - 'a' - p[i];
  while(j < 0) j += 26;

  c = j + 'a';
  return c;

}


char vai(char c)
{
  for(int i = 0; i < 5; i++)
    c = transforma(c, i);
  
  for(int i = 3; i >= 0; i--)
    c = inversa(c, i);

  return c;
  
}

bool confere()
{
  int rodar[5];
  p[0] = 0;
  for(int i = 0; i < 4; i++){
    p[i+1] = posi[i] - 'a';
    rodar[i+1] = 0;
  }

  
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 26; j++)
      inverso[i][j] = '?';

    for(int j = 0; j < 26; j++)
      inverso[i][permut[i][j]-'a'] = j + 'a';

    for(int j = 0; j < 26; j++)
      if(inverso[i][j] == '?')
	return false;
  }
 

  for(int i = 0; texto[0][i] != '\0'; i++){
    if(texto[1][i] != vai(texto[0][i]))
      return false;

    int j = 1;
    while(j < 5){
      p[j] = (p[j] + 1) % 26;
      rodar[j]++;
      if(rodar[j] == 26){
	rodar[j] = 0;
	j++;
      }
      else
	break;
    }
       
  }
  return true;   
}


bool bt()
{
  
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 26; j++)
      if(permut[i][j] == '?'){
	for(char c = 'a'; c <= 'z'; c++){
	  permut[i][j] = c;
	  if(bt())
	    return true;
	}
	permut[i][j] = '?';
	return false;
      }
  
  for(int j = 0; j < 4; j++)
    if(posi[j] == '?'){
      for(char c = 'a'; c <= 'z'; c++){
	posi[j] = c;
	if(bt())
	  return true;
      }
      posi[j] = '?';
      return false;
    }

  for(int i = 0; i < 2; i++)
    for(int j = 0; texto[i][j] != '\0'; j++)
      if(texto[i][j] == '?'){
	for(char c = 'a'; c <= 'z'; c++){
	  texto[i][j] = c;
	  if(bt())
	    return true;
	}
	texto[i][j] = '?';
	return false;  
      }
  

  return confere();
}

int main()
{
  int casos;
  scanf(" %d", &casos);
  for(int h = 1; h <= casos; h++){
    printf("Scenario #%d:\n", h);
    
    for(int i = 1; i < 5; i++)
      scanf(" %s", &permut[i][0]);
    scanf(" %s %s", &permut[0][0], posi);
    scanf(" %s %s", &texto[0][0], &texto[1][0]);


    bt();
    printf("%s\n\n", texto[0]);

  }
  return 0;
}
