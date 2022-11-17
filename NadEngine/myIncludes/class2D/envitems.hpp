#ifndef ENVITEM_HPP
# define ENVITEM_HPP

# include "../../vendor/raylib/src/raylib.h"
# include <stdlib.h>
# include <iostream>

namespace obj
{
	typedef struct VarCharEnvi
	{
		char *enviPosX;
		char *enviPosY;
		char *enviWidth;
		char *enviHeight;
		int	nbr = 4;
	}	VarCharEnvi;

	typedef struct EnvItem {
		Texture2D     texture;
		Color 		color;
		Rectangle 	rect;
		VarCharEnvi _varCharEnvi;
		Color		pixColor;

		int 		blocking;
		int			nbr;

		std::string	name;
	}   EnvItem;

	class EnvItems 
	{
		public:
			EnvItems(void);
			EnvItems(EnvItems const &src);
			~EnvItems(void);

			// void        ftInitEnvitem(Vector2 pos, Vector2 size,
			// 				int blocking, Color color, Texture2D texture, int nbr);
			VarCharEnvi	*ftReturnVarsCharEnvi(void);
			// void		ftNewEnvItem(int nbr);
			// Rectangle	ftReturnRectangle(int nbr) const;
			// Vector2		ftReturnEnviPos(int nbr) const;
			// Vector2		ftReturnEnviSize(int nbr) const;
			// Color		ftReturnEnviColor(int nbr) const;
			// Texture2D	ftReturnEnviTexture(int nbr) const;
			// EnvItem		*ftReturnEnvitemPtr(int nbr);
			int			ftReturnEnviAllNbr(void) const;
			// EnvItems	*ftReturnCopyEnvItems(void);

			// One item
			EnvItems    *ftInitOneEnvitem(Vector2 pos, Vector2 size, int blocking,
							Color color, Texture2D texture, int nbr, std::string name);
			Rectangle	ftReturnOneRectangle(void) const;
			Vector2		ftReturnOneEnviPos(void) const;
			Vector2		ftReturnOneEnviSize(void) const;
			Color		ftReturnOneEnviColor(void) const;
			Texture2D	ftReturnOneEnviTexture(void) const;
			EnvItem		*ftReturnOneEnvitemPtr(void);

			void		ftInitVarChar(int nbr);
			void		ftDeleteVarChar(int nbr);
			void		ftDestroyImgsPlayStop(void);

		private:
			EnvItem		_item;
			// VarCharEnvi	_varCharEnvi;
	};
};

#endif