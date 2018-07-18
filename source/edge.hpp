/*
Projektarbeit von Sidney Kuyateh (1578641), Marcel Nowak (2915204), Thomas Schäberle (9055502) und Steffen Walter (1145690)
*/
#ifndef EDGE_HPP
#define EDGE_HPP
#include <functional>

struct Edge
{
	size_t x;
	size_t y;
};

struct EdgeCompare
{
    bool operator() (const Edge& a, const Edge& b) const
    {
        return (a.x < b.x) || (a.x == b.x && a.y < b.y);
    }
};

#endif //EDGE_HPP
