#include <iostream>
#include <graphics.h>
#include <cstdio>
#include "graph.h"

using namespace std;

int main()
{
    freopen("task1.txt", "r", stdin);

    int n;
    cin >> n;
    int *matrix = new int[n*n]();


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int c;
            cin >> c;
            matrix[i*n+j] = c;
        }
    }
    cout << "matrix initialized" << endl;

    Graph graph = Graph(matrix, n);

    cout << "graph initialized" << endl;


    int gd = CUSTOM;
    int gm = CUSTOM_MODE(800,800);
    initgraph(&gd, &gm, "");
    graph.show();
    readkey();

    graph.tranz(matrix, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i*n+j] ;
        }
        cout << endl;
    }
    readkey();
}
