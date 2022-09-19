#include <GL/glut.h>
#include <cmath>


void display() {
    //Background
    glClearColor(0.2f,0.6f,1.0f,0.0f);
    //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT); 

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    
    
    glBegin(GL_TRIANGLES);
        //Roof #1
        glColor3f(0.02f,0.0f,0.1f);
        glVertex2f(-0.7f,0.0f);

        glColor3f(0.02f,0.0f,0.1f);
        glVertex2f(0.7f,0.0f);

        glColor3f(0.02f,0.0f,0.1f);
        glVertex2f(0.0f,0.4f);

        //Roof #2
        glColor3f(0.02f,0.0f,0.1f);
        glVertex2f(0.4f,-0.3f);

        glColor3f(0.02f,0.0f,0.1f);
        glVertex2f(0.7f,-0.1f);

        glColor3f(0.02f,0.0f,0.1f);
        glVertex2f(1.0f,-0.3f);

        //Branch #1
        glColor3f(0.2f,0.0f,0.0f);
        glVertex2f(-0.7f,-0.8f);

        glColor3f(0.2f,0.0f,0.0f);
        glVertex2f(-0.7f,-0.7f);

        glColor3f(0.2f,0.0f,0.0f);
        glVertex2f(-0.6f,-0.7f);

        //Branch #2
        glColor3f(0.2f,0.0f,0.0f);
        glVertex2f(-0.8f,-0.6f);

        glColor3f(0.2f,0.0f,0.0f);
        glVertex2f(-0.8f,-0.5f);

        glColor3f(0.2f,0.0f,0.0f);
        glVertex2f(-0.9f,-0.5f);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    //Tree Leaves
        int n = 100;
        float angleIncrement = 360.0f / n;  
        angleIncrement *= M_PI / 180.0f;    
        float angle = 0.0f;
        float radius = 0.25f;
        
        for(int k = 0; k < n; k++) {
            glColor3f(0.0f,0.4f,0.07f);
            glVertex2f(radius * cos(angle) -0.75f, radius * sin(angle)-0.2f);
            angle += angleIncrement;
        }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        //Sun
        n = 100;
        angleIncrement = 360.0f / n;  
        angleIncrement *= M_PI / 180.0f;    
        angle = 0.0f;
        radius = 0.25f;

        for(int k = 0; k < n; k++) {
            glColor4f(1.0f,1.0f,0.2f,0.6f);
            glVertex2f(radius * cos(angle) + 0.7f, radius * sin(angle) +0.6f);
            angle += angleIncrement;
        }
    glEnd();
    
    glBegin(GL_QUADS);
        //Grass

        glColor3f(0.0f,0.4f,0.07f);
        glVertex2f(-1.0,-1.0);

        glColor3f(0.0f,0.4f,0.07f);
        glVertex2f(-1.0,-0.9);

        glColor3f(0.0f,0.4f,0.07f);
        glVertex2f(1.0,-0.9);

        glColor3f(0.0f,0.4f,0.07f);
        glVertex2f(1.0,-1.0);
    
        //Tree Trunk
        glColor3f(0.2f,0.0f,0.0f);
        glVertex2f(-0.8f,-0.9f);

        glColor3f(0.2f,0.0f,0.0f);
        glVertex2f(-0.8f,-0.4f);

        glColor3f(0.2f,0.0f,0.0f);
        glVertex2f(-0.7f,-0.4f);

        glColor3f(0.2f,0.0f,0.0f);
        glVertex2f(-0.7f,-0.9f);

        //Square House Outline #1
        glColor3f(0.6f,0.2f,1.0f);
        glVertex2f(-0.5f,-1.0f);

        glColor3f(0.6f,0.2f,1.0f);
        glVertex2f(-0.5f,0.0f);
        

        glColor3f(0.6f,0.2f,1.0f);
        glVertex2f(0.5f,0.0f);
        
        
        glColor3f(0.6f,0.2f,1.0f);
        glVertex2f(0.5f,-1.0f);

        //Square House Outline #2
        glColor3f(0.6f,0.2f,1.0f);
        glVertex2f(0.5f,-1.0f);

        glColor3f(0.6f,0.2f,1.0f);
        glVertex2f(0.5f,-0.3f);
        

        glColor3f(0.6f,0.2f,1.0f);
        glVertex2f(1.0f,-0.3f);

        glColor3f(0.6f,0.2f,1.0f);
        glVertex2f(1.0f,-1.0f);

        //Window #1

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(-0.3f,-0.5f);

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(-0.3f,-0.3f);

        
        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(-0.1f,-0.3f);
        

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(-0.1f,-0.5f);

        //Window #2

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(0.3f,-0.5f);

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(0.3f,-0.3f);

        
        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(0.1f,-0.3f);
        

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(0.1f,-0.5f);

        //Window #3

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(0.6f,-0.6f);

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(0.6f,-0.45f);

        
        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(0.8f,-0.45f);
        

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(0.8f,-0.6f);

        //Garage

        glColor3f(0.3f,0.2f,0.0f);
        glVertex2f(-0.4f,-1.0f);

        glColor3f(0.3f,0.2f,0.0f);
        glVertex2f(-0.4f,-0.7f);

        glColor3f(0.3f,0.2f,0.0f);
        glVertex2f(0.4f,-0.7f);

        glColor3f(0.3f,0.2f,0.0f);
        glVertex2f(0.4f,-1.0f);

        //Door
        glColor3f(0.3f,0.2f,0.0f);
        glVertex2f(0.6f,-1.0f);

        glColor3f(0.3f,0.2f,0.0f);
        glVertex2f(0.6f,-0.7f);

        glColor3f(0.3f,0.2f,0.0f);
        glVertex2f(0.8f,-0.7f);

        glColor3f(0.3f,0.2f,0.0f);
        glVertex2f(0.8f,-1.0f);
        
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(-0.8f,0.6f);

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(-0.65f,0.75f);

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(-0.7f,0.45f);

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(-0.45f,0.75f);

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(-0.3f,0.43f);

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(-0.2f,0.79f);

        glColor4f(0.9f,0.92f,1.0f,0.7f);
        glVertex2f(-0.1f,0.4f);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT.
    glutInitWindowSize(500, 500);          // Set the window's initial width & height.
    glutInitWindowPosition(50, 50);        // Position the window's initial top-left corner.
    glutCreateWindow("OpenGL Hello World");// Create a window with the given title.
    glutDisplayFunc(display);              // Register display callback handler for window re-paint.
    glutMainLoop();                        // Enter the infinitely event-processing loop.
    return 0;
}