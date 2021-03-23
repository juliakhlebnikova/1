#include "graph.h"
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <cstdio>
#define PI 3.1415

clCircle::clCircle(int a, int n) {
    num = a;
    x = 400 + 300 * cos(2 * PI * a / n);
    y = 400 + 300 * sin(2 * PI * a / n);
}

void clCircle::show() {
    ellipse(x, y, 0, 360, r, r);
    char s[10];
    itoa(num + 1, s, 10);
    outtextxy(x - 5, y - 5, s);
}


clLine::clLine(int start, int end, int n) {
    int a = start;
    int b = end;
    x1 = 400 + 280 * (cos(2 * PI * a / n));
    y1 = 400 + 280 * (sin(2 * PI * a / n));
    x2 = 400 + 280 * (cos(2 * PI * b / n));
    y2 = 400 + 280 * (sin(2 * PI * b / n));
}

void clLine::show() {
    line(x1, y1, x2, y2);
    int x1rr = x2 - 20 * (0.966 * (x2 - x1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)) -
                          0.258 * ((y2 - y1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2))));
    int y1rr = y2 - 20 * (0.258 * (x2 - x1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)) +
                          0.966 * ((y2 - y1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2))));
    int x1rr1 = x2 - 20 * (0.966 * (x2 - x1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)) +
                           0.258 * ((y2 - y1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2))));
    int y1rr1 = y2 - 20 * (-0.258 * (x2 - x1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)) +
                           0.966 * ((y2 - y1) / sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2))));
    line(x2, y2, x1rr, y1rr);
    line(x2, y2, x1rr1, y1rr1);
}

/*int clLine::getStart() {return a;}

int clLine::getEnd() {return b;}*/


Graph::Graph(int *matrix, int n) {
    int roots_all[n];
    lines = new clLine *[n * n]();
    roots = new clCircle *[n]();
    for (int i = 0; i < n; ++i) roots_all[i] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i * n + j]) {
                lines[numLines] = new clLine(i, j, n);
                roots_all[i] = 1;
                roots_all[j] = 1;
                numLines++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (roots_all[i]) {
            roots[numRoots] = new clCircle(i, n);
            numRoots++;
        }
    }
}

void Graph::show() {
    for (int i = 0; i < numRoots; ++i) roots[i]->show();
    for (int i = 0; i < numLines; ++i) lines[i]->show();
}

void Graph::tranz(int* matrix, int n) {
    int roots_all[n];
    numLines = 0;
    numRoots = 0;

    lines = new clLine *[n * n]();
    roots = new clCircle *[n]();
    for (int i = 0; i < n; ++i) roots_all[i] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k <n; ++k) {
                if (matrix[i * n + j] && matrix[j * n + k]) {
                    matrix[i * n + k] = 1;
                    lines[numLines] = new clLine(i, k, n);
                    roots_all[i] = 1;
                    roots_all[k] = 1;
                    numLines++;
                }
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        if (roots_all[i]) {
            roots[numRoots] = new clCircle(i, n);
            numRoots++;
        }
    }

    for (int i = 0; i < numRoots; ++i) roots[i]->show();
    for (int i = 0; i < numLines; ++i) lines[i]->show();

}

void clDraw::show() {}

