compiler = g++
standard = -std=c++1z
output = -o
flags = $(compiler) $(standard) $(output)

all: clean main greeting split permuted_index

clean:
	rm *.out

main:
	$(flags) main.out main.cpp student.cpp grade.cpp median.cpp

greeting:
	$(flags) greeting.out greeting.cpp split.cpp concatenate.cpp length.cpp

split:
	$(flags) split_input.out split_input.cpp split.cpp

permuted_index:
	$(flags) permuted_index.out permuted_index.cpp split.cpp
