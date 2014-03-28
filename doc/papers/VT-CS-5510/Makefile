########################################
########################################
##
##  File:
##    Makefile
##
##  Description:
##    Makefile for complete automation of CS problem sets.
##
##  Author:
##    J. Caleb Wherry
##
##  Created:
##    01/22/2014
##  
########################################
########################################


# Phony targets (no physical file associated with name):
.PHONY: default run figures latex dist clean cleanall

# Log file:
LOGFILE = out.log

# C Compiler:
CC := gcc

# C++ Compiler:
CXX := g++

# C Flags:
CFLAGS := -Wall -Wextra -ggdb -pthread

# Compiler Flags:
CXXFLAGS := -Wall -Wextra -ggdb -O3 -fpermissive -std=c++0x

# C Source Files:
CSRCS = $(wildcard *.c)

# C++ Source Files:
CXXSRCS = $(wildcard *.cpp)

# C Program Names:
CPROGS = $(CSRCS:%.c=%)

# C++ Program Names:
CXXPROGS = $(CXXSRCS:%.cpp=%)

# LateX Files:
# Note: There should only be one LateX file per homework.
LATEX = $(wildcard *.tex)

# Compressed ZIP Distribution File:
DIST_FILE_ZIP = "cwherry.zip"

# Compressed TAR Distribution File:
DIST_FILE_TAR = "cwherry.tar.gz"

# Default target:
default: $(CPROGS) $(CXXPROGS) latex #run figures latex

# Compile executables from C sources:
# Note: If any of the source files are modified, everything gets recompiled. Not much I can do about that right now.
$(CPROGS): $(CSRCS)
	@printf "[Compiling] $@.c --> $@: \n\t"
	$(CC) $(CFLAGS) $@.c -o $@
	@printf "\tdone.\n"

# Compile executables from C++ sources:
# Note: If any of the source files are modified, everything gets recompiled. Not much I can do about that right now.
$(CXXPROGS): $(CXXSRCS)
	@printf "[Compiling] $@.cpp --> $@: \n\t"
	$(CXX) $(CXXFLAGS) $@.cpp -o $@
	@printf "\tdone.\n"

# Run all executables:
run:
	@for f in ""${CPROGS}" "${CXXPROGS}""; do \
	printf "[Running] $$f: \n"; \
	./$$f; \
	done

# Create figures:
figures:
	@printf "[Creating] Figures: \n"
	@for f in `ls *.bfile`; do \
	printf "\tgracebat -batch $$f -nosafe -hardcopy\n"; \
	gracebat -batch $$f -nosafe -hardcopy; \
	done
	@printf "\tdone.\n"

# Compile latex:
latex:
	@for f in ""${LATEX}""; do \
	printf "[Compiling] $$f: \n"; \
	printf "\ttexi2pdf --shell-escape $$f 2>&1 > /dev/null\n"; \
	texi2pdf --shell-escape $$f 2>&1 > /dev/null; \
	done

# Distribution target:
dist:
	@printf "[Compressing] Distribution tar:\n"
	@(PROBLEM_DIR=`basename \`pwd\``; cd ..; tar -zcvf ${DIST_FILE_TAR} $${PROBLEM_DIR}; mv ${DIST_FILE_TAR} $${PROBLEM_DIR}) 2>&1 > /dev/null
	@printf "\tCreated compressed tar: ${DIST_FILE_TAR}\n"
	@printf "[Compressing] Distribution zip:\n"
	@(PROBLEM_DIR=`basename \`pwd\``; cd ..; zip ${DIST_FILE_ZIP} $${PROBLEM_DIR}; mv ${DIST_FILE_ZIP} $${PROBLEM_DIR}) 2>&1 > /dev/null
	@printf "\tCreated compressed tar: ${DIST_FILE_ZIP}\n"

# Clean target:
clean:
	@printf "[Cleaning] Build... "
	@rm -rf ${CPROGS} ${CXXPROGS} ${LOGFILE} *.o *.aux *.bbl *.blg *.out *.log *to.pdf *.dat *.eps *.ps *.bfile *.dSYM
	@printf "done.\n"

# Clean all target:
cleanall: clean
	@printf "[Cleaning] All... "
	@rm -rf ${DIST_FILE_TAR} ${DIST_FILE_ZIP} *.pdf
	@printf "done.\n"
