#include <windows.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include <iomanip>

using namespace std;



void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2, int color, int color2, int color3,int num) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, num, RGB(color, color2, color3)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(13);
	if (key == 1)
	{

		whichKey = 5;   // 5 if z key is pressed
		return true;
	}
	key = GetAsyncKeyState(69);
	if (key == 1)
	{
		whichKey = 6;
		return true;
	}
	return false;
}

void myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B,int a,int b,int c)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(a, b, c)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}
void myTraingle(int x1, int y1, int color, int color2, int color3)
{
	myLine(x1, y1, x1 + 20, y1, color, color2, color3,2);
	myLine(x1, y1, x1 + 10, y1 + 17.3, color, color2, color3, 2);
	myLine(x1 + 20, y1, x1 + 10, y1 + 17.3, color, color2, color3, 2);
}

void myDiamond(int x1, int y1, int color, int color2, int color3)
{
	myLine(x1 + 10, y1, x1 + 20, y1 + 10, color, color2, color3, 2);
	myLine(x1 + 20, y1 + 10, x1 + 10, y1 + 20, color, color2, color3, 2);
	myLine(x1 + 10, y1, x1, y1 + 10, color, color2, color3, 2);
	myLine(x1, y1 + 10, x1 + 10, y1 + 20, color, color2, color3, 2);
}
void myDiamond2(int x, int y, int color, int color2, int color3)
{
	myLine(x + 5, y, x + 15, y, color, color2, color3, 2);
	myLine(x, y + 5, x + 5, y, color, color2, color3, 2);
	myLine(x + 15, y, x + 20, y + 5, color, color2, color3, 2);
	myLine(x + 20, y + 5, x + 10, y + 20, color, color2, color3, 2);
	myLine(x, y + 5, x + 10, y + 20, color, color2, color3, 2);
}
void myDestroyer(int x1, int y1, int color, int color2, int color3)
{
	myLine(x1, y1 + 10, x1 + 20, y1 + 10, color, color2, color3, 2);
	myLine(x1 + 10, y1, x1 + 5, y1 + 20, color, color2, color3, 2);
	myLine(x1 + 10, y1, x1 + 15, y1 + 20, color, color2, color3, 2);
	myLine(x1 + 15, y1 + 20, x1, y1 + 10, color, color2, color3, 2);
	myLine(x1 + 5, y1 + 20, x1, y1 + 20, color, color2, color3, 2);
}
void intro()
{
	myRectangle(100, 100, 700, 450, 75, 0, 130, 75, 0, 130);//purple-box
	myRectangle(200, 150, 600, 350, 255, 255, 255, 255, 255, 255);//white-box
	myRectangle(205, 155, 595, 345, 0, 0, 0, 0, 0, 0);//black-box

	//making-name;
	myLine(320, 170, 360, 170, 5, 252, 153, 5);//G
	myLine(320, 170, 320, 220, 5, 252, 153, 5);
	myLine(320, 220, 360, 220, 5, 252, 153, 5);
	myLine(360, 200, 360, 220, 5, 252, 153, 5);
	myLine(350, 200, 360, 200, 5, 252, 153, 5);

	//E
	myLine(380, 170, 380, 220, 5, 252, 153, 5);
	myLine(380, 170, 420, 170, 5, 252, 153, 5);
	myLine(380, 195, 420, 195, 5, 252, 153, 5);
	myLine(380, 220, 420, 220, 5, 252, 153, 5);

	//M
	myLine(440, 170, 440, 220, 5, 252, 153, 5);
	myLine(480, 170, 480, 220, 5, 252, 153, 5);
	myLine(440, 170, 460, 220, 5, 252, 153, 5);
	myLine(480, 170, 460, 220, 5, 252, 153, 5);

	//U
	myLine(380, 240, 380, 290, 5, 252, 153, 5);
	myLine(420, 240, 420, 290, 5, 252, 153, 5);
	myLine(380, 290, 420, 290, 5, 252, 153, 5);

	//S
	myLine(440, 240, 480, 240, 5, 252, 153, 5);
	myLine(440, 265, 480, 265, 5, 252, 153, 5);
	myLine(440, 290, 480, 290, 5, 252, 153, 5);
	myLine(440, 240, 440, 265, 5, 252, 153, 5);
	myLine(480, 265, 480, 290, 5, 252, 153, 5);

	//H
	myLine(500, 240, 500, 290, 5, 252, 153, 5);
	myLine(540, 240, 540, 290, 5, 252, 153, 5);
	myLine(500, 265, 540, 265, 5, 252, 153, 5);

	//R
	myLine(320, 240, 320, 290, 5, 252, 153, 5);
	myLine(320, 240, 360, 240, 5, 252, 153, 5);
	myLine(320, 265, 360, 265, 5, 252, 153, 5);
	myLine(360, 240, 360, 265, 5, 252, 153, 5);
	myLine(320, 265, 360, 290, 5, 252, 153, 5);

	//C
	myLine(260, 240, 300, 240, 5, 252, 153, 5);
	myLine(260, 240, 260, 290, 5, 252, 153, 5);
	myLine(260, 290, 300, 290, 5, 252, 153, 5);


}
void printArray(int arr[8][8])
{
	myRectangle(85, 85, 485, 485, 0, 0, 0,0,0,0);
	int colx = 85;
	int coly = 85;
	for (int i = 0; i < 9; i++)
	{
		myLine(colx, coly, colx, coly + 400, 255, 255, 255, 2);
		colx = colx + 50;
	}
	int rowy = 85;
	for (int i = 0; i < 9; i++)
	{
		myLine(85, rowy, 485, rowy, 255, 255, 255, 2);
		rowy = rowy + 50;
	}
	int x = 100, y = 100, n = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			n = arr[i][j];


			if (n == 1)
			{
				myRectangle(x, y, x + 20, y + 20, 255, 0, 255, 255, 0, 255);
			}
			else if (n == 2)
			{
				
					myEllipse(x, y, x + 20, y + 20, 0, 255, 0);
			}
			else if (n == 3)
			{
				myTraingle(x, y, 255, 223, 0);
			}

			else if (n == 4)
			{
				myDiamond(x, y, 80, 199, 199);
			}

			else if (n == 5)
			{
				myDiamond2(x, y, 75, 0, 130);
			}
			else if (n == 6)
			{
				myRectangle(x, y, x + 20, y + 20, 255, 0, 0, 255, 0, 0);
			}
			else if (n == 7)
			{
				myEllipse(x, y, x + 20, y + 20, 255, 0, 0);
			}
			else if (n == 8)
			{
				myTraingle(x, y, 255, 0, 0);
			}

			else if (n == 9)
			{
				myDiamond(x, y, 255, 0, 0);
			}

			else if (n == 10)
			{
				myDiamond2(x, y, 255, 0, 0);
			}
			else if (n == 11)
			{
				myDestroyer(x, y, 255, 0, 0);
			}
			
			x = x + 50;
		}
		x = 100;
		y = y + 50;
	}
}
bool checkDestroyer(int arr[8][8], int& points, bool sleep)
{
	bool flag = 0;
	
	if (sleep == 1)
		
	{
		
		for (int i = 0; i < 8 && flag==0; i++)
		{
			for (int j = 0; j < 8 &&flag==0; j++)
			{
				
				if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j]&&j<=5&&i<=5)  //	top left corner//
				{

					arr[i][j] = 11;
					printArray(arr);
					for (int k = 0; k < 8; k++)
					{
						arr[k][j] = rand() % 5 + 1;
					}
					for (int l = 0; l < 8; l++)
					{
						arr[i][l] = rand() % 5 + 1;
					}
					points = points + 16;
					flag = 1;
					Sleep(1000);
				}
				else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j]&&j<=5&&i>=2)//bottom left corner
				{
					arr[i][j] = 11;
					printArray(arr);
					for (int k = 0; k < 8; k++)
					{
						arr[k][j] = rand() % 5 + 1;
					}
					for (int l = 0; l < 8; l++)
					{
						arr[i][l] = rand() % 5 + 1;
					}
					points = points + 16;
					flag = 1;
					Sleep(1000);
				}
				else if (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2] && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j]&&j>=2&&i>=2 )//top right corner
				{
					arr[i][j] = 11;
					printArray(arr);
					for (int k = 0; k < 8; k++)
					{
						arr[k][j] = rand() % 5 + 1;
					}
					for (int l = 0; l < 8; l++)
					{
						arr[i][l] = rand() % 5 + 1;
					}
					points = points + 16;
					flag = 1;
					Sleep(1000);
				}
				else if (arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j - 2] && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i - 2][j]&&j>=2&&i>=2 ) //bottom right corner//
				{
					arr[i][j] = 11;
					printArray(arr);
					for (int k = 0; k <8; k++)
					{
						arr[k][j] = rand()%5+1;
					}
					for (int l = 0; l < 8; l++)
					{
						arr[i][l] = rand()%5+1;
					}
					points = points + 16;
					flag = 1;
					Sleep(1000);
				}
			}
		}
	}
	return flag;
}



int checkRepeatRow(int arr[8][8], int xi, int yj, int &points, bool sleep)
{
	int counter = 0;
	int totalcount = 0;
	if (checkDestroyer(arr, points, sleep) == 0)
	{
		while (counter <= 64)
		{
			//cout << counter<<" ";


			for (int i = 0; i < 8; i++)
			{

				for (int j = 0; j < 8; j++)
				{

					//for creating special gem//
					if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && sleep == 1)
					{
						/*/	arr[i][j] = 69;
							arr[i][j+1] = 69;
							arr[i][j+2] = 69;
							arr[i][j+3] = 69;
							*/
						points = points + 3;
						
						//shifting number upwards//
						totalcount++;
						for (int k = i; k > 0; k--)
						{
							swap(arr[k][j], arr[k - 1][j]);
							swap(arr[k][j + 1], arr[k - 1][j + 1]);
							swap(arr[k][j + 2], arr[k - 1][j + 2]);

							printArray(arr);
							if (sleep == 1)
							{
								Sleep(1000);
							}

						}
						//replacing top with random numbers//
						int n;
						n = 1 + (rand() % 5);
						arr[0][j] = n;
						n = 1 + (rand() % 5);
						arr[0][j + 1] = n;
						n = 1 + (rand() % 5);
						arr[0][j + 2] = n;
						arr[i][j + 3] = (arr[i][j + 3] + 5);
						printArray(arr);

						counter = 0;

					}
					//for blasting special gem of 4
					else if ((arr[i][j] % 5) == (arr[i][j + 1] % 5) && (arr[i][j] % 5) == (arr[i][j + 2] % 5) && (arr[i][j] >= 6 || arr[i][j + 1] >= 6 || arr[i][j + 2] >= 6))
					{
						if (arr[i][j] > 5 || arr[i][j + 1] > 5 || arr[i][j + 2])
						{
							/*arr[i][j] = 69;
							arr[i][j + 1] = 69;
							arr[i][j + 2] = 69;*/
							if (j >= 1 && i >= 1 && j <= 6 && i <= 6)
							{
								points = points + 9;
							}
							else
							{
								points = points + 6;
							}
							totalcount++;
						
							for (int k = i; k > 2; k--)
							{
								swap(arr[k - 1][j], arr[k - 2][j]);
								swap(arr[k - 1][j + 1], arr[k - 2][j + 1]);
								swap(arr[k - 1][j + 2], arr[k - 2][j + 2]);
								swap(arr[k][j], arr[k - 1][j]);
								swap(arr[k][j + 1], arr[k - 1][j + 1]);
								swap(arr[k][j + 2], arr[k - 1][j + 2]);
								swap(arr[k + 1][j], arr[k][j]);
								swap(arr[k + 1][j + 1], arr[k][j + 1]);
								swap(arr[k + 1][j + 2], arr[k][j + 2]);
								printArray(arr);
								if (sleep == 1)
								{
									Sleep(1000);
								}

							}
							int n;
							n = 1 + (rand() % 5);
							arr[0][j] = n;
							n = 1 + (rand() % 5);
							arr[0][j + 1] = n;
							n = 1 + (rand() % 5);
							arr[0][j + 2] = n;
							n = 1 + (rand() % 5);
							arr[1][j] = n;
							n = 1 + (rand() % 5);
							arr[1][j + 1] = n;
							n = 1 + (rand() % 5);
							arr[1][j + 2] = n;
							n = 1 + (rand() % 5);
							arr[2][j] = n;
							n = 1 + (rand() % 5);
							arr[2][j + 1] = n;
							n = 1 + (rand() % 5);
							arr[2][j + 2] = n;
						}
					}
					//to check 3 in a row//
					else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] != arr[i][j + 3])
					{
						/*arr[i][j] = 69;
						arr[i][j + 1] = 69;
						arr[i][j + 2] = 69;*/

						points = points + 3;
						//shifting number upwards//
						totalcount++;
						for (int k = i; k > 0; k--)
						{
							swap(arr[k][j], arr[k - 1][j]);
							swap(arr[k][j + 1], arr[k - 1][j + 1]);
							swap(arr[k][j + 2], arr[k - 1][j + 2]);
							printArray(arr);
							if (sleep == 1)
							{
								Sleep(1000);
							}

						}
						//replacing top with random numbers//
						int n;
						n = 1 + (rand() % 5);
						arr[0][j] = n;
						n = 1 + (rand() % 5);
						arr[0][j + 1] = n;
						n = 1 + (rand() % 5);
						arr[0][j + 2] = n;

						counter = 0;

					}


				}

			}
			counter++;


		}
	}
	//It will return whether there are 3/4 in a row//
	return totalcount;
}
int checkRepeatcolumms(int arr[8][8], int xi, int yj, int& points, bool sleep)
{
	int counter = 0;
	int totalcount = 0;
	int  flag = 0;
	int l = 0;
	//to ensure function will not work if destroyer is present/made//
	if (checkDestroyer(arr, points, sleep) == 0)
	{
		while (counter <= 64)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					//creating special gem//
					if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j] && sleep == 1)
					{
						/*arr[i][j] = 69;
						arr[i+1][j] = 69;
						arr[i+2][j] = 69;
						arr[i+3][j] = 69;*/
						l = j;
						if (j >= 1 && i >= 1 && j <= 6 && i <= 6)
						{
							points = points + 9;
						}
						else
						{
							points = points + 6;
						}
						totalcount++;

						for (int k = i; k >= 0; k--)
						{

							swap(arr[k][j], arr[k - 1][j]);
							swap(arr[k + 1][j], arr[k][j]);
							swap(arr[k + 2][j], arr[k + 1][j]);
							flag++;
							printArray(arr);
							if (sleep == 1)
							{
								Sleep(1000);
							}

						}
						//replacing with random number 
						int n;
						n = 1 + (rand() % 5);
						arr[0][l] = n;
						n = 1 + (rand() % 5);
						arr[1][l] = n;
						n = 1 + (rand() % 5);
						arr[2][l] = n;
						arr[i + 3][j] = (arr[i + 3][j] + 5);
						printArray(arr);
					}
					//blasting special gem//
					else if ((arr[i][j] % 5) == (arr[i + 1][j] % 5) && (arr[i][j] % 5) == (arr[i + 2][j] % 5)&&(arr[i][j]>=6|| arr[i+1][j] >= 6|| arr[i+2][j] >= 6))
					{
						if ((arr[i][j] > 5) || (arr[i + 1][j] > 5) || (arr[i + 2][j]>5))
						{
							totalcount++;
							if (j >= 1 && i >= 1 && j <= 6 && i <= 6)
							{
								points = points + 9;
							}
							else
							{
								points = points + 6;
							}
							for (int k = i; k >= 0; k--)
							{
								swap(arr[k - 1][j], arr[k - 2][j]);
								swap(arr[k - 1][j + 1], arr[k - 2][j + 1]);
								swap(arr[k - 1][j + 2], arr[k - 2][j + 2]);
								swap(arr[k][j], arr[k - 1][j]);
								swap(arr[k][j + 1], arr[k - 1][j + 1]);
								swap(arr[k][j + 2], arr[k - 1][j + 2]);
								swap(arr[k + 1][j], arr[k][j]);
								swap(arr[k + 1][j + 1], arr[k][j + 1]);
								swap(arr[k + 1][j + 2], arr[k][j + 2]);
								printArray(arr);
								if (sleep == 1)
								{
									Sleep(1000);
								}

							}
							int n;
							n = 1 + (rand() % 5);
							arr[0][j] = n;
							n = 1 + (rand() % 5);
							arr[0][j + 1] = n;
							n = 1 + (rand() % 5);
							arr[0][j + 2] = n;
							n = 1 + (rand() % 5);
							arr[1][j] = n;
							n = 1 + (rand() % 5);
							arr[1][j + 1] = n;
							n = 1 + (rand() % 5);
							arr[1][j + 2] = n;
							n = 1 + (rand() % 5);
							arr[2][j] = n;
							n = 1 + (rand() % 5);
							arr[2][j + 1] = n;
							n = 1 + (rand() % 5);
							arr[2][j + 2] = n;
						}
					}
					//to check 3 in a row//
					else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j]&&arr[i][j]!=arr[i+3][j])

					{
						/*arr[i][j] = 69;
						arr[i + 1][j] = 69;
						arr[i + 2][j] = 69*/;

						l = j;
						points=points+3;
						totalcount++;
						
						for (int k = i; k >= 0; k--)
						{

							swap(arr[k][j], arr[k - 1][j]);
							swap(arr[k + 1][j], arr[k][j]);
							swap(arr[k + 2][j], arr[k + 1][j]);
							flag++;
							printArray(arr);
							if (sleep == 1)
							{
								Sleep(1000);
							}

						}
						//replacing with random number 
						int n;
						n = 1 + (rand() % 5);
						arr[0][l] = n;
						n = 1 + (rand() % 5);
						arr[1][l] = n;
						n = 1 + (rand() % 5);
						arr[2][l] = n;

					}

				}
			}
			counter++;

		}
	}
	//It will return whether there are 3/4 in a column//
	return totalcount;

}
void checkWhole(int arr[8][8], int xi, int yj, int& points, bool sleep, int& check)
{
	while (checkRepeatcolumms(arr, xi, yj, points, sleep) > 0 || checkRepeatRow(arr, xi, yj, points, sleep) > 0)
	{
		if (checkRepeatcolumms(arr, xi, yj, points, sleep) > 0)
		{
			check = checkRepeatcolumms(arr, xi, yj, points, sleep);
			checkRepeatcolumms(arr, xi, yj, points, sleep);
		}
		else if (checkRepeatRow(arr, xi, yj, points, sleep) > 0)
		{
			check = checkRepeatRow(arr, xi, yj, points, sleep);
			checkRepeatRow(arr, xi, yj, points, sleep);
		}
		else if (checkDestroyer(arr, points, sleep)==1)
		{
			check = checkDestroyer(arr, points, sleep);
			checkDestroyer(arr, points, sleep);
			
		}
		
	}
	printArray(arr);
}