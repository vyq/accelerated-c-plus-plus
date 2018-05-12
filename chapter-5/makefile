compiler = g++
standard = -std=c++1z
output = -o
flags = $(compiler) $(standard) $(output)

all: clean main greeting split

clean:
	rm *.out

main:
	$(flags) main.out main.cpp student.cpp grade.cpp median.cpp

greeting:
	$(flags) greeting.out greeting.cpp

split:
	$(flags) split.out split.cpp
