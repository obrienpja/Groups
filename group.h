#include <iostream>
#include <typeinfo>
#include <complex>
#include <eigen-eigen-5a0156e40feb/Eigen/Eigenvalues>

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
		Eigen::MatrixXd regularRepresentation(int ele);
    void printGroup();
};
