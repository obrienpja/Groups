/**
 * Function template that checks whether or not a given matrix is Hermitian.
 * @param mat is a matrix that we are checking for Hermiticity
 */
template <typename T>
void Group::checkHermiticity(T mat)
{
  std::cout << "The Hermiticity check gives: " << std::endl;

  if(mat == mat.adjoint())
    std::cout <<  "true" << std::endl << std::endl;
  else
    std::cout <<  "false" << std::endl << std::endl;
}
