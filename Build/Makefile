CXX = g++
RM = rm -rf
TOUCH = touch

BIN_DIR = ../Bin
BUILD_DIR = .
SRC_DIR = ../Source
INCLUDE_DIR = ../Source
LIB_DIR = ../Source

FILENAME = Talangor
OUTPUT = $(BIN_DIR)/$(FILENAME)

LIBS = -L$(LIB_DIR) -lSDL -lSDL_gfx
CFLAGS = -Wall -O2 -I$(INCLUDE_DIR)

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp))

all: $(OBJS) $(OUTPUT)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $(CFLAGS) -o $@ $<

$(OUTPUT): $(OBJS)
	$(CXX) $(OBJS) $(LIBS) $(CFLAGS) -o $(OUTPUT)

run: $(OUTPUT)
	(cd $(BIN_DIR) && ./$(FILENAME))

clean:
	$(RM) $(wildcard $(BUILD_DIR)/*.o)

touch:
	$(TOUCH) $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR/*.h))


