//# include "iGraphics.h"
//
//int x = 300, y = 300, r = 15;
//
///*
//	function iDraw() is called again and again by the system.
//*/
////void iDraw()
////{
////    //place your drawing codes here
////    iClear();
////    iSetColor(20,200,255);
////    iFilledCircle(x,y,r);
////}
//
///*
//	function iMouseMove() is called when the user presses and drags the mouse.
//	(mx, my) is the position where the mouse pointer is.
//*/
////void iMouseMove(int mx, int my)
////{
////    //printf("x = %d, y= %d\n",mx,my);
////    //place your codes here
////}
//
///*
//	function iMouse() is called when the user presses/releases the mouse.
//	(mx, my) is the position where the mouse pointer is.
//*/
////void iMouse(int button, int state, int mx, int my)
////{
////    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
////    {
////        //place your codes here
////        //printf("x = %d, y= %d\n",mx,my);
////        x += 5;
////        y += 5;
////
////    }
////    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
////    {
////        //place your codes here
////        x -= 5;
////        y -= 5;
////    }
////}
//
///*
//	function iKeyboard() is called whenever the user hits a key in keyboard.
//	key- holds the ASCII value of the key pressed.
//*/
//void iKeyboard(unsigned char key)
//{
//    if(key == 'q')
//    {
//        exit(0);
//    }
//    //place your codes for other keys here
//}
//
///*
//	function iSpecialKeyboard() is called whenver user hits special keys like-
//	function keys, home, end, pg up, pg down, arraows etc. you have to use
//	appropriate constants to detect them. A list is:
//	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
//	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
//	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
//	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
//*/
//void iSpecialKeyboard(unsigned char key)
//{
//
//    if(key == GLUT_KEY_END)
//    {
//        exit(0);
//    }
//    //place your codes for other keys here
//}
//
//
//int main()
//{
//    //place your own initialization codes here.
//    iInitialize(400, 400, "");
//    return 0;
//}

//
//  author: Saifur Rahman
//	last modified: 17 July, 2019
//
# include "iGraphics.h"
# include "gl.h"

#define N_PLANETS 9

int sunX, sunY, sunR;

int planetMajorAxisLen[N_PLANETS];
int planetMinorAxisLen[N_PLANETS];
int planetRadius[N_PLANETS];
int planetSweepAngle[N_PLANETS];
int planetDelSweepAngle[N_PLANETS];

int satelliteOrbitR, satelliteR, satelliteSweepAngle=0;

void drawSun(int x, int y, int r) {
    iSetColor(255, 150, 0);
    iFilledCircle(x, y, r);
}

void drawOrbit(int x, int y, int a, int b) {
    iSetColor(255, 255, 255);
    iEllipse(x, y, a, b);
}

void drawPlanet(int x, int y, int orbitA, int orbitB, int planetR, int sweepAngle) {
    double pi = 2*acos(0);
    double sweepRadian = sweepAngle * pi / 180;
    int planetX = x + orbitA * cos(sweepRadian);
    int planetY = y + orbitB * sin(sweepRadian);
    iFilledCircle(planetX, planetY, planetR);
}

void drawSatellite(
    int x,
    int y,
    int planetOrbitA,
    int planetOrbitB,
    int planetSweepAngle,
    int satelliteOrbitR,
    int satelliteR,
    int satelliteSweepAngle) {
    double pi = 2*acos(0);
    double planetSweepRadian = planetSweepAngle * pi / 180;
    double satelliteSweepRadian = satelliteSweepAngle * pi / 180;

//    int planetX = x + planetOrbitA * cos(planetSweepRadian);
//    int planetY = y + planetOrbitB * sin(planetSweepRadian);

    int satelliteX =  x + planetOrbitA * cos(planetSweepRadian) + satelliteOrbitR * cos(satelliteSweepRadian);
    int satelliteY = y + planetOrbitB * sin(planetSweepRadian) + satelliteOrbitR * sin(satelliteSweepRadian);

    iSetColor(62, 62, 62);
    iFilledCircle(satelliteX, satelliteY, satelliteR);
}

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	double centerX, centerY;
	int i;

	iClear();

	//
	// The sun is at the left focal point of the eliptical orbit. So, the center of orbit
	// needs to be translated appropriately.
	//

	drawSun(sunX, sunY, sunR);

	for (i = 0; i < N_PLANETS; i++) {
        centerX = sunX + sqrt(pow(planetMajorAxisLen[i], 2) - pow(planetMinorAxisLen[i], 2));
        centerY = sunY;
        drawOrbit(centerX, centerY, planetMajorAxisLen[i], planetMinorAxisLen[i]);
        drawPlanet(
            centerX,
            centerY,
            planetMajorAxisLen[i],
            planetMinorAxisLen[i],
            planetRadius[i],
            planetSweepAngle[i]
            );
        if (i == 2) {
            drawSatellite(
                centerX,
                centerY,
                planetMajorAxisLen[i],
                planetMinorAxisLen[i],
                planetSweepAngle[i],
                satelliteOrbitR,
                satelliteR,
                satelliteSweepAngle
                );
        }

        if (i == 3) {
            drawSatellite(
                centerX,
                centerY,
                planetMajorAxisLen[i],
                planetMinorAxisLen[i],
                planetSweepAngle[i],
                satelliteOrbitR,
                satelliteR,
                satelliteSweepAngle
                );

            drawSatellite(
                centerX,
                centerY,
                planetMajorAxisLen[i],
                planetMinorAxisLen[i],
                planetSweepAngle[i]+10,
                satelliteOrbitR,
                satelliteR,
                satelliteSweepAngle
                );
        }
	}
	iSetColor(255, 255, 255);
	iText(10, 10, "Press p for pause, r for resume, END for exit.");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
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

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

void movePlanets(){
    const int dSatelliteSweepAngle = 10;

    int i;

    for (i = 0; i < N_PLANETS; i++) {
        planetSweepAngle[i] = (planetSweepAngle[i] + planetDelSweepAngle[i])%360;
        satelliteSweepAngle = (satelliteSweepAngle + dSatelliteSweepAngle)%360;
    }
}

int main()
{
    const int CX_MAX = 1366;
    const int CY_MAX = 768;

    // Initialize Sun's position and size.
    sunX = 150;
    sunY = CY_MAX/2;
    sunR = 40;

    planetMajorAxisLen[0] = 160;
    planetMinorAxisLen[0] = 120;
    planetRadius[0] = 7;
    planetSweepAngle[0] = 0;
    planetDelSweepAngle[0] = 3;

    planetMajorAxisLen[1] = 200;
    planetMinorAxisLen[1] = 150;
    planetRadius[1] = 10;
    planetSweepAngle[1] = 0;
    planetDelSweepAngle[1] = 1;

    planetMajorAxisLen[2] = 240;
    planetMinorAxisLen[2] = 180;
    planetRadius[2] = 12;
    planetSweepAngle[2] = 0;
    planetDelSweepAngle[2] = 4;

    planetMajorAxisLen[3] = 290;
    planetMinorAxisLen[3] = 210;
    planetRadius[3] = 8;
    planetSweepAngle[3] = 0;
    planetDelSweepAngle[3] = 3;

    planetMajorAxisLen[4] = 360;
    planetMinorAxisLen[4] = 260;
    planetRadius[4] = 20;
    planetSweepAngle[4] = 0;
    planetDelSweepAngle[4] = 5;

    planetMajorAxisLen[5] = 410;
    planetMinorAxisLen[5] = 300;
    planetRadius[5] = 16;
    planetSweepAngle[5] = 0;
    planetDelSweepAngle[5] = 4;

    planetMajorAxisLen[6] = 460;
    planetMinorAxisLen[6] = 335;
    planetRadius[6] = 14;
    planetSweepAngle[6] = 0;
    planetDelSweepAngle[6] = 3;

    planetMajorAxisLen[7] = 500;
    planetMinorAxisLen[7] = 365;
    planetRadius[7] = 13;
    planetSweepAngle[7] = 0;
    planetDelSweepAngle[7] = 5;

    planetMajorAxisLen[8] = 540;
    planetMinorAxisLen[8] = 395;
    planetRadius[8] = 5;
    planetSweepAngle[8] = 0;
    planetDelSweepAngle[8] = 4;

    // Initialize moon's orbit and radius
    satelliteOrbitR = 20;
    satelliteR = 5;

	//place your own initialization codes here.
	iShowBMP(0,0,"space.bmp");
	iSetTimer(7, movePlanets);
	iInitialize(CX_MAX, CY_MAX, "Solar system!");

	return 0;
}


