CC = clang

INCLUDE = -I./src -I./settings

SRC_DIR = src
BUILD_DIR = build
OBJS = fonts.o paddle.o ball.o pong.o hitbox.o sounds.o paddle_ia.o

LIBS = $$(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_primitives-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5 --libs --cflags)

LIB_OBJS = $(BUILD_DIR)/*o

main: main.c $(BUILD_DIR) $(OBJS)
	$(CC) $(INCLUDE) $< -o $@ $(LIBS) $(LIB_OBJS)

fonts.o: $(SRC_DIR)/fonts.c $(SRC_DIR)/fonts.h
	$(CC) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

paddle.o: $(SRC_DIR)/paddle.c $(SRC_DIR)/paddle.h
	$(CC) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

ball.o: $(SRC_DIR)/ball.c $(SRC_DIR)/ball.h
	$(CC) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

pong.o: $(SRC_DIR)/pong.c $(SRC_DIR)/pong.h
	$(CC) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

paddle_ia.o: $(SRC_DIR)/paddle_ia.c $(SRC_DIR)/paddle_ia.h
	$(CC) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

hitbox.o: $(SRC_DIR)/hitbox.c $(SRC_DIR)/hitbox.h
	$(CC) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

sounds.o: $(SRC_DIR)/sounds.c $(SRC_DIR)/sounds.h
	$(CC) -c $(INCLUDE) $< -o $(BUILD_DIR)/$@ $(LIBS)

$(BUILD_DIR):
	mkdir -p $@

.PHONY:
clean:
	$(RM) -r $(BUILD_DIR) main
