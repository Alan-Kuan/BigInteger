CXX = g++
CXXFLAG = -Iinclude/
LIB = big_integer.a
EXE = demo

OBJS = $(addprefix obj/,\
	   main.o \
       from_std_string.o \
	   assignment.o \
       constructor.o \
	   sign.o \
       arithmetic.o \
       comparison.o \
	   addition_and_substraction.o \
	   multiplication_and_division.o \
       increament_and_decreament.o \
       input_and_output.o)

vpath %.cpp src/

.PHONY: all clean

all: $(LIB) $(EXE)

$(LIB): $(OBJS)
	ar -src $@ $(OBJS)

$(EXE): $(OBJS)
	$(CXX) -o $@ $^

obj/%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAG)

clean:
	-rm $(OBJS)
	-rm $(EXE)
