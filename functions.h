void help(){
    cleardevice();
    setbkcolor(LIGHTGRAY);
    setcolor(BLUE);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, 0, 1000, 800);
	settextstyle(3,0,3);
	outtextxy(30, 50, (char*)"# Use your arrow keys to move the tiles.");
	outtextxy(30, 80, (char*)"# Tiles with the same value will merge into their sum.");
    outtextxy(30, 110, (char*)"# All the tiles will move in given direction.");
    outtextxy(30, 140, (char*)"# The game will continue until the target is reached.");
    outtextxy(30, 170, (char*)"# If the board is filled then the game will end.");
    outtextxy(30, 200, (char*)"  For example:(An up arrow is pressed )");
     readimagefile("image.jpg",5,250,475,600);
     readimagefile("image2.jpg",525,250,995,600);
     line(500,350,510,390);
     line(500,350,500,500);
     line(500,350,490,390);
	outtextxy(270, 650, (char*)"Press any key to return to main menu");
	getch();
	cleardevice();
	setbkcolor(BLUE);

}

void high_scores() {
	cleardevice();
	setcolor(BLUE);
	setbkcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, 0, 1000, 800);
	settextstyle(BOLD_FONT, 0, 6);
	outtextxy(200, 150, (char*)"Name of the Player:");
	settextstyle(3, 0, 4);
	outtextxy(200, 210, high_scorer);
	char out[100];
	settextstyle(BOLD_FONT, 0, 6);
	itoa(high_score, out, 10);
	outtextxy(200, 250, (char*)"Score:");
	settextstyle(3, 0, 4);
	outtextxy(200, 300, out);
	outtextxy(180, 550, (char*)"Press any key to return to main menu");
	setbkcolor(BLUE);

	getch();
}

void resume() {
	FILE *F=fopen("savestate.txt","r");
	if(ferror(F)){
        return;
	}
	fscanf(F,"%s %d %d", nameString, &score, &tar);
	for(auto &i:a){
        for(auto &j:i){
            fscanf(F,"%d",&j);
        }
	}
	fclose(F);

	F=fopen("highscores.txt","r");
	if(ferror(F)){
        return;
	}
	fscanf(F,"%s %d",high_scorer,&high_score);
	fclose(F);
}

void victory() {
	readimagefile("victory.jpg", 605, 450, 1000, 800);
	getch();
}

bool if_win() {
	for (auto & i : a)
		for (int j : i)
			if (j >= tar) {
				return true;
			}
	return false;
}

void over() {
	for (auto & i : a)
		for (int & j : i)
			j = 0;
	score = 0;
	setcolor(YELLOW);
	settextstyle(BOLD_FONT, 0, 6);
	outtextxy(250, 350, (char*)"GAME OVER!!!");
	getch();
	cleardevice();
}

bool game_over() {

	for (auto &i : a)
		for (auto &j : i)
			if (!j) {
				return false;
			}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (a[i + 1][j] == a[i][j] || a[i][j + 1] == a[i][j])
				return false;

	for (int i = 4; i < 5; i++)
		for (int j = 0, k = 1; j < 4; j++, k++)
			if (a[i][j] == a[i][k] || a[j][i] == a[k][i])
				return false;

	return true;
}

void add_tile() {
	int r, c;
	srand(time(nullptr));
	while (1) {
		r = rand() % 5;
		c = rand() % 5;
		if (a[r][c] == 0) {
			a[r][c] = 5 * pow(2, rand() % 2);
			break;
		}
	}
}

bool possible() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (temp[i][j] != a[i][j]) {
				return true;
			}
	return false;
}

void right() {
	int i, j, li, ri;
	for (j = 0; j < 5; j++) {
		li = 4, ri = j;
		for (i = 3; i >= 0; i--) {
			if (a[i][j] != 0) {
				if (a[i + 1][j] == 0 || a[i + 1][j] == a[i][j]) {
					if (a[li][ri] == a[i][j]) {
						a[li][ri] *= 2;
						score += a[li][ri] / 5;
						a[i][j] = 0;
					} else {
						if (a[li][ri] == 0) {
							a[li][ri] = a[i][j];
							a[i][j] = 0;

						} else {
							a[--li][ri] = a[i][j];
							a[i][j] = 0;
						}
					}
				} else
					li--;
			}
		}
	}
}

void down() {
	int i, j, li, ri;

	for (i = 0; i < 5; i++) {
		li = i, ri = 4;
		for (j = 3; j >= 0; j--) {
			if (a[i][j] != 0) {
				if (a[i][j + 1] == 0 || a[i][j + 1] == a[i][j]) {
					if (a[li][ri] == a[i][j]) {
						a[li][ri] *= 2;
						score += a[li][ri] / 5;
						a[i][j] = 0;

					} else {
						if (a[li][ri] == 0) {
							a[li][ri] = a[i][j];
							a[i][j] = 0;

						} else {
							a[li][--ri] = a[i][j];
							a[i][j] = 0;
						}
					}
				} else
					ri--;
			}
		}
	}
}

void up() {
	int i, j, li, ri;

	for (i = 0; i < 5; i++) {
		li = i, ri = 0;
		for (j = 1; j < 5; j++) {
			if (a[i][j] != 0) {
				if (a[i][j - 1] == 0 || a[i][j - 1] == a[i][j]) {
					if (a[li][ri] == a[i][j]) {
						a[li][ri] *= 2;
						score += a[li][ri] / 5;
						a[i][j] = 0;
					} else {
						if (a[li][ri] == 0) {
							a[li][ri] = a[i][j];
							a[i][j] = 0;

						} else {
							a[li][++ri] = a[i][j];
							a[i][j] = 0;
						}
					}
				} else
					ri++;
			}
		}
	}
}

void left() {
	int i, j, li, ri;

	for (j = 0; j < 5; j++) {
		li = 0, ri = j;
		for (i = 1; i < 5; i++) {
			if (a[i][j] != 0) {
				if (a[i - 1][j] == 0 || a[i - 1][j] == a[i][j]) {
					if (a[li][ri] == a[i][j]) {
						a[li][ri] *= 2;
						score += a[li][ri] / 5;
						a[i][j] = 0;
					} else {
						if (a[li][ri] == 0) {
							a[li][ri] = a[i][j];
							a[i][j] = 0;

						} else {
							a[++li][ri] = a[i][j];
							a[i][j] = 0;
						}
					}
				} else
					li++;
			}
		}
	}
}

void save(){
    FILE *F=fopen("savestate.txt","w");
	if(ferror(F)){
        return;
	}
	fprintf(F,"%s %d %d\n", nameString, score, tar);
	for(auto &i:a){
        for(auto &j:i){
            fprintf(F,"%d ",j);
        }
        fprintf(F,"\n");
	}
	fclose(F);
}

void play() {
    bool f=true;
	while (true) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				temp[i][j] = a[i][j];

        if (game_over()) {
			over();
			return;
		}

		if (if_win() && f) {
            victory();
			f=false;
		}

		key = getch();

		switch (key){
		case LEFT:
			left();
			break;
		case UP:
			up();
			break;
		case DOWN:
			down();
			break;
		case RIGHT:
			right();
			break;
        case 's':
            save();
		case 'e':
			cleardevice();
			for (auto & i : a)
				for (int & j : i)
					j = 0;
            score=0;
			return;
		default:
			break;
		}

		if (possible())
			add_tile();
		update();
	}
}

void high_count() {
	std::ofstream fout("High.gm");
	fout << score;
	fout.close();
	high_score = score;

	char out[100];
	settextstyle(3, 0, 4);
	itoa(high_score, out, 10);
	outtextxy(650, 150, out);
	setcolor(YELLOW);
	strcpy(high_scorer, nameString);

	FILE *F=fopen("highscores.txt","w");
	if(ferror(F)){
        return;
	}
	fprintf(F,"%s %d",high_scorer,high_score);
	fclose(F);
}

void update() {
	setbkcolor(CYAN);
	int i, j, p, q;
	char out[100];
	settextstyle(3, 0, 4);
	itoa(score, out, 10);
	setcolor(YELLOW);
	outtextxy(650, 240, out);

	if (high_score < score) {
		high_count();
	}

	int colors[] = {LIGHTRED, LIGHTGRAY, MAGENTA, LIGHTMAGENTA, YELLOW, LIGHTGREEN, GREEN, LIGHTCYAN, CYAN, LIGHTBLUE, BLUE};
	int x, y;
	for (i = 0, x = 100; i < 5; i++, x += 100) {
		for (j = 0, y = 100; j < 5; j++, y += 100) {
			if (a[i][j]) {
				setfillstyle(SOLID_FILL, colors[(int)log2(a[i][j] / 5.0)]);
				bar(x + 2, y + 2, x + 98, y + 98);
				p = (i + 1) * 100;
				q = (j + 1) * 100;
				itoa(a[i][j], out, 10);
				setbkcolor(colors[(int)log2(a[i][j] / 5.0)]);
				setcolor(BLACK);
				settextstyle(3, 0, 4);

				outtextxy(p + 5, q + 35, out);
				setbkcolor(CYAN);
			} else {
				setfillstyle(SOLID_FILL, 1);
				bar(x + 2, y + 2, x + 98, y + 98);
			}
		}
	}
}

void draw() {
	setbkcolor(CYAN);

	setfillstyle(SOLID_FILL, CYAN);
	bar(0, 0, 1000, 800);
	settextstyle(3, 0, 4);
	char out[100];
	setcolor(YELLOW);
	itoa(score, out, 10);
	outtextxy(650, 240, out);
	itoa(high_score, out, 10);
	outtextxy(650, 150, out);
	setcolor(WHITE);

	settextstyle(BOLD_FONT, 0, 5);
	outtextxy(510, 50, nameString);
	outtextxy(20, 50, (char*)"Name of the Player:");

	settextstyle(4, 0, 1);
	outtextxy(650, 110, (char*)"HIGH SCORE :");
	outtextxy(650, 200, (char*)"SCORE :");
	outtextxy(620, 300, (char*)"Use Direction keys to play");
	outtextxy(650, 360, (char*)"Press 's' to save and exit");
	outtextxy(650, 400, (char*)"Press 'e' to exit");

	setcolor(WHITE);
	setlinestyle(3, 0, 4);

	for (int i = 1; i < 7; i++)
		for (int j = 1; j < 7; j++)
			for (int k = 1; k < 7; k++)
				for (int l = 1; l < 7; l++)
					line(i * 100, j * 100, k * 100, l * 100);
}

void init() {
	int r1, c1, r2, c2;
	srand(time(nullptr));
	r1 = rand() % 5;
	c1 = rand() % 5;
	do {
		r2 = rand() % 5;
		c2 = rand() % 5;
	} while (!(r1 != r2 && c1 != c2));

	a[r1][c1] = 5 * pow(2, rand() % 2);
	a[r2][c2] = 5 * pow(2, rand() % 2);

	FILE *F=fopen("highscores.txt","r");
	if(ferror(F)){
        return;
	}
	fscanf(F,"%s %d",high_scorer,&high_score);
	fclose(F);
}

void doCursor(int on) {
	int curX, oldColor = WHITE;
	char uBarStr[2] = {'_', 0};
	if (!on) {
		oldColor = getcolor();
		setcolor(getbkcolor());
	}
	curX = getx();
	outtext(uBarStr);
	moveto(curX, gety());
	if (!on)
		setcolor(oldColor);
}

void getGrString(char *inputString) {
	int stringIndex = 0;
	int xVal[255];
	char inputChar, outString[2];
	int oldColor;
	outString[1] = 0;
	xVal[0] = getx();
	do {
		doCursor(ON);
		inputChar = getch();
		doCursor(OFF);
		if (inputChar == 0)
			getch();
		else {
			if (inputChar == 8) {
				oldColor = getcolor();
				--stringIndex;
				if (stringIndex < 0)
					stringIndex = 0;
				moveto(xVal[stringIndex], gety());
				setcolor(getbkcolor());
				outString[0] = inputString[stringIndex];
				outtext(outString);
				moveto(xVal[stringIndex], gety());
				setcolor(oldColor);
			} else {
				inputString[stringIndex] = inputChar;
				outString[0] = inputChar;
				outtext(outString);
				++stringIndex;
				xVal[stringIndex] = getx();
			}
		}
	} while (inputChar != 13 && inputChar != 10);
	inputString[stringIndex] = 0;
}

void newLine() {
	moveto(200, gety() + textheight((char*)"A") + 50);
}

void start() {
	setfillstyle(SOLID_FILL, CYAN);
	bar(0, 0, 1000, 800);
	setbkcolor(CYAN);
	setcolor(WHITE);
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 0);
	moveto(200, 100);
	outtext((char*)"Player's Name:");
	line(200, 150, 550, 150);
	newLine();
	strcpy(nameString,"\r");
	while(!strcmp(nameString,"\r")){
            getGrString(nameString);
	}
	setbkcolor(BLUE);
	newLine();
}

void target() {
	setfillstyle(SOLID_FILL, CYAN);
	bar(0, 0, 1000, 800);
	setbkcolor(CYAN);
	settextstyle(BOLD_FONT, HORIZ_DIR, 5);
	outtextxy(280, 100, (char*)"Choose your target");
	setfillstyle(SOLID_FILL, BLUE);
	bar(200, 250, 350, 320);
	bar(600, 250, 750, 320);
	outtextxy(190, 190, (char*)"Option 1");
	outtextxy(580, 190, (char*)"Option 2");
	setbkcolor(BLUE);
	outtextxy(220, 260, (char*)"5120");
	outtextxy(610, 260, (char*)"10240");
	settextstyle(3, 0, 4);
	setbkcolor(CYAN);
	outtextxy(300, 400, (char*)"Press 1 for Option 1");
	outtextxy(450, 450, (char*)"OR");
	outtextxy(300, 500, (char*)"Press 2 for Option 2");
	setbkcolor(BLUE);
	opt = '0';
	while (1) {
		opt = getch();
		switch (opt) {
		case '1':
			tar = 5120;
			break;
		case '2':
			tar = 10240;
			break;
		default:
			break;
		}
		if (opt == '1'||opt=='2')
			return;
	}
}

void reverse_video(int x, int y, char *str) {

	x = p(x);
	y = p(y);

	setcolor(YELLOW);
	delay(100);
	outtextxy(x, y, str);
	setcolor(WHITE);
	delay(100);
}

void normal_video(int x, int y, char *str) {

	x = p(x);
	y = p(y);

	outtextxy(x, y, str);
}

char menu() {

	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
	setcolor(WHITE);

	for (int i = 1; i < MAX_ITEM; i++)
        normal_video(COL, (i * INC) + ROW, mainMenu[i]);

    reverse_video(COL, ROW, mainMenu[0]);

	int i = 0;
	while (true) {

		setcolor(CYAN);
		setcolor(WHITE);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);

		int key = getch();

		switch (key) {
		case 00:
			key = getch();
			switch (key) {
			case 72:
                normal_video(COL, (i * INC) + ROW, mainMenu[i]);
				i--;
				if (i == -1)
					i = MAX_ITEM - 1;
                    reverse_video(COL, (i * INC) + ROW, mainMenu[i]);
				break;
			case 80:
                normal_video(COL, (i * INC) + ROW, mainMenu[i]);
				i++;
				if (i == MAX_ITEM)
					i = 0;
                    reverse_video(COL, (i * INC) + ROW, mainMenu[i]);
				break;
            default:
                break;
			}
			break;
		case 13:
			return (i + 49);
		default:
		    break;
		}
	}
}

void home_draw() {
	setbkcolor(BLUE);
	setfillstyle(SOLID_FILL, CYAN);
	bar(0, 0, 1000, 800);
	setfillstyle(SOLID_FILL, CYAN);
	bar(0, 0, 1000, 800);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, BLUE);
	bar(250, 80, 720, 210);
	settextstyle(BOLD_FONT, HORIZ_DIR, 8);
	setlinestyle(3, 0, 4);
	line(250, 80, 720, 80);
	line(250, 210, 720, 210);
	line(250, 80, 250, 210);
	line(720, 80, 720, 210);
	outtextxy(270, 100, (char*)"5x Puzzle");
	settextstyle(4, 0, 4);
}

void control_menu() {
	char choice;

	while (true) {
        home_draw();
		choice = menu();

		switch (choice) {
		case '1':
			target();
			start();
			init();
			draw();
			update();
			play();
			break;

		case '2':
			resume();
			draw();
			update();
			play();
			break;

		case '3':
			high_scores();
			break;

		case '4':
			help();
			break;

		case '5':
			setcolor(BLUE);
			return;

		default:
			break;
		}
	}
}

void home() {
	settextstyle(BOLD_FONT, HORIZ_DIR, 5);
	delay(500);
	outtextxy(250, 100, (char*)"Welcome to 5x Puzzle");
	settextstyle(3, 0, 3);
	delay(500);
	outtextxy(150, 200, (char*)"Made by: ");
	delay(500);
	outtextxy(250, 250, (char*)"190041205 - Majidul Islam Chowdhury");
	delay(500);
	outtextxy(250, 300, (char*)"190041217 - Sabrina Sanjeen Roza");
	delay(500);
	outtextxy(250, 350, (char*)"190041224 - Md. Abdullahil Kafi");
	delay(500);
	outtextxy(400, 550, (char*)"Press any key to proceed");
	delay(500);
	setbkcolor(CYAN);
	getch();
	cleardevice();
}
