#Makefile Linux
EXEC = MetalSlug
COMPILO = g++
OPTION = -Wall -Wno-switch

#Path
PATH_INC = include
PATH_LIB = lib
PATH_SRC = src
PATH_OBJ = obj

#Directories
OBJ_DIR = obj obj/model obj/controller obj/view

# SFML
PATH_SFML = $(PATH_LIB)/SFML
LIB_SFML  = -lsfml-audio-s -lsfml-network-s -lsfml-graphics-s -lsfml-window-s -lsfml-system-s

# TOOLS 
# PATH_TOOLS = $(PATH_LIB)/tools
# LIB_TOOLS  = -lXMLtools

#Librairies
LIB_DEP = -ljpeg -lGL -lGLEW -ludev -lXrandr -lX11 -lpthread -lfreetype -lopenal -lsndfile

#Liste fichiers .cpp et .O
SRC = $(wildcard $(PATH_SRC)/*.cpp) $(wildcard $(PATH_SRC)/*/*.cpp) 
OBJ = $(SRC:$(PATH_SRC)/%.cpp=$(PATH_OBJ)/%.o)

#Actions
all : $(EXEC)
	export LD_LIBRARY_PATH=$(PATH_LIB) && ./$(EXEC)

valgrind : $(EXEC)
	export LD_LIBRARY_PATH=$(PATH_LIB) && valgrind ./$(EXEC)

debug : $(EXEC)
	export LD_LIBRARY_PATH=$(PATH_LIB) && gdb ./$(EXEC)

$(EXEC) : $(OBJ)
	@echo "\033[31m[Link] $(EXEC)\033[00m"
	@$(COMPILO) $(OPTION) -std=c++11 -o $@ -Wl,-Bstatic $^ -L$(PATH_SFML) $(LIB_SFML) -Wl,-Bdynamic $(LIB_DEP)

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.cpp
	@echo "\033[32m[Build] $@\033[00m"
	@$(COMPILO) $(OPTION) -o $@ -c $< -I$(PATH_INC)

init :
	mkdir -p obj obj/model obj/controller obj/view obj/tools

clean :
	@echo "Suppression des .o"
	@find . -name '*.o' -exec rm  {} \;

install : 
	sudo apt-get install g++ build-essential udev libudev-dev libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libfreetype6-dev libglew-dev libjpeg-dev libsndfile1-dev libopenal-dev

commit :
	git commit -a
	git push

add :
	@git add . --verbose

documentation :
	doxygen