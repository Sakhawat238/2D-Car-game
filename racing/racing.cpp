#define _CRT_SECURE_NO_WARNINGS
#include "iGraphics.h"
#include <time.h>
#include <stdio.h>
#include <Windows.h>



int tempx = 0, tempy = 0;
int playsound = 1;

int i = 100;
int load = 1;
int choice = 0;
int car_x = 350, car_y = 20;
int c1 = 0, c2 = 0, c3 = 0, count = 0;
int chcx = 290, chcy = 40, chcw = 250, chch = 30;
int rtrack = 0;
int strack = 0;
int c_choose = 1;
double screen_width = 800;
double screen_height = 450;
double loading_x = 25;
double opening_car_width = 800, opening_car_height = 150;
double x50 = 50, x300 = 300,x550=550, y325 = 325, y40 = 40, bxw = 200, bxh = 70;
//holes
double ellipse_x = 388, ellipse_y1 = 300, ellipse_a1 = 0, ellipse_b1 = 0, ellipse_y2 = 300, ellipse_a2 = 0, ellipse_b2 = 0;
double ellipse1_x1 = 365, ellipse1_x2 = 385, ellipse1_y1 = 297, ellipse1_a1 = 0, ellipse1_b1 = 0, ellipse1_y2 = 297, ellipse1_a2 = 0, ellipse1_b2 = 0;
double ellipse2_x1 = 385, ellipse2_x2 = 385, ellipse2_y1 = 297, ellipse2_a1 = 0, ellipse2_b1 = 0, ellipse2_y2 = 297, ellipse2_a2 = 0, ellipse2_b2 = 0;

//side line
double sdlx[4] = { 285.15625, 313.671875, 333.0625, 310.25 };
double sdly[4] = { 283, 288, 290, 285 };
double sdlx1[4] = { 310.25, 333.0625, 333.0625, 310.25 };
double sdly1[4] = { 285, 290, 289.125, 283.5 };
double sdry[4] = { 285, 290, 288, 283 };
double sdrx[4] = { 463.30379, 438.1772152, 458.828125, 489.84375 };
double sdry1[4] = { 285, 290, 289.0253165, 283.3291156 };
double sdrx1[4] = { 463.30379, 438.1772152, 438.1772152, 463.30379 };
// 2 sideline
double sdlx2[4] = { 171.09375, 199.609375, 211.015625, 182.5 };
double sdly2[4] = { 263, 268, 270, 265 };
//obstacle
double obly[4] = { 280, 297, 297, 280 };
double oblx[4] = { 343.2659933, 338.26599, 367.1380471, 372.1380471 };
double obly1[3] = { 280, 297, 294 };
double oblx1[3] = { 372.1380471, 367.1380471, 374.4949495 };
double obly2[4] = { 280, 297, 297, 280 };
double oblx2[4] = { 391.5824916, 396.5824916, 425.45455, 420.4545 };
double obly3[3] = { 280, 297, 294 };
double oblx3[3] = { 391.5824916, 396.5824916, 386.1616162 };
int sc = 0;
//flag
int front_load = 1;
int fifteen = 0;
int select_cchose = 0;
int select_race = 0;
int car_select = 0;
int thirteen = 0;
int workinghof = 0;
int givescore = 0,trying=0;
//random
int random;
int obs_count = 1;
//score
int score_delay = 1;
int score = 0;
//obstacle_collison_box
double box_x[4] = { 351, 351, 470, 470 };
double box_y[4] = { 20, 140, 140, 20 };

//obstacle speed variabable
double obs11_0_3 = 1.8, obs11_1_2 = 1, obs12_2 = 1.2;//obs11,obs12;
double obs21_0_3 = 1.8, obs21_1_2 = 1, obs22_2 = 1.2;//obs21,obs22;
double toron = 0, toron_flag = 0;



//car_not_choose
int not_car = 0;
//car_unlock
int need_score;
//game pause
int pause = 0;
//game load
int score_load;
int car_load;
//hof
char hoffname[6][100] = { "empty", "empty", "empty", "empty", "empty", "RAFEEN" };
int  hoffscore[6] = { 0, 0, 0, 0, 0, 0 };
char hoffscore1[5][5] = { "0", "0", "0", "0", "0" };
char hoffnumber[5][5] = { "1.", "2.", "3.", "4.", "5." };
int idx=0, end_game_flag = 0;
//high
char highname[100] = { "" };
int highscore=0;
char high_score[5];
int h = 0;

void mydelay(int mseconds)
{
	clock_t start, end;
	double elapsed;

	start = clock();
	while (1)
	{
		end = clock();
		elapsed = ((double)(end - start)) / ((double)CLOCKS_PER_SEC / 1000.0);
		if (elapsed>mseconds)break;
	}
}

void sound()
{
	PlaySound("CarHorn.wav", NULL, SND_ASYNC);
	
}

void sound1()
{
	PlaySound("ss.wav", NULL, SND_ASYNC);
}

void sound2()
{
	PlaySound("sa.wav", NULL, SND_ASYNC);
}

void csound()
{
	PlaySound("F:\\visual\\racing\\tone\\c1.wav", NULL, SND_ASYNC);
}

void menu()
{
	if (choice == 0) iShowBMP(0, 0, "menu.bmp");
	if (choice == 1 && fifteen<15) iShowBMP(0, 0, "ng.bmp"),  fifteen++;
	if (choice == 2 && fifteen<1) iShowBMP(0, 0, "rsm.bmp"),fifteen++;
	if (choice == 3 && fifteen<15) iShowBMP(0, 0, "ins.bmp"), fifteen++;
	if (choice == 4 && fifteen<15) iShowBMP(0, 0, "hof.bmp"), fifteen++;
	if (choice == 5 && fifteen<15) iShowBMP(0, 0, "crd.bmp"), fifteen++;
	if (choice == 6 && fifteen<15) iShowBMP(0, 0, "ext.bmp"), fifteen++;
}

void loading_dot()
{	
	iSetColor(255, 0, 0);
	iText(275, 235, "LOADING", GLUT_BITMAP_TIMES_ROMAN_24);
	if (count >= 17) {
		count = count % 17;
		c1 = 0, c2 = 0, c3 = 0;
	}
	if (count >= 5 && c1 == 0){
		iFilledCircle(395, 239, 5, 100);
	}
	if (count >= 10 && c2 == 0){
		iFilledCircle(415, 239, 5, 100);
	}
	if (count >= 15 && c3 == 0){
		iFilledCircle(435, 239, 5, 100);
		if (count >= 16) c1 = 1, c2 = 1, c3 = 1;
	}
}

void loading_background()
{
	iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, 800, 500);

	iSetColor(88, 88, 88);
	iFilledRectangle(0, 75, 800, 300);

	iSetColor(250, 250, 0);
	iFilledRectangle(0, 85, 800, 5);
	iFilledRectangle(0, 360, 800, 5);
	iSetColor(255, 255, 255);
	iFilledRectangle(30, 175, 40, 10);
}

void loading_speed_metre()
{
	iFilledRectangle(120, 175, 40, 10);
	iFilledRectangle(210, 175, 40, 10);
	iFilledRectangle(300, 175, 40, 10);
	iFilledRectangle(390, 175, 40, 10);
	iFilledRectangle(480, 175, 40, 10);
	iFilledRectangle(570, 175, 40, 10);
	iFilledRectangle(660, 175, 40, 10);
	iFilledRectangle(750, 175, 40, 10);
	iFilledRectangle(30, 275, 40, 10);
	iFilledRectangle(120, 275, 40, 10);
	iFilledRectangle(210, 275, 40, 10);
	iFilledRectangle(300, 275, 40, 10);
	iFilledRectangle(390, 275, 40, 10);
	iFilledRectangle(480, 275, 40, 10);
	iFilledRectangle(570, 275, 40, 10);
	iFilledRectangle(660, 275, 40, 10);
	iFilledRectangle(750, 275, 40, 10);
	iSetColor(255, 255, 255);
	iFilledRectangle(0, 225, 800, 5);
}

void race_track()
{
	if (rtrack == 0) iShowBMP(0, 0, "rt11.bmp");   
	else if (rtrack >= 1 && rtrack<=7) iShowBMP(0, 0, "rt12.bmp");
	else if (rtrack >7  && rtrack<=14) iShowBMP(0, 0, "rt13.bmp");
	if (rtrack >= 14) rtrack = rtrack%14;
	
	
}

void car()
{
	if(c_choose==1)iShowBMP(car_x, car_y, "car1.bmp");
	if (c_choose == 2)iShowBMP(car_x, car_y, "car2.bmp");
	if (c_choose == 3)iShowBMP(car_x, car_y, "car3.bmp");
	if (c_choose == 4)iShowBMP(car_x, car_y, "car4.bmp");
	if (c_choose == 5)iShowBMP(car_x, car_y, "car5.bmp");
	if (c_choose == 6)iShowBMP(car_x, car_y, "car6.bmp");
	if (c_choose == 7)iShowBMP(car_x, car_y, "car7.bmp");
	if (c_choose == 8)iShowBMP(car_x, car_y, "car8.bmp");
}

void notcar()
{
	iSetColor(0, 0, 255);
	iFilledRectangle(280, 225, 210, 30);
	iSetColor(255, 255, 255);
	iText(284, 228, "Please Choose a Car", GLUT_BITMAP_TIMES_ROMAN_24);
}

void hole()
{
	iSetColor(65, 56, 36);
	iFilledEllipse(ellipse_x, ellipse_y1, ellipse_a1, ellipse_b1, 100000);
	ellipse_y1 -= 4;
	ellipse_a1 += 3.34;
	ellipse_b1 += .9;

	iSetColor(20, 20, 20);
	iFilledEllipse(ellipse_x, ellipse_y2, ellipse_a2, ellipse_b2, 100000);
	ellipse_y2 -= 4.20;
	ellipse_a2 += 3.197327;
	ellipse_b2 += .697211;
	if ((ellipse_y1 - ellipse_b2) <= 141) {
		if ((ellipse_y2 - ellipse_b2) >= 0 && (ellipse_y2 - ellipse_b2) <= box_y[1]){
			if (((box_x[0] >= (ellipse_x - ellipse_a1 - 2)) && (box_x[0] <= (ellipse_x + ellipse_a1 + 2))) || ((box_x[2] >= (ellipse_x - ellipse_a1)) && (box_x[2] <= (ellipse_x + ellipse_a1)))) pause=1,end_game_flag=1;
		}
		//if (((box_x[0] * box_x[0]) / (ellipse_a2*ellipse_a2) + (box_y[0] * box_y[0]) / (ellipse_b2*ellipse_b2)) >= .9 && ((box_x[0] * box_x[0]) / (ellipse_a2*ellipse_a2) + (box_y[0] * box_y[0]) / (ellipse_b2*ellipse_b2) <= 1.1)) exit(0);
	}
	if (ellipse_y1 <= 10) ellipse_y1 = 300, ellipse_a1 = 0, ellipse_b1 = 0, ellipse_y2 = 300, ellipse_a2 = 0, ellipse_b2 = 0, obs_count = 0;
	printf("%lf %lf %lf\n", ellipse_b1, ellipse_b2, box_y[2]);
}
void hole1()
{
	iSetColor(65, 56, 36);
	iFilledEllipse(ellipse1_x1, ellipse1_y1, ellipse1_a1, ellipse1_b1, 100000);
	ellipse1_x1 = (95 * ellipse1_y1 + 7920) / 99;
	ellipse1_y1 -= 5;
	ellipse1_a1 += 1.7;
	ellipse1_b1 += .4;

	iSetColor(20, 20, 20);
	iFilledEllipse(ellipse1_x2, ellipse1_y2, ellipse1_a2, ellipse1_b2, 100000);
	ellipse1_x2 = (95 * ellipse1_y2 + 7920) / 99;
	ellipse1_y2 -= 5.08;
	ellipse1_a2 += 1.645;
	ellipse1_b2 += .315;
	if ((ellipse1_y1 - ellipse1_b2) <= 141) {
		if ((ellipse1_y2 - ellipse1_b2) >= 0 && (ellipse1_y2 - ellipse1_b2) <= box_y[1]){
			if (((box_x[0] >= (ellipse1_x1 - ellipse1_a1 - 2)) && (box_x[0] <= (ellipse1_x1 + ellipse1_a1 + 2))) || ((box_x[2] >= (ellipse1_x1 - ellipse1_a1)) && (box_x[2] <= (ellipse1_x1 + ellipse1_a1)))) pause=1,end_game_flag = 1;
		}
		//if (((box_x[0] * box_x[0]) / (ellipse_a2*ellipse_a2) + (box_y[0] * box_y[0]) / (ellipse_b2*ellipse_b2)) >= .9 && ((box_x[0] * box_x[0]) / (ellipse_a2*ellipse_a2) + (box_y[0] * box_y[0]) / (ellipse_b2*ellipse_b2) <= 1.1)) exit(0);
	}
	if (ellipse1_y1 <= 10) ellipse1_x1 = 365, ellipse1_x2 = 365, ellipse1_y1 = 297, ellipse1_a1 = 0, ellipse1_b1 = 0, ellipse1_y2 = 297, ellipse1_a2 = 0, ellipse1_b2 = 0, obs_count = 0;
	//printf("%lf %lf\n", ellipse1_y1, ellipse1_x);
	//iLine(80, 0, 365, 297);
}
void hole2()
{
	iSetColor(65, 56, 36);
	iFilledEllipse(ellipse2_x1, ellipse2_y1, ellipse2_a1, ellipse2_b1, 100000);
	ellipse2_x1 = (219780 - 355 * ellipse2_y1) / 297;
	ellipse2_y1 -= 5;
	ellipse2_a1 += 1.7;
	ellipse2_b1 += .4;

	iSetColor(20, 20, 20);
	iFilledEllipse(ellipse2_x2, ellipse2_y2, ellipse2_a2, ellipse2_b2, 100000);
	ellipse2_x2 = (219780 - 355 * ellipse2_y2) / 297;
	ellipse2_y2 -= 5.08;
	ellipse2_a2 += 1.645;
	ellipse2_b2 += .315;
	if (ellipse2_y2 <= 10) ellipse2_x1 = 385, ellipse2_x2 = 385, ellipse2_y1 = 297, ellipse2_a1 = 0, ellipse2_b1 = 0, ellipse2_y2 = 297, ellipse2_a2 = 0, ellipse2_b2 = 0, obs_count = 0;
	if ((ellipse2_y1 - ellipse2_b2) <= 141) {
		if ((ellipse2_y2 - ellipse2_b2) >= 0 && (ellipse2_y2 - ellipse2_b2) <= box_y[1]){
			if (((box_x[0] >= (ellipse2_x1 - ellipse2_a1 - 2)) && (box_x[0] <= (ellipse2_x1 + ellipse2_a1 + 2))) || ((box_x[2] >= (ellipse2_x1 - ellipse2_a1)) && (box_x[2] <= (ellipse2_x1 + ellipse2_a1)))) pause=1,end_game_flag = 1;
		}
		//if (((box_x[0] * box_x[0]) / (ellipse_a2*ellipse_a2) + (box_y[0] * box_y[0]) / (ellipse_b2*ellipse_b2)) >= .9 && ((box_x[0] * box_x[0]) / (ellipse_a2*ellipse_a2) + (box_y[0] * box_y[0]) / (ellipse_b2*ellipse_b2) <= 1.1)) exit(0);
	}
	//iLine(740, 0, 385, 297);
}


void obstacle11()
{
	iSetColor(255, 255, 255);
	//iLine(150, 0, 355, 297);
	//iLine(325, 0, 375, 297);
	iFilledPolygon(oblx, obly, 4);

	if (obly[0] > 0){
		obly[0] -= obs11_0_3;
		oblx[0] = (205 * obly[0] + 44550) / 297;
		obly[1] -= obs11_1_2;
		oblx[1] = ((205 * obly[0] + 44550) / 297) - 5;

		obly[2] -= obs11_1_2;
		oblx[2] = ((50 * obly[3] + 96525) / 297) - 5;
		obly[3] -= obs11_0_3;
		oblx[3] = (50 * obly[3] + 96525) / 297;

		//accelaration
		if (obly[0] <= 250 && obly[0] >= 247) obs11_0_3 += 1.5, obs11_1_2 += 1.5, obs12_2 += 1.5;
		if (toron_flag == 1) obs11_0_3 += 1, obs11_1_2 += 1, obs12_2 += 1, toron_flag = 0;

	}
	if (obly[0] <= 0){
		obs_count = 0;
		oblx[0] = 343.2659933, oblx[1] = 338.26599, oblx[2] = 367.1380471, oblx[3] = 372.1380471;
		obly[0] = 280, obly[1] = 297, obly[2] = 297, obly[3] = 280;
		obs11_0_3 = 1.8 + toron, obs11_1_2 = 1 + toron, obs12_2 = 1.2 + toron;

	}

	//printf("%lf %lf %lf %lf\n", obly[0], obly[1], obly[2], obly[3]);

	//collinson 
	if (obly[0] <= 141){
		if ((box_x[0] >= oblx[0] && box_x[0] <= oblx[3]) || (box_x[2] >= oblx[0] && box_x[2] <= oblx[3]) && (box_x[1] >= oblx[0] && box_x[1] <= oblx[3]) || (box_x[3] >= oblx[0] && box_x[3] <= oblx[3]) || (box_x[0] >= oblx1[0]) && box_x[0] <= oblx1[2]) pause=1,end_game_flag = 1;
	}
	//printf("%lf %lf %lf %lf\n", box_x[0], box_x[1], box_x[2], box_x[3]);
}


void obstacle12()
{
	iSetColor(0, 0, 0);
	iFilledPolygon(oblx1, obly1, 3);
	if (obly1[0] > 0){
		obly1[0] -= obs11_0_3;
		oblx1[0] = (50 * obly1[0] + 96525) / 297;
		obly1[1] -= obs11_1_2;
		oblx1[1] = ((50 * obly1[0] + 96525) / 297) - 5;
		obly1[2] -= obs12_2;
		oblx1[2] = (50 * obly1[2] + 96525) / 297;
	}
	if (obly1[0] <= 0){
		obs_count = 0;
		oblx1[0] = 372.1380471, oblx1[1] = 367.1380471, oblx1[2] = 374.4949495;
		obly1[0] = 280, obly1[1] = 297, obly1[2] = 294;
		//obs11_0_3 = 1.8, obs11_1_2 = 1, obs12_2 = 1.2;

	}
	//printf("%lf %lf %lf %lf\n", obly1[0], obly1[1], obly1[2], obly1[3]);
	//colision
	/*if (obly[0] <= 141){
	if (box_x[0] >= 247.323232 || box_x[0] <= 348.737373 || box_x[2] >= 247.323232 || box_x[2] <= 348.737373) exit(0);
	}*/
}

void obstacle21(){
	iSetColor(255, 255, 255);
	//iLine(500, 0, 385, 297);
	//iLine(675, 0, 405, 297);
	iFilledPolygon(oblx2, obly2, 4);
	if (obly2[0] > 0){
		obly2[0] -= obs21_0_3;
		oblx2[0] = (148500 - 115 * obly2[0]) / 297;
		obly2[1] -= obs21_1_2;
		oblx2[1] = ((148500 - 115 * obly2[0]) / 297) + 5;

		obly2[2] -= obs21_1_2;
		oblx2[2] = ((7425 - 10 * obly2[3]) / 11) + 5;
		obly2[3] -= obs21_0_3;
		oblx2[3] = (7425 - 10 * obly2[3]) / 11;
		if (obly2[0] <= 250 && obly2[0] >= 247) obs21_0_3 += 1.5, obs21_1_2 += 1.5, obs22_2 += 1.5;
		if (toron_flag == 1) obs21_0_3 += 1, obs21_1_2 += 1, obs22_2 += 1, toron_flag = 0;
	}
	if (obly2[0] <= 0){
		obs_count = 0;
		oblx2[0] = 391.5824916, oblx2[1] = 396.5824916, oblx2[2] = 425.45455, oblx2[3] = 420.4545;
		obly2[0] = 280, obly2[1] = 297, obly2[2] = 297, obly2[3] = 280;
		obs21_0_3 = 1.8 + toron, obs21_1_2 = 1 + toron, obs22_2 = 1.2 + toron;
	}
	//colision
	if (obly2[0] <= 141){
		if ((box_x[1] >= oblx2[0] && box_x[1] <= oblx2[3]) || (box_x[2] >= oblx2[0] && box_x[2] <= oblx2[3]) && (box_x[0] >= oblx2[0] && box_x[0] <= oblx2[3]) || (box_x[3] >= oblx2[0] && box_x[3] <= oblx2[3])) pause=1,end_game_flag = 1;
	}
	//printf("%lf %lf %lf %lf\n", oblx2[0], oblx2[1], oblx2[2], oblx2[3]);
	//printf("%lf %lf %lf %lf\n", box_x[0], box_x[1], box_x[2], box_x[3]);
}



void obstacle22(){
	iSetColor(0, 0, 0);
	iFilledPolygon(oblx3, obly3, 3);
	if (obly3[0] > 0){
		obly3[0] -= obs21_0_3;
		oblx3[0] = (148500 - 115 * obly3[0]) / 297;
		obly3[1] -= obs21_1_2;
		oblx3[1] = ((148500 - 115 * obly3[0]) / 297) + 5;
		obly3[2] -= obs22_2;
		oblx3[2] = (148500 - 115 * obly3[2]) / 297;
		if (obly3[0] <= 141) {
			if (box_x[2] >= oblx3[2] && box_x[0] <= oblx3[0]) pause=1,end_game_flag = 1;
		}
	}
	if (obly3[0] <= 0){
		obs_count = 0;
		oblx3[0] = 391.5824916, oblx3[1] = 396.5824916, oblx3[2] = 386.161616;
		obly3[0] = 280, obly3[1] = 297, obly3[2] = 294;
		//obs21_0_3 = 1.8, obs21_1_2 = 1, obs22_2 = 1.2;
	}
	//printf("%lf %lf %lf\n", oblx3[0], oblx3[1], oblx3[2]);
	//collision
	/*if (obly[0] == 141){
	if (box_x[0] >= 247.323232 || box_x[0] <= 348.737373 || box_x[2] >= 247.323232 || box_x[2] <= 348.737373) exit(0);
	}*/

}
void obstacle()
{
	if (obs_count == 1) random = rand() % (6 - 1) + 1;
	if (random == 1) { hole(); obs_count++; }
	if (random == 5) { obstacle11(); obstacle12(); obs_count++; }
	if (random == 3){ obstacle21(); obstacle22(); obs_count++; }
	if (random == 4) { hole1(); }
	if (random == 2) hole2();
}


void sideline1(){
	iSetColor(200, 200, 200);
	//left side
	//iLine(0, 207, 365, 297);
	//iLine(0, 217, 365, 297);
	//iLine(0, 233, 365, 297);
	iFilledPolygon(sdlx, sdly, 4);
	if (sdly[0] > 207){
		sdly[0] -= 5;
		sdlx[0] = (365 * sdly[0] - 85045) / 64;
		sdly[1] -= 5;
		sdlx[1] = (365 * sdly[1] - 85045) / 64;

		sdly[2] -= 5;
		sdlx[2] = (73 * sdly[2] - 15841) / 16;
		sdly[3] -= 5;
		sdlx[3] = (73 * sdly[3] - 15841) / 16;

	}
	if (sdly[0] <= 207){
		sdlx[0] = 285.15625, sdlx[1] = 313.671875, sdlx[2] = 333.0625, sdlx[3] = 310.25;
		sdly[0] = 283, sdly[1] = 288, sdly[3] = 285, sdly[2] = 290;
	}


	iSetColor(0, 0, 0);
	iFilledPolygon(sdlx1, sdly1, 4);
	if (sdly1[0] > 207){

		sdly1[0] -= 5;
		sdlx1[0] = (73 * sdly1[0] - 15841) / 16;
		sdly1[1] -= 5;
		sdlx1[1] = (73 * sdly1[1] - 15841) / 16;
		sdlx1[2] = sdlx1[1];
		sdly1[2] = (18 * sdlx1[2] + 15111) / 73;
		sdlx1[3] = sdlx1[0];
		sdly1[3] = (18 * sdlx1[3] + 15111) / 73;
	}
	if (sdly1[0] <= 207){
		sdlx1[0] = 310.25, sdlx1[1] = 333.0625, sdlx1[2] = 333.0625, sdlx1[3] = 281.25;
		sdly1[0] = 283, sdly1[2] = 288, sdly1[1] = 289.125, sdly1[3] = 283.5;
	}


}

void sideline2(){
	//right side
	iSetColor(255, 255, 255);
	//iLine(800, 207, 403, 297);
	//iLine(800, 218, 403, 297);
	//iLine(800, 233, 403, 297);
	iFilledPolygon(sdrx, sdry, 4);
	if (sdry[0] > 207){
		sdry[0] -= 5;
		sdrx[0] = (149746 - 397 * sdry[0]) / 79;
		sdry[1] -= 5;
		sdrx[1] = (149746 - 397 * sdry[1]) / 79;

		sdry[2] -= 5;
		sdrx[2] = (143701 - 397 * sdry[2]) / 64;
		sdry[3] -= 5;
		sdrx[3] = (143701 - 397 * sdry[3]) / 64;

	}
	if (sdry[0] <= 207){
		sdry[0] = 285, sdry[1] = 290, sdry[2] = 288, sdry[3] = 283;
		sdrx[0] = 463.30379, sdrx[1] = 438.1772152, sdrx[2] = 458.828125, sdrx[3] = 489.84375;
	}

	iSetColor(100, 100, 100);
	iFilledPolygon(sdrx1, sdry1, 4);
	if (sdry1[0] > 207){

		sdry1[0] -= 5;
		sdrx1[0] = (149746 - 397 * sdry1[0]) / 79;
		sdry1[1] -= 5;
		sdrx1[1] = (149746 - 397 * sdry1[1]) / 79;
		sdrx1[2] = sdrx1[1];
		sdry1[2] = (154179 - 90 * sdrx1[2]) / 397;
		sdrx1[3] = sdrx1[0];
		sdry1[3] = (154179 - 90 * sdrx1[3]) / 397;
	}
	if (sdry1[0] <= 207){
		sdrx1[0] = 463.30379, sdrx1[1] = 438.1772152, sdrx1[2] = 438.1772152, sdrx1[3] = 463.30379;
		sdry1[0] = 285, sdry1[2] = 290, sdry1[1] = 289.0253165, sdry1[3] = 283.3291156;
	}





}

void sideline3()
{
	iSetColor(200, 200, 200);
	iFilledPolygon(sdlx2, sdly2, 4);
	if (sdly2[0] > 207){
		sdly2[0] -= 5;
		sdlx2[0] = (365 * sdly2[0] - 85045) / 64;
		sdly2[1] -= 5;
		sdlx2[1] = (365 * sdly2[1] - 85045) / 64;

		sdly2[2] -= 5;
		sdlx2[2] = (73 * sdly2[2] - 15841) / 16;
		sdly2[3] -= 5;
		sdlx2[3] = (73 * sdly2[3] - 15841) / 16;

	}
	if (sdly2[0] <= 207){
		sdlx2[0] = 171.09375, sdlx2[1] = 199.609375, sdlx[2] = 211.015625, sdlx2[3] = 182.5;
		sdly2[0] = 263, sdly2[1] = 268, sdly[2] = 270, sdly2[3] = 265;
	}
}

void car_unlock()
{
	if (c_choose == 2 && need_score < 100) iShowBMP(340, 165, "lock1.bmp");
	if (c_choose == 3 && need_score < 150) iShowBMP(340, 165, "lock2.bmp");
	if (c_choose == 4 && need_score < 200) iShowBMP(340, 165, "lock3.bmp");
	if (c_choose == 5 && need_score < 250) iShowBMP(340, 165, "lock4.bmp");
	if (c_choose == 6 && need_score < 300) iShowBMP(340, 165, "lock5.bmp");
	if (c_choose == 7 && need_score < 350) iShowBMP(340, 165, "lock6.bmp");
	if (c_choose == 8 && need_score < 400) iShowBMP(340, 165, "lock7.bmp");
}

void car_choose()
{
	iShowBMP(0, 0, "carchoose.bmp");
	if(c_choose==1)iShowBMP(222, 120, "carside1.bmp");
	if (c_choose == 2)iShowBMP(222, 120, "carside2.bmp");
	if (c_choose == 3)iShowBMP(222, 120, "carside3.bmp");
	if (c_choose == 4)iShowBMP(222, 120, "carside4.bmp");
	if (c_choose == 5)iShowBMP(222, 120, "carside5.bmp");
	if (c_choose == 6)iShowBMP(222, 120, "carside6.bmp");
	if (c_choose == 7)iShowBMP(222, 120, "carside7.bmp");
	if (c_choose == 8)iShowBMP(222, 120, "carside8.bmp");
	car_unlock();
}

void h_o_f()
{
	iShowBMP(0, 0, "halloffame.bmp");
}

void opening()
{
	//iSetColor(0, 0, 0);
	//iFilledRectangle(0, 0, 800, 450);
	iShowBMP(0, 0, "frnt.bmp");
	iShowBMP(opening_car_width, opening_car_height, "U.bmp");
	if (opening_car_width > 200)opening_car_width -= 30,  opening_car_height -= 3;
	if (opening_car_width <= 200){
		//iSetColor(0, 0, 0);
		//iText(300, 366, "ULTIMAE CAR RACING", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 255);
		iText(300, 50, "Click Here to Continue", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 0, 0);
		iRectangle(chcx, chcy, chcw, chch);
	}
	if (opening_car_width <= 200)
	{
		if (chcx >= 287)
		{
			chcx--;
			chcy--;
			chcw += 2;
			chch += 2;
		}
		if (chcx < 287)
		{
			chcx = 290, chcy = 40, chcw = 250, chch = 30;
		}
	}
} 

void intscore(int sc420)
{
	int temp_scr, scr_i, each, initial = 0;
	char rev_scr[10000] = "";
	char scr_txt[10000] = "";
	temp_scr = sc420;
	while (temp_scr != 0)
	{
		each = temp_scr % 10;
		rev_scr[initial] = '0' + each;
		initial++;
		temp_scr = temp_scr / 10;
	}
	for (scr_i = 0; scr_i < initial; scr_i++)
		scr_txt[scr_i] = rev_scr[initial - scr_i - 1];
	iSetColor(0, 0, 255);
	iFilledRectangle(600,415,190,30);
	iSetColor(0, 0, 0);
	iText(612, 422, "SCORE : ", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0, 0, 0);
	iText(710, 422, scr_txt, GLUT_BITMAP_TIMES_ROMAN_24);
}

void gamepause()
{
	iShowBMP(0, 0, "pause.bmp");
}

void refresh()
{
	oblx[0] = 343.2659933, oblx[1] = 338.26599, oblx[2] = 367.1380471, oblx[3] = 372.1380471;
	obly[0] = 280, obly[1] = 297, obly[2] = 297, obly[3] = 280;
	oblx1[0] = 372.1380471, oblx1[1] = 367.1380471, oblx1[2] = 374.4949495;
	obly1[0] = 280, obly1[1] = 297, obly1[2] = 294;
	oblx2[0] = 391.5824916, oblx2[1] = 396.5824916, oblx2[2] = 425.45455, oblx2[3] = 420.4545;
	obly2[0] = 280, obly2[1] = 297, obly2[2] = 297, obly2[3] = 280;
	oblx3[0] = 391.5824916, oblx3[1] = 396.5824916, oblx3[2] = 386.161616;
	obly3[0] = 280, obly3[1] = 297, obly3[2] = 294;
	ellipse_y1 = 300, ellipse_a1 = 0, ellipse_b1 = 0, ellipse_y2 = 300, ellipse_a2 = 0, ellipse_b2 = 0, obs_count = 0;
	ellipse1_x1 = 365, ellipse1_x2 = 365, ellipse1_y1 = 297, ellipse1_a1 = 0, ellipse1_b1 = 0, ellipse1_y2 = 297, ellipse1_a2 = 0, ellipse1_b2 = 0, obs_count = 0;
	ellipse2_x1 = 385, ellipse2_x2 = 385, ellipse2_y1 = 297, ellipse2_a1 = 0, ellipse2_b1 = 0, ellipse2_y2 = 297, ellipse2_a2 = 0, ellipse2_b2 = 0, obs_count = 0;
}
void save_file()
{
	FILE *svf = fopen("loaddata.txt", "w+");
	fprintf(svf, "%d %d", score, c_choose);
	fclose(svf);
}

void load_file()
{
	FILE *ldf = fopen("loaddata.txt", "r");
	fscanf(ldf, "%d %d", &score, &c_choose);
	fclose(ldf);
}

void writelock()
{
	FILE *upl = fopen( "lockdata.txt", "w+" );
	fprintf(upl, "%d", need_score);
	fclose(upl);
}

void readlock()
{
	FILE *ll = fopen("lockdata.txt", "r");
	fscanf(ll, "%d", &need_score);
	fclose(ll);
}


void high_write(){
	FILE *high = fopen("high.txt", "w+");
	fprintf(high, "%d  %s\n",highscore,highname );
	fclose(high);
}
void high_read(){
	FILE *high = fopen("high.txt", "r");
	fscanf(high, "%d  %s\n", &highscore, &highname );
	fclose(high);
}
void end_game(){
	
	if (thirteen < 30) iShowBMP(0, 0, "wreck.bmp"),idx=0;
	thirteen++;
	high_read();
	if (score < highscore && thirteen >= 30) iShowBMP(0, 0, "loser.bmp");

	if (score >= highscore && thirteen >= 30) {

		highscore = score;

		iShowBMP(0, 0, "scoresave.bmp");
		iSetColor(255, 0, 0);
		iText(300, 350, "Press F2 to erase", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(270, 170, highname, GLUT_BITMAP_TIMES_ROMAN_24);
		//sprintf_s(high_score, "%d", highscore);
		high_write();
	}


}
/*
void hofwrite(){
	FILE *hof = fopen("hof.txt", "w+");

	//char name[5][100] = { "[NO NAME]", "rafeen", "sushu", "imon", "nadu" };
	for (int i = 0; i < 5; i++){
		fprintf(hof, "%s  %s\n", hoffname[i], hoffscore1[i]);
	}
	fclose(hof);
}
void hofread(){
	FILE *hof = fopen("hof.txt", "r");
	for (int i = 0; i < 5; i++){
		fscanf(hof, "%s  %s\n", hoffname[i], hoffscore1[i]);
	}
	fclose(hof);
}
//hof manipulation

void manipulation(){
	char temp2[100];
	int i, j, k, temp;
	for (i = 0; i<6; i++){
		for (j = 0; j<5; j++){
			if (hoffscore[j + 1]>hoffscore[j]){
				temp = hoffscore[j];
				hoffscore[j] = hoffscore[j + 1];
				hoffscore[j + 1] = temp;
				strcpy(temp2, hoffname[j]);
				strcpy(hoffname[j], hoffname[j + 1]);
				strcpy(hoffname[j + 1], temp2);
			}
		}
	}
}

void workingwithhof(){
	manipulation();
	hofwrite();
	hofread();

}
void callme(){
	iShowBMP(0, 0, "scoresave.bmp");
	//givescore = 1;
	//iText(350, 200, hoffname[idx], GLUT_BITMAP_TIMES_ROMAN_24);
	if (workinghof == 1)  workingwithhof;
}
void end_game(){

	if(thirteen<30) iShowBMP(0, 0, "wreck.bmp");
	thirteen++;
	
	if (score < hoffscore[5] && thirteen >= 30) iShowBMP(0, 0, "loser.bmp");
	
	if (score>=hoffscore[5] && thirteen >= 30) {
		hoffscore[5] = score;
		trying = 1;
		

	}
	if (trying == 1) callme();
}*/

void iDraw() {

	iClear();
	
	count++;
	rtrack++;
	//end game
	if ((select_race == 1 && car_select == 1 && pause == 1 && end_game_flag == 1) || (choice == 2 && fifteen == 1 && pause == 1 && end_game_flag == 1)) end_game();
	//pause
	if ((select_race == 1 && car_select == 1 && pause == 1 && end_game_flag == 0) || (choice == 2 && fifteen == 1 && pause == 1 && end_game_flag == 0)) gamepause();

	//load
	if (choice == 2 && fifteen==1 && pause ==0)
	{
		
		race_track();
		//score start
		if (score_delay % 50 == 0) score++;
		need_score = score;
		if (need_score > 100 && need_score % 50 == 0) writelock();
		score_delay++;
		intscore(score);
		//start end
		sideline1();
		sideline2();
		obstacle();
		car();

	}
	//new race
	if (select_race==1 && car_select==1 && pause==0)
	{

		race_track();
		//score start
		if (score_delay % 5 == 0)
			score++;
		need_score = score;
		if (need_score > 100 && need_score % 50 == 0) writelock();
		score_delay++;
		intscore(score);
		//start end
		sideline1();
		sideline2();
		obstacle();
		car();
	}

	//car_chose
	if (select_cchose == 1 && select_race == 0){ car_choose(); }

	//car & track selection
	if (choice == 1 && fifteen == 15 && select_cchose == 0 && select_race == 0)
	{
		iShowBMP(0, 0, "slct.bmp");
		if (not_car == 1 && car_select==0) notcar();
	}

	//instruction
	if (choice == 3 && fifteen == 15)
	{
		iShowBMP(0, 0, "instruct.bmp");
		iSetColor(255, 0,0);
		iText(30, 400, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//hall of fame
	if (choice == 4 && fifteen == 15)
	{
		iShowBMP(0, 0, "halloffame.bmp");
		iSetColor(255, 0, 0);
		iText(30, 400, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(270, 250, "NAME", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(490, 250, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);

		/*manipulation();
		hofwrite();
		hofread();
		iText(150, 290, hoffname[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(150, 255, hoffname[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(150, 220, hoffname[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(150, 185, hoffname[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(150, 150, hoffname[1], GLUT_BITMAP_TIMES_ROMAN_24);

		iText(130, 290, hoffnumber[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(130, 255, hoffnumber[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(130, 220, hoffnumber[2], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(130, 185, hoffnumber[3], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(130, 150, hoffnumber[4], GLUT_BITMAP_TIMES_ROMAN_24);

		iText(700, 290, hoffscore1[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 255, hoffscore1[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 220, hoffscore1[2], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 185, hoffscore1[3], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 150, hoffscore1[4], GLUT_BITMAP_TIMES_ROMAN_24);*/
		
		high_read();
		//high_write();
		sprintf_s(high_score, "%d", highscore);
		iText(500, 220, high_score, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(280, 220, highname, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//credit
	if (choice == 5 && fifteen == 15)
	{
		iShowBMP(0, 0, "creditt.bmp");
		iSetColor(255, 0, 0);
		iText(30, 400, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//exit
	if (choice == 6 && fifteen == 15)
	{
		exit(0);
	}

	//loading part
		if (load == 1 && front_load == 0)
		{
			loading_background();
			
			loading_speed_metre();

			loading_dot();

			iRectangle(275, 191, 250, 30);
			iFilledRectangle(279, 195, loading_x, 23);
			loading_x += 3;
			if (loading_x >= 246)
			{
				loading_x = 20;
				load = 0;
			}
		}

	//menu part
	if (load == 0) menu(),high_read(); 
	

	//starting part
	if (front_load == 1)  opening();
	
	mydelay(20);

}




void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my) 
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//to go from front to menu
		if (opening_car_width <= 200 && (mx >= 295 && mx <= 530) && (my >= 40 && my <= 70))
		{
			front_load = 0;
		}
		//to choose in menu
		if (choice==0 && load == 0 && fifteen==0)
		{
			if((mx >= 50 && mx <=200) && (my >= 332 && my <= 400)) choice = 1,score=0,end_game_flag=0;
			if ((mx >= 287 && mx <= 488) && (my >= 332 && my <= 400))choice = 2 ,load_file();
			if ((mx >= 535 && mx <= 736) && (my >= 332 && my <= 400)) choice = 3;
			if ((mx >= 58 && mx <= 260) && (my >= 38 && my <= 88)) choice = 4;
			if ((mx >= 302 && mx <= 502) && (my >= 38 && my <= 88)) choice = 5;
			if ((mx >= 542 && mx <= 742) && (my >= 38 && my <= 88)) choice = 6;	
		}
		//to choose car select/race
		if (choice==1 && select_cchose==0 && fifteen == 15)
		{
			if ((mx >= 260 && mx <= 460) && (my >= 298 && my <= 352)) { select_cchose = 1,readlock(); }
			if ((mx >= 260 && mx <= 460) && (my >= 192 && my <= 248) && car_select==0){ not_car = 1; }
			if ((mx >= 260 && mx <= 460) && (my >= 192 && my <= 248) && car_select == 1){ select_race = 1; }
		}
		//to choose different cars
		if (select_cchose == 1 && fifteen == 15)
		{
			if ((mx >= 95 && mx <= 150) && (my >= 180 && my <= 275) && c_choose>1)  c_choose--;
			if ((mx >= 660 && mx <= 715) && (my >= 180 && my <= 275) && c_choose<8) c_choose++;
			if ((mx >= 367 && mx <= 424) && (my >= 27 && my <= 54))   select_cchose = 0;
			//else if ((mx >= 224 && mx <= 585) && (my >= 140 && my <= 300))  select_cchose = 0;
		}
		//to go to menu from instruction
		if (choice == 3 && fifteen == 15)
		{
			if ((mx >= 30 && mx <= 90) && (my >= 400 && my <= 430)) choice = 0,fifteen=0,load=0;
		}
		//to go to menu from hall of fame
		if (choice == 4 && fifteen == 15)
		{
			if ((mx >= 30 && mx <= 90) && (my >= 400 && my <= 430)) choice = 0, fifteen = 0, load = 0;
		}
		//to go to menu from credit
		if (choice == 5 && fifteen == 15)
		{
			if ((mx >= 30 && mx <= 90) && (my >= 400 && my <= 430)) choice = 0, fifteen = 0, load = 0;
		}
		//to select a car and back to select menu
		if (select_cchose == 1 && fifteen == 15)
		{
			if ((mx >= 224 && mx <= 585) && (my >= 140 && my <= 300))
			{
				if (c_choose == 1 && need_score >= 0) select_cchose = 0, car_select = 1;
				if (c_choose == 2 && need_score >= 100) select_cchose = 0, car_select = 1;
				if (c_choose == 3 && need_score >= 150) select_cchose = 0, car_select = 1;
				if (c_choose == 4 && need_score >= 200) select_cchose = 0, car_select = 1;
				if (c_choose == 5 && need_score >= 250) select_cchose = 0, car_select = 1;
				if (c_choose == 6 && need_score >= 300) select_cchose = 0, car_select = 1;
				if (c_choose == 7 && need_score >= 350) select_cchose = 0, car_select = 1;
				if (c_choose == 8 && need_score >= 400) select_cchose = 0, car_select = 1;
			}
		}
		//functions in pause menu
		if (pause == 1 && (car_select == 1 || choice == 2))
		{
			if ((mx >= 275 && my <= 505) && (my >= 286 && my <= 346)) pause = 0;
			if ((mx >= 275 && my <= 505) && (my >= 194 && my <= 254)) save_file();
			if ((mx >= 275 && my <= 505) && (my >= 100 && my <= 160)) choice = 0, fifteen = 0, refresh(), load = 0, car_select = 0, select_cchose = 0, select_race = 0;
		}
    }
			
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
	{

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void iKeyboard(unsigned char key)
{
	/*if (end_game_flag == 1 && givescore==1)
	{
		if (idx <= 8){
			hoffname[5][idx] = key;
			idx++;
		}
	}*/
	if (end_game_flag == 1)
	{
		if (idx <= 10)
		{
			highname[idx] = key;
			idx++;
			
		}
	}
	if ((key == 'a' || key == 'A') && car_x - 15 > 0)
	{
		car_x -= 15;
		box_x[0] -= 15;
		box_x[1] -= 15;
		box_x[2] -= 15;
		box_x[3] -= 15;
	}
	if ((key == 'd' || key == 'D') && car_x + 125 < 800)
	{
		car_x += 15;
		box_x[0] += 15;
		box_x[1] += 15;
		box_x[2] += 15;
		box_x[3] += 15;
	}
	//obstacle accelaration by keyboard
	if ((key == 'w' || key == 'W') && car_x + 125 < 800 && random == 2) {
		if (toron <= 2) { toron++, toron_flag = 1; }
		else toron_flag = 0;

	}
	if ((key == 'w' || key == 'W') && car_x + 125 < 800 && random == 3) {
		if (toron <= 2) { toron++, toron_flag = 1; }
		else toron_flag = 0;
	}
	if ((key == 'h') || (key == 'H')) sound();
	if (key == 'q' || key == 'Q') exit(0);
	if (key == 'p' || key == 'P') pause = 1;
	
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_LEFT && car_x - 15 > 0)
	{
		car_x -= 15;
		box_x[0] -= 15;
		box_x[1] -= 15;
		box_x[2] -= 15;
		box_x[3] -= 15;
	}
	if (key == GLUT_KEY_RIGHT  && car_x + 125 < 800)
	{
		car_x += 15;
		box_x[0] += 15;
		box_x[1] += 15;
		box_x[2] += 15;
		box_x[3] += 15;
	}
	if (end_game_flag == 1 && pause == 1)
	{
		if (key == GLUT_KEY_F1) end_game_flag = 0, refresh(), pause = 0, choice = 4, fifteen = 15, load = 0, car_select = 0, select_cchose = 0, select_race = 0,idx=0;
	}
	if (key == GLUT_KEY_F2)
	{
		idx--;
		highname[idx] =NULL;

	}
}


int main() {
	
	sound2();
	
	iSetTimer(22000, sound2);
	//iSetTimer(34000, sound1);
	iInitialize(screen_width, screen_height, "racing");
	
	
	return 0;
}