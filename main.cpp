#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

// ID's de ventana principal y subventanas
GLint mainWindow,
	subWindow1, subWindow2, subWindow3,
	subWindow4, subWindow5, subWindow6,
	subWindow7, subWindow8, subWindow9,
	subWindow10, subWindow11, subWindow12,
	subWindow13, subWindow14, subWindow15,
	subWindow16, subWindow17, subWindow18,
	subWindow19;

GLint windowToRender;

// Tamaño de la ventana principal
GLint width = 800;
GLint height = 600;

// Parámetros de la cámara virtual 1
GLint mouseButton = 0;
GLboolean mouseRotate = false;
GLboolean mouseZoom = false;
GLboolean mousePan = false;
GLint xClick = 0;
GLint yClick = 0;
GLint xAux = 0;
GLint yAux = 0;
GLfloat rotX = 0.f;
GLfloat rotY = 0.f;
GLfloat panX = 0.f;
GLfloat panY = 0.f;
GLfloat zoomZ = -10.f;

// Parámetros de las herramientas
GLint mouseButtonT = 0;
GLboolean mouseRotateT = false;
GLboolean mouseZoomT = false;
GLboolean mousePanT = false;
GLint xClickT = 0;
GLint yClickT = 0;
GLint xAuxT = 0;
GLint yAuxT = 0;
GLfloat rotXT = 0.f;
GLfloat rotYT = 0.f;
GLfloat panXT = 0.f;
GLfloat panYT = 0.f;
GLfloat zoomZT = -10.f;

bool filled = false;
int figura = 0;

/*
0 = Sin figura
1 = Ya tiene figura
2 = Pintando (marcó el primer punto, le falta segundo punto)
3 = Crear segundo punto, cierra
	esfera,
	cubo, toroide,
	octaedro
	dodecaedro, icosaedro
	tetera, disco,
	linea
4 = Crear tercer punto, cierra
	cono,
	piramide,
	triangulo,
	piramide rectangular,

5 = Crear cuarto punto, cierra
	Quad
*/
int estado = 0;

char estadoDeCambio = 'p';
/*
	p = pos
	r = rot
	s = sca
*/

int index = 0;
double figurasArray [15][20];
int arraySize = 15;
		/*
		indice
		0	tipo de figura
		1	posX
		2	posY
		3	posZ

		4	rotX
		5	rotY
		6	rotZ

		7	scaX
		8	scaY
		9	scaZ

		10  puntoX1
		11  puntoY1
		12  puntoZ1

		13  puntoX2
		14  puntoY2
		15  puntoZ2

		16  puntoX3
		17  puntoY3
		18  puntoZ3

		19 filled (1 verdadero 0)
		*/

// Función que recarga las subventanas de herramientas
void reloadTools(){
	glutSetWindow(subWindow2);
	glutPostRedisplay();
	glutSetWindow(subWindow3);
	glutPostRedisplay();
	glutSetWindow(subWindow4);
	glutPostRedisplay();
	glutSetWindow(subWindow5);
	glutPostRedisplay();
	glutSetWindow(subWindow6);
	glutPostRedisplay();
	glutSetWindow(subWindow7);
	glutPostRedisplay();
	glutSetWindow(subWindow8);
	glutPostRedisplay();
	glutSetWindow(subWindow9);
	glutPostRedisplay();
	glutSetWindow(subWindow10);
	glutPostRedisplay();
	glutSetWindow(subWindow11);
	glutPostRedisplay();
	glutSetWindow(subWindow12);
	glutPostRedisplay();
	glutSetWindow(subWindow13);
	glutPostRedisplay();
	glutSetWindow(subWindow14);
	glutPostRedisplay();
	glutSetWindow(subWindow15);
	glutPostRedisplay();
	glutSetWindow(subWindow16);
	glutPostRedisplay();
	glutSetWindow(subWindow17);
	glutPostRedisplay();
	glutSetWindow(subWindow18);
	glutPostRedisplay();
	glutSetWindow(subWindow19);
	glutPostRedisplay();
}

// Función que se invoca cada vez que se redimensiona la ventana
void resize(GLint w, GLint h)
{
	width = w;
	height = h;
	
	//La ventana principal
	glutSetWindow(subWindow1);
	glutPositionWindow(width /4, 0);
	glutReshapeWindow(width * 3/4, height);

	//Herramientas
	glutSetWindow(subWindow2);
	glutPositionWindow(0, 0);
	glutReshapeWindow(width /8, height /9);

	glutSetWindow(subWindow3);
	glutPositionWindow(width/8, 0);
	glutReshapeWindow(width /8, height /9);

	glutSetWindow(subWindow4);
	glutPositionWindow(0, height /9);
	glutReshapeWindow(width /8, height /9);	
	
	glutSetWindow(subWindow5);
	glutPositionWindow(width/8, height /9);
	glutReshapeWindow(width /8, height /9);		

	glutSetWindow(subWindow6);
	glutPositionWindow(0, height *2/9);
	glutReshapeWindow(width /8, height /9);

	glutSetWindow(subWindow7);
	glutPositionWindow(width/8, height *2/9);
	glutReshapeWindow(width /8, height /9);		

	glutSetWindow(subWindow8);
	glutPositionWindow(0, height *3/9);
	glutReshapeWindow(width /8, height /9);	

	glutSetWindow(subWindow9);
	glutPositionWindow(width/8, height *3/9);
	glutReshapeWindow(width /8, height /9);		

	glutSetWindow(subWindow10);
	glutPositionWindow(0, height *4/9);
	glutReshapeWindow(width /8, height /9);	

	glutSetWindow(subWindow11);
	glutPositionWindow(width/8, height *4/9);
	glutReshapeWindow(width /8, height /9);		

	glutSetWindow(subWindow12);
	glutPositionWindow(0, height *5/9);
	glutReshapeWindow(width /8, height /9);		

	glutSetWindow(subWindow13);
	glutPositionWindow(width/8, height *5/9);
	glutReshapeWindow(width /8, height /9);		

	glutSetWindow(subWindow14);
	glutPositionWindow(0, height *6/9);
	glutReshapeWindow(width /8, height /9);	

	glutSetWindow(subWindow15);
	glutPositionWindow(width/8, height *6/9);
	glutReshapeWindow(width /8, height /9);		

	glutSetWindow(subWindow16);
	glutPositionWindow(0, height *7/9);
	glutReshapeWindow(width /8, height /9);	

	glutSetWindow(subWindow17);
	glutPositionWindow(width/8, height *7/9);
	glutReshapeWindow(width /8, height /9);		

	glutSetWindow(subWindow18);
	glutPositionWindow(0, height *8/9);
	glutReshapeWindow(width /8, height /9);	

	glutSetWindow(subWindow19);
	glutPositionWindow(width/8, height *8/9);
	glutReshapeWindow(width /8, height /9);

	reloadTools();		
}

// Función que se invoca cada vez que se redimensiona la ventana
void resizeTool(GLint w, GLint h)
{
	if (h == 0)
	{
		h = 1;
	}
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.f, (float)w / h, 0.1f, 1000.f);		// Transf. de Proyección en Perspectiva
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h);								// Transf. de Viewport (mapeo al área de dibujo)
}

// Geometría sistema coordenado
void geomCoordSys(GLfloat size)
{
	float currentColor[4];
	glGetFloatv(GL_CURRENT_COLOR, currentColor);

	// Eje X (Rojo)
	glColor3f(1., 0., 0.);
	glBegin(GL_LINES);
	glVertex3f(0., 0., 0.);
	glVertex3f(size, 0., 0.);
	glEnd();

	// Eje Y (Verde))
	glColor3f(0., 1., 0.);
	glBegin(GL_LINES);
	glVertex3f(0., 0., 0.);
	glVertex3f(0., size, 0.);
	glEnd();

	// Eje Z (Azul)
	glColor3f(0., 0., 1.);
	glBegin(GL_LINES);
	glVertex3f(0., 0., 0.);
	glVertex3f(0., 0., size);
	glEnd();
	glColor3f(currentColor[0], currentColor[1], currentColor[2]);
}

// Función que se invoca cada vez que se dibuja
void render()
{
	glutSetWindow(mainWindow);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Se limpian los buffers con el color activo definido por glClearColor
	glutSwapBuffers();			// Se intercambian buffers
}


void drawMain(){
	glutSetWindow(subWindow1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Transformación de vista
	glTranslatef(panX, panY, zoomZ);
	glRotatef(rotY, 1.0, 0.0, 0.0);
	glRotatef(rotX, 0.0, 1.0, 0.0);

	geomCoordSys(2.f);

	for(int i=0; i<15; i++){
		glPushMatrix();
		glTranslatef(	GLfloat(figurasArray[i][1]/300),
						GLfloat(figurasArray[i][2]/300),
						GLfloat(figurasArray[i][3])/300);

		glRotatef(	GLfloat(figurasArray[i][4]), 1.0, 0.0, 0.0);
		glRotatef(	GLfloat(figurasArray[i][5]), 0.0, 1.0, 0.0);
		glRotatef(	GLfloat(figurasArray[i][6]), 0.0, 0.0, 1.0);

		glScalef(	GLfloat(figurasArray[i][7]),
					GLfloat(figurasArray[i][8]),
					GLfloat(figurasArray[i][9]));

		if(index == i){
			glColor3f(0.8, 0.2, 0.1);
		}else{
			glColor3f(1.0, 1.0, 1.0);
		}

		for(int debugIndex = 0; debugIndex<20; debugIndex++){
			if(figurasArray[i][0]!=0){
				cout << "i: "<< figurasArray[i][debugIndex] << endl;
			}
		}

		if(figurasArray[i][0] == 1){
			//Esfera
			if(figurasArray[i][19]==1){
				glutSolidSphere(1.0, 20, 10);
			}else{
				glutWireSphere(1.0, 20, 10);			
			}

		}else if(figurasArray[i][0] == 2){
			//Cono
			if(figurasArray[i][19]==1){
				glutSolidCone(1.0, 1.0, 20, 10);
			}else{
				glutWireCone(1.0, 1.0, 20, 10);
			}

		}else if(figurasArray[i][0] == 3){
			//Cubo
			if(figurasArray[i][19]==1){
				glutSolidCube(1);
			}else{
				glutWireCube(1);
			}

		}else if(figurasArray[i][0] == 4){
			//Toroide
			if(figurasArray[i][19]==1){
				glutSolidTorus(0.7, 1.4, 5, 25);
			}else{
				glutWireTorus(0.7, 1.4,  5, 25);
			}

		}else if(figurasArray[i][0] == 5){
			//Piramide (Tetraedro)
			if(figurasArray[i][19]==1){
				glutSolidTetrahedron();
			}else{
				glutWireTetrahedron();
			}

		}else if(figurasArray[i][0] == 6){
			//Octaedro
			if(figurasArray[i][19]==1){
				glutSolidOctahedron();
			}else{
				glutWireOctahedron();
			}

		}else if(figurasArray[i][0] == 7){
			//Dodecahedro
			if(figurasArray[i][19]==1){
				glutSolidDodecahedron();
			}else{
				glutWireDodecahedron();
			}

		}else if(figurasArray[i][0] == 8){
			//Icosaedro
			if(figurasArray[i][19]==1){
				glutSolidIcosahedron();
			}else{
				glutWireIcosahedron();
			}

		}else if(figurasArray[i][0] == 9){
			//Tetera				
			if(figurasArray[i][19]==1){
				glutSolidTeapot(0.5);			
			}else{
				glutWireTeapot(0.5);			
			}	

		}else if(figurasArray[i][0] == 10){
			//Cilindro
			glRotatef(-90, 1.f, 0.f, 0.f);				
			if(figurasArray[i][19]==1){
				glutSolidCylinder (1.0, 2.0, 20, 10);
			}else{
				glutWireCylinder (1.0, 2.0,  20, 10);
			}			

		}else if(figurasArray[i][0] == 11){
			//Disco
			glScalef(1.f, 1.f, 0.f);	
			glutSolidTorus(0.7, 1.2, 10, 50);

		}else if(figurasArray[i][0] == 12){
			//Puntos
			glScalef(0.2f, 0.2f, 0.f);
			glutSolidSphere(1.0, 20, 2);

		}else if(figurasArray[i][0] == 13){
			//Linea
			glBegin(GL_LINES);
				glVertex3f(	GLfloat(figurasArray[i][10]),
							GLfloat(figurasArray[i][11]),
							GLfloat(figurasArray[i][12]));

				glVertex3f(	GLfloat(figurasArray[i][13]),
							GLfloat(figurasArray[i][14]),
							GLfloat(figurasArray[i][15]));
			glEnd();	

		}else if(figurasArray[i][0] == 14){
			//Triangulo
			if(figurasArray[i][19]==1){
				glBegin(GL_TRIANGLES);
				glVertex3f(	GLfloat(figurasArray[i][10]),
							GLfloat(figurasArray[i][11]),
							GLfloat(figurasArray[i][12]));

				glVertex3f(	GLfloat(figurasArray[i][13]),
							GLfloat(figurasArray[i][14]),
							GLfloat(figurasArray[i][15]));

				glVertex3f(	GLfloat(figurasArray[i][16]),
							GLfloat(figurasArray[i][17]),
							GLfloat(figurasArray[i][18]));
			    glEnd();
			}else{
				glBegin(GL_LINES);
					glVertex3f(	GLfloat(figurasArray[i][10]),
								GLfloat(figurasArray[i][11]),
								GLfloat(figurasArray[i][12]));
					glVertex3f(	GLfloat(figurasArray[i][13]),
								GLfloat(figurasArray[i][14]),
								GLfloat(figurasArray[i][15]));
				glEnd();	
			    glBegin(GL_LINES);
					glVertex3f(	GLfloat(figurasArray[i][10]),
								GLfloat(figurasArray[i][11]),
								GLfloat(figurasArray[i][12]));
					glVertex3f(	GLfloat(figurasArray[i][16]),
								GLfloat(figurasArray[i][17]),
								GLfloat(figurasArray[i][18]));
				glEnd();	
				glBegin(GL_LINES);
					glVertex3f(	GLfloat(figurasArray[i][13]),
								GLfloat(figurasArray[i][14]),
								GLfloat(figurasArray[i][15]));
					glVertex3f(	GLfloat(figurasArray[i][16]),
								GLfloat(figurasArray[i][17]),
								GLfloat(figurasArray[i][18]));
				glEnd();	
			}			

		}else if(figurasArray[i][0] == 15){
			//Quad
			glScalef(.1f,.1f,.1f);
			if(figurasArray[i][19]==1){
				glBegin(GL_TRIANGLES);
					glVertex3f(	GLfloat(figurasArray[i][10]),
								GLfloat(figurasArray[i][11]),
								GLfloat(figurasArray[i][12]));

					glVertex3f(	GLfloat(figurasArray[i][13]),
								GLfloat(figurasArray[i][14]),
								GLfloat(figurasArray[i][15]));

					glVertex3f(	GLfloat(figurasArray[i][16]),
								GLfloat(figurasArray[i][17]),
								GLfloat(figurasArray[i][18]));
	    		glEnd(); 			
			}else{
				glBegin(GL_LINES);
					glVertex3f(	GLfloat(figurasArray[i][10]),
								GLfloat(figurasArray[i][11]),
								GLfloat(figurasArray[i][12]));
					glVertex3f(	GLfloat(figurasArray[i][13]),
								GLfloat(figurasArray[i][14]),
								GLfloat(figurasArray[i][15]));
				glEnd();			
			}

		}else if(figurasArray[i][0] == 16){
			int piramidHeight = figurasArray[i][11] - figurasArray[i][14];
			if (piramidHeight < 0){
				piramidHeight = piramidHeight * -1;
				glRotatef(180, 0.0, 1.0, 0.0);
			}
			piramidHeight = piramidHeight/10;

			int piramidWidth = figurasArray[i][13] - figurasArray[i][16];
			if (piramidWidth < 0){
				piramidWidth = piramidWidth * -1;
				glRotatef(180, 1.0, 0.0, 0.0);
			}
			piramidWidth = piramidWidth/10;

			piramidWidth = 1;
			piramidHeight = 1;

			glBegin(GL_LINES);
				glVertex3f(	GLfloat(figurasArray[i][10]),
					GLfloat(figurasArray[i][11]),
					GLfloat(figurasArray[i][12]));

				glVertex3f(	GLfloat(figurasArray[i][10]) + width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])+width);
			glEnd();

			glBegin(GL_LINES);
				glVertex3f(	GLfloat(figurasArray[i][10]),
					GLfloat(figurasArray[i][11]),
					GLfloat(figurasArray[i][12]));

				glVertex3f(	GLfloat(figurasArray[i][10]) + width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])-width);
			glEnd();

			glBegin(GL_LINES);
				glVertex3f(	GLfloat(figurasArray[i][10]),
					GLfloat(figurasArray[i][11]),
					GLfloat(figurasArray[i][12]));

				glVertex3f(	GLfloat(figurasArray[i][10]) - width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])+width);
			glEnd();	

			glBegin(GL_LINES);
				glVertex3f(	GLfloat(figurasArray[i][10]),
					GLfloat(figurasArray[i][11]),
					GLfloat(figurasArray[i][12]));

				glVertex3f(	GLfloat(figurasArray[i][10]) - width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])-width);
			glEnd();		

			glBegin(GL_LINES);
				glVertex3f(	GLfloat(figurasArray[i][10]) + width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])+width);

				glVertex3f(	GLfloat(figurasArray[i][10]) + width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])-width);
			glEnd();

			glBegin(GL_LINES);
				glVertex3f(	GLfloat(figurasArray[i][10]) + width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])-width);

				glVertex3f(	GLfloat(figurasArray[i][10]) - width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])-width);
			glEnd();

			glBegin(GL_LINES);
				glVertex3f(	GLfloat(figurasArray[i][10]) - width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])-width);

				glVertex3f(	GLfloat(figurasArray[i][10]) - width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])+width);
			glEnd();

			glBegin(GL_LINES);
				glVertex3f(	GLfloat(figurasArray[i][10]) - width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])+width);

				glVertex3f(	GLfloat(figurasArray[i][10]) + width,
					GLfloat(figurasArray[i][11]-height),
					GLfloat(figurasArray[i][12])+width);
			glEnd();

		}else{

		}
		glPopMatrix();
	}
	//glutPostRedisplay();
}

// Función que se invoca para dibujar las herramientas
void renderTool()
{
	// windowToRender es una variable global cuyo valor es alterado y es ejecutado sólo por las ventanas
	glutSetWindow(windowToRender);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Transformación de vista
	glTranslatef(panXT, panYT, zoomZT);
	glRotatef(rotYT, 1.0, 0.0, 0.0);
	glRotatef(rotXT, 0.0, 1.0, 0.0);

	int slice;
	int stacks;

	if(windowToRender == subWindow1){
		// Escena
		geomCoordSys(2.f);
		drawMain();
		//cout << index << endl;
	}
	else if(windowToRender == subWindow2){
		slice = 20;
		stacks = 2;
		glPushMatrix();
		glColor3f(0.1, 0.2, 0.8);
		glScalef(1.5f, 1.5f, 1.5f);
		if(filled){
			glutSolidSphere(1.0, slice, stacks);
		}else{
			glutWireSphere(1.0, slice, stacks);			
		}
		glPopMatrix();

	}else if(windowToRender == subWindow3){
		slice = 20;
		stacks = 10;
		glPushMatrix();
		glColor3f(0.2, 0.8, 0.1);
		glScalef(2.0f, 2.0f, 2.0f);
		glTranslatef(0.f, 0.2f, 0.f);
		glRotatef(70, 1.0, 0.0, 0.0);
		if(filled){
			glutSolidCone(1.0, 1.0, slice, stacks);
		}else{
			glutWireCone(1.0, 1.0, slice, stacks);
		}	
		glPopMatrix();

	}else if(windowToRender == subWindow4){
		glPushMatrix();
		glColor3f(1.0, 1.0, 0.0);
		glScalef(2.0f, 2.0f, 2.0f);
		glRotatef(30, 0.0, 1.0, 0.0);
		glRotatef(15, 1.0, 0.0, 0.0);
		glRotatef(10, 0.0, 0.0, 1.0);
		if(filled){
			glutSolidCube(1);
		}else{
			glutWireCube(1);
		}		
		glPopMatrix();

	}else if(windowToRender == subWindow5){
		slice = 5;
		stacks = 25;
		glPushMatrix();
		glColor3f(0.8, 0.2, 0.1);		
		glRotatef(10, 1.0, 0.0, 0.0);	
		if(filled){
			glutSolidTorus(0.7, 1.4, slice, stacks);
		}else{
			glutWireTorus(0.7, 1.4, slice, stacks);
		}
		glPopMatrix();

	}else if(windowToRender == subWindow6){
		glPushMatrix();
		glColor3f(0.7, 1.0, 1.0);
		glScalef(2.0f, 2.0f, 2.0f);
		glRotatef(-30, 0.0, 1.0, 0.0);	
		glRotatef(-10, 1.0, 0.0, 0.0);	
		glTranslatef(0.f, -0.3f, 0.f);
		//glColor3f(0.8, 0.2, 0.1);
		//Tiene originalmente un radio de 3^1/2 (Raiz de 3)		
		if(filled){
			glutSolidTetrahedron();
		}else{
			glutWireTetrahedron();
		}
		glPopMatrix();

	}else if(windowToRender == subWindow7){
		glPushMatrix();
		glColor3f(1.0, 0.7, 1.0);
		glScalef(1.7f, 1.7f, 1.7f);
		glRotatef(-17, 0.0, 1.0, 0.0);	
		glRotatef(-15, 1.0, 0.0, 0.0);	
		glTranslatef(0.f, -0.2f, 0.f);
		//glColor3f(0.8, 0.2, 0.1);
		//Tiene originalmente vertices de tamaño 1	
		if(filled){
			glutSolidOctahedron();
		}else{
			glutWireOctahedron();
		}	
		glPopMatrix();		

	}else if(windowToRender == subWindow8){
		//Tiene originalmente un radio de 3^1/2 (Raiz de 3)	
		glColor3f(0.7, 1.0, 0.7);
		if(filled){
			glutSolidDodecahedron();
		}else{
			glutWireDodecahedron();
		}	

	}else if(windowToRender == subWindow9){
		glPushMatrix();
		glColor3f(0.8, 0.8, 0.2);
		glScalef(1.7f, 1.7f, 1.7f);
		glRotatef(-29, 0.0, 0.0, 1.0);	
		//glColor3f(0.8, 0.2, 0.1);
		//Tiene originalmente vertices de tamaño 1	
		if(filled){
			glutSolidIcosahedron();
		}else{
			glutWireIcosahedron();
		}	
		glPopMatrix();	

	}else if(windowToRender == subWindow10){
		glPushMatrix();
		glColor3f(0.5, 1.0, 1.0);
		glTranslatef(0.f, -0.2f, 0.f);
		if(filled){
			glutSolidTeapot(1.2);			
		}else{
			glutWireTeapot(1.2);			
		}
		glPopMatrix();

	}else if(windowToRender == subWindow11){
		slice = 20;
		stacks = 10;
		glPushMatrix();
		glColor3f(0.4, 0.2, 0.15);
		glTranslatef(0.f, -1.0f, 0.f);
		glScalef(1.2f, 1.2f, 1.2f);
		glRotatef(-55, 1.f, 0.f, 0.f);
		if(filled){
			glutSolidCylinder (1.0, 2.0, slice,  stacks);
		}else{
			glutWireCylinder (1.0, 2.0, slice,  stacks);
		}
		glPopMatrix();

	}else if(windowToRender == subWindow12){
		slice = 10;
		stacks = 50;
		glPushMatrix();
		glScalef(0.8f, 0.8f, 0.f);
		glRotatef(10, 1.0, 0.0, 0.0);	
		glutSolidTorus(0.7, 1.2, slice, stacks);		
		glPopMatrix();

	}else if(windowToRender == subWindow13){
		//Puntos
		slice = 20;
		stacks = 2;
		glPushMatrix();
		glScalef(0.2f, 0.2f, 0.f);
		glTranslatef(-5.f, 0.f, 0.f);

		glTranslatef(0.f, 4.0f, 0.f);
		glutSolidSphere(1.0, slice, stacks);
		
		glTranslatef(6.f, -5.0f, 0.f);
		glutSolidSphere(1.0, slice, stacks);
		
		glTranslatef(4.f, 2.5f, 0.f);
		glutSolidSphere(1.0, slice, stacks);

		glTranslatef(-10.f, -7.f, 0.f);
		glutSolidSphere(1.0, slice, stacks);

		glTranslatef(3.f, -2.f, 0.f);
		glutSolidSphere(1.0, slice, stacks);

		glPopMatrix();

	}else if(windowToRender == subWindow14){
		//Linea
		slice = 10;
		stacks = 50;
		glPushMatrix();
		glBegin(GL_LINES);
			glVertex3f(-3., -3., 0.);
			glVertex3f(3., 3., 0.);
		glEnd();		
		glPopMatrix();

	}else if(windowToRender == subWindow15){
		//Triangulo
		glPushMatrix();
		glColor3f(0.0, 0.5, 0.25);
		glScalef(1.4f, 1.4f, 1.4f);
		if(filled){
			glBegin(GL_TRIANGLES);
			glVertex3f( 0.0f, 1.0f, 0.0f);
		    glVertex3f(-1.0f,-1.0f, 0.0f);
		    glVertex3f( 1.0f,-1.0f, 0.0f);
		    glEnd();
		}else{
			glBegin(GL_LINES);
				glVertex3f( 0.0f, 1.0f, 0.0f);
		    	glVertex3f(-1.0f,-1.0f, 0.0f);
			glEnd();	
		    glBegin(GL_LINES);
			    glVertex3f(-1.0f,-1.0f, 0.0f);
			    glVertex3f( 1.0f,-1.0f, 0.0f);
			glEnd();	

			glBegin(GL_LINES);
			    glVertex3f( 1.0f,-1.0f, 0.0f);
			    glVertex3f( 0.0f, 1.0f, 0.0f);
			glEnd();	
		}
		glPopMatrix();

	}else if(windowToRender == subWindow16){
		//Quad
		slice = 10;
		stacks = 50;
		glPushMatrix();
		glColor3f(1.0, 0.5, 0.0);
		if(filled){
			glBegin(GL_TRIANGLES);
				glVertex3f(-2., -0.5, 0.);
				glVertex3f(1., 1., 0.);
				glVertex3f(2., 1., 0.);
    		glEnd(); 			
    		glBegin(GL_TRIANGLES);	
				glVertex3f(2., -2.0, 0.);
				glVertex3f(0.5, -0.2, 0.);
				glVertex3f(2., 1., 0.);
    		glEnd(); 		
    		glBegin(GL_TRIANGLES);	
				glVertex3f(-2., -0.5, 0.);
				glVertex3f(0.5, -0.2, 0.);
				glVertex3f(2., 1., 0.);
    		glEnd();     		
		}else{
			glBegin(GL_LINES);
				glVertex3f(-2., -0.5, 0.);
				glVertex3f(1., 1., 0.);
			glEnd();		
			glBegin(GL_LINES);
				glVertex3f(1., 1., 0.);
				glVertex3f(2., 1., 0.);
			glEnd();	
			glBegin(GL_LINES);
				glVertex3f(2., 1., 0.);
				glVertex3f(2., -2.0, 0.);
			glEnd();
			glBegin(GL_LINES);
				glVertex3f(2., -2.0, 0.);
				glVertex3f(0.5, -0.2, 0.);
			glEnd();		
			glBegin(GL_LINES);
				glVertex3f(0.5, -0.2, 0.);
				glVertex3f(-2., -0.5, 0.);
			glEnd();	
		}
		glPopMatrix();		

	}else if(windowToRender == subWindow17){
		//Piramide Cuadrangular


		/*
		glBegin(GL_QUADS);
			glVertex3f(0.f, 0.f, 3.0f);
			glVertex3f(1.5f, 1.5f, 0.0f);
			glVertex3f(-1.5f, 1.5f, 0.0f);
			glVertex3f(-1.5f, -1.5f, 0.0f);		
			glVertex3f(1.5f, -1.5f, 0.0f);		
		glEnd();
		*/

		glPushMatrix();
		glTranslatef(0.f, -1.f, 0.f);
		glRotatef(-90, 1.0, 0.0, 0.0);	

		glBegin(GL_LINES);
			glVertex3f(0.f, 0.f, 3.0f);
			glVertex3f(1.5f, 1.5f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(0.f, 0.f, 3.0f);
			glVertex3f(-1.5f, 1.5f, 0.0f);
		glEnd();

		glBegin(GL_LINES);		
			glVertex3f(0.f, 0.f, 3.0f);
			glVertex3f(-1.5f, -1.5f, 0.0f);		
		glEnd();		

		glBegin(GL_LINES);		
			glVertex3f(0.f, 0.f, 3.0f);
			glVertex3f(1.5f, -1.5f, 0.0f);		
		glEnd();

		glBegin(GL_LINES);	
			glVertex3f(1.5f, 1.5f, 0.0f);		
			glVertex3f(-1.5f, 1.5f, 0.0f);
		glEnd();

		glBegin(GL_LINES);	
			glVertex3f(-1.5f, 1.5f, 0.0f);	
			glVertex3f(-1.5f, -1.5f, 0.0f);
		glEnd();

		glBegin(GL_LINES);			
			glVertex3f(-1.5f, -1.5f, 0.0f);	
			glVertex3f(1.5f, -1.5f, 0.0f);
		glEnd();

		glBegin(GL_LINES);			
			glVertex3f(1.5f, -1.5f, 0.0f);	
			glVertex3f(1.5f, 1.5f, 0.0f);
		glEnd();	
		glPopMatrix();

	}else if(windowToRender == subWindow18){
		// Herramienta Borrar
		slice = 10;
		stacks = 50;
		glPushMatrix();
		
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.f, -0.2f, 0.f);
		glutWireTeapot(1.2);
		glTranslatef(0.f, 0.2f, 0.f);
		
		//Pinto una gran X roja encima de la figura
		glColor3f(0.8, 0.2, 0.1);
		glBegin(GL_LINES);
			glVertex3f(-3., -3., 0.);
			glVertex3f(3., 3., 0.);
		glEnd();	
		glBegin(GL_LINES);
			glVertex3f(-3., 3., 0.);
			glVertex3f(3., -3., 0.);
		glEnd();	

		glPopMatrix();

	}else if(windowToRender == subWindow19){
		// Herramienta Fill
		glPushMatrix();
		glTranslatef(-1.5f, 1.f, 0.f);		
		glScalef(1.4f, 1.4f, 1.4f);
		glRotatef(30, 0.0, 1.0, 0.0);
		glRotatef(15, 1.0, 0.0, 0.0);
		glRotatef(10, 0.0, 0.0, 1.0);
		if(filled){
			glutWireCube(1);			
		}else{
			glutSolidCube(1);			
		}

		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.5f, -1.f, 0.f);
		glScalef(1.4f, 1.4f, 1.4f);
		glRotatef(-30, 0.0, -1.0, 0.0);
		glRotatef(-15, -1.0, 0.0, 0.0);
		glRotatef(-10, 0.0, 0.0, -1.0);
		if(filled){
			glutSolidCube(1);	
		}else{
			glutWireCube(1);
		}
		glPopMatrix();

	}	
	else{

	}
	glColor3f(1.0, 1.0, 1.0);
	glutSwapBuffers();
}

void setWindowToRender1(){
	windowToRender = subWindow1;
	renderTool();
	//drawMain();
}

void setWindowToRender2(){
	windowToRender = subWindow2;
	renderTool();
}

void setWindowToRender3(){
	windowToRender = subWindow3;
	renderTool();
}

void setWindowToRender4(){
	windowToRender = subWindow4;
	renderTool();
}

void setWindowToRender5(){
	windowToRender = subWindow5;
	renderTool();
}

void setWindowToRender6(){
	windowToRender = subWindow6;
	renderTool();
}

void setWindowToRender7(){
	windowToRender = subWindow7;
	renderTool();
}

void setWindowToRender8(){
	windowToRender = subWindow8;
	renderTool();
}

void setWindowToRender9(){
	windowToRender = subWindow9;
	renderTool();
}

void setWindowToRender10(){
	windowToRender = subWindow10;
	renderTool();
}

void setWindowToRender11(){
	windowToRender = subWindow11;
	renderTool();
}

void setWindowToRender12(){
	windowToRender = subWindow12;
	renderTool();
}

void setWindowToRender13(){
	windowToRender = subWindow13;
	renderTool();
}

void setWindowToRender14(){
	windowToRender = subWindow14;
	renderTool();
}

void setWindowToRender15(){
	windowToRender = subWindow15;
	renderTool();
}

void setWindowToRender16(){
	windowToRender = subWindow16;
	renderTool();
}

void setWindowToRender17(){
	windowToRender = subWindow17;
	renderTool();
}

void setWindowToRender18(){
	windowToRender = subWindow18;
	renderTool();
}

void setWindowToRender19(){
	windowToRender = subWindow19;
	renderTool();
}

void setFiguraTo1(int button, int state, int x, int y){
	figura = 1;
}

void setFiguraTo2(int button, int state, int x, int y){
	figura = 2;
}

void setFiguraTo3(int button, int state, int x, int y){
	figura = 3;
}

void setFiguraTo4(int button, int state, int x, int y){
	figura = 4;
}

void setFiguraTo5(int button, int state, int x, int y){
	figura = 5;
}

void setFiguraTo6(int button, int state, int x, int y){
	figura = 6;
}

void setFiguraTo7(int button, int state, int x, int y){
	figura = 7;
}

void setFiguraTo8(int button, int state, int x, int y){
	figura = 8;
}

void setFiguraTo9(int button, int state, int x, int y){
	figura = 9;
}

void setFiguraTo10(int button, int state, int x, int y){
	figura = 10;
}

void setFiguraTo11(int button, int state, int x, int y){
	figura = 11;
}

void setFiguraTo12(int button, int state, int x, int y){
	figura = 12;
}

void setFiguraTo13(int button, int state, int x, int y){
	figura = 13;
}

void setFiguraTo14(int button, int state, int x, int y){
	figura = 14;
}

void setFiguraTo15(int button, int state, int x, int y){
	figura = 15;
}

void setFiguraTo16(int button, int state, int x, int y){
	figura = 16;
}

void setFiguraTo17(int button, int state, int x, int y){
	for(int i=0; i<19; i++){
		figurasArray[index][i] = 0;
	}

	for(index=arraySize-1; index>=0; index--){
		if(figurasArray[index][0] != 0){
			break;
		}
	}

	figura = 0;

	glutSetWindow(subWindow1);
	glutPostRedisplay();
	//drawMain();
}

void changeFilledValue(int button, int state, int x, int y){
	if(state==0){
		filled = !filled;
		glutSwapBuffers();	
		reloadTools();
	}
}

void addFigureToDraw(int x, int y){
	if(figura > 19 || figura == 0){
		return;
	}

	figurasArray[index][0] = figura;

	for(int i=4; i<8; i++){
		figurasArray[index][i] = 0;
	}

	// La escala
	for(int i=7; i<10; i++){
		figurasArray[index][i] = 1;
	}

	for(int i=10; i<19; i++){
		figurasArray[index][i] = 0;
	}	
	
	if(filled){
		figurasArray[index][19] = 1;	
	}else{
		figurasArray[index][19] = 0;			
	}
	if(figura == 13){
		if(estado == 0 || estado == 1){
			// 0 = Sin figura 
			//1 = Ya tiene figura
			figurasArray[index][10] = x;
			figurasArray[index][11] = y;
			figurasArray[index][12] = 0;
			estado = 2;
			return;
		}
		else if(estado == 2){
			figurasArray[index][13] = x;
			figurasArray[index][14] = y;
			figurasArray[index][15] = 0;
			estado = 1;
		}	

	}else if(figura == 14){
		//Triangulo
		figurasArray[index][7] = 0.5;
		figurasArray[index][8] = 0.5;

		figurasArray[index][1] = x/150;
		figurasArray[index][2] = y/150;
		figurasArray[index][3] = 0;

		figurasArray[index][10] = figurasArray[index][1] +1;
		figurasArray[index][11] = figurasArray[index][2] +1;
		figurasArray[index][12] = figurasArray[index][3] +1;

		figurasArray[index][13] = figurasArray[index][1] -1;
		figurasArray[index][14] = figurasArray[index][2] +1;
		figurasArray[index][15] = figurasArray[index][3] +1;

	}else if(figura == 15){
		if(estado == 0 || estado == 1){
			// 0 = Sin figura 
			//1 = Ya tiene figura
			figurasArray[index][10] = x;
			figurasArray[index][11] = y;
			figurasArray[index][12] = 0;
			estado = 2;
			return;
		}
		else if(estado == 2){
			figurasArray[index][13] = x;
			figurasArray[index][14] = y;
			figurasArray[index][15] = 0;
			estado = 1;
		}	

	}else if(figura == 16){
		// Piramide Cuadrangular

		figurasArray[index][1] = x/150;
		figurasArray[index][2] = y/150;
		figurasArray[index][3] = 0;

	/*
		figurasArray[index][7] = 0.2;
		figurasArray[index][8] = 0.2;
		figurasArray[index][9] = 0.2;

		figurasArray[index][7] = x/150;
		figurasArray[index][8] = y/150;
		figurasArray[index][9] = 0;
	*/

		figurasArray[index][7] = 0.1;
		figurasArray[index][8] = 0.1;
		figurasArray[index][9] = 0.1;

		figurasArray[index][10] = .2;
		figurasArray[index][11] = .2;
		figurasArray[index][12] = .2;

		figurasArray[index][13] = -.2;
		figurasArray[index][14] = .2;
		figurasArray[index][15] = .2;

		figurasArray[index][16] = -.2;
		figurasArray[index][17] = -.2;
		figurasArray[index][18] = .2;

	}else{
		figurasArray[index][1] = x;
		figurasArray[index][2] = y;
		figurasArray[index][3] = 0;
	}
	
	index++;
	if(index >= arraySize){
		index = 0;
	}


	glutSetWindow(subWindow1);
	glutPostRedisplay();	

}

void mouse1(int button, int state, int x, int y)
{
	mouseButton = button;
	mouseRotate = false;
	mouseZoom = false;
	mousePan = false;
	xClick = x;
	yClick = y;


	if (button == GLUT_LEFT_BUTTON)
	{
		mouseRotate = true;
		xAux = rotX;
		yAux = rotY;

		if(button == 0 && state == 1 && windowToRender == subWindow1){
			addFigureToDraw(x, y);			
			drawMain();
		}		

	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
	
		mouseZoom = true;
		xAux = zoomZ;
	}
	else if (button == GLUT_MIDDLE_BUTTON)
	{
		mousePan = true;
		xAux = panX;
		yAux = panY;
	}

	glutSetWindow(subWindow1);
	glutPostRedisplay();

}

void mouseMotion1(int x, int y)
{
	if (mouseRotate == true)
	{
		if (mouseButton == GLUT_LEFT_BUTTON)
		{
			if ((x - xClick + xAux) > 360.0)
			{
				xAux = xAux - 360.0;
			}
			if ((x - xClick + xAux) < 0.0)
			{
				xAux = xAux + 360.0;
			}
			if ((y - yClick + yAux) > 360.0)
			{
				yAux = yAux - 360.0;
			}
			if ((y - yClick + yAux) < 0.0)
			{
				yAux = yAux + 360.0;
			}
			rotX = x - xClick + xAux;
			rotY = y - yClick + yAux;
		}
	}
	else if (mouseZoom == true)
	{
		if (mouseButton == GLUT_RIGHT_BUTTON)
		{
			zoomZ = ((x - xClick) / 10.0) + xAux;
		}
	}
	else if (mousePan == true)
	{
		if (mouseButton == GLUT_MIDDLE_BUTTON)
		{
			panX = ((x - xClick) / 63.0) + xAux;
			panY = ((y - yClick) / (-63.0)) + yAux;
		}
	}

	glutSetWindow(subWindow1);
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	glutPostRedisplay();
}

void mouseMotion(int x, int y)
{
	glutPostRedisplay();
}

//	Función que se invoca cada vez que se oprime una tecla especial (Flechas, F1, ESC, etc.)
void specialKeyboard(int key, int x, int y)
{
	if(key == 1){
		// F1 		
		estadoDeCambio = 'p';
	}else if(key == 2){
		// F2
		estadoDeCambio = 'r';
	}else if(key == 3){
		// F3
		estadoDeCambio = 's';
	}else if(key == 4){
		// F4
		//for(index=0; index<arraySize; index++){
		for(index; index>=0; index--){		
			if(figurasArray[index][0] != 0){
				break;
			}
		}		
	}
	else if(key == 5){
		// F5
		for(index; index<arraySize; index++){		
			if(figurasArray[index][0] != 0){
				break;
			}
		}
	}

	if(estadoDeCambio == 'p'){
		int deltaPos = 250;

		if(key == 102){
			//mover en X +
			figurasArray[index][1]+= deltaPos;
			figurasArray[index][10]+= deltaPos;
			figurasArray[index][13]+= deltaPos;			
			figurasArray[index][16]+= deltaPos;						
		}
		else if(key == 100){
			//mover en X -
			figurasArray[index][1]-= deltaPos;
			figurasArray[index][10]-= deltaPos;
			figurasArray[index][13]-= deltaPos;
			figurasArray[index][16]-= deltaPos;
		}
		else if(key == 101){
			//mover en Y +
			figurasArray[index][2]+= deltaPos;
			figurasArray[index][11]+= deltaPos;
			figurasArray[index][14]+= deltaPos;			
			figurasArray[index][17]+= deltaPos;				
		}
		else if(key == 103){
			//mover en Y -
			figurasArray[index][2]-= deltaPos;
			figurasArray[index][11]-= deltaPos;
			figurasArray[index][14]-= deltaPos;			
			figurasArray[index][17]-= deltaPos;					
		}
		else if(key == 104){
			//mover en Z +
			figurasArray[index][3]+= deltaPos;
			figurasArray[index][12]+= deltaPos;
			figurasArray[index][15]+= deltaPos;		
			figurasArray[index][18]+= deltaPos;			
		}
		else if(key == 105){
			//mover en Z -
			figurasArray[index][3]-= deltaPos;	
			figurasArray[index][12]-= deltaPos;	
			figurasArray[index][15]-= deltaPos;			
			figurasArray[index][18]-= deltaPos;					
		}	
	}else if(estadoDeCambio == 'r'){
		if(key == 102){
			//mover en X +
			figurasArray[index][4]++;
			figurasArray[index][4]++;
		}
		else if(key == 100){
			//mover en X -
			figurasArray[index][4]--;
		}
		else if(key == 101){
			//mover en Y +
			figurasArray[index][5]--;
		}
		else if(key == 103){
			//mover en Y +
			figurasArray[index][5]++;
		}
		else if(key == 104){
			//mover en Z +
			figurasArray[index][6]++;
		}
		else if(key == 105){
			//mover en Z -
			figurasArray[index][6]--;
		}			
	}else if(estadoDeCambio == 's'){
		if(key == 102){
			//mover en X +
			figurasArray[index][7]++;			
		}
		else if(key == 100){
			//mover en X -
			figurasArray[index][7]--;
		}
		else if(key == 101){
			//mover en Y +
			figurasArray[index][8]--;
		}
		else if(key == 103){
			//mover en Y +
			figurasArray[index][8]++;
		}
		else if(key == 104){
			//mover en Z +
			figurasArray[index][9]++;
		}
		else if(key == 105){
			//mover en Z -
			figurasArray[index][9]--;
		}			
	}

	glutSetWindow(subWindow1);
	glutPostRedisplay();
}

int main(GLint argc, GLchar **argv)
{
	// 1. Se crea la ventana principal y subventanas (contextos OpenGL) usando GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	mainWindow = glutCreateWindow("Paint 3D");

	//Main
	subWindow1 = glutCreateSubWindow(mainWindow, width /4, 0, width * 3/4, height);

	//Herramientas
	subWindow2 = glutCreateSubWindow(mainWindow, 0,			0, width /8, height / 9);
	subWindow3 = glutCreateSubWindow(mainWindow, width/8,	0, width /8, height / 9);

	subWindow4 = glutCreateSubWindow(mainWindow, 0,			height /9, width /8, height / 9);
	subWindow5 = glutCreateSubWindow(mainWindow, width/8, 	height /9, width /8, height / 9);

	subWindow6 = glutCreateSubWindow(mainWindow, 0,			height *2/9, width /8, height / 9);
	subWindow7 = glutCreateSubWindow(mainWindow, width/8,	height *2/9, width /8, height / 9);

	subWindow8 = glutCreateSubWindow(mainWindow, 0,			height *3/9, width /8, height / 9);
	subWindow9 = glutCreateSubWindow(mainWindow, width/8,	height *3/9, width /8, height / 9);

	subWindow10 = glutCreateSubWindow(mainWindow, 0,		height *4/9, width /8, height / 9);
	subWindow11 = glutCreateSubWindow(mainWindow, width/8,	height *4/9, width /8, height / 9);

	subWindow12 = glutCreateSubWindow(mainWindow, 0,		height *5/9, width /8, height / 9);
	subWindow13 = glutCreateSubWindow(mainWindow, width/8,	height *5/9, width /8, height / 9);

	subWindow14 = glutCreateSubWindow(mainWindow, 0,		height *6/9, width /8, height / 9);
	subWindow15 = glutCreateSubWindow(mainWindow, width/8,	height *6/9, width /8, height / 9);

	subWindow16 = glutCreateSubWindow(mainWindow, 0,		height *7/9, width /8, height / 9);
	subWindow17 = glutCreateSubWindow(mainWindow, width/8,	height *7/9, width /8, height / 9);

	subWindow18 = glutCreateSubWindow(mainWindow, 0,		height *8/9, width /8, height / 9);
	subWindow19 = glutCreateSubWindow(mainWindow, width/8,	height *8/9, width /8, height / 9);

	// 1.2 Se definen las funciones callback para el manejo de eventos
	glutSetWindow(mainWindow);
	glutReshapeFunc(resize);	// La función resize se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(render);	// La función render se invocará cada vez que se tenga que dibujar
	//glutMouseFunc(mouse1);
	//glutMotionFunc(mouseMotion1);

	//Main
	glutSetWindow(subWindow1);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender1);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(mouse1);
	glutMotionFunc(mouseMotion1);
	glutSpecialFunc(specialKeyboard);	// La función keyboard se invocará cada vez que se oprima una tecla especial (F1, ESC, etc.)	

	//Tools
	glutSetWindow(subWindow2);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender2);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo1);

	glutSetWindow(subWindow3);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender3);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo2);

	glutSetWindow(subWindow4);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender4);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo3);

	glutSetWindow(subWindow5);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender5);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo4);

	glutSetWindow(subWindow6);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender6);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo5);

	glutSetWindow(subWindow7);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender7);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo6);

	glutSetWindow(subWindow8);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender8);	// La función render1 se invocará cada vez que se tenga que dibujar;
	glutMouseFunc(setFiguraTo7);

	glutSetWindow(subWindow9);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender9);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo8);

	glutSetWindow(subWindow10);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender10);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo9);

	glutSetWindow(subWindow11);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender11);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo10);

	glutSetWindow(subWindow12);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender12);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo11);

	glutSetWindow(subWindow13);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender13);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo12);

	glutSetWindow(subWindow14);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender14);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo13);

	glutSetWindow(subWindow15);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender15);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo14);

	glutSetWindow(subWindow16);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender16);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo15);

	glutSetWindow(subWindow17);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender17);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo16);

	glutSetWindow(subWindow18);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender18);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(setFiguraTo17);

	glutSetWindow(subWindow19);
	glutReshapeFunc(resizeTool);	// La función resize1 se invocará cada vez que se redimensione la ventana
	glutDisplayFunc(setWindowToRender19);	// La función render1 se invocará cada vez que se tenga que dibujar
	glutMouseFunc(changeFilledValue);

	// 2. Se direcciona a las funciones correctas del API de OpenGL
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		//fprintf(stderr, "GLEW Error");
		return false;
	}

	// 3. Se inicia el ciclo de escucha de eventos
	glutMainLoop();
	return 0;
}
