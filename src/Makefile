PROJECT_NAME ?= SmartCalc_v1

PATH_BACKEND ?= ./backend/
PATH_FRONTEND ?= ./frontend/
PATH_BUILD ?= ./build/
PATH_DOCS ?= ./docs/

CUR_DATE ?= `date +"%Y.%m.%d"`
PATH_ARCHIVE ?= $(PROJECT_NAME)_$(CUR_DATE)

MK := mkdir -p
RM := rm -rf

.PHONY: all uninstall open_report clean fclean check style valgrind leaks re

all: test install clean dist

run: install
	$(MAKE) -C $(PATH_BUILD)
	@$(PATH_BUILD)$(PROJECT_NAME)

install:
	@$(MK) $(PATH_BUILD)
	cmake CMakeLists.txt -S . -B $(PATH_BUILD)

uninstall:
	@$(RM) $(PATH_BUILD)CMakeFiles
	@$(RM) $(PATH_BUILD)$(SmartCalc_v1)_autogen
	@$(RM) $(PATH_BUILD)cmake_install.cmake
	@$(RM) $(PATH_BUILD)CMakeCache.txt
	@$(RM) $(PATH_BUILD)Makefile

test:
	$(MAKE) -C $(PATH_BACKEND) test

gcov_report:
	$(MAKE) -C $(PATH_BACKEND) gcov_report

open_report:
	$(MAKE) -C $(PATH_BACKEND) open

dvi: 
	mkdir -p docs
	doxygen Doxyfile
	@mv html latex docs
	open docs/html/index.html

dist: clean
	@$(MK) $(PATH_ARCHIVE)
	@cp -r $(PATH_BACKEND) $(PATH_ARCHIVE)
	@cp -r $(PATH_FRONTEND) $(PATH_ARCHIVE)
	@cp CMakeLists.txt $(PATH_ARCHIVE)
	@cp CMakeLists.txt.user $(PATH_ARCHIVE)
	@cp Makefile $(PATH_ARCHIVE)
	@tar -czvf $(PATH_ARCHIVE).tar.gz $(PATH_ARCHIVE)
	@$(RM) $(PATH_ARCHIVE)

check: style valgrind leaks

style:
	$(MAKE) -C $(PATH_BACKEND) style
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -n $(PATH_FRONTEND)*.cpp $(PATH_FRONTEND)*.h
	@rm .clang-format

valgrind:
	$(MAKE) -C $(PATH_BACKEND) valgrind

leaks:
	$(MAKE) -C $(PATH_BACKEND) leaks

clean: uninstall
	@$(MAKE) -C $(PATH_BACKEND) clean
	@$(RM) $(PATH_DOCS)latex.aux
	@$(RM) $(PATH_DOCS)latex.dvi
	@$(RM) $(PATH_DOCS)latex.log

fclean: clean
	@$(MAKE) -C $(PATH_BACKEND) fclean
	@$(RM) $(PATH_BUILD)
	@$(RM) $(PATH_DOCS)
	@$(RM) $(PATH_ARCHIVE).tar.gz
	@$(RM) *-Debug

re: fclean all
