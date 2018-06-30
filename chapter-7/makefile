compiler = g++-8
standard = -std=c++17
output = -o
flags = $(compiler) $(standard) $(output)

all: main count line_numbers sentence

main:
	$(flags) main.out main.cpp student.cpp grade.cpp median.cpp split.cpp average.cpp

count:
	$(flags) count.out count.cpp

line_numbers:
	$(flags) line_numbers.out line_numbers.cpp split.cpp

sentence:
	$(flags) sentence.out sentence.cpp split.cpp
