// ��ά�任.cpp : �������̨Ӧ�ó������ڵ㡣
#include <GL/glut.h>  
#include <stdlib.h> 
using namespace std;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //������ɫ 
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); //���ʰ�ɫ  

	glLoadIdentity();  //���ص�λ����  

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
	case 'a': case 'A': glTranslated(-0.1, 0, 0); break;     //����ƽ��0.1
	case 'd': case 'D': glTranslated(0.1, 0, 0); break;     //����ƽ��0.1
	case 'w': case 'W': glTranslated(0, 0.1, 0); break;     //����ƽ��0.1
	case 's': case 'S': glTranslated(0, -0.1, 0); break;     //����ƽ��0.1
	case 'q': case 'Q': glTranslated(0, 0, 0.1); break;     //����ƽ��0.1
	case 'e': case 'E': glTranslated(0, 0, -0.1); break;     //����ƽ��0.1

	case 'j': case 'J': glRotated(10, 0, 1, 0); break;      //��y����ת10��
	case 'l': case 'L': glRotated(10, 0, -1, 0); break;
	case 'i': case 'I': glRotated(10, 1, 0, 0); break;      //��x����ת10��
	case 'k': case 'K': glRotated(10, -1, 0, 0); break;
	case 'u': case 'U': glRotated(10, 0, 0, 1); break;      //��z����ת10��
	case 'o': case 'O': glRotated(10, 0, 0, -1); break;

	case 'z': case 'Z': glScalef(1.5, 1.5, 1.5); break;         //�Ŵ�
	case 'x': case 'X': glScalef(0.5, 0.5, 0.5); break;         //��С

	default: break;
	}

	glutPostRedisplay();      //���»���
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutWireIcosahedron();
	//glTranslated(0, 0, 0);
	glFlush();
	glutSwapBuffers();      //��ʾ�ղŻ��Ƶ�ͼ��˫����
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

