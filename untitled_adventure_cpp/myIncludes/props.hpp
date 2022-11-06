#ifndef PROPS_HPP
# define PROPS_HPP

#include "squareProps.hpp"

class Props
{
    public:
        Props(int nbr);
        ~Props(void);

        void        ftAddSquareProps(Vector2 pos, Vector2 size, Color color, int nbr);
        Rectangle   ftReturnRectangleSqPr(int nbr);
        Color       ftReturnRecColorSqPr(int nbr);

    private:
        SquareProps *_squareProps;
};

#endif