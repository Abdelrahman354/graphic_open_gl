from OpenGL.GL import *

from OpenGL.GLU import *
from OpenGL.GLUT import glutBitmapCharacter, glutBitmapString
from OpenGL.GLUT import GLUT_BITMAP_HELVETICA_18
from OpenGL.GLUT import GLUT_BITMAP_TIMES_ROMAN_24

from OpenGL.GLUT import *
from math import sin, cos
import random

b = None  # Declare a variable b
s = None  # Declare a variable s
buildColor = None  # Declare a variable buildColor
score_Str = None  # Declare a variable score_Str
slevel = None  # Declare a variable slevel
gameEndStatus = None  # Declare a variable gameEndStatus


class Building:
    def _init_(self):
        self.block_x = 0.0
        self.no_floors = 0
        self.block_y = 0.0
        self.state = False


class Cloud:
    def _init_(self):
        self.block_x = 0.0
        self.block_y = 0.0
        self.state = False


def buildingBlock():
    global b, buildColor
    b.block_x = 50.0
    random.seed()
    b.no_floors = random.randint(4, 6)
    buildColor = random.randint(0, 2)
    b.block_y = b.no_floors * 10 + 15
    b.state = True
    s.state = False


def CloudBlock():
    global s
    s.block_x = 50.0
    random.seed()
    s.block_y = random.randint(50, 80)
    s.state = True
    b.state = False


def semiCircle(p1, q1, radius):
    angle = 1.0
    glBegin(GL_POINTS)
    while angle < 360.0:
        p = p1 + sin(angle) * radius
        q = q1 + cos(angle) * radius
        if q >= 100:
            glVertex2f(p, q)
        angle += 1.0
    glEnd()


def Circle(x1, y1, radius):
    angle = 1.0
    glBegin(GL_POINTS)
    while angle < 360.0:
        x2 = x1 + sin(angle) * radius
        y2 = y1 + cos(angle) * radius
        glVertex2f(x2, y2)
        angle += 1.0
    glEnd()


def drawJet():
    # left tail wing
    glColor3f(1.0, 1.0, 0.6)
    glBegin(GL_POLYGON)
    glVertex2f(5.5, 47.0)
    glVertex2f(8.5, 47.0)
    glVertex2f(5.5, 48.0)
    glVertex2f(4.5, 48.0)
    glEnd()

    # left front wing
    glColor3f(0.6, 0.6, 0.6)
    glBegin(GL_POLYGON)
    glVertex2f(13.0, 47.0)
    glVertex2f(20.0, 47.0)
    glVertex2f(13.0, 50.0)
    glVertex2f(11.0, 50.0)
    glEnd()

    # tail
    glColor3f(1.0, 0.5, 0.5)
    glBegin(GL_POLYGON)
    glVertex2f(4.7, 45.0)
    glVertex2f(5.5, 51.0)
    glVertex2f(7.0, 51.0)
    glVertex2f(9.0, 45.0)
    glEnd()

    # body
    glColor3f(0.5, 1.0, 0.5)
    glBegin(GL_POLYGON)
    glVertex2f(8.5, 45.0)
    glVertex2f(14.5, 45.0)
    glVertex2f(17.5, 46.0)
    glVertex2f(8.5, 46.0)
    glEnd()

    # right front wing
    glColor3f(0.6, 0.6, 0.6)
    glBegin(GL_POLYGON)
    glVertex2f(15.0, 47.0)
    glVertex2f(22.0, 47.0)
    glVertex2f(19.0, 50.0)
    glVertex2f(15.0, 50.0)
    glEnd()

    # right tail wing
    glColor3f(1.0, 1.0, 0.6)
    glBegin(GL_POLYGON)
    glVertex2f(8.5, 47.0)
    glVertex2f(11.5, 47.0)
    glVertex2f(11.5, 48.0)
    glVertex2f(10.5, 48.0)
    glEnd()

    # cockpit
    glColor3f(0.3, 0.3, 0.9)
    glBegin(GL_POLYGON)
    glVertex2f(11.0, 46.0)
    glVertex2f(14.0, 46.0)
    glVertex2f(15.0, 47.0)
    glVertex2f(10.0, 47.0)
    glEnd()

    # engine
    glColor3f(0.5, 0.5, 0.5)
    glBegin(GL_POLYGON)
    glVertex2f(8.5, 45.0)
    glVertex2f(9.5, 45.0)
    glVertex2f(9.5, 43.0)
    glVertex2f(8.5, 43.0)
    glEnd()

    # flame
    glColor3f(1.0, 0.3, 0.0)
    glBegin(GL_POLYGON)
    glVertex2f(8.5, 41.0)
    glVertex2f(9.5, 41.0)
    glVertex2f(9.5, 43.0)
    glVertex2f(8.5, 43.0)
    glEnd()


def drawString(x, y, z, font, string):
    glRasterPos3f(x, y, z)
    for c in string:
        glutBitmapCharacter(font, ord(c))


def gameEnd():
    global score_Str, gameEndStatus
    drawBg()

    glColor3f(0.3, 0.3, 0.3)
    glBegin(GL_POLYGON)
    glVertex2f(20.0, 35.0)
    glVertex2f(40.0, 35.0)
    glVertex2f(40.0, 65.0)
    glVertex2f(20.0, 65.0)
    glEnd()

    glColor3f(1.0, 1.0, 0.0)
    glBegin(GL_POLYGON)
    glVertex2f(19.5, 34.5)
    glVertex2f(40.5, 34.5)
    glVertex2f(40.5, 65.5)
    glVertex2f(19.5, 65.5)
    glEnd()

    glColor3f(0.3, 0.3, 0.3)
    glBegin(GL_POLYGON)
    glVertex2f(20.0, 30.0)
    glVertex2f(40.0, 30.0)
    glVertex2f(40.0, 70.0)
    glVertex2f(20.0, 70.0)
    glEnd()

    glColor3f(1.0, 1.0, 0.0)
    glBegin(GL_POLYGON)
    glVertex2f(19.5, 29.5)
    glVertex2f(40.5, 29.5)
    glVertex2f(40.5, 70.5)
    glVertex2f(19.5, 70.5)
    glEnd()

    glColor3f(0.0, 0.0, 0.0)
    glBegin(GL_POLYGON)
    glVertex2f(20.0, 20.0)
    glVertex2f(40.0, 20.0)
    glVertex2f(40.0, 30.0)
    glVertex2f(20.0, 30.0)
    glEnd()

    glColor3f(1.0, 1.0, 1.0)
    drawString(21.0, 22.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Game Over")

    drawString(21.0, 40.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Score: " + score_Str)

    if gameEndStatus == 1:
        drawString(21.0, 50.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "You Crashed!")
    elif gameEndStatus == 2:
        drawString(21.0, 50.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "You Landed Safely!")

    drawString(23.0, 60.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Press R to Restart")


def drawBg():
    # sky
    glColor3f(0.0, 0.8, 1.0)
    glBegin(GL_POLYGON)
    glVertex2f(0.0, 0.0)
    glVertex2f(100.0, 0.0)
    glVertex2f(100.0, 100.0)
    glVertex2f(0.0, 100.0)
    glEnd()

    # ground
    glColor3f(0.0, 1.0, 0.0)
    glBegin(GL_POLYGON)
    glVertex2f(0.0, 0.0)
    glVertex2f(100.0, 0.0)
    glVertex2f(100.0, 15.0)
    glVertex2f(0.0, 15.0)
    glEnd()

    # mountains
    glColor3f(0.5, 0.5, 0.5)
    glBegin(GL_TRIANGLES)
    glVertex2f(0.0, 15.0)
    glVertex2f(5.0, 25.0)
    glVertex2f(10.0, 15.0)
    glEnd()

    glColor3f(0.5, 0.5, 0.5)
    glBegin(GL_TRIANGLES)
    glVertex2f(5.0, 15.0)
    glVertex2f(10.0, 25.0)
    glVertex2f(15.0, 15.0)
    glEnd()

    glColor3f(0.5, 0.5, 0.5)
    glBegin(GL_TRIANGLES)
    glVertex2f(10.0, 15.0)
    glVertex2f(15.0, 25.0)
    glVertex2f(20.0, 15.0)
    glEnd()

    # sun
    glColor3f(1.0, 1.0, 0.0)
    Circle(75.0, 85.0, 7.0)

    # clouds
    glColor3f(1.0, 1.0, 1.0)
    if s.state:
        Circle(s.block_x, s.block_y, 2.0)
        Circle(s.block_x + 3, s.block_y, 2.0)
        Circle(s.block_x + 1.5, s.block_y + 1.5, 2.0)

    # building
    if b.state:
        if buildColor == 0:
            glColor3f(0.5, 0.5, 0.5)
        elif buildColor == 1:
            glColor3f(0.6, 0.6, 0.6)
        else:
            glColor3f(0.7, 0.7, 0.7)
        glBegin(GL_POLYGON)
        glVertex2f(b.block_x, b.block_y)
        glVertex2f(b.block_x + 10, b.block_y)
        glVertex2f(b.block_x + 10, b.block_y - b.no_floors * 10)
        glVertex2f(b.block_x, b.block_y - b.no_floors * 10)
        glEnd()


def drawScene():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()

    drawBg()

    glColor3f(1.0, 1.0, 1.0)
    drawString(5.0, 95.0, 0.0, GLUT_BITMAP_HELVETICA_18, "Score: " + score_Str)

    if slevel == 1:
        drawString(70.0, 95.0, 0.0, GLUT_BITMAP_HELVETICA_18, "Level: Easy")
    elif slevel == 2:
        drawString(70.0, 95.0, 0.0, GLUT_BITMAP_HELVETICA_18, "Level: Medium")
    elif slevel == 3:
        drawString(70.0, 95.0, 0.0, GLUT_BITMAP_HELVETICA_18, "Level: Hard")

    drawJet()

    if b.state:
        if buildColor == 0:
            glColor3f(0.5, 0.5, 0.5)
        elif buildColor == 1:
            glColor3f(0.6, 0.6, 0.6)
        else:
            glColor3f(0.7, 0.7, 0.7)
        glBegin(GL_POLYGON)
        glVertex2f(b.block_x, b.block_y)
        glVertex2f(b.block_x + 10, b.block_y)
        glVertex2f(b.block_x + 10, b.block_y - b.no_floors * 10)
        glVertex2f(b.block_x, b.block_y - b.no_floors * 10)
        glEnd()

    if s.state:
        glColor3f(1.0, 1.0, 1.0)
        Circle(s.block_x, s.block_y, 2.0)
        Circle(s.block_x + 3, s.block_y, 2.0)
        Circle(s.block_x + 1.5, s.block_y + 1.5, 2.0)

    glutSwapBuffers()


def update(x=0, y=0):
    if b.state:
        b.block_x -= 0.15
        if b.block_x < -10.0:
            b.state = False
    if s.state:
        s.block_x -= 0.1
        if s.block_x < -4.0:
            s.state = False
    glutPostRedisplay()


def reshape(width, height):
    if height == 0:
        height = 1
    glViewport(0, 0, width, height)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluOrtho2D(0.0, 100.0, 0.0, 100.0)
    glMatrixMode(GL_MODELVIEW)


def specialKeys(key, x, y):
    global gameEndStatus
    if key == GLUT_KEY_RIGHT:
        if b.state:
            if b.block_y >= 35.0 and b.block_y <= 47.0:
                if b.block_x <= 22.0 and b.block_x >= 18.0:
                    gameEndStatus = 2
                else:
                    gameEndStatus = 1
            else:
                gameEndStatus = 1
        else:
            gameEndStatus = 1
        glutIdleFunc(gameEnd)
    elif key == GLUT_KEY_LEFT:
        pass


def normalKeys(key, x, y):
    global b, s, score_Str, slevel, gameEndStatus
    if key == b"r":
        b = Building()
        s = Cloud()
        score_Str = "0"
        slevel = 1
        gameEndStatus = 0
        buildingBlock()
        glutPostRedisplay()


def menuOptions(option):
    global slevel
    if option == 1:
        slevel = 1
    elif option == 2:
        slevel = 2
    elif option == 3:
        slevel = 3


def createMenu():
    menu = glutCreateMenu(menuOptions)
    glutAddMenuEntry("Easy", 1)
    glutAddMenuEntry("Medium", 2)
    glutAddMenuEntry("Hard", 3)
    glutAttachMenu(GLUT_RIGHT_BUTTON)


def init():
    glClearColor(0.0, 0.0, 0.0, 0.0)
    glClearDepth(1.0)
    glEnable(GL_DEPTH_TEST)
    glDepthFunc(GL_LEQUAL)
    glShadeModel(GL_SMOOTH)
    createMenu()


def main():
    glutInit()
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH)
    glutInitWindowSize(800, 600)
    glutInitWindowPosition(100, 100)
    glutCreateWindow("Airplane Game")
    init()
    glutDisplayFunc(drawScene)
    glutIdleFunc(update)
    glutReshapeFunc(reshape)
    glutSpecialFunc(specialKeys)
    glutKeyboardFunc(normalKeys)
    glutMainLoop()


if _name_ == '_main_':
    b = Building()
    s = Cloud()
    score_Str = "0"
    slevel = 1
    gameEndStatus = 0
    buildingBlock()
    main()
