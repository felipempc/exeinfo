CXX ?= g++
PROGRAM = exeinfo
CXXFILES = exeinfo_main.cpp exeinfo_app.cpp
OBJS = $(CXXFILES:.cpp=.o)
DEPDIR = .deps
CXXFLAGS = `pkg-config --cflags gtkmm-4.0` -std=c++17 -Wall -g
LIBS = `pkg-config --libs gtkmm-4.0`

all: $(PROGRAM)

-include $(OBJS:%.o=$(DEPDIR)/%.Po)

%.o: %.cpp
	@mkdir -p $(DEPDIR)
	$(CXX) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $(CXXFLAGS) $<
	@mv -f $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po

$(PROGRAM): $(OBJS)
	$(CXX) -o $(PROGRAM) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)
	rm -f $(PROGRAM)

