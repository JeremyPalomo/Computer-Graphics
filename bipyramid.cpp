// Jeremy Palomo
// CS3233
// Pentagonal Bipyramid
// 9-30-22
// Creates a slightly rotated Pentagonal Bipyramid.

#include <GL/glut.h>
#include <cmath>
using namespace std;

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);

    float color_one[][4] = {{1.0f,0.0f,0.0f,0.5f}, {0.5f,0.5f,0.1f,0.5f}, {0.0f,1.0f,0.0f,0.5f}, {0.5f,0.5f,1.0f,0.5f}, {0.0f,0.0f,1.0f,0.5f}}; // Color for top half o pyramid
    float color_two[][4] = {{0.5f,0.5f,0.1f,0.5f}, {0.0f,1.0f,0.0f,0.5f}, {0.5f,0.5f,1.0f,0.5f}, {0.0f,0.0f,1.0f,0.5f}, {1.0f,0.0f,0.0f,0.5f}}; // Color for bottom half o pyramid
    float pentagon_points[7][3] {{},{},{},{},{},{0.0,3.0,0.0},{0.0,-3.0,0.0}};
    
    glRotatef(40.0f, 1.0f, 1.0f, 1.0f);  //Transformations
    glScalef(0.5f,0.5f,0.5f);


    float angleIncrement = 360.0f / 5.0;
    angleIncrement *= M_PI / 180.0f;
    float angle = 0.0f;
    float radius = 1.0;

    for (int k = 0; k < 5; ++k) { //Calcultes the correct x, y, and z coordinates for the pentagon base
        pentagon_points[k][0] = radius*cos(angle);
        pentagon_points[k][1] = 0.0;
        pentagon_points[k][2] = radius*sin(angle);
        angle += angleIncrement;
    }

    glBegin(GL_TRIANGLE_FAN); //Make Pentagon Base
    for(int i =0; i < 5; i++)
        glVertex3fv(pentagon_points[i]);
    glEnd();

    glBegin(GL_TRIANGLES); // Make Triangle Faces
     for(int j=0; j<2; j++) {
        for(int i =0; i < 5; i++) {
            if(j == 1)
                glColor3fv(color_one[i]);
            else
                glColor3fv(color_two[i]);
            glVertex3fv(pentagon_points[j+5]);
            glVertex3fv(pentagon_points[i]);
            if(i==4)
                glVertex3fv(pentagon_points[0]);
            else
                glVertex3fv(pentagon_points[i+1]);
        }
        
    } 

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Pentagonal Bipyramid");
    glutDisplayFunc(display);  
    glutMainLoop();
    return 0;
}