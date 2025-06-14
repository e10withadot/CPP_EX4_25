# ey.gellis@gmail.com
.PHONY: main tests valgrind clean

CXX = g++
CXXFLAGS = -Wall -Wextra -g

PROG = Container
PROG_SRC = main.cpp
PROG_OBJ = $(PROG_SRC:.cpp=.o)

TEST = Test
TEST_SRC = test.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

main: $(PROG)
	./$(PROG)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PROG): $(PROG_OBJ)
	$(CXX) $(CXXFLAGS) $(PROG_OBJ) -o $@

$(TEST): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(TEST_OBJ) -o $@

tests: $(TEST)
	./$(TEST)

valgrind: $(PROG)
	Valgrind --leak-check=full --error-exitcode=1 ./$(PROG)

clean:
	rm -f $(PROG) $(TEST) $(PROG_OBJ) $(TEST_OBJ) 
