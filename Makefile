CXX = g++
CXXFLAG = -Iinclude/
EXE = run

OBJS = $(addprefix obj/,\
	   main.o \
       from_std_string.o \
	   assignment.o \
       constructor.o \
       arithmetic.o \
       comparison.o \
	   addition_and_substraction.o \
       increament_and_decreament.o \
       input_and_output.o)

vpath %.cpp src/

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) -o $@ $^

obj/%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAG)

clean:
	-rm $(OBJS)
	-rm $(EXE)
