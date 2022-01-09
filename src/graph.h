#pragma once

#include <iostream>
#include <queue>

#include "types.h"

// ОРИЕНТИРОВАННЫЙ ГРАФ
// список смежности (односвязный список)
// неупорядоченный добавление в конец

// Конструктор (+)
// Деструкор (+)
// Добавление вершины (+)
// Добавление дуги (+)
// Удаление вершины (+)
// Удаление дуги (+)
// Поиск вершины (+)
// Поиск дуги (+)
// Печать графа (+)

// Обход (+)
// Обход графа в ширину (вершины) А-2.2.3 (стр.82) 2.2.4 (стр.82)

// Алгоритм (+)
// Алгоритм Дейкстры

// создаём массив 1xN с точками

class Graph {
    node *root;

public:
    // Конструктор по умолчанию
    Graph();

    // Конструктор с одной вершиной
    Graph(int a);

    // Конструктор копирования
    Graph(const Graph &graph);

    // Деструктор
    ~Graph();

    // Добавление вершины (неупорядочено)
/*    int addNode (int a) {
        if (root == nullptr) {
            root = new node();
            root->value = a;
            return 1;
        } else {
            *//*node *newNode = new node();*//*
            node *cur = root;

            while (cur->nextNode != nullptr) {
                if (cur->value == a) {
                    std::cout << "Такая вершина уже есть!" << std::endl;
                    return 0;
                } else {
                    cur = cur->nextNode;
                }
            }

            if (cur->value == a) {
                std::cout << "Такая вершина уже есть!" << std::endl;
                return 0;
            } else {
                cur->nextNode = new node();
                cur->nextNode->value = a;
                return 1;
            }
        }

        // новая нода
        // ищем конец
        // добавляем в конец

    }*/

    // Добавление вершины (упорядочено)
    int addNode(int a);

    // Добавление дуги (неупорядочено)
    int addArc(int a, int b, int weight = 1);

    int delNode(int a);

    //Удаление дуги
    int delArc(int a, int b);

    //Поиск вершины
    int searchNode(int a);

    //Поиск дуги
    int searchArc(int a, int b);

    // Печать графа
    void print();

    // Обход графа в ширину (вершины) А-2.2.3 (стр.82) 2.2.4 (стр.82)
    bool roundWidth(int a);

    // вспомогательные функции для Дейкстры
private:
    void ISS (node *s);

    void chill (node *u, arc *a);

    int countNode();

    bool isEmpty(node *Q[], int count);

    node *extractMin(node *Q[], int count);

public:
    // Алгоритм Дейкстры
    void DIJKSTRA(int a);
};
