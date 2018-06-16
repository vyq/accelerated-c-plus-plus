compiler = g++-8
standard = -std=c++17
output = -o
flags = $(compiler) $(standard) $(output)

all: count line_numbers

count:
	$(flags) count.out count.cpp

line_numbers:
	$(flags) line_numbers.out line_numbers.cpp split.cpp
