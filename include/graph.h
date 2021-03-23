#ifndef TASK1_GRAPH_GRAPH_H
#define TASK1_GRAPH_GRAPH_H

#include <graphics.h>
#include "graph.h"

class clDraw{
public:
    virtual void show();
};

class clLine: public clDraw{
private:
    int x1, y1, x2, y2;
public:
    clLine(int start, int end, int n);
    void show() override;
};

class clCircle: public clDraw{
private:
    int num;
    int x, y, r = 20;
public:
    clCircle(int a, int n);
    void show() override;
};

class Graph: public clDraw{
private:
    clLine** lines;
    clCircle** roots;
    int numLines = 0, numRoots = 0;
public:
    Graph(int* matrix, int n);
    void show() override;
    void tranz(int* matrix, int n);
};


#endif //TASK1_GRAPH_GRAPH_H
