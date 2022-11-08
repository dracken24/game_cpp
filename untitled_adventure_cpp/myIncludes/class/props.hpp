#ifndef PROPS_HPP
# define PROPS_HPP

#include "squareProps.hpp"

class Props
{
	public:
		Props(int nbr);
		~Props(void);

		// Square props //
		void        ftAddSquareProps(Vector2 pos, Vector2 size, Color color, int nbr);
		Rectangle   ftReturnRectangleSqPr(int nbr);
		Color       ftReturnRecColorSqPr(int nbr);
		SquareProps *ftReturnSquareProp(int nbr) const;
		void        ftSetPosSquareProp(Vector2 pos, int nbr);
		void        ftMoveSquareProp(Vector2 pos, int nbr);
		int         ftReturnNbr(void) const;
		int         ftReturnOneNbr(int nbr) const;
		float       ftReturnSqurtPos(char c, int nbr) const;
		float       ftReturnSqurtWorH(char c, int nbr) const;
		float		ftReturnSpeedModifier(char c, int nbr) const;
		void		ftSetSpeedModifier(float speed, char c, int nbr);
		void		ftChangeSpeedModifier(float speed, char c, int nbr);

	private:
		SquareProps *_squareProps;
		int         _nbr;
};

#endif