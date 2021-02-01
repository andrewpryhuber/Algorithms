#ifndef NODE_H
#define NODE_H

#include <vector>

class Node 
{
    public:
        Node(int val);
        int getVal();
        bool visited;


    private: 
        int val;
        std::vector<Node*> adjacent;

};



#endif