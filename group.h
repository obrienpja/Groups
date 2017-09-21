#include <iostream>
#include <typeinfo>
#include <complex>
#include <cmath>
#include <eigen-eigen-5a0156e40feb/Eigen/Eigenvalues>
#include <eigen-eigen-5a0156e40feb/unsupported/Eigen/CXX11/Tensor>

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
    Eigen::Tensor<std::complex<double>, 3> pauliMatrices();
};
