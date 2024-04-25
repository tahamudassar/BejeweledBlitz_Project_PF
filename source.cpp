#include <iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include <winuser.h>
#include "Header.h"
using namespace std;

int main()
{
	intro();
	Sleep(2000);
	myRectangle(100, 100, 700, 450, 0, 0, 0, 0, 0, 0);
	srand(time(0));
	int  n = 0;
	
	int arr[8][8];
	int points = 0;
	int check = 0;
	//populating 2D array with random numbers//
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			n = 1 + (rand() % 5);
			arr[i][j] = n;

		}
	}
	//checking for repetition//
	checkWhole(arr, 0, 0, points, 0, check);
	//printing after check is complete//
	printArray(arr);
	//Cursor//
	


	int key1 = 1;
	int x1 = 100;
	int y1 = 125;
	int x2 = 125, y2 = 130;
	int tempx;
	int tempy;
	int xi = 0;
	int yj = 0;
	int count1 = 0;
	
	points = 0;
	int timedone;
	int timer = 0;
	if (timer == 20)
	{
		timedone = 1;
	}
	key1 = 0;
	gotoxy(0, 0);
	timer = clock() / 1000;
	cout << "\n time: " << timer;
	gotoxy(0, 0);
	
	myRectangle(x1, y1, x2, y2, 255, 0, 255, 255, 0, 255);
	int i=0;
	
	while (timer <= 60)
	{
		if (timer == 20)
		{
			timedone = 1;
		}
		key1 = 6;
		gotoxy(0, 0);
		timer = clock() / 1000;
		cout << "\n time: " << timer;
		gotoxy(0, 0);
		isCursorKeyPressed(key1);
		if (key1 == 1 && x2 >= 150)//if left key is pressed 
		{

			myRectangle(x1, y1, x2, y2, 0, 0, 0, 0, 0, 0);
			x1 -= 50;
			x2 -= 50;
			myRectangle(x1, y1, x2, y2, 255, 0, 255, 255, 0, 255);
			xi = xi - 1;



		}
		else if (key1 == 2 && y2 >= 150)// if up key is pressed
		{
			myRectangle(x1, y1, x2, y2, 0, 0, 0, 0, 0, 0);
			y1 -= 50;
			y2 -= 50;
			myRectangle(x1, y1, x2, y2, 255, 0, 255, 255, 0, 255);
			yj = yj - 1;
		}
		else if (key1 == 3 && x2 <= 450)//if right key is pressed
		{

			myRectangle(x1, y1, x2, y2, 0, 0, 0, 0, 0, 0);
			x1 += 50;
			x2 += 50;
			myRectangle(x1, y1, x2, y2, 255, 0, 255, 255, 0, 255);
			xi = xi + 1;
		}
		else if (key1 == 4 && y2 <= 450)// if down key is pressed
		{
			myRectangle(x1, y1, x2, y2, 0, 0, 0, 0, 0, 0);
			y1 += 50;
			y2 += 50;
			myRectangle(x1, y1, x2, y2, 255, 0, 255, 255, 0, 255);
			yj = yj + 1;
		}
		else if (key1 == 5 && count1 == 0) // if select key is pressed
		{
			tempx = xi;
			tempy = yj;
			myRectangle(x1, y1, x2, y2, 0, 0, 255, 0, 0, 255);
			count1 = 1;
			cout << arr[tempy][tempx]; 
		}
		else if (key1 == 5 && count1 == 1)  // if select key is pressed again
		{
			swap(arr[yj][xi], arr[tempy][tempx]);
			checkWhole(arr, tempy, tempx, points, 1, check);
			if (check == 0)//fail swap//
			{
				swap(arr[yj][xi], arr[tempy][tempx]);
			}


			check = 0;

			count1 = 0;
			printArray(arr);
			//checking for 3 in a row/column//

			gotoxy(50, 0);
			cout << "   Points  " << points;
		}
		else if (timer > 70)
		{
			return 0;
		}
		i++;
	}

				

	}

			

		
	



