// #include "group.h"
#include "CyclicGroup.h"

int main()
{
	std::cout << "Group, version 0.1" << std::endl << std::endl;

  Group g;
  g.cyclicGroup(7);
  // g.printGroup();
	//
  // std::cout << "The multiplication table is that of a group: " << std::endl;
	//
  // if(g.checkIfGroup())
  //   std::cout << "True" << std::endl << std::endl;
  // else
  //   std::cout << "False" << std::endl << std::endl;
	//
  // g.regularRepresentation();
	// g.printPauliMatrix(2);

	Eigen::MatrixXd regRep (7,7);

	regRep = g.regularRepresentationOfElement(0);

	std::cout <<  "REG REP" <<std::endl << regRep << std::endl;

	Eigen::MatrixXd ldlt (7,7);

	Eigen::HessenbergDecomposition<Eigen::MatrixXd> hessOfA(regRep);

	std::cout << "Hessenberg Decomposition:" << std::endl << hessOfA.matrixH() << std::endl;




	/**
	Cyclegroup creator and method test

	CyclicGroup cgroup(4);

	cgroup.printGroup();
	**/

  // g.regularRepresentation(0) * g.regularRepresentation(1);

	return 0;
}
