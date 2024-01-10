CXX = g++
CXXFLAGS = -Wall -Wconversion -g -Wextra
# CXXFLAGS += -Werror
CXXFLAGS += -std=c++17
CXXFLAGS += -I game_objects/ -I level/ -I menegge/ -I creator/ -I physics/
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
LDFLAGS = -L/path/to/SFML/libraries   # If SFML is installed in a custom location

# Object files 
OBJS = menegge/main.o menegge/game.o menegge/globals.o creator/creator.o game_objects/ball.o game_objects/brick.o game_objects/paddle.o level/colisions.o level/events.o level/level.o physics/physics.o


# Executable
APP = app

$(APP): $(OBJS)
	$(CXX) $(OBJS) -o $(APP) $(LIBS) $(LDFLAGS)

%.o : %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clear:
	rm -f $(APP) $(OBJS)

run: 
# $(APP)
	./$(APP)
