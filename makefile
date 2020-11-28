CC = g++
CFLAGS = -O3
LINKFLAGS =

PROJECT_NAME = cross_plus
TARGET = $(PROJECT_NAME).out
PRJ_DIR = ./project
BUD_DIR = ./build

SRC_DIR = $(PRJ_DIR)/source
INC_DIR = $(PRJ_DIR)/include
LIB_DIR = $(BUD_DIR)/lib
BIN_DIR = $(BUD_DIR)/bin
OBJ_DIR = $(BUD_DIR)/obj

INCLUDE = -I $(INC_DIR)
LIBS = -L $(LIB_DIR) -lGL -lGLU -lglut
SRCS = $(shell find $(SRC_DIR) -name "*.cpp")
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:%.cpp=%.o)))

${TARGET} : ${OBJS}
	@$(CC) $(LINKFLAGS) -o $(TARGET) $(OBJS) $(LIBS)
	@mv $(notdir ${TARGET}) $(BIN_DIR)/

${OBJS} : $(SRCS)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $^
	@mv $(notdir ${OBJS}) $(OBJ_DIR)/

.PHONY : clean
clean :
	@rm -f $(OBJ_DIR)/*.o
	@rm -f $(BIN_DIR)/$(TARGET)

.PHONY : run
run : $(TARGET)
	$(BIN_DIR)/$(TARGET)

.PHONY : create_dirs
create_dirs :
	@mkdir $(PRJ_DIR)
	@mkdir $(BUD_DIR)
	@mkdir $(SRC_DIR)
	@mkdir $(INC_DIR)
	@mkdir $(LIB_DIR)
	@mkdir $(BIN_DIR)
	@mkdir $(OBJ_DIR)

.PHONY : upload
upload:
	git push --force $(PROJECT_NAME) master