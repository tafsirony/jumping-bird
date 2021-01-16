#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<mmsystem.h>
#include<glut.h>

#define pi (2*acos(0.0))

#define PI 3.1416

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
int a=0;
double angle;
double incx, incy;
int state,state1,state2,state3;
int tx,ty,tx1=-50,ty1=150,tx2=-60,ty2=-20,tx3,ty3,tx4=-14,ty4=15; //defining x,y for writing position
float tx5=150,ty5,tx6=300,ty6,tx7=-90,ty7=0,tx8=-10,ty8=16;

char txt1[100]="JUMPING BIRD";
char txt2[100]="PRESS SPACE TO START";
char txt3[100]="GAME OVER!";
char txt4[100]="SCORE : ";
double inc_ang=0.05;
int stop=0;
double score;
char msg[30];
char sc[30]="SCORE = ";

struct point
{
	double x,y,z;
};

void continuous()
{
    tx+=1;
    tx1-=1;
    tx2+=1;

    if(state ==0 && ty4>10){ state =1;}
    if(state ==1 && ty4<15){ state =0;}

    if(state==1) ty4-=3;
    if(state==0) ty4+=3;

    if(state1 ==0 && tx5 <-690){ state1 =1;}
    if(state1 ==1 && tx5==155 ){state1 =0;}

    if(state1==0) tx5-=0.2;
    if(state1==1){tx5=155;}

    if(state2 ==0 && tx6 <-250){ state2 =1;}
    if(state2 ==1 && tx6==100 ){state2 =0;}

    if(state2==0) tx6-=0.2;
    if(state2==1){tx6=100;}

    if(state3==0) {state3=1;}

    if(state3==1) {
                   ty7-=0.05;
                   }

    glutPostRedisplay();

}

void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
	}
}

void drawGrid()
{
	int i;
	if(drawgrid==1)
	{
		glColor3f(0.6, 0.6, 0.6);	//grey
		glBegin(GL_LINES);{
			for(i=-8;i<=8;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*10, -90, 0);
				glVertex3f(i*10,  90, 0);

				//lines parallel to X-axis
				glVertex3f(-90, i*10, 0);
				glVertex3f( 90, i*10, 0);
			}
		}glEnd();
	}
}

void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,2);
		glVertex3f( a,-a,2);
		glVertex3f(-a,-a,2);
		glVertex3f(-a, a,2);
	}glEnd();
}

void circle1(double radius,int segments) // eye white part
{
    int i;
    struct point points[100];
    float angle= 0.0;

        glBegin(GL_POLYGON);
        {
             for(i=0;i<100;i++){
                angle = 2*3.1416*i/100;
                glVertex3f(cos(angle)*radius,sin(angle)*segments,0);
            }
        }
        glEnd();

}
void circle2(double radius,int segments) // used for eye ball
{
     int i;
    struct point points[100];
    float angle= 0.0;

        glBegin(GL_POLYGON);
        {
             for(i=0;i<100;i++){
                angle = 2*3.1416*i/100;
                glVertex3f(cos(angle)*radius,sin(angle)*segments,0);
            }
        }
        glEnd();
}

void birdBody(double radius,int segments) //bird body
{
    int i;
    struct point points[100];
    glColor3f(0,0.5,0);
    float angle= 0.0;
        glBegin(GL_POLYGON);
        {
            for(i=0;i<100;i++){
                angle = 2*3.1416*i/100;
                glVertex3f(cos(angle)*radius,sin(angle)*segments,0);
            }

        }
        glEnd();
}
void tail()
{
      glColor3f(1,1,0);
        int i;
    struct point points[100];

    //position

        glBegin(GL_QUADS);
        {
        glVertex2f(-25,15);
        glVertex2f(-5,15);
        glVertex2f(-5,25);
        glVertex2f(-25,25);
        }
        glEnd();
}

void draw_rec()
{
    glColor3f(0,1,0);
   // glRotatef(2*angle,0,0,1);
   // continuous();
   // glTranslatef(tx,ty,0);
    //glRotatef(5*angle,0,0,1);
    drawSquare(10);

}
void pillar1()
{

glPushMatrix();

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);
    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();

     glPushMatrix();
    glTranslatef(60,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);
    }
    glEnd();

    glPopMatrix();

    glPopMatrix();

     glPushMatrix();
    glTranslatef(80,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

}
void pillar2()
{

    glPushMatrix();
    glTranslatef(360,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(170,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();

     glPushMatrix();
    glTranslatef(300,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();

     glPushMatrix();
    glTranslatef(280,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

    glPopMatrix();



}
void pillar3()
{

    glPushMatrix();
    glTranslatef(440,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();


    glPopMatrix();


    glPushMatrix();
    glTranslatef(340,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();


     glPushMatrix();
    glTranslatef(490,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();


    glPopMatrix();

    glPopMatrix();

     glPushMatrix();
    glTranslatef(210,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

}
void pillar4()
{
    glPushMatrix();

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();


    glPopMatrix();



    glPushMatrix();
    glTranslatef(-20,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();


     glPushMatrix();
    glTranslatef(60,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();

     glPushMatrix();
    glTranslatef(80,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

}
void drawSS()
{
    glColor3f(1,0,0);
    drawSquare(20);
    glPushMatrix();
    //glRotatef(angle,0,0,1);
    glTranslatef(110,0,0);
    //glRotatef(2*angle,0,0,1);
    glColor3f(0,1,0);
    drawSquare(15);
    //glPopMatrix();if(state ==2) incx-=0.1;
    glPushMatrix();
    {
//        glRotatef(angle,0,0,1);
        glTranslatef(60,0,0);
       // glRotatef(2*angle,0,0,1);
        glColor3f(0,0,1);
        drawSquare(10);
    }
    glPopMatrix();

}
void lip()
{
    glBegin(GL_POLYGON);
    {
        glColor3f(1,0,0);
        glVertex3f(6,16,0);
        glVertex3f(-1,16,0);
        glVertex3f(1,9,0);
        glVertex3f(-1,12,0);
    }
    glEnd();

}
void draw_bird_body()
{
    glPushMatrix();
    glTranslatef(tx3,ty3,0);

    glPushMatrix();
    glPushMatrix();
    glTranslatef(tx4,ty4,0);
    glRotatef(-290,10,30,0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-4,25,0);
    circle2(1,2); //bird eye ball
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1); // eye white
    glTranslatef(-4,25,0);
    circle1(3,5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-10,20,0);
    birdBody(10,15.); //bird body
    glPopMatrix();

    glPushMatrix();
    lip(); //lips
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,1);
    tail(); //tail
    glPopMatrix();

}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case 32: // ascii val of space
            glutIdleFunc(continuous);
			break;

		default:
			break;
	}
}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:
		    ty7-=8; 	//down arrow key

			cameraHeight -= 3.0;
			break;
		case GLUT_KEY_UP:
		    ty7+=8; // up arrow key

			cameraHeight += 3.0;

			break;

		case GLUT_KEY_RIGHT:
		    tx3+=15;

			//cameraAngle += 0.03;
			break;

		case GLUT_KEY_LEFT:
		    tx3-=5;
			cameraAngle -= 0.03;
			break;

		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;
        case 32:
            glutIdleFunc(continuous);
            break;

		default:
			break;
	}
}

void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				drawaxes=1-drawaxes;
			}
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}

void draw_text(const char *text,int length,int x,int y)
{
    glMatrixMode(GL_PROJECTION);
    double *matrix=new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX,matrix);
    glLoadIdentity();
    glOrtho(-400,500,-100,300,-5,5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i=0;text[i]!='\0';i++)
 {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(int)text[i]);
 }
   glPopMatrix();
   glMatrixMode(GL_PROJECTION);
   glLoadMatrixd(matrix);
   glMatrixMode(GL_MODELVIEW);

}

void clash()
{
    glPushMatrix();
    glColor3f(1,0,0);
    draw_text(txt3,100,-20,80); //text3= game over
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    draw_text(sc,100,-20,60); //score
    draw_text(msg,10,60,60); // score point
    glPopMatrix();
}

void loadGame()
{
    int num = 10;
    itoa(score,msg,10);//converting score into string : library

     if(stop==1)//when pillar touches
     {
         return clash();
     }
     if(ty7>=-10&&(tx5<=-173&&tx5>=-200))
     {
         stop=1;
     }
     if(ty7<=-25&&(tx5<=-151&&tx5>=-176))
     {
         stop=1;
     }
     if(ty7<=-63&&(tx5<=-230&&tx5>=-254))
     {
        stop=1;
     }
     if(ty7>=10&&(tx5<=-250&&tx5>=-274))
     {
         stop=1;
     }
     if(ty7<=-25&&(tx5<=-338&&tx5>=-374))
     {
        stop=1;
     }
     if(ty7>=20&&(tx5<=-382&&tx5>=-400))
     {
         stop=1;
     }
     if(ty7<=-65&&(tx5<=-472&&tx5>=-488))
     {
         stop=1;
     }
     if(ty7<=-20&&(tx5<=-512&&tx5>=-532))
     {
         stop=1;
     }
     if(ty7<=-65&&(tx5<=-660&&tx5>=-680))
     {
         stop=1;
     }
     if(ty7>=-6&&(tx5<=-529&&tx5>=-540))
     {
         stop=1;
     }
     if(ty7>=-13&&(tx5<=-611&&tx5>=-628))
     {
         stop=1;
     }
     if(ty7>=-20&&(tx5<=-380&&tx5>=-400))
     {
         stop=1;
     }
     if(ty7>=-10&&(tx5<=-450&&tx5>=-470))
     {
         stop=1;
     }

    glPushMatrix();

    glColor3f(1,1,1);
    draw_text(msg,100,-200,250); // message
    draw_text(sc,100,-280,250); // corner score

    glColor3f(1,1,0);
    draw_text(txt1,100,tx1,ty1); // text1 = jumping bird
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,1,0);
	glPopMatrix();

    glPushMatrix();
    glColor3f(1,0,0);
    draw_text(txt2,100,tx2,ty2);
    glPopMatrix();
    glPushMatrix();

    glPushMatrix();
    glTranslatef(tx7,ty7,0);
    draw_bird_body();
    glPopMatrix();

	glPopMatrix();

	glPushMatrix();

	score= score+.01;
	glTranslatef(tx5,ty5,0);
	glColor3f(1,1,1);
	pillar1();
	pillar2();
	pillar3();
    glPopMatrix();
}

void display(){

     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glClearColor(0.0,0.0,0.1,0); //background color

	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	gluLookAt(0,0,200,	0,0,0,	0,1,0);

	// select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	loadGame();

	glutSwapBuffers();
}

void init(){
	//codes for initialization
	drawgrid=0;
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=45;

	//clear the screen
    glClearColor(0,0,0,0);

	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(){
     sndPlaySound("music.wav" ,SND_ASYNC);
   // PlaySound(TEXT("music.wav"),NULL,SND_ASYNC);
   // Beep(314,1400);

	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(-500, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("Jumping bird");

	init();


	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseListener);
//    glutTimerFunc(1000,MyTimerFunc,0);


	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
