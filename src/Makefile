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
	@echo "No errors"
