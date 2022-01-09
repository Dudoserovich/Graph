#pragma once

struct node;
struct arc;

struct node { // вершина графа

    int value; // номер вершины
    node *nextNode; // следующая вершина
    arc *arcs; // ссылка на список дуг

    // для обхода в ширину
    int mark = 0; // 0 - непомечена, 1 - помечена и не пройдена, 2 - помечена и пройдена

    // для дейкстры
    int d = INT16_MAX;
    node *p = nullptr;

    node() {
        nextNode = nullptr;
        arcs = nullptr;
    }

};

struct arc { // дуга графа
    node *node_; // ссылка на вершину из массива 1xn
    arc *nextArc; // ссылка на следующую вершину
    int weight;

    // для обхода в ширину
    bool mark = false; //

    arc() {
        node_ = nullptr;
        nextArc = nullptr;
    }

};