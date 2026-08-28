#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

using namespace std;

// ============ WINDOW SETUP (COMMON - DO NOT CHANGE) ============
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const float ORTHO_LEFT = 0;
const float ORTHO_RIGHT = 80;
const float ORTHO_BOTTOM = 0;
const float ORTHO_TOP = 45;
const float TRAIN_TRACK_Y = 17.0f;

// ============ SCENE 1 - SUMMER VARIABLES ============
// Train
float summerTrainX = 5.0f;
float summerTrainSpeed = 0.15f;
bool summerTrainMoving = false;
const float SUMMER_TRAIN_MIN_X = 5.0f;
const float SUMMER_TRAIN_MAX_X = 75.0f;

// Car
float summerCarX = 30.0f;
float summerCarSpeed = 0.1f;
bool summerCarMoving = false;

// Clouds
float summerCloud1X = 10.0f;
float summerCloud2X = 50.0f;
float summerCloud3X = 70.0f;
float summerCloudSpeed = 0.05f;

// Trees
float summerTree1X = 15.0f, summerTree1Y = 25.0f;
float summerTree2X = 35.0f, summerTree2Y = 28.0f;
float summerTree3X = 60.0f, summerTree3Y = 26.0f;
float summerTreeSwayAngle = 0.0f;
float summerTreeSwaySpeed = 0.05f;

// Sun
float summerSunX = 70.0f, summerSunY = 35.0f;
float summerSunBrightness = 1.0f;

// Smoke
float summerSmokeX = summerTrainX + 2.0f;
float summerSmokeY = 22.0f;
float summerSmokeOpacity = 1.0f;
bool summerSmokeVisible = true;

// River
float summerRiverWavePhase = 0.0f;

// Animation flags
bool summerAnimationsRunning = true;

// ============ SCENE 1 - DRAWING FUNCTIONS ============

void summerDrawTrack()
{
    glColor3f(0.35f, 0.32f, 0.22f);
    glBegin(GL_QUADS);
    glVertex2f(0, TRAIN_TRACK_Y);
    glVertex2f(80, TRAIN_TRACK_Y);
    glVertex2f(80, TRAIN_TRACK_Y + 2.5f);
    glVertex2f(0, TRAIN_TRACK_Y + 2.5f);
    glEnd();

    // Railway sleepers
    glColor3f(0.4f, 0.3f, 0.2f);
    for (float i = 0; i < 80; i += 4) {
        glBegin(GL_QUADS);
        glVertex2f(i, TRAIN_TRACK_Y + 0.5f);
        glVertex2f(i + 2, TRAIN_TRACK_Y + 0.5f);
        glVertex2f(i + 2, TRAIN_TRACK_Y + 1.7f);
        glVertex2f(i, TRAIN_TRACK_Y + 1.7f);
        glEnd();
    }
}

void summerDrawSun()
{
    glColor3f(summerSunBrightness, summerSunBrightness * 0.8f, 0.0f);
    
    // Draw circle using triangles
    int segments = 30;
    float radius = 2.5f;
    
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(summerSunX, summerSunY);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * 3.14159f * i / segments;
        float x = summerSunX + radius * cos(angle);
        float y = summerSunY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Sun glow (larger circle)
    glColor3f(summerSunBrightness, summerSunBrightness * 0.6f, 0.0f);
    radius = 3.0f;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * 3.14159f * i / segments;
        float x = summerSunX + radius * cos(angle);
        float y = summerSunY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

// ============ TAIYEBA ENHANCEMENT ============
void summerEnhanceTaiyeba()
{
    // Enhanced sun with multiple glow layers for better brightness effect
    float radius = 4.0f;
    int segments = 30;
    
    // Outer glow (dim)
    glColor4f(summerSunBrightness, summerSunBrightness * 0.4f, 0.0f, 0.3f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * 3.14159f * i / segments;
        float x = summerSunX + radius * cos(angle);
        float y = summerSunY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    
    // Middle glow layer
    glColor4f(summerSunBrightness * 0.9f, summerSunBrightness * 0.7f, 0.0f, 0.4f);
    radius = 3.5f;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * 3.14159f * i / segments;
        float x = summerSunX + radius * cos(angle);
        float y = summerSunY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void summerDrawCloud(float cloudX, float cloudY)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    
    // Draw circles to form cloud
    float radius = 1.5f;
    int segments = 20;
    
    // Main cloud shape (3 circles)
    for (float offsetX = 0; offsetX <= 4; offsetX += 2) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cloudX + offsetX, cloudY);
        for (int i = 0; i <= segments; i++) {
            float angle = 3.14159f * i / segments; // Half circle
            float x = cloudX + offsetX + radius * cos(angle);
            float y = cloudY + radius * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }
}

void summerDrawClouds()
{
    summerDrawCloud(summerCloud1X, 38.0f);
    summerDrawCloud(summerCloud2X, 36.0f);
    summerDrawCloud(summerCloud3X, 37.0f);
}

void summerDrawTree(float treeX, float treeY, float swayAngle)
{
    // Trunk
    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(treeX - 0.4f, treeY);
    glVertex2f(treeX + 0.4f, treeY);
    glVertex2f(treeX + 0.4f, treeY + 3.0f);
    glVertex2f(treeX - 0.4f, treeY + 3.0f);
    glEnd();

    // Foliage (green circle with sway)
    glPushMatrix();
    glTranslatef(treeX, treeY + 3.5f, 0.0f);
    glRotatef(swayAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-treeX, -(treeY + 3.5f), 0.0f);

    glColor3f(0.0f, 0.6f, 0.0f);
    float radius = 2.5f;
    int segments = 25;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(treeX, treeY + 3.5f);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * 3.14159f * i / segments;
        float x = treeX + radius * cos(angle);
        float y = treeY + 3.5f + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glPopMatrix();
}

void summerDrawTrees()
{
    summerDrawTree(summerTree1X, summerTree1Y, summerTreeSwayAngle);
    summerDrawTree(summerTree2X, summerTree2Y, -summerTreeSwayAngle * 0.7f);
    summerDrawTree(summerTree3X, summerTree3Y, summerTreeSwayAngle * 0.5f);
}

void summerDrawGrass()
{
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(80, 0);
    glVertex2f(80, 15.0f);
    glVertex2f(0, 15.0f);
    glEnd();

    // Grass patches
    glColor3f(0.0f, 0.6f, 0.0f);
    for (float i = 0; i < 80; i += 10) {
        glBegin(GL_TRIANGLES);
        glVertex2f(i, 14.5f);
        glVertex2f(i + 2, 15.5f);
        glVertex2f(i + 4, 14.5f);
        glEnd();
    }
}

void summerDrawHills()
{
    glColor3f(0.1f, 0.4f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(0, 15.0f);
    glVertex2f(20, 25.0f);
    glVertex2f(40, 18.0f);
    glVertex2f(60, 28.0f);
    glVertex2f(80, 20.0f);
    glVertex2f(80, 15.0f);
    glEnd();
}

void summerDrawRiver()
{
    glColor3f(0.2f, 0.5f, 0.8f);
    glBegin(GL_QUAD_STRIP);
    
    for (float x = 0; x <= 80; x += 1) {
        float waveOffset = 0.5f * sin(x * 0.2f + summerRiverWavePhase);
        glVertex2f(x, 8.0f + waveOffset);
        glVertex2f(x, 6.0f + waveOffset);
    }
    glEnd();

    // Water highlight (moving)
    glColor3f(0.5f, 0.7f, 1.0f);
    glBegin(GL_LINES);
    glLineWidth(2.0f);
    for (float x = -80 + fmod(summerRiverWavePhase * 10, 80); x < 80; x += 8) {
        float waveOffset = 0.5f * sin(x * 0.2f + summerRiverWavePhase);
        glVertex2f(x, 7.2f + waveOffset);
        glVertex2f(x + 3, 7.0f + waveOffset);
    }
    glEnd();
    glLineWidth(1.0f);
}

void summerDrawTrain()
{
    // Train body
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(summerTrainX, TRAIN_TRACK_Y);
    glVertex2f(summerTrainX + 6, TRAIN_TRACK_Y);
    glVertex2f(summerTrainX + 6, TRAIN_TRACK_Y + 3.5f);
    glVertex2f(summerTrainX, TRAIN_TRACK_Y + 3.5f);
    glEnd();

    // Train cabin/engine (front)
    glColor3f(0.6f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
    glVertex2f(summerTrainX + 5.5f, TRAIN_TRACK_Y);
    glVertex2f(summerTrainX + 8, TRAIN_TRACK_Y);
    glVertex2f(summerTrainX + 8, TRAIN_TRACK_Y + 4.0f);
    glVertex2f(summerTrainX + 5.5f, TRAIN_TRACK_Y + 4.0f);
    glEnd();

    // Windows
    glColor3f(0.7f, 0.9f, 1.0f);
    for (float wx = summerTrainX + 0.5f; wx < summerTrainX + 5; wx += 1.5f) {
        glBegin(GL_QUADS);
        glVertex2f(wx, TRAIN_TRACK_Y + 1.5f);
        glVertex2f(wx + 1, TRAIN_TRACK_Y + 1.5f);
        glVertex2f(wx + 1, TRAIN_TRACK_Y + 3);
        glVertex2f(wx, TRAIN_TRACK_Y + 3);
        glEnd();
    }

    // Wheels
    glColor3f(0.2f, 0.2f, 0.2f);
    int segments = 15;
    float wheelRadius = 0.8f;
    
    for (float wheelX = summerTrainX + 1.5f; wheelX < summerTrainX + 7; wheelX += 2.5f) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(wheelX, TRAIN_TRACK_Y - 0.5f);
        for (int i = 0; i <= segments; i++) {
            float angle = 2.0f * 3.14159f * i / segments;
            float x = wheelX + wheelRadius * cos(angle);
            float y = TRAIN_TRACK_Y - 0.5f + wheelRadius * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }

    // Smoke from train
    if (summerSmokeVisible) {
        summerDrawSmoke();
    }
}

void summerDrawSmoke()
{
    summerSmokeX = summerTrainX + 2.0f;
    
    // Multiple smoke puffs
    for (int i = 0; i < 3; i++) {
        float smokeSize = 1.5f - (i * 0.3f);
        float smokeY = TRAIN_TRACK_Y + 4.5f + (i * 1.0f);
        glColor4f(0.7f, 0.7f, 0.7f, summerSmokeOpacity * (1.0f - i * 0.3f));
        
        int segments = 20;
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(summerSmokeX, smokeY);
        for (int j = 0; j <= segments; j++) {
            float angle = 2.0f * 3.14159f * j / segments;
            float x = summerSmokeX + smokeSize * cos(angle);
            float y = smokeY + smokeSize * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }
}

void summerDrawCar()
{
    // Car body
    glColor3f(0.2f, 0.2f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(summerCarX, 13.0f);
    glVertex2f(summerCarX + 3, 13.0f);
    glVertex2f(summerCarX + 3, 15.0f);
    glVertex2f(summerCarX, 15.0f);
    glEnd();

    // Car cabin/roof
    glColor3f(0.15f, 0.15f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(summerCarX + 0.5f, 15.0f);
    glVertex2f(summerCarX + 2.5f, 15.0f);
    glVertex2f(summerCarX + 2.3f, 16.0f);
    glVertex2f(summerCarX + 0.7f, 16.0f);
    glEnd();

    // Windows
    glColor3f(0.6f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(summerCarX + 0.7f, 14.2f);
    glVertex2f(summerCarX + 1.5f, 14.2f);
    glVertex2f(summerCarX + 1.5f, 14.8f);
    glVertex2f(summerCarX + 0.7f, 14.8f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(summerCarX + 1.8f, 14.2f);
    glVertex2f(summerCarX + 2.7f, 14.2f);
    glVertex2f(summerCarX + 2.7f, 14.8f);
    glVertex2f(summerCarX + 1.8f, 14.8f);
    glEnd();

    // Wheels
    glColor3f(0.1f, 0.1f, 0.1f);
    int segments = 12;
    float wheelRadius = 0.6f;
    
    for (float wheelX = summerCarX + 0.8f; wheelX < summerCarX + 3; wheelX += 1.8f) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(wheelX, 13.0f);
        for (int i = 0; i <= segments; i++) {
            float angle = 2.0f * 3.14159f * i / segments;
            float x = wheelX + wheelRadius * cos(angle);
            float y = 13.0f + wheelRadius * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }
}

void summerDrawRuralHouse()
{
    float houseX = 45.0f;
    float houseY = 14.0f;

    // House walls
    glColor3f(0.8f, 0.6f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(houseX, houseY);
    glVertex2f(houseX + 5, houseY);
    glVertex2f(houseX + 5, houseY + 4);
    glVertex2f(houseX, houseY + 4);
    glEnd();

    // Roof (triangle)
    glColor3f(0.6f, 0.3f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(houseX, houseY + 4);
    glVertex2f(houseX + 5, houseY + 4);
    glVertex2f(houseX + 2.5f, houseY + 5.5f);
    glEnd();

    // Door
    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(houseX + 1.8f, houseY);
    glVertex2f(houseX + 3.2f, houseY);
    glVertex2f(houseX + 3.2f, houseY + 2.5f);
    glVertex2f(houseX + 1.8f, houseY + 2.5f);
    glEnd();

    // Windows
    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(houseX + 0.5f, houseY + 2.5f);
    glVertex2f(houseX + 1.3f, houseY + 2.5f);
    glVertex2f(houseX + 1.3f, houseY + 3.5f);
    glVertex2f(houseX + 0.5f, houseY + 3.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(houseX + 3.7f, houseY + 2.5f);
    glVertex2f(houseX + 4.5f, houseY + 2.5f);
    glVertex2f(houseX + 4.5f, houseY + 3.5f);
    glVertex2f(houseX + 3.7f, houseY + 3.5f);
    glEnd();
}

void summerDrawSky()
{
    glColor3f(0.5f, 0.8f, 1.0f); // Light blue sky
    glBegin(GL_QUADS);
    glVertex2f(0, 15.0f);
    glVertex2f(80, 15.0f);
    glVertex2f(80, 45.0f);
    glVertex2f(0, 45.0f);
    glEnd();
}

// ============ SCENE 1 - ANIMATION FUNCTIONS ============

void summerMoveTrain()
{
    if (summerTrainMoving) {
        summerTrainX += summerTrainSpeed;
        
        if (summerTrainX > SUMMER_TRAIN_MAX_X) {
            summerTrainX = SUMMER_TRAIN_MIN_X;
        }
    }
}

void summerMoveCar()
{
    if (summerCarMoving) {
        summerCarX += summerCarSpeed;
        
        if (summerCarX > 80) {
            summerCarX = -3;
        }
    }
}

void summerAnimateClouds()
{
    summerCloud1X += summerCloudSpeed;
    summerCloud2X += summerCloudSpeed;
    summerCloud3X += summerCloudSpeed;

    if (summerCloud1X > 85) summerCloud1X = -5;
    if (summerCloud2X > 85) summerCloud2X = -5;
    if (summerCloud3X > 85) summerCloud3X = -5;
}

void summerAnimateTrees()
{
    summerTreeSwayAngle += summerTreeSwaySpeed;
    if (summerTreeSwayAngle > 3.0f || summerTreeSwayAngle < -3.0f) {
        summerTreeSwaySpeed *= -1;
    }
}

void summerAnimateRiver()
{
    summerRiverWavePhase += 0.05f;
}

void summerAnimateSmoke()
{
    if (summerSmokeVisible && summerTrainMoving) {
        summerSmokeOpacity -= 0.01f;
        if (summerSmokeOpacity <= 0) {
            summerSmokeOpacity = 1.0f;
        }
    }
}

void summerAnimateAll()
{
    if (summerAnimationsRunning) {
        summerMoveTrain();
        summerMoveCar();
        summerAnimateClouds();
        summerAnimateTrees();
        summerAnimateRiver();
        summerAnimateSmoke();
    }
}

// ============ SCENE 1 - INTERACTION FUNCTIONS ============

void summerHandleMouseClick(int button, int state, int x, int y)
{
    // Convert screen coordinates to OpenGL coordinates
    float glX = (x / (float)WINDOW_WIDTH) * (ORTHO_RIGHT - ORTHO_LEFT);
    float glY = (WINDOW_HEIGHT - y) / (float)WINDOW_HEIGHT * (ORTHO_TOP - ORTHO_BOTTOM);

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Check if clicked on train
        if (glX >= summerTrainX && glX <= summerTrainX + 8 &&
            glY >= TRAIN_TRACK_Y && glY <= TRAIN_TRACK_Y + 4) {
            summerTrainMoving = !summerTrainMoving;
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Check if clicked on sun
        if (sqrt(pow(glX - summerSunX, 2) + pow(glY - summerSunY, 2)) <= 3.0f) {
            summerSunBrightness = (summerSunBrightness == 1.0f) ? 0.5f : 1.0f;
        }
    }
}

void summerHandleKeyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 's':
        case 'S':
            summerAnimationsRunning = !summerAnimationsRunning;
            break;
        case 't':
        case 'T':
            summerTrainMoving = !summerTrainMoving;
            break;
        case 'c':
        case 'C':
            summerCarMoving = !summerCarMoving;
            break;
        case 'x':
        case 'X':
            summerTreeSwaySpeed = (summerTreeSwaySpeed == 0) ? 0.05f : 0;
            break;
        case 'z':
        case 'Z':
            cout << "Moving to next scene (Monsoon)..." << endl;
            // TODO: Add scene transition logic
            break;
        case 27: // ESC key
            exit(0);
            break;
    }
}

// ============ MAIN DISPLAY FUNCTION ============

void display()
{
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Sky blue background
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw all scene elements in order (back to front)
    summerDrawSky();
    summerDrawHills();
    summerDrawClouds();
    summerDrawSun();
    summerEnhanceTaiyeba();  // ← TAIYEBA'S ENHANCEMENT
    summerDrawTrees();
    summerDrawRuralHouse();
    summerDrawRiver();
    summerDrawGrass();
    summerDrawTrack();
    summerDrawTrain();
    summerDrawCar();

    glutSwapBuffers();
}

// ============ TIMER FOR ANIMATIONS ============

void timer(int value)
{
    summerAnimateAll();
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

// ============ RESHAPE FUNCTION ============

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_BOTTOM, ORTHO_TOP);
    glMatrixMode(GL_MODELVIEW);
}

// ============ MAIN FUNCTION ============

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Train Journey - Scene 1: Summer");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_BOTTOM, ORTHO_TOP);

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(summerHandleMouseClick);
    glutKeyboardFunc(summerHandleKeyboard);
    glutTimerFunc(16, timer, 0);

    cout << "========== Scene 1: Summer Scene ==========" << endl;
    cout << "Controls:" << endl;
    cout << "  S - Start/Stop all animations" << endl;
    cout << "  T - Start/Stop train" << endl;
    cout << "  C - Start/Stop car" << endl;
    cout << "  X - Toggle tree sway" << endl;
    cout << "  Z - Move to next scene" << endl;
    cout << "  Left Click on Train - Toggle train movement" << endl;
    cout << "  Right Click on Sun - Toggle brightness" << endl;
    cout << "  ESC - Exit" << endl;
    cout << "==========================================" << endl;

    glutMainLoop();

    return 0;
}
