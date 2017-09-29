#include <iostream>
#include <typeinfo>
#include <complex>
#include <cmath>
#include <Eigen/Eigenvalues>
#include <unsupported/Eigen/CXX11/Tensor>

using namespace Eigen;
using namespace std;

/**
 * Group class
 * @author Patrick O'Brien <obrienpja@gmail.com>
 * @author Shehtab Zaman <shehtabzaman@gmail.com>
 */
class Group
{
	public:
		Group();
		Group(MatrixXd group);
    MatrixXd group;
    int order;
    bool checkIfGroup();
    MatrixXd regularRepresentationOfElement(int ele);
    void regularRepresentation();
    void printGroup();
    void correctedCyclicGroup();
    Tensor<complex<double>, 3> pauliMatrices();
    Matrix<complex<double>,2,2> pauliMatrix(int n);
    void printPauliMatrix(int n);
    template <typename T>
    void checkHermiticity(T mat);
    complex<double> fourierFactor(double theta);
};

/**
 * Pauli Group Class
 * Subclass of Group
 * Contains the Pauli Matrices
 * @author Patrick O'Brien <obrienpja@gmail.com>
 * @author Shehtab Zaman <shehtabzaman@gmail.com>
 */
class PauliGroup:public Group
{
  public:
    PauliGroup();
    // vector <Matrix<complex<double>,2,2> > PauliElements; <-- Initialization of Elements as arrays
    Tensor <complex<double>,3> PauliTensor;
    Matrix <complex<double>,2,2> PauliMatrix(int subScript);
    void printPauliMatrix(int subScript);
};

/**
 * Cyclic Group class
 * Subclass of Group
 * @author Patrick O'Brien <obrienpja@gmail.com>
 * @author Shehtab Zaman <shehtabzaman@gmail.com>
 */
class CyclicGroup:public Group
{
  public:
    //Cyclic Group constructor with dimensions
     CyclicGroup(int dim);
		 MatrixXd HDecomp(int ele);
    //Inherits other group public methods
};

#include "group.tpp"
