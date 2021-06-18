#ifndef PATHFINDING_PATH_H
#define PATHFINDING_PATH_H

#include <array>
#include <vector>

namespace Path{
    inline constexpr int row_length {3};
    inline constexpr int column_length {3};

    enum State{
        blockage,
        clearance
    };

    class Node{
    public:
        int m_col {};
        int m_row {};
        double g_cost {};
        double h_cost {};
        double f_cost {};
        bool m_traversable {};
        Node* parent {nullptr};

        Node(int row, int col, bool traversable)
                : m_col {col}, m_row {row}, m_traversable {traversable}
        {}

        Node() = default;

        double fCost(const Node& startNode, const Node& endNode) const;
        double fCost() const;
        void setParent(const Node&node);
        bool operator ==(const Node& node) const;
        friend double distance(const Node& start, const Node& end);
        friend std::vector<Path::Node> getNeighbour(const std::array<std::array<int, Path::column_length>, Path::row_length>& grid, const Node& node);
    };

    std::vector<Path::Node> findPath(const std::array<std::array<int, Path::column_length>, Path::row_length>& grid,  Node& start, const Node& end);
    double distance(const Node& start, const Node& end);

    std::vector<Path::Node> getNeighbour(const std::array<std::array<int, Path::column_length>, Path::row_length>& grid, const Node& node);
}

using path_t = std::vector<Path::Node>;
using grid_t = std::array<std::array<int, Path::column_length>, Path::row_length>;

#endif //PATHFINDING_PATH_H
