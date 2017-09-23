#include "group.h"

using namespace Eigen;
/**
*Creates multiplication table of Cyclic Group with order int dim
* @param dim The order of the Cyclic Group
*/
CyclicGroup::CyclicGroup(int dim):Group(){
  order = dim;
  group.resize(dim, dim);
  for(int j = 0; j < dim; j++)
    for(int l = 0; l < dim; l++)
      group(l, j) = (l + j) % dim;
};

/**
*
*Create a pseudo block-diagonal decomposition of a representation
* of an element of the cyclic group (I think)
* @param ele
*/

MatrixXd CyclicGroup::HDecomp(int ele)
{
  HessenbergDecomposition<MatrixXd>
  hessofGroup(regularRepresentationOfElement(ele));
  return hessofGroup.matrixH();
}
