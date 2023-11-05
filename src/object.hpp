#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <string>
using namespace std;

class Object{

    protected:
        string imageFile;
        int x, y;

    public:
        Object(int, int, string);

        virtual void draw() const = 0;

        virtual void undraw() const = 0;

        int getX() const;

        int getY() const;
};

#endif