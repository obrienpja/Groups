#include "group.h"

int main()
{
	std::cout << "Group, version 0.1" << std::endl << std::endl;

  Group g;
  g.cyclicGroup(4);
  g.printGroup();

  for(int i = 0; i < 4; i++)
  {
    g.regularRepresentation(i);
  }

	return 0;
}
