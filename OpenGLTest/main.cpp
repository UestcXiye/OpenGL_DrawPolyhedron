// 三维变换.cpp : 定义控制台应用程序的入口点。
#include <GL/glut.h>  
#include <stdlib.h> 
using namespace std;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //背景黑色 
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); //画笔白色  

	glLoadIdentity();  //加载单位矩阵  

	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutSolidOctahedron();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void myKeyboard(unsigned char key, int x, int y)
{
	glMatrixMode(GL_MODELVIEW);
	glMatrixMode(GL_PROJECTION);
	switch (key)
	{
	case 'a': case 'A': glTranslated(-0.1, 0, 0); break;     //向左平移0.1
	case 'd': case 'D': glTranslated(0.1, 0, 0); break;     //向右平移0.1
	case 'w': case 'W': glTranslated(0, 0.1, 0); break;     //向上平移0.1
	case 's': case 'S': glTranslated(0, -0.1, 0); break;     //向下平移0.1
	case 'q': case 'Q': glTranslated(0, 0, 0.1); break;     //向外平移0.1
	case 'e': case 'E': glTranslated(0, 0, -0.1); break;     //向里平移0.1

	case 'j': case 'J': glRotated(10, 0, 1, 0); break;      //绕y轴旋转10度
	case 'l': case 'L': glRotated(10, 0, -1, 0); break;
	case 'i': case 'I': glRotated(10, 1, 0, 0); break;      //绕x轴旋转10度
	case 'k': case 'K': glRotated(10, -1, 0, 0); break;
	case 'u': case 'U': glRotated(10, 0, 0, 1); break;      //绕z轴旋转10度
	case 'o': case 'O': glRotated(10, 0, 0, -1); break;

	case 'z': case 'Z': glScalef(1.5, 1.5, 1.5); break;         //放大
	case 'x': case 'X': glScalef(0.5, 0.5, 0.5); break;         //缩小

	default: break;
	}

	glutPostRedisplay();      //重新绘制
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutWireIcosahedron();
	//glTranslated(0, 0, 0);
	glFlush();
	glutSwapBuffers();      //显示刚才绘制的图像，双缓冲
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutKeyboardFunc(myKeyboard);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}

