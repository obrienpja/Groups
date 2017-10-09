#include <iostream>
#include <complex>
#include <cmath>
#include <Eigen/Eigenvalues>
#include <unsupported/Eigen/CXX11/Tensor>
#include <unsupported/Eigen/KroneckerProduct>
#include <vector>
#include <set>
#include <numeric>

/**
 * Group class
 * @author Patrick O'Brien <obrienpja@gmail.com>
 * @author Shehtab Zaman <shehtabzaman@gmail.com>
 */
class Group
{
	public:
		Group();
		Group(Eigen::MatrixXd group);
    Eigen::MatrixXd group;
		Eigen::MatrixXd rearrangedGroup;
    int order;
		// std::complex<double> If = std::complex<double>{0.0, 1.0};

    bool checkIfGroup();
    Eigen::MatrixXd regularRepresentationOfElement(int ele);
    void regularRepresentation();
    void printGroup();
    void correctedCyclicGroup();
    Eigen::Matrix<std::complex<double>, 2, 2> pauliMatrix(int n);
    void printPauliMatrix(int n);

		template <typename T>
    void checkHermiticity(T mat);

		std::complex<double> fourierFactor(double theta);
		void kronProduct(Eigen::MatrixXcd mat1, Eigen::MatrixXcd mat2);
		std::set<int> printClasses(int ele);
		std::set< std::set <int> > printAllClasses();

		template<typename T>
		struct square2{};
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
		Eigen::Matrix <std::complex<double>,2,2> PauliMatrix(int subScript);
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
		 Eigen::MatrixXd HDecomp(int ele);
    //Inherits other group public methods
};

#include "group.tpp"
