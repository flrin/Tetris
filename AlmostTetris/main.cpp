#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <Mmsystem.h>
#pragma comment(lib, "Winmm.lib")

using namespace std;

int m[22][22], bag[9], s = 1, con = 1, c = 0, bag2[9], score = 0, combo[5], comboscore = 0, s2 = 1;
int col[9] = { 0,14,3,5,2,4,1,12 };

void SchimbaBag() {
	for (int i = 1; i <= 7; i++)bag[i] = bag2[i];
}

void NewBag() {
	int r, i = 1, k;

	for (int i = 1; i <= 7; i++)bag2[i] = 0;

	while (i <= 7) {
		r = rand() % 7 + 1;
		for (int j = 1; j <= i; j++) {
			if (r == bag2[j]) { break; }
			k = j;
		}
		if (k == i) {
			bag2[i] = r;
			i++;
		}
	}
}

struct patrat {
	int x, y;
}t[6];

void pbar(int x, int y) { bar(x, y, x + 20, y + 20); }

void NextPiece() {
	int x, y;
	setfillstyle(SOLID_FILL, col[bag[con + 1]]);
	switch (bag[con + 1]) {
	case 1:
		x = 105;
		y = 100;
		pbar(x, y);
		pbar(x + 21, y);
		pbar(x, y + 21);
		pbar(x + 21, y + 21);
		break;
	case 2:
		x = 85;
		y = 105;
		pbar(x, y);
		pbar(x + 21, y);
		pbar(x + 42, y);
		pbar(x + 63, y);
		break;
	case 3:
		x = 115;
		y = 100;
		pbar(x, y);
		pbar(x, y + 21);
		pbar(x + 21, y + 21);
		pbar(x - 21, y + 21);
		break;
	case 4:
		x = 115;
		y = 100;
		pbar(x, y);
		pbar(x + 21, y);
		pbar(x, y + 21);
		pbar(x - 21, y + 21);
		break;
	case 5:
		x = 115;
		y = 100;
		pbar(x, y);
		pbar(x - 21, y);
		pbar(x, y + 21);
		pbar(x + 21, y + 21);
		break;
	case 6:
		x = 95;
		y = 100;
		pbar(x, y);
		pbar(x, y + 21);
		pbar(x + 21, y + 21);
		pbar(x + 42, y + 21);
		break;
	case 7:
		x = 135;
		y = 100;
		pbar(x, y);
		pbar(x, y + 21);
		pbar(x - 21, y + 21);
		pbar(x - 42, y + 21);
		break;


	}
}

void CoutMatrice() {
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 10; j++) {
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n\n";
}

void RenderFrame() {
	char str[3];
	sprintf(str, "%d", score);
	setcolor(15);
	setlinestyle(1, 0, 4);
	rectangle(197, 47, 412, 472); ///x1=200, y1=50, x2=400, y2=450 ///frame ul mare


	outtextxy(79, 49, "NEXT");
	rectangle(70, 47, 180, 157);   ///coada
	if (s)NextPiece();

	rectangle(20, 167, 180, 340);

	outtextxy(29, 169, "SCORE");      ///scorul
	sprintf(str, "%d", score);
	outtextxy(29, 190, str);

	outtextxy(29, 230, "X1");
	sprintf(str, "%d", combo[1]);        ///combo x1
	outtextxy(70, 230, str);

	outtextxy(29, 255, "X2");
	sprintf(str, "%d", combo[2]);        ///combo x2
	outtextxy(70, 255, str);

	outtextxy(29, 280, "X3");
	sprintf(str, "%d", combo[3]);        ///combo x3
	outtextxy(70, 280, str);

	outtextxy(29, 305, "X4");
	sprintf(str, "%d", combo[4]);        ///combo x4
	outtextxy(70, 305, str);

	outtextxy(3, 400, "PRESS C FOR");
	outtextxy(3, 430, "CONTROLS");

	setcolor(8);
	setlinestyle(0, 0, 1);
	for (int i = 220; i <= 412; i += 21) {
		line(i, 50, i, 468);
	}
	for (int i = 70; i <= 472; i += 21) {
		line(200, i, 409, i);
	}


}

void CoutForma() {
	for (int i = 1; i <= 4; i++) {
		cout << t[i].x << " " << t[i].y << "\n";
	}
	cout << "\n\n";
}

void UpdateazaForma() {
	for (int i = 1; i <= 4; i++) {
		m[t[i].x][t[i].y] = bag[con];
	}
}


void InitializareForma() {
	switch (bag[con]) {
	case 1:
		t[1].x = 1;
		t[1].y = 5;
		t[2].x = 1;
		t[2].y = 6;
		t[3].x = 2;
		t[3].y = 5;
		t[4].x = 2;
		t[4].y = 6;

		break;

	case 2:
		t[2].x = 1;
		t[2].y = 5;
		t[1].x = 2;
		t[1].y = 5;
		t[3].x = 3;
		t[3].y = 5;
		t[4].x = 4;
		t[4].y = 5;

		break;

	case 3:
		t[2].x = 1;
		t[2].y = 5;
		t[1].x = 2;
		t[1].y = 5;
		t[3].x = 2;
		t[3].y = 6;
		t[4].x = 2;
		t[4].y = 4;

		break;

	case 4:
		t[3].x = 1;
		t[3].y = 5;
		t[2].x = 1;
		t[2].y = 6;
		t[1].x = 2;
		t[1].y = 5;
		t[4].x = 2;
		t[4].y = 4;

		break;

	case 5:
		t[3].x = 1;
		t[3].y = 5;
		t[2].x = 1;
		t[2].y = 4;
		t[1].x = 2;
		t[1].y = 5;
		t[4].x = 2;
		t[4].y = 6;

		break;

	case 6:
		t[3].x = 1;
		t[3].y = 5;
		t[2].x = 2;
		t[2].y = 5;
		t[1].x = 2;
		t[1].y = 6;
		t[4].x = 2;
		t[4].y = 7;

		break;

	case 7:
		t[3].x = 1;
		t[3].y = 5;
		t[2].x = 2;
		t[2].y = 5;
		t[1].x = 2;
		t[1].y = 4;
		t[4].x = 2;
		t[4].y = 3;

		break;
	}

	for (int i = 1; i <= 4; i++)
		if (m[t[i].x][t[i].y]) {
			s = 0;
		}

}

void StergeForma() {
	for (int i = 1; i <= 4; i++) {
		m[t[i].x][t[i].y] = 0;
	}
}

void SpreJos() {
	for (int i = 1; i <= 4; i++) {
		t[i].x++;
	}
}

void SpreDreapta() {
	for (int i = 1; i <= 4; i++) {
		t[i].y++;
	}
}

void SpreStanga() {
	for (int i = 1; i <= 4; i++) {
		t[i].y--;
	}
}

void Render() {
	int x = 200, y = 50, k = 1, l = 1;

	RenderFrame();

	for (int i = y; k <= 20; i += 21) {
		for (int j = x; l <= 10; j += 21) {
			if (m[k][l]) {
				setfillstyle(1, col[m[k][l]]);
				bar(j, i, j + 20, i + 20);
				setcolor(BLACK);
				rectangle(j - 1, i - 1, j + 21, i + 21);
				//cout<<m[k][l];
			}
			l++;
		}
		l = 1;
		k++;
	}
}

bool IsEmptyBelow() {
	bool sem[5] = { 0 }, a = 1;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++)
			if (t[i].x + 1 == t[j].x && i != j && t[i].y == t[j].y)sem[i] = 1;
	}

	for (int i = 1; i <= 4; i++) {
		if (sem[i] == 0) {
			if (m[t[i].x + 1][t[i].y] == 0 && t[i].x < 20);
			else a = 0;
		}
	}
	return a;
}

bool IsEmptyRight() {
	bool sem[5] = { 0 }, a = 1;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++)
			if (t[i].y + 1 == t[j].y && i != j && t[i].x == t[j].x)sem[i] = 1;
	}

	for (int i = 1; i <= 4; i++) {
		if (sem[i] == 0) {
			if (m[t[i].x][t[i].y + 1] == 0 && t[i].y < 10);
			else a = 0;
		}
	}
	return a;
}

bool IsEmptyLeft() {
	bool sem[5] = { 0 }, a = 1;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++)
			if (t[i].y - 1 == t[j].y && i != j && t[i].x == t[j].x)sem[i] = 1;
	}

	for (int i = 1; i <= 4; i++) {
		if (sem[i] == 0) {
			if (m[t[i].x][t[i].y - 1] == 0 && t[i].y > 1);
			else a = 0;
		}
	}
	return a;
}

void CoboaraJocul(int linie) {
	for (int i = linie; i >= 1; i--) {
		for (int j = 1; j <= 10; j++) {
			m[i][j] = m[i - 1][j];
		}
	}
}

void CheckCompleteLine() {
	int j = 1, sc = score;
	for (int i = 1; i <= 20; i++) {
		for (j = 1; j <= 10; j++)
			if (m[i][j] == 0)
				break;

		if (j == 11) {
			for (int k = 1; k <= 10; k++)
				m[i][k] = 0;
			CoboaraJocul(i);
			PlaySound(TEXT("LineDelete.wav"), NULL, SND_FILENAME | SND_ASYNC);
			score += 100 * (comboscore + 1);
			comboscore++;

		}
		j = 1;
	}
	if (score != sc) {
		combo[comboscore]++;
		comboscore = 0;
	}
}

void CoutBag() {
	for (int i = 1; i <= 7; i++)cout << bag[i] << " ";
	cout << "\n";
}

bool CanRotate() {
	int x, y, a;

	for (int i = 2; i <= 4; i++) {
		x = t[i].x - t[1].x;
		y = t[i].y - t[1].y;

		a = x;
		x = y;
		y = -a;

		if (m[x + t[1].x][y + t[1].y] || y + t[1].y < 1 || y + t[1].y>10 || x + t[1].x > 20) {
			return 0;
		}
	}
	return 1;
}

void Roteste() {
	int x, y, a;

	for (int i = 2; i <= 4; i++) {
		x = t[i].x - t[1].x;
		y = t[i].y - t[1].y;

		a = x;
		x = y;
		y = -a;

		t[i].x = x + t[1].x;
		t[i].y = y + t[1].y;

	}

}

void Controls() {
	swapbuffers();
	cleardevice();
	int a = 150, x = 150;
	settextstyle(2, HORIZ_DIR, 18);
	setcolor(WHITE);
	outtextxy(90, 30, "CONTROLS");

	setlinestyle(0, 0, 3);
	line(10 + 10, x + 42, 60, x + 42);
	line(35 + 10, x + 27, 60, x + 42);
	line(35 + 10, x + 58, 60, x + 42);

	line(20, x + 92, 60, x + 92);
	line(20, x + 92, 35, x + 77);
	line(20, x + 92, 35, x + 107);

	line(40, x + 122, 40, x + 162);
	line(40, x + 122, 55, x + 142);
	line(40, x + 122, 25, x + 142);

	settextstyle(2, HORIZ_DIR, 8);
	outtextxy(a, x + 30, "to move right");
	outtextxy(a, x + 80, "to move left");
	outtextxy(a, x + 130, "to rotate clockwise");
	outtextxy(a, x + 180, "to instantly drop your piece");
	outtextxy(10, x + 180, "[SPACE]");

	setcolor(GREEN);
	outtextxy(50, 420, "PRESS ENTER TO CONTINUE");

	swapbuffers();
	while (!GetAsyncKeyState(13)) {}


}

void StartMenu() {
	cleardevice();

	char c;
	settextstyle(2, HORIZ_DIR, 18);
	outtextxy(10, 130, "ALMOST TETRIS");

	setcolor(GREEN);
	settextstyle(2, HORIZ_DIR, 8);
	outtextxy(50, 300, "PRESS ENTER TO CONTINUE");

	while (1) {
		c = getch();
		if (c == 13)break;
	}
	cleardevice();

}

void EndMenue() {
	char str[3];
	swapbuffers();
	cleardevice();

	setcolor(WHITE);
	settextstyle(2, HORIZ_DIR, 18);
	outtextxy(60, 35, "GAME OVER");
	settextstyle(2, HORIZ_DIR, 8);
	outtextxy(120, 130, "FINAL SCORE: ");
	sprintf(str, "%d", score);
	outtextxy(320, 130, str);
	settextstyle(2, HORIZ_DIR, 8);
	outtextxy(20, 250, "DO YOU WANT TO PLAY AGAIN?");
	settextstyle(2, HORIZ_DIR, 18);
	outtextxy(200, 280, "Y/N");

	swapbuffers();
	while (1) {
		char c = getch();
		if (c == 'n') {
			s2 = 0;
			break;
		}
		else if (c == 'y') {
			cleardevice();
			break;
		}
	}
}

void InstaDrop() {
	while (IsEmptyBelow()) {
		SpreJos();
	}
	mciSendString("play InstaDrop4.mp3", NULL, 0, NULL);
	c = 0;
}

void Replay() {
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 10; j++)m[i][j] = 0;
	}
	for (int i = 1; i <= 4; i++) {
		t[i].x = 0;
		t[i].y = 0;
		combo[i] = 0;
	}
    settextstyle(2, HORIZ_DIR, 8);
	con = 1;
	c = 0;
	score = 0;
	comboscore = 0;
}



int main()
{
	initwindow(500, 500, "", 900, 0, 0);
	mciSendString("play Tetris2.mp3 repeat", NULL, 0, NULL);
	srand((unsigned)time(NULL));

	int cl[7] = { 0 }, sem = 0;

	StartMenu();
	NewBag();
	SchimbaBag();
	bag[8] = bag2[1];
	InitializareForma();
	settextstyle(2, HORIZ_DIR, 8);

	while (s2) {
		if (!s) {
			NewBag();
			SchimbaBag();
			bag[8] = bag2[1];
			InitializareForma();
			settextstyle(2, HORIZ_DIR, 8);
		}


		while (s) {
			cleardevice();
			Render();

			//CoutMatrice();

			if (clock() - c > 500) {
				c = clock();
				if (IsEmptyBelow()) {
					StergeForma();
					SpreJos();
				}
				else {
					con++;
					if (con == 8) {
						con = 1;
						SchimbaBag();
						NewBag();
						bag[8] = bag2[1];
					}

					InitializareForma();
					CheckCompleteLine();
				}
			}
			if (GetAsyncKeyState(40) && clock() - cl[0] > 100) {   ///jos
				cl[0] = clock();
				if (IsEmptyBelow()) {
					StergeForma();
					SpreJos();
					PlaySound(TEXT("MoveSound.wav"), NULL, SND_ASYNC);
				}
				else {
					con++;
					if (con == 8) {
						con = 1;
						SchimbaBag();
						NewBag();
						bag[8] = bag2[1];
						//CoutBag();
					}
					InitializareForma();
					CheckCompleteLine();
				}
			}
			StergeForma();
			if (GetAsyncKeyState(39) && IsEmptyRight() && clock() - cl[1] > 101) {   ///dreapta
				cl[1] = clock();
				SpreDreapta();
				PlaySound(TEXT("MoveSound.wav"), NULL, SND_ASYNC);
			}

			if (GetAsyncKeyState(37) && IsEmptyLeft() && clock() - cl[2] > 100) {   ///stanga
				cl[2] = clock();
				SpreStanga();
				PlaySound(TEXT("MoveSound.wav"), NULL, SND_ASYNC);
			}

			if (GetAsyncKeyState(38) && clock() - cl[3] > 250) {   ///rotire,sus
				cl[3] = clock();
				if (CanRotate())Roteste();
				PlaySound(TEXT("RotateSound.wav"), NULL, SND_ASYNC);
			}

			if (GetAsyncKeyState(32) && clock() - cl[4] > 500) {  ///insta-drop
				cl[4] = clock();
				InstaDrop();
			}

			if (GetAsyncKeyState(67)) {
				cleardevice();
				Controls();
				break;
			}

			UpdateazaForma();
			swapbuffers();
		}
		if (!s) {
			cleardevice();
			swapbuffers();
			Render();
			swapbuffers();
			PlaySound(TEXT("GameOver.wav"), NULL, SND_ASYNC);
			delay(3000);
			EndMenue();
			Replay();
			s = 1;
		}
	}

	closegraph();
	return 0;
}
