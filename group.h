#include <iostream>
#include <typeinfo>
#include <complex>
#include <cmath>
#include <Eigen/Eigenvalues>
#include <unsupported/Eigen/CXX11/Tensor>

// using namespace std::literals;

/**
 * Group class
 * @author Patrick O'Brien <obrienpja@gmail.com>
 */
class Group
{
	private:
		Eigen::MatrixXd group;
	public:
    void cyclicGroup(int dim);
    bool checkIfGroup();
		Eigen::MatrixXd regularRepresentationOfElement(int ele);
    void regularRepresentation();
    void printGroup();
    void correctedCyclicGroup();
    Eigen::Tensor<std::complex<double>, 3> pauliMatrices();
		Eigen::Matrix<std::complex<double>,2,2> pauliMatrix(int n);
		void printPauliMatrix(int n);
};
