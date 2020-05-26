CXXFLAGS += -O2
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

ASFLAGS64  = --64

all:
	$(AS) rdrand_func_windows.S ${ASFLAGS64} -o rdrand_func_windows.o
	$(AS) rdrand_func_linux.S ${ASFLAGS64} -o rdrand_func_linux.o
	$(CXX) -c rdrand_func1.cpp -o rdrand_func1.o $(CXXFLAGS)
	$(CXX) -c rdrand_func4.cpp -o rdrand_func4.o $(CXXFLAGS)
	$(CXX) -c rdrand_func8.cpp -o rdrand_func8.o $(CXXFLAGS)
	$(CXX) -c rdrand_func16.cpp -o rdrand_func16.o $(CXXFLAGS)
	$(CXX) -c rdrand_func32.cpp -o rdrand_func32.o $(CXXFLAGS)

linux:
	$(CXX) rdrand_func1.o rdrand_func_linux.o -o rdrand_func1
	$(CXX) rdrand_func4.o rdrand_func_linux.o -o rdrand_func4
	$(CXX) rdrand_func8.o rdrand_func_linux.o -o rdrand_func8
	$(CXX) rdrand_func16.o rdrand_func_linux.o -o rdrand_func16
	$(CXX) rdrand_func32.o rdrand_func_linux.o -o rdrand_func32
