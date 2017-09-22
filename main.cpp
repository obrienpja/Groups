// #include "group.h"
#include "CyclicGroup.h"

int main()
{
	std::cout << "Group, version 0.1" << std::endl << std::endl;

  Group g;
  g.cyclicGroup(3);
  g.printGroup();

  std::cout << "The multiplication table is that of a group: " << std::endl;

  if(g.checkIfGroup())
    std::cout << "True" << std::endl << std::endl;
  else
    std::cout << "False" << std::endl << std::endl;

  g.regularRepresentation();
	g.printPauliMatrix(2);

	/**
	Cyclegroup creator and method test

	CyclicGroup cgroup(4);

	cgroup.printGroup();
	**/

  // g.regularRepresentation(0) * g.regularRepresentation(1);

	return 0;
}
