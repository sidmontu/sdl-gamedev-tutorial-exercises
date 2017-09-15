LIB_FLAGS			:= -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

all: tutorial-01 tutorial-02

tutorial-01: tutorial_01/main.cpp tutorial_01/hello.bmp
	@mkdir -p bin
	@g++ -o./bin/$@ tutorial_01/main.cpp $(LIB_FLAGS)

tutorial-02: tutorial_02/main.cpp tutorial_02/hello.bmp
	@mkdir -p bin
	@g++ -o./bin/$@ tutorial_02/main.cpp $(LIB_FLAGS)

clean:
	@rm -rf bin
