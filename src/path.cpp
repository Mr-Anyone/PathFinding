#include <vector>
#include <iostream>
#include "path.h"
#include <cmath>

bool Path::Node::operator==(const Node &node) const {
    return node.m_col == this->m_col && node.m_row == this->m_row;
}

double Path::distance(const Node &start, const Node &end) {
    return std::sqrt(pow(start.m_row - end.m_row, 2) + pow(start.m_col - end.m_col, 2));
}


double Path::Node::fCost(const Node& startNode, const Node& endNode) const {

    return distance(startNode, *this)+ distance(endNode, *this);;
}

double Path::Node::fCost() const {
    return this->g_cost + this->h_cost;
}


static path_t TraverseNode(const Path::Node& endNode){
    path_t path;
    return path;
}

static int smallestFCost(const std::vector<Path::Node>& vet){
    int count = 0;
    for(int i = 0; i<vet.size(); ++i) {
        if (vet[i].fCost() < vet[count].fCost())
            count = i;
    }
    return count;
}

std::vector<Path::Node>
    Path::getNeighbour
        (const std::array<std::array<int, Path::column_length>, Path::row_length>& grid, const Node& node)
{
    std::vector<Path::Node> result {};
    for(int i = -1; i<=1; ++i){
        for(int x = -1; x <=1; ++ x){
            if( (x != 0 || i != 0)  && node.m_row + i >= 0 && node.m_row + i <= Path::row_length - 1 && node.m_col + x >=0 && node.m_col + x <= Path::column_length - 1) // Not the center block
                result.emplace_back(i + node.m_row, x + node.m_col, true);
        }
    }

    return result;
}

static bool skipOrNot(const Path::Node& node, const std::vector<Path::Node>& closedList){
    for(auto& closedNode : closedList){
        if (closedNode == node)
            return true;
    }
    return !node.m_traversable;

}

static bool inVet(const Path::Node& node, const std::vector<Path::Node>& openList){
    for(auto& ele: openList){
        if(node == ele)
            return true;
    }
    return false;
}

void Path::Node::setParent(const Node&node){
    this->parent = new Node;
    *(this->parent) = node;
}

static int findEle(const Path::Node& node, const std::vector<Path::Node>& vet){
    for(int i = 0 ; i<vet.size(); ++i){
        if (vet[i] == node){
            return i;
        }
    }

    assert(false);
}

path_t traverse(Path::Node* node){
    path_t result {};
    while(true){
        if(node){ // Not a nullptr
            result.push_back(*node);
            node = node->parent;
        }else{
            return result;
        }
    }
}

path_t Path::findPath(const grid_t& grid, Node& start, const Node& end){
    std::vector<Node> openSet {};
    std::vector<Node> closedSet {};

    start.g_cost = 0;
    start.h_cost = Path::distance(start, end);
    start.f_cost = start.fCost(); // Set F Cost
    openSet.push_back(start);

    while(!openSet.empty()){
        // Finding the current Node
        auto currentNode {openSet[smallestFCost(openSet)]};


        openSet.erase(openSet.begin() + findEle(currentNode, openSet));
        closedSet.push_back(currentNode);

        if (currentNode == end){ // Found Solutions

            std::cout << "Found Solution" << std::endl;
            return traverse(&currentNode);
        }

        auto neighbours {getNeighbour(grid, currentNode)};
        for(auto& neighbour : neighbours){ // Loop through
            if(skipOrNot(neighbour, closedSet)) // Skip
                continue;

            double newDistance {currentNode.g_cost + Path::distance(currentNode, neighbour)};
            neighbour.g_cost = Path::distance(neighbour, start);
            if ( newDistance < neighbour.g_cost || !inVet(neighbour, openSet)){
                neighbour.setParent(currentNode);
                neighbour.h_cost = Path::distance(neighbour, end);
                neighbour.g_cost = newDistance;
                neighbour.f_cost = neighbour.g_cost + neighbour.g_cost;

                if(!inVet(neighbour, openSet))
                    openSet.push_back(neighbour);
            }

        }
    }

    std::cout << "No Solution found" << std::endl;
    return path_t {}; // Empty array
}