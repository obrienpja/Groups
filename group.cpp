#include "group.h"

/**
 * Add hopping contribution to the Hamiltonian
 * @param dim The dimension of the Hamiltonian, set by the system size
 */
void Group::cyclicGroup(int dim)
{
  group.resize(dim, dim);

  for(int j = 0; j < dim; j++)
    for(int l = 0; l < dim; l++)
      group(l, j) = (l + j) % dim;
}

/**
 * Print the group
 */
void Group::printGroup()
{
  std::cout << "The group is: " << std::endl << group << std::endl << std::endl;
  std::cout << "The group size is: " << std::endl << sqrt(group.size()) << std::endl << std::endl;
}

/**
 * Check if group variable (which is a multiplication table) is a group
 */
bool Group::checkIfGroup()
{
  int size = sqrt(group.size());
  for(int l = 0; l < size; l++)
  {
    Eigen::MatrixXd groupRow = group.row(l);
    for(unsigned j = 0; j < size; j++)
      for(unsigned k = j + 1; k < size; k++)
        if (groupRow(j) == groupRow(k)){return false;}

    Eigen::MatrixXd groupColumn = group.col(l);
    for(unsigned j = 0; j < size; j++)
      for(unsigned k = j + 1; k < size; k++)
        if (groupColumn(j) == groupColumn(k)){return false;}
  }
  return true;
}

/**
 * Print the regular representation of element ele
 * @param ele The element to find the regular representation for
 */
Eigen::MatrixXd Group::regularRepresentationOfElement(int ele)
{
  int size = sqrt(group.size());
  Eigen::MatrixXd reg(size, size);
  reg = Eigen::MatrixXd::Zero(size, size);

  for(int l = 0; l < size; l++)
    for(int j = 0; j < size; j++)
      if(group(l, j) == ele) {reg(l, j) = 1;}

  return reg;
}

/**
 * Print the regular representation of the group
 */
void Group::regularRepresentation()
{
  for(int l = 0; l < sqrt(group.size()); l++)
  {
    std::cout << "The regular representation of the element is: " << std::endl << regularRepresentationOfElement(l) << std::endl << std::endl;
  }
}

Eigen::Tensor<std::complex<double>, 3> pauliMatrices()
{
  Eigen::Tensor<std::complex<double>, 3> sigma(3, 2, 2);
  std::complex<float> If(0.0f, 1.0f);
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

  return sigma;
}
