#include "group.h"

/**
 * Group default constructor
 */
 Group::Group()
 {
 }

/**
 * Group constructor
 * @param groupVal Group that gets constructed by Group class
 */
 Group::Group(Eigen::MatrixXd groupVal)
 {
   group = groupVal;
   order = sqrt(group.size());
 }

 /**
  * Return the group variable
  */
 Eigen::MatrixXd Group::getGroup()
 {
   return group;
 }

 /**
  * Set the group variable
  * @param groupVar Group that gets stored in the group variable
  */
 void Group::setGroup(Eigen::MatrixXd groupVar)
 {
   group = groupVar;
 }

 /**
  * Group constructor
  * @param groupVal Group that gets constructed by Group class
  */
 int Group::getOrder()
 {
   return order;
 }

 /**
  * Set the order of the group
  * @param orderVal Value that gets stored into order
  */
 void Group::setOrder(int orderVal)
 {
   order = orderVal;
 }

/**
 * Print the group
 */
void Group::printGroup()
{
  std::cout << "The group is: " << std::endl << group << std::endl << std::endl;
}

/**
 * Check if group variable (which is a multiplication table) is a group. This is essentially what is known as the rearrangement theorem
 */
bool Group::checkIfGroup()
{
  for(int l = 0; l < order; l++)
  {
    Eigen::MatrixXd groupRow = group.row(l);
    for(unsigned j = 0; j < order; j++)
      for(unsigned k = j + 1; k < order; k++)
        if (groupRow(j) == groupRow(k)){return false;}

    Eigen::MatrixXd groupColumn = group.col(l);
    for(unsigned j = 0; j < order; j++)
      for(unsigned k = j + 1; k < order; k++)
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
  Eigen::MatrixXd reg(order, order);
  reg = Eigen::MatrixXd::Zero(order, order);

  for(int l = 0; l < order; l++)
    for(int j = 0; j < order; j++)
      if(group(l, j) == ele) {reg(l, j) = 1;}

  return reg;
}

/**
 * Print the regular representation of the group
 */
void Group::regularRepresentation()
{
  for(int l = 0; l < order; l++)
  {
    std::cout << "The regular representation of the element is: " << std::endl << regularRepresentationOfElement(0)*regularRepresentationOfElement(l) << std::endl << std::endl;
  }
}

/**
 * Rearranges the multiplication table in the regular representation form
 */
void Group::correctedCyclicGroup()
{
  rearrangedGroup = regularRepresentationOfElement(0)*group;
}

/**
 * Fourier factor for a given angle
 */
// std::complex<double> Group::fourierFactor(double theta)
// {
//   return cos(theta) + If*sin(theta);
// }

/**
 * Kronecker product between matrices (just prints the result)
 * @param mat1 First matrix in Kronecker product (coefficients)
 * @param mat2 First matrix in Kronecker product (contained)
 */
void Group::kronProduct(Eigen::MatrixXcd mat1, Eigen::MatrixXcd mat2)
{
  std::cout << "The Kronecker product is: " << std::endl
		<< kroneckerProduct(mat1, mat2) << std::endl;
}

std::set<int> Group::printClasses(int ele)
{
  correctedCyclicGroup();
  std::set<int> conjugates;

  for(int i = 0; i < order; i++)
  {
    conjugates.insert(group(rearrangedGroup(i, ele), i));
  }

  return conjugates;
}

std::set< std::set <int> > Group::printAllClasses()
{
  std::set< std::set <int> > classes;

  for(int i = 0; i < order; i++)
    classes.insert(printClasses(i));

  return classes;
}
