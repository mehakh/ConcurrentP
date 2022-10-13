APP_NAME := concurrency-lab

CXX := g++
CXXFLAGS := -Wall -g

MKDIR = mkdir
 
INCLUDES := -I./include -I./json/include 
LIB_INCLUDES :=
SRC_DIR := src
BUILD_DIR := build

INC := $(INCLUDES) $(LIB_INCLUDES)

SRC := $(shell find $(SRC_DIR) -name "*.cpp")
OBJECTS  := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))
 
LIBS :=

all: $(APP_NAME)

$(APP_NAME): $(OBJECTS)
	$(CXX) -o $(APP_NAME) $(OBJECTS) $(CXXFLAGS) $(LIBS) 
 
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(BUILD_DIR)
	$(CXX) $(INC) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

clean:
	rm -f $(APP_NAME)
	rm -f $(OBJECTS)
	rm -rf $(BUILD_DIR)
