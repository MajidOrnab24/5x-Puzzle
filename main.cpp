#include "declarations.h"

int a[5][5], temp[5][5], tar;
int score, high_score;
char key, opt;
char nameString[80], high_scorer[80];
option mainMenu[] =
	{
		"NEW GAME",
		"LOAD GAME",
		"BEST PLAYER",
		"HELP",
		"EXIT"};

#include "functions.h"

int main() {

	initwindow(1000, 800, "5X PUZZLE");

	FILE *F;
	if ((F = fopen("highscores.txt", "r")) == nullptr) {
		return 1;
	}

	fscanf(F, "%s %d", high_scorer, &high_score);

	fclose(F);

	home();

	setbkcolor(BLUE);

	control_menu();

	closegraph();

	return 0;
}
