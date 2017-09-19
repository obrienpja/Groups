#include "group.h"

/**
 * Add hopping contribution to the Hamiltonian
 * @param dim The dimension of the Hamiltonian, set by the system size
 */
void Group::cyclicGroup(int dim)
{
  group.resize(dim, dim);

  for(int j = 0; j < dim; j++)
    for(int i = 0; i < dim; i++)
      group(i,j) = (i + j) % dim;
}

/**
 * Check if group variable (which is a multiplication table) is a group
 */
bool Group::checkIfGroup()
{
  int size = sqrt(group.size());
  for(int i = 0; i < size; i++)
  {
    Eigen::MatrixXd groupRow = group.row(i);
    for(unsigned j = 0; j < size; j++)
      for(unsigned k = j + 1; k < size; k++)
        if (groupRow(j) == groupRow(k)){return false;}

    Eigen::MatrixXd groupColumn = group.col(i);
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
Eigen::MatrixXd Group::regularRepresentation(int ele)
{
  int size = sqrt(group.size());
  Eigen::MatrixXd reg(size, size);
  reg = Eigen::MatrixXd::Zero(size, size);

  for(int i = 0; i < size; i++)
    for(int j = 0; j < size; j++)
      if(group(i, j) == ele) {reg(i, j) = 1;}

  std::cout << "The regular representation is: " << std::endl << reg << std::endl << std::endl;
}

/**
 * Print the group
 */
void Group::printGroup()
{
  std::cout << "The group is: " << std::endl << group << std::endl << std::endl;
  std::cout << "The group size is: " << std::endl << sqrt(group.size()) << std::endl << std::endl;
}
