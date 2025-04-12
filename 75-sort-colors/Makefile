### If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.

LIBS =
TLIBS =  -lgtest
TLIBS += -lgtest_main
TLIBS += -pthread

###
CXXFLAGS = -std=c++23
CXXFLAGS += -ggdb
CXXFLAGS += -Wall
CXXFLAGS += -Weffc++
CXXFLAGS += -Wextra
CXXFLAGS += -Wconversion
CXXFLAGS += -Wsign-conversion
CXXFLAGS += -pedantic
CXXFLAGS += -pedantic-errors
CXXFLAGS += -Werror
CXXFLAGS += -Wmissing-declarations

# .PHONY: all
# all: main.out
# 	@./main.out

.PHONY: all
all: test.out
	@./test.out


.PHONY: test
test: test.out
	@./test.out #--gtest_filter=QuickSortTest.Example2

# main.out: ./main.cpp
# 	@echo Compiling $@
# 	@$(CXX) $(CXXFLAGS) main.cpp -o main.out $(LIBS)

test.out: test.cpp main.cpp
	@echo Compiling test suite with GoogleTest
	@$(CXX) $(CXXFLAGS) test.cpp main.cpp -o test.out $(TLIBS) $(LIBS)

.PHONY: clean
clean:
	rm -rf *.o *.out *.out.dSYM
