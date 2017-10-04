#include "group.h"

int main()
{
	std::cout << "Group, version 0.1" << std::endl << std::endl;

	PauliGroup pauli;

	Eigen::Matrix<std::complex<double>,2,2> paulix = pauli.PauliMatrix(0);
	Eigen::Matrix<std::complex<double>,2,2> pauliy = pauli.PauliMatrix(1);
	Eigen::Matrix<std::complex<double>,2,2> pauliz = pauli.PauliMatrix(2);

	std::cout << "Pauli_x Matrix: " << std::endl
	  					<< paulix << std::endl;
	std::cout << "Pauli_y Matrix: " << std::endl
					 	  << pauliy << std::endl;
	std::cout << "Pauli_z Matrix: " << std::endl
							<< pauliz << std::endl << std::endl;

	// Ask user for group size and create cyclic group for it
	int groupSize = 0;
	std::cout << "Please enter the size of group: " << std::endl;
	std::cin >> groupSize;

	CyclicGroup cgroup(groupSize);
  cgroup.printGroup();

	for(int i = 0; i < groupSize; i++)
		std::cout << "Cyclic Group Hessen Decomp (Possibly Block Diagonal?):"  <<std::endl
	  << cgroup.HDecomp(i) << std::endl;

	GellMann g1;

	g1.printGellMann(1);

	// std::cout << "The Kronecker product of Paulix and Pauliy is: " << std::endl
	// 	<< kroneckerProduct(paulix, pauliy) << std::endl;

	return 0;
}
