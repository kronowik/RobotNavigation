#pragma once
#include "Map.h"
#include <list>

class Node
{
private:
    Point fState;
    Node* fParent = NULL;
    std::string fAction;
    int fCost;
    unsigned fDistance;

public:
    Node();
    Node(Point aState, Node* aParent, std::string aAction, int aCost=0, unsigned aDistance=0);

    Point getState() { return fState; }
    Node* getParent() { return fParent; }
    std::string getAction() { return fAction; }
    int getCost() { return fCost; }
    unsigned getDistance() { return fDistance; }
    std::list<Node*> getPredecessors();
};