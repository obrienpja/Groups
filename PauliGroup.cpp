#include "group.h"

/**
 * PauliGroup constructor
 */
PauliGroup::PauliGroup():Group(){
  std::complex<double> If(0.0f, 1.0f);

  for(int i = 0; i < 3; i++)
  {
    pauliMats(0, i) = Eigen::Matrix<std::complex<double>, 2, 2>::Zero(2, 2);
  }

  pauliMats(0,0)(0,1) = 1.0;
  pauliMats(0,0)(1,0) = 1.0;
  pauliMats(0,1)(0,1) = -1.0*If;
  pauliMats(0,1)(1,0) = 1.0*If;
  pauliMats(0,2)(0,0) = 1.0;
  pauliMats(0,2)(1,1) = -1.0;
};

/**
 * Returns a Pauli matrix
 * @param subScript number in [0,2] that gives the x, y, or z Pauli matrix
 */
Eigen::Matrix<std::complex<double>, 2, 2> PauliGroup::PauliMatrix(int subScript)
{
  return pauliMats(0, subScript);
}

/**
 * Creates a GellMann Group
 */
GellMann::GellMann():Group(){
  std::complex<double> If(0.0f, 1.0f);

	for(int i = 0; i < 8; i++)
	{
		gellMannMats(0, i) = Eigen::Matrix<std::complex<double>, 3, 3>::Zero(3, 3);
	}

  gellMannMats(0, 0)(0, 1) = 1.0;
  gellMannMats(0, 0)(1, 0) = 1.0;
  gellMannMats(0, 1)(0, 1) = -1.0*If;
  gellMannMats(0, 1)(1, 0) = 1.0*If;
  gellMannMats(0, 2)(0, 0) = 1.0;
  gellMannMats(0, 2)(1, 1) = -1.0;
  gellMannMats(0, 3)(0, 2) = 1.0;
  gellMannMats(0, 3)(2, 0) = 1.0;
  gellMannMats(0, 4)(0, 2) = -1.0*If;
  gellMannMats(0, 4)(2, 0) = 1.0*If;
  gellMannMats(0, 5)(1, 2) = 1.0;
  gellMannMats(0, 5)(2, 1) = 1.0;
  gellMannMats(0, 6)(1, 2) = -1.0*If;
  gellMannMats(0, 6)(2, 1) = 1.0*If;
  gellMannMats(0, 7)(0, 0) = 1.0/sqrt(3);
  gellMannMats(0, 7)(1, 1) = 1.0/sqrt(3);
  gellMannMats(0, 7)(2, 2) = -2.0/sqrt(3);
};

void GellMann::printGellMann(int subScript)
{
  std::cout << std::endl << gellMannMats(0, subScript) << std::endl;
}

// /**
//  * Returns the n-th Pauli Matrix where n=[0,2]
//  * @param subScript Sub Script for the n-th Pauli Matrix
//  */
// Matrix <complex<double>,2,2> PauliGroup::PauliMatrix(int subScript)
// {
//   Matrix<std::complex<double>,2,2> pauli;
//   for (int i =0 ; i < 2; i++)
//     for( int j = 0; j < 2; j++)
//       pauli(i,j) = PauliTensor(subScript,i,j);
//
//   return pauli;
// }
