CXX = clang++ -std=c++17

INCLUDE = -I.

BUILD_DIR = build

OBJ_RULES = text_utilities.o Settings.o Game.o Bird.o Log.o LogPair.o World.o StateMachine.o TitleScreenState.o CountDownState.o PlayingState.o

LIBS = $$(pkg-config sfml-graphics sfml-audio sfml-window sfml-system --libs --cflags)
LIB_OBJS = $(BUILD_DIR)/*o

main: $(BUILD_DIR) $(OBJ_RULES) main.cpp
	$(CXX) $(INCLUDE) $@.cpp -o $@ $(LIBS) $(LIB_OBJS)

Settings.o: Settings.cpp Settings.hpp
	$(CXX) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

text_utilities.o: $(BUILD_DIR) src/text_utilities.hpp src/text_utilities.cpp
	$(CXX) -c $(INCLUDE) src/text_utilities.cpp -o $(BUILD_DIR)/$@ $(LIBS)

Game.o: src/Game.cpp src/Game.hpp
	$(CXX) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

Bird.o: src/Bird.cpp src/Bird.hpp
	$(CXX) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)
	
Log.o: src/Log.cpp src/Log.hpp
	$(CXX) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

LogPair.o: src/LogPair.cpp src/LogPair.hpp
	$(CXX) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

World.o: src/World.cpp src/World.hpp
	$(CXX) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

StateMachine.o: src/states/StateMachine.cpp src/states/StateMachine.hpp
	$(CXX) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

TitleScreenState.o: src/states/TitleScreenState.cpp src/states/TitleScreenState.hpp
	$(CXX) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

CountDownState.o: src/states/CountDownState.cpp src/states/CountDownState.hpp
	$(CXX) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

PlayingState.o: src/states/PlayingState.cpp src/states/PlayingState.hpp
	$(CXX) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)


$(BUILD_DIR):
	mkdir -p $@

.PHONY:
clean:
	$(RM) -r $(BUILD_DIR) main
