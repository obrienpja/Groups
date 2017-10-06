#include <iostream>
#include <complex>
#include <cmath>
#include <Eigen/Eigenvalues>
#include <unsupported/Eigen/CXX11/Tensor>
#include <unsupported/Eigen/KroneckerProduct>
#include <vector>
#include <set>

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
		MatrixXd rearrangedGroup;
    int order;
    bool checkIfGroup();
    MatrixXd regularRepresentationOfElement(int ele);
    void regularRepresentation();
    void printGroup();
    void correctedCyclicGroup();
    Matrix<complex<double>, 2, 2> pauliMatrix(int n);
    void printPauliMatrix(int n);
    template <typename T>
    void checkHermiticity(T mat);
    complex<double> fourierFactor(double theta);
		void kronProduct(MatrixXcd mat1, MatrixXcd mat2);
		set<int> printClasses(int ele);
		std::set< std::set <int> > printAllClasses();
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
    // Tensor <complex<double>,3> PauliTensor;
		Eigen::Matrix<Eigen::Matrix<std::complex<double>, 2, 2>, 1, 3> pauliMats;
		Matrix <complex<double>,2,2> PauliMatrix(int subScript);
    // void printPauliMatrix(int subScript);
};

/**
 * Pauli Group Class
 * Subclass of Group
 * Contains the Pauli Matrices
 * @author Patrick O'Brien <obrienpja@gmail.com>
 * @author Shehtab Zaman <shehtabzaman@gmail.com>
 */
class GellMann:public Group
{
  public:
		Eigen::Matrix<Eigen::Matrix<std::complex<double>, 3, 3>, 1, 8> gellMannMats;
    GellMann();
    void printGellMann(int ele);
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
