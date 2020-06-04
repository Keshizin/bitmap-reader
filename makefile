BIN_DIR=bin
OUTPUT_NAME=libdibr.a
SRC_DIR=src
OBJ_DIR=obj
INC_DIR=inc

CPPSOURCES=$(wildcard $(SRC_DIR)/*.cpp)
OBJFILES=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPPSOURCES))

INC_FLAGS=-I$(INC_DIR)

all: $(BIN_DIR)/$(OUTPUT_NAME)

# Geração da biblioteca estática
$(BIN_DIR)/$(OUTPUT_NAME): $(OBJFILES)
	ar rcs $@ $^

# Compilação
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@g++ -c $< $(INC_FLAGS) -o $@ -Wall


# -----------------------------------------------------------------------------
#  T E S T I N G   B U I L D S
# -----------------------------------------------------------------------------
OUTPUT_TEST_NAME=dibtest.exe
TEST_DIR=tests

DIRLIB_FLAGS=-L$(BIN_DIR)
LIB_FLAGS=-ldibr

test-all:
	$(MAKE) all
	g++ $(TEST_DIR)/main.cpp $(INC_FLAGS) $(DIRLIB_FLAGS) $(LIB_FLAGS) -o $(BIN_DIR)/$(OUTPUT_TEST_NAME) -Wall

# -----------------------------------------------------------------------------
#  C L E A N I N G   B U I L D
# -----------------------------------------------------------------------------
clean-exe:
	del $(BIN_DIR)\$(OUTPUT_NAME)
	del $(BIN_DIR)\$(OUTPUT_TEST_NAME)

clean-obj:
	del $(OBJ_DIR)\*.o
	del $(TEST_DIR)\*.o

clean-all:
	$(MAKE) clean-exe
	$(MAKE) clean-obj