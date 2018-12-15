#include "GeneralList.h"

#ifndef __G_LIST__
#define __G_LIST__

namespace g_list
{
	using namespace std;
	using gereral_list::GeneralList;

	class GList
	{
		public:
			GList();
			~GList();

		public:
			void generalList();

		private:
			GeneralList<int>* general_list;
	};
}

#endif
