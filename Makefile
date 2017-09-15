UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIB_FLAGS				:= -lSDL2
	INCLUDE_FLAGS			:= 
endif
ifeq ($(UNAME_S),Darwin)
	INCLUDE_FLAGS			:= -I/opt/local/include/SDL2 -I/opt/local/include -D_THREAD_SAFE 
	LIB_FLAGS				:= -L/opt/local/lib -lSDL2
endif


all: tutorial-01 tutorial-02

tutorial-01: tutorial_01/main.cpp tutorial_01/hello.bmp
	@mkdir -p bin
	@g++ -o./bin/$@ $(INCLUDE_FLAGS) tutorial_01/main.cpp $(LIB_FLAGS)

tutorial-02: tutorial_02/main.cpp tutorial_02/hello.bmp
	@mkdir -p bin
	@g++ -o./bin/$@ $(INCLUDE_FLAGS) tutorial_02/main.cpp $(LIB_FLAGS)

clean:
	@rm -rf bin
