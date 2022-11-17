#ifndef PROPS_HPP
# define PROPS_HPP

# include "squareProps.hpp"
using namespace std;

namespace obj
{
	class Props
	{
		public:
			Props(void);
			Props(Props const &src);
			~Props(void);

			void		ftChangeNbr(int nbr, string name);
			int			ftReturnNbr(string name) const;

		private:
			int			_nbrEnvItems = 0;
			int			_nbrSquareProps = 0;
			int			_nbrbuttons = 0;
	};
};

#endif