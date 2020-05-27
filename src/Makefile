CXXFLAGS += -O2
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

ASFLAGS64  = --64

all:
	$(info For Windows use: $(MAKE) windows)
	$(info For Linux use: $(MAKE) linux)
	$(error Missing argument: windows or linux)

compile:
	$(CXX) -c rdrand_func1.cpp -o rdrand_func1.o $(CXXFLAGS)
	$(CXX) -c rdrand_func4.cpp -o rdrand_func4.o $(CXXFLAGS)
	$(CXX) -c rdrand_func8.cpp -o rdrand_func8.o $(CXXFLAGS)
	$(CXX) -c rdrand_func16.cpp -o rdrand_func16.o $(CXXFLAGS)
	$(CXX) -c rdrand_func32.cpp -o rdrand_func32.o $(CXXFLAGS)
	$(CXX) -c rdrand_func64.cpp -o rdrand_func64.o $(CXXFLAGS)
	$(CXX) -c rdrand_func128.cpp -o rdrand_func128.o $(CXXFLAGS)
	$(CXX) -c rdrand_func256.cpp -o rdrand_func256.o $(CXXFLAGS)
	$(CXX) -c rdrand_func512.cpp -o rdrand_func512.o $(CXXFLAGS)
	$(CXX) -c rdrand_func1024.cpp -o rdrand_func1024.o $(CXXFLAGS)
	$(CXX) -c rdrand.cpp -o rdrand.o $(CXXFLAGS)

linux: compile
	$(AS) rdrand_func_linux.S ${ASFLAGS64} -o rdrand_func_linux.o
	$(CXX) rdrand_func1.o rdrand_func_linux.o -o rdrand_func1
	$(CXX) rdrand_func4.o rdrand_func_linux.o -o rdrand_func4
	$(CXX) rdrand_func8.o rdrand_func_linux.o -o rdrand_func8
	$(CXX) rdrand_func16.o rdrand_func_linux.o -o rdrand_func16
	$(CXX) rdrand_func32.o rdrand_func_linux.o -o rdrand_func32
	$(CXX) rdrand_func64.o rdrand_func_linux.o -o rdrand_func64
	$(CXX) rdrand_func128.o rdrand_func_linux.o -o rdrand_func128
	$(CXX) rdrand_func256.o rdrand_func_linux.o -o rdrand_func256
	$(CXX) rdrand_func512.o rdrand_func_linux.o -o rdrand_func512
	$(CXX) rdrand_func1024.o rdrand_func_linux.o -o rdrand_func1024
	$(CXX) rdrand.o rdrand_func_linux.o -o rdrand

windows: compile
	$(AS) rdrand_func_windows.S ${ASFLAGS64} -o rdrand_func_windows.o
	$(CXX) rdrand_func1.o rdrand_func_windows.o -o rdrand_func1.exe
	$(CXX) rdrand_func4.o rdrand_func_windows.o -o rdrand_func4.exe
	$(CXX) rdrand_func8.o rdrand_func_windows.o -o rdrand_func8.exe
	$(CXX) rdrand_func16.o rdrand_func_windows.o -o rdrand_func16.exe
	$(CXX) rdrand_func32.o rdrand_func_windows.o -o rdrand_func32.exe
	$(CXX) rdrand_func64.o rdrand_func_windows.o -o rdrand_func64.exe
	$(CXX) rdrand_func128.o rdrand_func_windows.o -o rdrand_func128.exe
	$(CXX) rdrand_func256.o rdrand_func_windows.o -o rdrand_func256.exe
	$(CXX) rdrand_func512.o rdrand_func_windows.o -o rdrand_func512.exe
	$(CXX) rdrand_func1024.o rdrand_func_windows.o -o rdrand_func1024.exe
	$(CXX) rdrand.o rdrand_func_windows.o -o rdrand.exe
