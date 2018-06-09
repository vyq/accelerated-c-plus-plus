compiler = g++-8
standard = -std=c++17
flags = $(compiler) $(standard)

all: scratch

scratch:
	$(flags) scratch.cpp
