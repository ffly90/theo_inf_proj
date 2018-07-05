/*
Projektarbeit von Sidney Kuyateh, Marcel Nowak, Thomas Schäberle und Steffen Walter
*/
#ifndef EDGE_HPP
#define EDGE_HPP

struct Edge
{
    int x;
    int y;
};

struct EdgeCompare
{
    bool operator() (const Edge& a, const Edge& b) const
    {
        return (a.x < b.x) || (a.x == b.x && a.y < b.y);
    }
};

#endif //EDGE_HPP
