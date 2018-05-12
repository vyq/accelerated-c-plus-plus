compiler = g++
standard = -std=c++1z
output = -o
flags = $(compiler) $(standard) $(output)

all: clean main greeting

clean:
	rm main greeting

main:
	$(flags) main main.cpp student.cpp grade.cpp median.cpp

greeting:
	$(flags) greeting greeting.cpp
