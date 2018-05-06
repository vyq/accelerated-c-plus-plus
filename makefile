compiler = g++
standard = -std=c++1z
flags = $(compiler) $(standard)

all: scratch

scratch:
	$(flags) scratch.cpp
