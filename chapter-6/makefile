compiler = g++-8
standard = -std=c++17
output = -o
flags = $(compiler) $(standard) $(output)

all: main greeting split permuted_index reader palindrome link copy accumulate

main:
	$(flags) main.out main.cpp student.cpp grade.cpp median.cpp split.cpp average.cpp

greeting:
	$(flags) greeting.out greeting.cpp split.cpp concatenate.cpp length.cpp

split:
	$(flags) split_input.out split_input.cpp split.cpp

permuted_index:
	$(flags) permuted_index.out permuted_index.cpp split.cpp

reader:
	$(flags) reader.out reader.cpp split.cpp

palindrome:
	$(flags) palindrome.out palindrome.cpp

link:
	$(flags) link.out link.cpp

copy:
	$(flags) copy.out copy.cpp

accumulate:
	$(flags) accumulate.out accumulate.cpp
