#include "group.h"

using namespace Eigen;
using namespace std;

/**
 * Creates a Pauli Group Object
 */
PauliGroup::PauliGroup():Group(){
  Tensor<std::complex<double>, 3> sigma(3, 2, 2);
  complex<float> If(0.0f, 1.0f);
  sigma(0,0,0) = 0.0f;
  sigma(0,0,1) = 1.0f;
  sigma(0,1,0) = 1.0f;
  sigma(0,1,1) = 0.0f;
  sigma(1,0,0) = 0.0f;
  sigma(1,0,1) = -1.0f*If;
  sigma(1,1,0) = 1.0f*If;
  sigma(1,1,1) = 0.0f;
  sigma(2,0,0) = 1.0f;
  sigma(2,0,1) = 0.0f;
  sigma(2,1,0) = 0.0f;
  sigma(2,1,1) = -1.0f;
  PauliTensor = sigma;
};

/**
 * Creates a GellMann Group
 */
GellMann::GellMann():Group(){
  complex<double> If(0.0f, 1.0f);

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

void GellMann::printGellMann(int ele)
{
  std::cout << std::endl << gellMannMats(0, ele) << std::endl;
}

/**
 * Returns the n-th Pauli Matrix where n=[1,3]
 * @param subScript Sub Script for the n-th Pauli Matrix
 */
Matrix <complex<double>,2,2> PauliGroup::PauliMatrix(int subScript)
{
  Matrix<std::complex<double>,2,2> pauli;
  for (int i =0 ; i < 2; i++)
    for( int j = 0; j < 2; j++)
      pauli(i,j) = PauliTensor(subScript,i,j);

  return pauli;
}
