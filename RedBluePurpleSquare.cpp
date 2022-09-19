//--------------------------------------------------------------------------
// Red/Blue/Purple Squares
//
// This is the example we studied in class on Friday, 9/18/20.
//--------------------------------------------------------------------------

#ifdef _WIN32
    #include <GL/glut.h>
#elif __linux__
    #include <GL/glut.h>
#elif __APPLE__
    #define GL_SILENCE_DEPRECATION
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
#endif

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

    // Enabling blending makes it possible to use the alpha component of the
    // color to control opacity.
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // These functions set the world coordinate system that will be used
    // for drawing the squares in the code that follows.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0f, 2.0f, 2.0f, -2.0f); //Arguments: xmin, xmax, ymin, ymax

    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad

        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(-0.5f, -0.5f);    // x, y
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(-0.5f, 0.5f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.4f, -0.4f);    // x, y
        glVertex2f(0.6f, -0.4f);
        glVertex2f(0.6f, 0.6f);
        glVertex2f(-0.4f, 0.6f);

        // Make this square purple with an alpha of 0.5. With blending enabled
        // (see above), it should appear a bit transparent. Note the name of
        // the glColor4f() function.
        glColor4f(0.5f, 0.0f, 0.5f, 0.5f);
        glVertex2f(-0.3f, -0.3f);    // x, y
        glVertex2f(0.7f, -0.3f);
        glVertex2f(0.7f, 0.7f);
        glVertex2f(-0.3f, 0.7f);

    glEnd();

    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop
    return 0;
}
