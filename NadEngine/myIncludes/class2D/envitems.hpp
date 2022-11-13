#ifndef ENVITEM_HPP
# define ENVITEM_HPP

#include "../../vendor/raylib/src/raylib.h"

typedef struct EnvItem {
	Texture2D     texture;
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
						int blocking, Color color, Texture2D texture, int nbr);
		void		ftNewEnvItem(int nbr);
		Rectangle	ftReturnRectangle(int nbr) const;
		Vector2		ftReturnEnviPos(int nbr) const;
		Vector2		ftReturnEnviSize(int nbr) const;
		Color		ftReturnEnviColor(int nbr) const;
		Texture2D	ftReturnEnviTexture(int nbr) const;
		EnvItem		*ftReturnEnvitemPtr(int nbr);
		EnvItems	*ftReturnCopyEnvItems(void);
		int			ftReturnEnviAllNbr(void) const;

		// One item
		void        ftInitOneEnvitem(Vector2 pos, Vector2 size,
						int blocking, Color color, Texture2D texture);
		Rectangle	ftReturnOneRectangle(void) const;
		Vector2		ftReturnOneEnviPos(void) const;
		Vector2		ftReturnOneEnviSize(void) const;
		Color		ftReturnOneEnviColor(void) const;
		Texture2D	ftReturnOneEnviTexture(void) const;
		EnvItem		*ftReturnOneEnvitemPtr(void);

	private:
		EnvItem		*_envItems;
		EnvItem		_item;
		int			_allNbr;
		
};

#endif