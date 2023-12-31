CXX ?= g++
PROGRAM = exeinfo
CXXFILES = $(wildcard *.cpp)
OBJDIR = ./obj
OBJS = $(CXXFILES:%.cpp=$(OBJDIR)/%.o)
DEPDIR = .deps
CXXFLAGS = `pkg-config --cflags gtkmm-4.0` -std=c++17 -Wall -g
LIBS = `pkg-config --libs gtkmm-4.0`


-include $(OBJS:%.o=$(DEPDIR)/%.Po)

all: clean $(PROGRAM)

build: $(PROGRAM)


$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(DEPDIR)
	$(CXX) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $(CXXFLAGS) $<
	@mv -f $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po

$(PROGRAM): $(OBJS)
	$(CXX) -o $(PROGRAM) $(OBJS) $(LIBS)


clean:
	@echo "Cleaning out..."
	rm -f $(OBJS)
	rm -f $(PROGRAM)

check:
	@echo "SOURCES = "$(CXXFILES)
	@echo "OBJDIR = "$(OBJDIR)
	@echo "OBJS = "$(OBJS)
	@echo "PROGRAM = "$(PROGRAM)

.PHONY: all build clean check

