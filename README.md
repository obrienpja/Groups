# Groups
Group theory repository written in C++/Eigen

You can check out the documentation [here](https://obrienpja.github.io/Groups/index.html)

Currently, the code can find the regular representation of a group. The code can also find the classes of the group, and thus can find the number of classes in the group. Soon, we hope to have the code find the dimensionalities of the irreducible representations.

Presumably, more complete group theoretical packages can do much more than our code right now, but we hope that our code will be a physics library. Eventually, we hope to do group theoretical analysis of physics data (like STM).

You will need a makefile like this (using the current version of Eigen):
```
EIGEN = /usr/local/eigen-eigen-5a0156e40feb/

compile:
	g++ main.cpp group.cpp CyclicGroup.cpp PauliGroup.cpp -o main -I$(EIGEN)

run:
	compile
	./main
```

Once you have such a makefile
```
make
./main
```

References:
Michael Tinkham : Group Theory and Quantum Mechanics
