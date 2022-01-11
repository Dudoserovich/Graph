#include "graph.h"

// Конструктор по умолчанию
Graph::Graph() {
    root = nullptr;
}

// Конструктор с одной вершиной
Graph::Graph(int a) {
    root = nullptr;
    addNode(a);
    //root = new node();
    //root->value = 1;
}

// Конструктор копирования
Graph::Graph(const Graph &graph) {
    node *thisNode;
    arc *thisArc;

    thisNode = graph.root;

    this->root = nullptr;
    // коппирование если пустой граф
    if (thisNode == nullptr)
        this->root = nullptr;
    else { // если коппируется не пустой граф
        // добавляем все вершины из graph
        while (thisNode != nullptr) {
            // добавляем вершину из graph в this
            this->addNode(thisNode->value);

            thisNode = thisNode->nextNode; // следуюшая вершина graph
        }

        // добавляем связи вершин
        thisNode = graph.root;
        while (thisNode != nullptr) {
            thisArc = thisNode->arcs;
            int a = thisNode->value; // начало ребра
            int b; // конец ребра
            int weight; // вес ребра

            while (thisArc != nullptr) {
                b = thisArc->node_->value; // копируем конец ребра
                weight = thisArc->weight; // коппируем вес ребра
                this->addArc(a, b, weight); // добавляем связь

                thisArc = thisArc->nextArc; // следующее коппируемое ребро
            }

            thisNode = thisNode->nextNode;
        }
    }
}

// Деструктор
Graph::~Graph() {
    //std::cout << "Деструктор" << std::endl;
    node *help;

    delNode(root->value);
/*        while (root != nullptr) {
            help = root->nextNode;
            delNode(help->value);
            root = help;
        }*/
    root = nullptr;
}

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
int Graph::addNode(int a) {
    if (root == nullptr) {
        root = new node;
        root->value = a;
        root->nextNode = nullptr;
        return true;
    } else {
        // поиск ноды с таким же номером (вдруг уже существует)
        node *cur = root;

        if (cur->value > a) {
            // добавление новой ноды в начало
            root = new node;
            root->value = a;
            root->nextNode = cur;
            return true;
        } else if (cur->value == a) {
            std::cout << "Такая вершина уже есть!" << std::endl;
            return false;
        }

        while (cur->nextNode != nullptr) {
            if (cur->nextNode->value > a) {
                // добавление новой ноды в середину (упорядочено)
                node *newNode = new node;
                newNode->value = a;
                newNode->nextNode = cur->nextNode;
                cur->nextNode = newNode;
                return true;
            } else if (cur->nextNode->value == a) {
                return false;
            }
            cur = cur->nextNode;
        }

        // добавление ноды в конец
        node *newNode = new node;
        newNode->value = a;
        cur->nextNode = newNode;
        return true;

    }

    // новая нода
    // ищем куда запихать
    // пихаем
}

// Добавление дуги (неупорядочено)
int Graph::addArc(int a, int b, int weight) { // a - начало, b - конец

    // проверка на попытку задать отрицательный вес
    if (weight < 0) {
        std::cout << "Вес не может быть отрицательным" << std::endl;
        return 0;
    }

    node *curA = root;
    node *curB = root;

    // ищем первую вершину (начало ребра)
    while (curA != nullptr && curA->value != a) {
        curA = curA->nextNode;
    }
    // ищем вторую вершину (конец ребра)
    while (curB != nullptr && curB->value != b) {
        curB = curB->nextNode;
    }

    // проверяем найдены ли такие вершины
    if (curA == nullptr) {
        std::cout << "Ноды " << a << " нет!" << std::endl;
        return 0;
    }
    if (curB == nullptr) {
        std::cout << "Ноды " << b << " нет!" << std::endl;
        return 0;
    }

    if (curA->value == a && curB->value == b) {
        // смотрим есть ли такая дуга

        // если искомая дуга первая
        if (curA->arcs == nullptr) {
            curA->arcs = new arc();
            curA->arcs->node_ = curB;

            curA->arcs->weight = weight;

            return 1;
        } else { // если не первая
            arc *curArc = curA->arcs;

            // бежим по всем дугам, пока что-ниюудь не найдём или нет
            while (curArc->nextArc != nullptr) {
                if (curArc->node_ == curB) {
                    std::cout << "Такая дуга уже есть!" << std::endl;
                    return 0;
                } else {
                    curArc = curArc->nextArc;
                }
            }

            if (curArc->node_ == curB) {
                std::cout << "Такая дуга уже есть!" << std::endl;
                return 0;
            } else {
                curArc->nextArc = new arc();
                curArc->nextArc->node_ = curB;

                curArc->nextArc->weight = weight;

                return 1;
            }
        }
    }

}

int Graph::delNode(int a) {
    // существует ли вершина?
    node *nodeA = root;
    node *nodeHelp = nullptr;

    while (nodeA != nullptr && nodeA->value != a) {
        nodeHelp = nodeA;
        nodeA = nodeA->nextNode;
    }

    if (nodeA == nullptr) {
        std::cout << "node " << a << " not found" << std::endl;
        return false;
    }

    // идём по всем вершинам и ищем вхождение вершины в дугах. Удаляем эти дуги
    node *curNode = root;
    arc *curArc;
    arc *helpArc;

    while (curNode != nullptr) {
        curArc = curNode->arcs;

        if (curArc != nullptr) {
            while (curArc != nullptr) {
                helpArc = curArc;
                curArc = curArc->nextArc;
                if (helpArc->node_ == nodeA) {
                    delArc(curNode->value, a); // храни господь эту строчку
                }
            }
        }

        curNode = curNode->nextNode;
    }

    // удаляем все дуги выходящие из вершины А
    curArc = nodeA->arcs;
    arc *curArcHelp;

    while (curArc != nullptr) {
        curArcHelp = curArc;
        curArc = curArc->nextArc;
        delete curArcHelp;
    }

    // удаляем вершину A
    if (nodeHelp == nullptr) { // А - первая вершина списка
        root = nodeA->nextNode;
    } else if (nodeA->nextNode == nullptr) { // А - последняя вершина списка
        nodeHelp->nextNode = nullptr;
    } else { // А - вершина в середине
        nodeHelp->nextNode = nodeA->nextNode;
    }
    delete nodeA;
    return true;
}

//Удаление дуги
int Graph::delArc(int a, int b) {
    node *nodeA = root;
    node *nodeB = root;

    while (nodeA != nullptr && nodeA->value != a) {
        nodeA = nodeA->nextNode;
    }
    while (nodeB != nullptr && nodeB->value != b) {
        nodeB = nodeB->nextNode;
    }

    if (nodeA == nullptr) {
        std::cout << "node " << a << " not found" << std::endl;
        return false;
    }
    if (nodeB == nullptr) {
        std::cout << "node " << b << " not found" << std::endl;
        return false;
    }

    arc *curArc = nodeA->arcs;
    arc *lastArc = nullptr;

    while (curArc != nullptr && curArc->node_ != nodeB) { // ищем дугу
        lastArc = curArc;
        curArc = curArc->nextArc;
    }

    if (curArc->node_ == nodeB) {
        if (lastArc == nullptr) { // АB - первая дуга
            lastArc = curArc->nextArc;
            nodeA->arcs = lastArc;
        } else if (curArc->nextArc == nullptr) { // АB - последняя дуга списка
            lastArc->nextArc = nullptr;
        } else { // А - вершина в середине
            lastArc->nextArc = curArc->nextArc;
        }
        delete curArc;
        return true;

    } else return false;

}

//Поиск вершины
int Graph::searchNode(int a) {
    node *nodeA = root;

    while (nodeA != nullptr && nodeA->value != a) {
        nodeA = nodeA->nextNode;
    }

    if (nodeA == nullptr) {
        std::cout << "Нода " << a << " не найдена!" << std::endl;
        return false;
    } else return true;
}

//Поиск дуги
int Graph::searchArc(int a, int b) {
    node *nodeA = root;
    node *nodeB = root;

    while (nodeA != nullptr && nodeA->value != a) {
        nodeA = nodeA->nextNode;
    }
    while (nodeB != nullptr && nodeB->value != b) {
        nodeB = nodeB->nextNode;
    }

    if (nodeA == nullptr) {
        std::cout << "нода " << a << " не найдена!" << std::endl;
        return false;
    }
    if (nodeB == nullptr) {
        std::cout << "нода " << b << " не найдена!" << std::endl;
        return false;
    }

    arc *curArc = nodeA->arcs;

    while (curArc != nullptr && curArc->node_ != nodeB) { // ищем дугу
        curArc = curArc->nextArc;
    }

    if (curArc != nullptr && curArc->node_ == nodeB) {
        return true;
    } else return false;
}

// Печать графа
void Graph::print() {
    node *thisNode;
    arc *thisArc;

    thisNode = root;

    if (thisNode == nullptr)
        std::cout << "Граф пуст!" << std::endl;
    else {
        while (thisNode != nullptr) {
            std::cout << "|" << thisNode->value << "| D(";
            //<< thisNode->p
            if (thisNode->p == nullptr) std::cout << "undefined";
            else std::cout << thisNode->p->value;
            std::cout << ") | -> ";
            thisArc = thisNode->arcs;

            while (thisArc != nullptr) {
                std::cout << thisArc->node_->value << "(вес: " << thisArc->weight << ")" << " -> ";
                thisArc = thisArc->nextArc;
            }
            std::cout << '\\' << std::endl;

            thisNode = thisNode->nextNode;
        }
    }
}

// Обход графа в ширину (вершины) А-2.2.3 (стр.82) 2.2.4 (стр.82)
bool Graph::roundWidth(int a) {
    // коппируем граф, чтобы от греха подальше ничего не ломать
    Graph g = *this;
    //g.print();

    // ищем начальную вершину
    node *nodeA = g.root;

    while (nodeA != nullptr && nodeA->value != a) {
        nodeA = nodeA->nextNode;
    }

    if (nodeA == nullptr) {
        std::cout << "Начальная нода " << a << " не найдена!" << std::endl;
        return false;
    }

    // нашли искомую ноду, теперь сам алгоритм обхода с запоминанием вершин с использованием очереди
    std::queue<node*> Q;
    //std::queue<node*> out;
    Q.push(nodeA);

    //std::cout << Q.front()->value << '|' << Q.back()->arcs->node_->value<< std::endl;
    nodeA->mark = 1; // помечаем начальную вершину

    arc* w = nullptr; // проходимая дуга

    std::cout << "Обход в ширину(вершины): ";

    while (!Q.empty()) {
        arc* q = Q.front()->arcs; // записываем все исходящие вершины
        w = Q.front()->arcs; // записываем текущее ребро

        while (w != nullptr) {
/*                if (w->mark) {
                    w = nullptr;
                    continue;
                }*/
            w->mark = true; // прошли дугу

            node* p = w->node_; // записываем конец ребра
            if (p->mark == 0) { // если вершина не помечена, помечаем и записываем в стек
                p->mark = 1;
                Q.push(p);
            }

            w = w->nextArc; // следующая дуга
        }

        if (q != nullptr) {
            if (q->node_->mark == 1) {
                q->node_->mark = 2;
            }
/*                if (q->node_->mark == 2) {
                    out.push(q->node_);
                }*/
        }

        if (q != nullptr)
            q = q->nextArc;
        if (q == nullptr || q->mark) {
            std::cout << Q.front()->value << ' ';
            Q.pop();
        }
    }

    std::cout << std::endl;

    // Чистка нод и рёбер


/*       // вывод прохода
       while (!out.empty()) {
           std::cout << out.front()->value << ' ';
           out.pop();
       }
       std::cout << std::endl;*/

    // создаём очередь вершин
    // пихаем начальную вершину в очередь и помечаем

    // сам алгоритм обхода

}

// Алгоритм Дейкстры
void Graph::ISS (node *s) {
    node *curNode = root;

    while (curNode != nullptr) {
        curNode->d = INT32_MAX;
        curNode->p = nullptr;
        curNode = curNode->nextNode;
    }

    s->d = 0;
}

void Graph::chill (node *u, arc *a) {
    if (a->node_->d > u->d + a->weight) {
        a->node_->d = u->d + a->weight;
        a->node_->p = u;
    }
}

int Graph::countNode(){
    node *curNode = root;
    int count = 0;

    while (curNode != nullptr) {
        count++;
        curNode = curNode->nextNode;
    }
    return count;
}

bool Graph::isEmpty(node *Q[], int count) {
    for (int i = 0; i < count; ++i) {
        if (Q[i] != nullptr) return false;
    }
    return true;
}

node* Graph::extractMin(node *Q[], int count) {
    node *min_node = new node;
    min_node->d = INT32_MAX;
    int c = -1;

    if(!isEmpty(Q,count)) {
        for (int i = 0; i < count; ++i) {
            if (Q[i] == nullptr) {
                continue;
            }

            if (Q[i]->d < min_node->d) {
                min_node = Q[i];
                c = i;
            }
        }
    }

    Q[c] = nullptr;

    return min_node;
}

void Graph::DIJKSTRA(int a) {
    int count = countNode();
    //int countQ = count;
    int countS = 0;

    node *S[count];
    node *Q[count];

    node *u = nullptr;

    node *curNode = root;

    while (curNode != nullptr && curNode->value != a) {
        curNode = curNode->nextNode;
    }

    if (curNode == nullptr) {
        std::cout << "Такой ноды нет!" << std::endl;
        return;
    }

    ISS(curNode);

    node *helpNode = root;

    // инициализация Q и S
    for (int i = 0; i < count; ++i) {
        S[i] = nullptr;
        Q[i] = helpNode;
        helpNode = helpNode->nextNode;
    }

    while (!isEmpty(Q, count)) {
        u = extractMin(Q, count);
        S[countS] = u;
        countS++;

        // для каждого ребра U помечаем вершины как достижимые за определённо расстояние

        // 1. узнать сколько у нас рёбер из U
        //
        arc *curArc = u->arcs;
        while (curArc != nullptr) {
            // relax()
            chill(u, curArc);
            curArc = curArc->nextArc;
        }

    }
}