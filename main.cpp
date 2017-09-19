#include "group.h"

int main()
{
	std::cout << "Group, version 0.1" << std::endl << std::endl;

  Group g;
  g.cyclicGroup(4);
  g.printGroup();

  std::cout << "The multiplication table is that of a group: " << std::endl;

  if(g.checkIfGroup())
    std::cout << "True" << std::endl << std::endl;
  else
    std::cout << "False" << std::endl << std::endl;

  for(int i = 0; i < 4; i++)
  {
    g.regularRepresentation(i);
  }

	return 0;
}
