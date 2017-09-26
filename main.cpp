#include "group.h"



int main()
{
	std::cout << "Group, version 0.1" << std::endl << std::endl;

  Group g;

  // if(g.checkIfGroup())
  //   std::cout << "True" << std::endl << std::endl;
  // else
  //   std::cout << "False" << std::endl << std::endl;

	PauliGroup pauli;

	Eigen::Matrix<std::complex<double>,2,2> paulix = pauli.PauliMatrix(0);
	Eigen::Matrix<std::complex<double>,2,2> pauliy = pauli.PauliMatrix(1);
	Eigen::Matrix<std::complex<double>,2,2> pauliz = pauli.PauliMatrix(2);

	std::cout << "Pauli_x Matrix: " << std::endl
	  					<< paulix << std::endl;
	std::cout << "Pauli_y Matrix: " << std::endl
					 	  << pauliy << std::endl;
	std::cout << "Pauli_z Matrix: " << std::endl
							<< pauliz << std::endl;

	std::cout << std::endl;

  g.checkHermiticity(paulix);

	CyclicGroup cgroup(6);

	std::cout << "Cyclic Group Hessen Decomp (Possibly Block Diagonal?):"  <<std::endl
	  << cgroup.HDecomp(0) << std::endl;

	return 0;
}
