#include <iostream>
#include <cmath>
using namespace std;


void multipy(double matrixFirst[][3], double matrixSecond[][1], double matrixThird[][1]) {
    int x,y;
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 3; i++) {
            matrixThird[j][0] += (matrixFirst[j][i] * matrixSecond[i][0]);  
        }
    }
    cout << "New Coordinates: (" << matrixThird[0][0] << ", " << matrixThird[1][0] << ")" << endl;
}


void rotate(double xStart, double yStart, double xRotate) {
    xRotate = (xRotate)*(M_PI/180);
    double matrixFirst[3][3] = {{cos(xRotate),(-1 * sin(xRotate)),0},{sin(xRotate),cos(xRotate),0},{0,0,1}};
    double matrixSecond[3][1] = {{xStart},{yStart},{1}};
    double matrixThird[3][1] = {{0},{0},{0}};

    multipy(matrixFirst,matrixSecond, matrixThird);
}

void translate(double xStart, double yStart, double xTranslate, double yTranslate) {
    double matrixFirst[3][3] = {{1,0,xStart},{0,1,yStart},{0,0,1}};
    double matrixSecond[3][1] = {{xTranslate},{yTranslate},{1}};
    double matrixThird[3][1] = {{0},{0},{0}};

    multipy(matrixFirst,matrixSecond, matrixThird);
}

void scale(double xStart, double yStart, double xScale, double yScale) {
    double matrixFirst[3][3] = {{xScale,0,0},{0,yScale,0},{0,0,1}};
    double matrixSecond[3][1] = {{xStart},{yStart},{1}};
    double matrixThird[3][1] = {{0},{0},{0}};

    multipy(matrixFirst,matrixSecond, matrixThird);
}


int main() {
    int xStart,yStart;
    string transformations;

    cout << "Choose starting x and y coordinates" << endl;
    
    cin >> xStart >> yStart;
    cout << "Choose transformation: " << "Translate " << "Scale " << "Rotate " << endl;
    cin >> transformations;
    
    if(transformations == "Rotate") {
        double xRotate;
        cout << "Enter a rotation in degrees: " << endl;
        cin >> xRotate;
        rotate(xStart, yStart, xRotate);
    }
    else if(transformations == "Scale") {
        int xScale, yScale;
        cout << "Enter a scalar(x,y): " << endl;
        cin >> xScale >> yScale;
        scale(xStart, yStart, xScale, yScale);
    }
    else if(transformations == "Translate") { 
        int xTranslate, yTranslate;
        cout << "Enter a translation(x,y): " << endl;
        cin >> xTranslate >> yTranslate;
        translate(xStart, yStart, xTranslate, yTranslate);
    }  
    else
        cout << "Invalid Choice" << endl;

}