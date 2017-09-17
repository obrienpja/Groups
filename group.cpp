#include "group.h"

/**
 * Add hopping contribution to the Hamiltonian
 * @param dim The dimension of the Hamiltonian, set by the system size
 */
void Group::cyclicGroup(int dim)
{
  group.resize(dim, dim);

  for(int j = 0; j < dim; j++)
  {
    for(int i = 0; i < dim; i++)
    {
      group(i,j) = (i + j) % dim;
    }
  }
}

/**
 * Check if group variable is a group
 */
bool Group::checkIfGroup()
{
  int size = 4;
  for (unsigned j = 0; j < size; j++)
    for (unsigned k = j + 1; k < size; k++)
      if (group(j) == group(k)){return false;}
  return true;
}

/**
 * Print the regular representation of element ele
 * @param ele The element to find the regular representation for
 */
Eigen::MatrixXd Group::regularRepresentation(int ele)
{
  Eigen::MatrixXd reg(4,4);
  reg = Eigen::MatrixXd::Zero(4, 4);

  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      if(group(i, j) == ele) {reg(i, j) = 1;}

  std::cout << "The regular representation is: " << std::endl << reg << std::endl << std::endl;
}

/**
 * Print the group
 */
void Group::printGroup()
{
  std::cout << "The group is: " << std::endl << group << std::endl << std::endl;
}
