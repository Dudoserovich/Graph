#include <iostream>
#include "graph.h"

int main() {
    Graph g;
/*    g.print();

    g.addNode(2);
    g.print();

    std::cout << std::endl;
    g.addNode(1);
    g.print();

    std::cout << std::endl;
    g.addArc(2, 2, 1);
    g.print();

    std::cout << std::endl;
    g.addArc(2, 1, 4);
    g.print();

    std::cout << std::endl;
    g.addArc(1, 2, 3);
    g.print();*/

    //g.~Graph();
/*    std::cout << std::endl;
    g.delArc(2, 1);
    g.delArc(2, 2);
    g.delNode(2);
    g.print();*/

// =============Обходик============

// Первый тест
/*
    for(int i = 1; i < 7; i++)
        g.addNode(i);

   g.addArc(1, 2);
    g.addArc(1, 3);
    g.addArc(2, 3);
    g.addArc(2, 4);
    g.addArc(3, 4);
    g.addArc(4, 5);
    g.addArc(5, 1);
    g.addArc(5, 2);
    g.addArc(5, 6);
    g.print();

    g.roundWidth(2);*/

    // Второй тест
    for(int i = 1; i < 8; i++)
        g.addNode(i);

    g.addArc(1, 2);
    g.addArc(1, 3);
    g.addArc(2, 4);
    g.addArc(2, 5);
    g.addArc(3, 6);
    g.addArc(3, 7);
    g.roundWidth(1);

    // Второй тест v1.1
    g.roundWidth(2);

    // Второй тест v1.2
    g.roundWidth(4);

    // =============ДЕЙКСТРА============
    Graph a;

    a.addNode(5);
    a.addNode(1);
    a.addNode(3);
    a.addNode(6);
    a.addNode(4);

    a.addArc(5,6,5);
    a.addArc(1,3,4);
    a.addArc(5,1,5);
    a.addArc(3,5,8);
    a.addArc(5,5,2);
    a.addArc(4,5,4);
    a.addArc(4,1,8);
    a.addArc(4,3,5);
    a.addArc(4,6,9);

    a.addArc(5,4, 3);
    a.addArc(1,4, 6);
    a.addArc(3,4, 8);
    a.addArc(4,4, 7);

    a.DIJKSTRA(3);

    std::cout << "------------------------------------------------------------" << std::endl;
    a.print();
    std::cout << "------------------------------------------------------------" << std::endl;

    Graph G1;
    for (int i = 1; i < 7; ++i) {
        G1.addNode(i);
    }

    G1.addArc(1, 4, 4);
    G1.addArc(1, 6, 1);
    G1.addArc(4, 6, 4);
    G1.addArc(4, 2, 5);
    G1.addArc(2, 5, 5);
    G1.addArc(2, 3, 6);
    G1.addArc(3, 5, 7);
    G1.addArc(3, 6, 2);
    G1.addArc(5, 6, 4);
    G1.DIJKSTRA(4);
    G1.print();

/*    Graph g1 = g;

    std::cout << "После коппирования(без изменений графов)" << '\n' << "Коппируемый граф:" << std::endl;
    g.print();
    std::cout << "\nПолученный граф:" << std::endl;
    g1.print();

    g1.addNode(8);
    g1.addArc(1,8);
    std::cout << "После коппирования(изменённый полученный граф)" << '\n' << "Коппируемый граф:" << std::endl;
    g.print();
    std::cout << "\nПолученный граф:" << std::endl;
    g1.print();*/

    return 0;
}
