#include "group.h"



int main()
{
	std::cout << "Group, version 0.1" << std::endl << std::endl;

  Group g;
  // g.cyclicGroup(7);
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

	// Eigen::MatrixXd regRep (7,7);
	//
	// regRep = g.regularRepresentationOfElement(0);
	//
	// std::cout <<  "REG REP" <<std::endl << regRep << std::endl;
	//
	// Eigen::MatrixXd ldlt (7,7);
	//
	// Eigen::HessenbergDecomposition<Eigen::MatrixXd> hessOfA(regRep);
	//
	// std::cout << "Hessenberg Decomposition:" << std::endl << hessOfA.matrixH() << std::endl;




	/**
	Cyclegroup creator and method test

	CyclicGroup cgroup(4);

	cgroup.printGroup();
	**/

  // g.regularRepresentation(0) * g.regularRepresentation(1);
	 PauliGroup pauli;

	 Eigen::Matrix<std::complex<double>,2,2> paulix = pauli.PauliMatrix(1);
	 Eigen::Matrix<std::complex<double>,2,2> pauliy = pauli.PauliMatrix(2);
	 Eigen::Matrix<std::complex<double>,2,2> pauliz = pauli.PauliMatrix(3);

	//  for (int i =0 ; i < 2; i++){
	// 	 for( int j = 0; j < 2; j++){
	// 		 paulix(i,j) = pauliTensor(1,i,j);
	// 	 }
	//  }


	std::cout << "Pauli_x Matrix: " <<std::endl
	  					<< paulix << std::endl;
	std::cout << "Pauli_y Matrix: " <<std::endl
					 	  << pauliy << std::endl;
	std::cout << "Pauli_z Matrix: " <<std::endl
							<< pauliz << std::endl;

	std::cout << std::endl;

	CyclicGroup cgroup(6);

	std::cout << "Cyclic Group Hessen Decomp (Possibly Block Diagonal?):"  <<std::endl
	  << cgroup.HDecomp(0) << std::endl;


	return 0;
}
