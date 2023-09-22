CC := g++



ASAN :=#-fsanitize=address
STDFLAGS :=-Wall -Wextra -std=c++17
CFLAGS ?= $(STDFLAGS) $(ASAN)
TST_CFLAGS ?=$(CFLAGS) $(shell pkg-config --cflags check)
GCOV_FLAGS ?= -fprofile-arcs -ftest-coverage
TST_LIBS := $(shell pkg-config --libs check)

DIR ?= ./

BASE_DIR ?= $(DIR)base/
BASE_SRC := $(wildcard $(BASE_DIR)*.c)
BASE_INC := $(wildcard $(BASE_DIR)*.h)
BASE_OBJ_DIR ?= $(BASE_DIR)objs/
BASE_OBJ := $(addprefix $(BASE_OBJ_DIR), $(notdir $(BASE_SRC:.c=.o)))

EXTRA_DIR ?= $(DIR)extra/
EXTRA_SRC := $(wildcard $(EXTRA_DIR)*.c)
EXTRA_INC := $(wildcard $(EXTRA_DIR)*.h)
EXTRA_OBJ_DIR ?= $(EXTRA_DIR)objs/
EXTRA_OBJ := $(addprefix $(EXTRA_OBJ_DIR), $(notdir $(EXTRA_SRC:.c=.o)))

TEST_DIR ?= $(DIR)tests/
TEST_SRC := $(wildcard $(TEST_DIR)*.cc)
TEST_INC := $(wildcard $(TEST_DIR)*.h)
TEST_OBJ_DIR ?= $(TEST_DIR)objs/
TEST_OBJ := $(addprefix $(TEST_OBJ_DIR), $(notdir $(TEST_SRC:.c=.o)))

GCOV_BASE_OBJ := $(addprefix $(TEST_OBJ_DIR), $(notdir $(BASE_SRC:.c=.o)))
GCOV_EXTRA_OBJ := $(addprefix $(TEST_OBJ_DIR), $(notdir $(EXTRA_SRC:.c=.o)))
GCOV_TARGET ?= $(DIR)coverage
GCOV_INFO ?= coverage.info

AR := ar rc
RAN := ranlib
MK := mkdir -p
RM := rm -rf

LIB ?= calculator.a
TEST_LIB ?= calculator_test.a
TEST_EXE ?= $(DIR)run_test



CC=g++
STRICT_CFLAGS=-Wall -std=c++17 -Wextra -pedantic -g 
# STRICT_CFLAGS=-Wall -std=c++17 -Wextra -pedantic -g


GCOVR_CFLAGS=-fprofile-arcs -ftest-coverage -fPIC
GCOVR_CFLAGS=--coverage
GCOVR_LFLAGS=-lgcov
GCOVR_LFLAGS=--coverage

GTEST_LFLAGS=-lgtest -lgtest_main

SOURCES+=tests/calculator_test.cc
SOURCES+=tests/main_test.cc
SOURCES+=base/calculation.cc
SOURCES+=base/checking.cc
SOURCES+=base/convertation.cc
SOURCES+=base/polish_notation.cc
SOURCES+=base/validation.cc
SOURCES+=base/variable_operations.cc

BINARIES=$(patsubst %.cc,%.o,$(SOURCES))

.PHONY: all test $(LIB) gcov_report open check style valgrind leaks clean fclean rebuild

all: test $(LIB) gcov_report clean


test: run_tests

tests/main_test.out: $(BINARIES)
		$(CC) -o $@ $^ $(GTEST_LFLAGS) $(GCOVR_LFLAGS) -g

%.o: %.cc $(HEADERS)
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS) $(GTEST_CFLAGS)

run_tests: tests/main_test.out
		./tests/main_test.out


# test: create_obj_test_dir $(TEST_LIB) $(TEST_OBJ)
# 	$(CC) $(TEST_OBJ) $(GCOV_FLAGS) $(ASAN) -L. $(TEST_LIB) -o $(TEST_EXE) $(TST_LIBS)
# 	$(TEST_EXE)

# create_obj_test_dir:
# 	@$(MK) $(TEST_OBJ_DIR)

$(TEST_LIB): $(GCOV_BASE_OBJ) $(GCOV_EXTRA_OBJ)
	$(AR) $(TEST_LIB) $(GCOV_BASE_OBJ) $(GCOV_EXTRA_OBJ)
	$(RAN) $(TEST_LIB)

$(GCOV_BASE_OBJ): $(TEST_OBJ_DIR)%.o: $(BASE_DIR)%.c $(BASE_INC)
	$(CC) $(TST_CFLAGS) $(GCOV_FLAGS) $< -o $@

$(GCOV_EXTRA_OBJ): $(TEST_OBJ_DIR)%.o: $(EXTRA_DIR)%.c $(EXTRA_INC)
	$(CC) $(TST_CFLAGS) $(GCOV_FLAGS) $< -o $@

$(TEST_OBJ_DIR)%.o: $(TEST_DIR)%.c $(TEST_INC)
	$(CC) $(TST_CFLAGS) $< -o $@

$(LIB): create_obj_dir $(BASE_OBJ) $(EXTRA_OBJ)
	$(AR) $(LIB) $(BASE_OBJ) $(EXTRA_OBJ)
	$(RAN) $(LIB)

create_obj_dir:
	@$(MK) $(BASE_OBJ_DIR) $(EXTRA_OBJ_DIR)

$(BASE_OBJ): $(BASE_OBJ_DIR)%.o: $(BASE_DIR)%.c $(BASE_INC)
	$(CC) $(STDFLAGS) $< -o $@

$(EXTRA_OBJ): $(EXTRA_OBJ_DIR)%.o: $(EXTRA_DIR)%.c $(EXTRA_INC)
	$(CC) $(STDFLAGS) $< -o $@

gcov_report: test $(GCOV_TARGET)

$(GCOV_TARGET): $(GCOV_INFO)
	genhtml $(GCOV_INFO) -o $(GCOV_TARGET)

$(GCOV_INFO):
	geninfo $(TEST_OBJ_DIR) -b . -o $(DIR)$(GCOV_INFO)

open:
	@open $(GCOV_TARGET)/index.html

check: style valgrind leaks

style:
	@cp ../../materials/linters/.clang-format $(BASE_DIR).clang-format
	@clang-format -n $(BASE_DIR)*.c $(BASE_DIR)*.h
	@$(RM) $(BASE_DIR).clang-format
	@cp ../../materials/linters/.clang-format $(EXTRA_DIR).clang-format
	@clang-format -n $(EXTRA_DIR)*.c $(EXTRA_DIR)*.h
	@$(RM) $(EXTRA_DIR).clang-format
	@cp ../../materials/linters/.clang-format $(TEST_DIR).clang-format
	@clang-format -n $(TEST_DIR)*.c $(TEST_DIR)*.h
	@$(RM) $(TEST_DIR).clang-format

valgrind: test
	valgrind $(TEST_EXE) -s --leak-check=full --track-origins=yes

leaks: test
ifeq ($(shell uname), Darwin)
	@CK_FORK=no leaks --atExit -- $(TEST_EXE)
endif

clean:
	@$(RM) $(BASE_OBJ_DIR)
	@$(RM) $(EXTRA_OBJ_DIR)
	@$(RM) $(TEST_OBJ_DIR)
	@$(RM) $(TEST_LIB)
	@$(RM) $(GCOV_INFO)
	@$(RM) run_test.dSYM
	rm -rf *.o *.exe *.out *.oa *.a *.gcov *.txt
	rm -rf base/*.o base/*.exe base/*.out base*.oa base/*.a base/*.gcov base/*.txt base/*.gcda base/*.gcno
	rm -rf tests/*.o tests/*.exe tests/*.out tests/*/*.o tests/*.o 
	rm -rf *.gcno *.gcda tests/*/*.gcno tests/*/*.gcda tests/*.gcno tests/*.gcda tests/*.gcov tests/*/*.gcov

fclean: clean
	@$(RM) $(GCOV_TARGET)
	@$(RM) $(TEST_EXE)
	@$(RM) $(LIB)

rebuild: fclean all