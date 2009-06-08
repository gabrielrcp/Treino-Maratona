#include <cstdio>
#include <map>
#include <string>

using namespace std;

map < string , map<string,int> > code;


string p1, p2, c1, c2;
char buffer[200];
int score1, score2;
int cd1, cd2;
int game;

void comecaJogo()
{
	scanf(" %s",buffer);
	c1 = buffer;
	scanf(" %s",buffer);
	p1 = buffer;
	scanf(" %s",buffer);
	c2 = buffer;
	scanf(" %s",buffer);
	p2 = buffer;
	score1 = 0;
	score2 = 0;
	game++;
}

void imprime()
{
	printf("Game #%d:\n",game);
	if(score1 == 1)
		printf("%s: %d point\n",p1.c_str(),score1);
	else
		printf("%s: %d points\n",p1.c_str(),score1);
	if(score2 == 1)
		printf("%s: %d point\n",p2.c_str(),score2);
	else
		printf("%s: %d points\n",p2.c_str(),score2);
	if(score1 > score2)
		printf("WINNER: %s\n\n",p1.c_str());
	else if(score1 < score2)
		printf("WINNER: %s\n\n",p2.c_str());
	else
		printf("TIED GAME\n\n");
}

int main(){

	game = 0;

	code["cs"]["Kamen"] = 0;
	code["cs"]["Nuzky"] = 1;
	code["cs"]["Papir"] = 2;

	code["en"]["Rock"] = 0;
	code["en"]["Scissors"] = 1;
	code["en"]["Paper"] = 2;

	code["fr"]["Pierre"] = 0;
	code["fr"]["Ciseaux"] = 1;
	code["fr"]["Feuille"] = 2;

	code["de"]["Stein"] = 0;
	code["de"]["Schere"] = 1;
	code["de"]["Papier"] = 2;

	code["hu"]["Ko"] = 0;
	code["hu"]["Koe"] = 0;
	code["hu"]["Ollo"] = 1;
	code["hu"]["Olloo"] = 1;
	code["hu"]["Papir"] = 2;

	code["it"]["Sasso"] = 0;
	code["it"]["Roccia"] = 0;
	code["it"]["Forbice"] = 1;
	code["it"]["Carta"] = 2;
	code["it"]["Rete"] = 2;

	code["jp"]["Guu"] = 0;
	code["jp"]["Choki"] = 1;
	code["jp"]["Paa"] = 2;
	
	code["pl"]["Kamien"] = 0;
	code["pl"]["Nozyce"] = 1;
	code["pl"]["Papier"] = 2;
	
	code["es"]["Piedra"] = 0;
	code["es"]["Tijera"] = 1;
	code["es"]["Papel"] = 2;
	

	comecaJogo();
	while(1)
	{
	    scanf(" %s", buffer);
	    if(buffer[0] == '.'){
		    imprime();
		    break;
	    }
	    else if(buffer[0] == '-')
	    {
		    imprime();
		    comecaJogo();
	    }
	    else
	    {
		    cd1 = code[c1][buffer];
		    scanf(" %s", buffer);
		    cd2 = code[c2][buffer];
		    if(cd1 != cd2)
		    {
			    if(cd1+1==cd2 || cd1-2 == cd2)
				    score1++;
			    else
				    score2++;
		    }
	    }
	}

	return 0;
}
