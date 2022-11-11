#ifndef ENVITEM_HPP
# define ENVITEM_HPP

#include "../../vendor/raylib/src/raylib.h"

typedef struct EnvItem {
	Texture     texture;
	Color 		color;
	Rectangle 	rect;

	int 		blocking;
	int			nbr;
}   EnvItem;

class EnvItems 
{
	public:
		EnvItems(void);
		~EnvItems(void);

		void        ftInitEnvitem(Vector2 pos, Vector2 size,
			int blocking, Color color, Texture texture, int nbr);
		void		ftNewEnvItem(int nbr);
		Rectangle	ftReturnRectangle(int nbr) const;
		Vector2		ftReturnEnviPos(int nbr) const;
		Vector2		ftReturnEnviSize(int nbr) const;
		Color		ftReturnEnviColor(int nbr) const;
		Texture		ftReturnEnviTexture(int nbr) const;
		EnvItem		*ftReturnEnvitemPtr(int nbr);
		int			ftReturnEnviAllNbr(void) const;

	private:
		EnvItem		*_envItems;
		int			_allNbr;
		
};

#endif