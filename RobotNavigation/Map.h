#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector> 

enum Status {
    Floor,
    Wall,
    Goal,
    Nil
};

struct Point {
    unsigned x;
    unsigned y;
};

class Map {
private:
    unsigned fHeight;
    unsigned fWidth;
    // flattened 2d vector of cells in Map
    // accessing fMapArray[3][5] == fMapArray[(3 * fHeight) + 5]
    std::vector<Status> fMapArray;

public:
    Map();

    void setSize(unsigned aWidth, unsigned aHeight);

    unsigned getHeight() { return fHeight; }
    unsigned getWidth() { return fWidth; }

    void setStatus(unsigned aX, unsigned aY, Status aStatus);
    void setStatus(Point aPoint, Status aStatus);
    Status getStatus(unsigned aX, unsigned aY);

    // draws cells of map with status coloured
    void draw(sf::RenderWindow& window);


    // Create output stream of map for printing
    friend std::ostream& operator<<(std::ostream& aOstream, const Map& aMap);
};