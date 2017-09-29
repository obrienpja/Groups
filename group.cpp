#include "group.h"

/**
 * Group constructor
 * @param groupVal Group that gets constructed by Group class
 */
 Group::Group()
 {
 }

/**
 * Group constructor
 * @param groupVal Group that gets constructed by Group class
 */
 Group::Group(MatrixXd groupVal)
 {
   group = groupVal;
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
 * Check if group variable (which is a multiplication table) is a group. This is essentially what is known as the rearrangement theorem
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
    std::cout << "The regular representation of the element is: " << std::endl << regularRepresentationOfElement(0)*regularRepresentationOfElement(l) << std::endl << std::endl;
  }
}

/**
 * Rearranges the multiplication table in the regular representation form
 */
void Group::correctedCyclicGroup()
{
  std::cout << "The proper multiplication table is: " << std::endl << regularRepresentationOfElement(0)*group << std::endl;
}

std::complex<double> Group::fourierFactor(double theta)
{
  complex<double> If(0.0f, 1.0f);
  return cos(theta) + If*sin(theta);
}
