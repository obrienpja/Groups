#include "group.h"

int main()
{
	std::cout << "Group, version 0.1" << std::endl << std::endl;

	PauliGroup pauli;

	Eigen::Matrix<std::complex<double>,2,2> paulix = pauli.PauliMatrix(0);
	Eigen::Matrix<std::complex<double>,2,2> pauliy = pauli.PauliMatrix(1);
	Eigen::Matrix<std::complex<double>,2,2> pauliz = pauli.PauliMatrix(2);

	std::cout << "Pauli_x Matrix: " << std::endl
	  					<< paulix << std::endl;
	std::cout << "Pauli_y Matrix: " << std::endl
					 	  << pauliy << std::endl;
	std::cout << "Pauli_z Matrix: " << std::endl
							<< pauliz << std::endl << std::endl;

	// Ask user for group size and create cyclic group for it
	int groupSize = 0;
	std::cout << "Please enter the size of group: " << std::endl;
	std::cin >> groupSize;

	CyclicGroup cgroup(groupSize);
  cgroup.printGroup();

	for(int i = 0; i < groupSize; i++)
		std::cout << "Cyclic Group Hessen Decomp (Possibly Block Diagonal?):"  <<std::endl
	  << cgroup.HDecomp(i) << std::endl;

	GellMann g1;

	g1.printGellMann(1);

	cgroup.printClasses(2);

	Eigen::MatrixXd group2(6,6);
	group2 << 0,1,2,3,4,5,1,0,4,5,2,3,2,5,0,4,3,1,3,4,5,0,1,2,4,3,1,2,5,0,5,2,3,1,0,4;
	std::cout << "group2 is:  " << std::endl;
	std::cout << group2 << std::endl;
	Group g2(group2);

	// for(int i = 0; i < 6; i++)
	// 	g2.printClasses(i);

	std::set< std::set <int> > allClasses;
	allClasses = g2.printAllClasses();

	set< set<int> >::const_iterator si;
	set<int>::const_iterator si2;

	for (si = allClasses.begin(); si != allClasses.end(); ++si)
	{
    for (si2 = si->begin(); si2 != si->end(); ++si2)
    {
        cout << *si2 << " ";
    }
    cout << endl;
	}

	std::cout << "The number of classes is: " << allClasses.size() << std::endl;

	return 0;
}
