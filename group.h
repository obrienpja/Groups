#include <iostream>
#include <typeinfo>
#include <complex>
#include <cmath>
#include <Eigen/Eigenvalues>
#include <unsupported/Eigen/CXX11/Tensor>

// using namespace std::literals;

using namespace Eigen;
using namespace std;
/**
 * Group class
 * @author Patrick O'Brien <obrienpja@gmail.com>
 */
class Group
{
	public:
		MatrixXd group;
		int order;
    // void cyclicGroup(int dim); //Deprecated -- Use CyclicGroup class
    bool checkIfGroup();
		MatrixXd regularRepresentationOfElement(int ele);
    void regularRepresentation();
    void printGroup();
    void correctedCyclicGroup();
    Tensor<complex<double>, 3> pauliMatrices();
		Matrix<complex<double>,2,2> pauliMatrix(int n);
		void printPauliMatrix(int n);
};
/**
* Pauli Group Class
* Subclass of Group
* Contains the Pauli Matrices
*
*/
class PauliGroup:public Group
{
  public:
    PauliGroup();
    // List <MatrixXd<complex<double>,2,2> PauliElements;
    Tensor <complex<double>,3> PauliTensor;
    Matrix <complex<double>,2,2> PauliMatrix(int subScript);

    void printPauliMatrix(int subScript);
};

/**
* Cyclic Group class
* Subclass of Group
*/

class CyclicGroup:public Group
{
  public:
    //Cyclic Group constructor with dimensions
     CyclicGroup(int dim);
		 MatrixXd HDecomp(int ele);
    //Inherits other group public methods
};
