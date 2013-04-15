# Project Makefile

CXX = g++
CXXWARNINGS = -Wall -Wextra -Werror -Wno-unused-parameter
CXXSTYLE = -MMD -O2
CXXFLAGS = -std=c++11 $(CXXWARNINGS) $(CXXSTYLE)

SOURCES = $(shell find . -type f -name '*.cpp')
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(SOURCES:.cpp=.d)

LDFLAGS = /usr/local/lib/libboost_program_options.a

EXEC = yahtzee

#######################################

all: $(EXEC)
depend: $(DEPENDS)
clean:
	@rm -f $(DEPENDS) $(OBJECTS) $(EXEC)

$(EXEC): $(OBJECTS)
	@echo "Linking    $@..."
	@$(CXX) -o $@ $(OBJECTS) $(LDFLAGS) 

#%.d: %.cpp
#	@echo "Building   $@..."
#	@set -e; $(CC) -M $(CPPFLAGS) $< \
#                  | sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
#                [ -s $@ ] || rm -f $@

%.o : %.cpp
	@echo "Compiling  $<..."
	@${CXX} -c ${CXXFLAGS} $< -o $@

-include $(DEPENDS)

