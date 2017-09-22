EIGEN = /usr/local/eigen-eigen-5a0156e40feb/ #Folder Name: eigen-eigen-5a0156e40feb

compile:main.cpp group.cpp
	g++ main.cpp group.cpp -o main -I $(EIGEN)

run: compile
	./main
