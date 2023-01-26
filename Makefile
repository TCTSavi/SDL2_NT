CC= g++
RS= windres
MAIN= SDL2_App
MFILES = SDL2_App_Init SDL2_App_loadMedia SDL2_App_Close
IFILES = 
RCFILES =
DFiles = Define

P_INC = Inc
P_LIB = lib
P_RES = res
P_SRC = src
P_OBJ = obj
P_BIN = bin

MOBJS  = $(patsubst %,%.o,$(MFILES))
IOBJS = $(patsubst %,%.o,$(IFILES))
IRC = $(patsubst %,%.o,$(RCFILES))

vpath %.o ${P_OBJ}

all: ${P_BIN}/${MAIN}.exe
	$<
	
${P_BIN}/${MAIN}.exe: ${P_OBJ}/${MAIN}.o ${MOBJS} ${IOBJS} ${IRC} 
	${CC} -static-libgcc -static-libstdc++ -o $@ $< $(patsubst %,${P_OBJ}/%,$(MOBJS)) $(patsubst %,${P_OBJ}/%,$(IOBJS)) $(patsubst %,${P_RES}/%,$(IRC)) -lmingw32 -lSDL2main -lSDL2
	
${P_OBJ}/${MAIN}.o: ${MAIN}.cpp ${MAIN}.h ${DFiles}.h
	${CC}  -c $< -o $@

${MOBJS}: %.o:${P_SRC}/%.cpp ${MAIN}.h ${DFiles}.h 
	${CC}  -c $< -o ${P_OBJ}/$@
	
${IOBJS}: %.o:${P_LIB}/%.cpp ${P_INC}/%.h
	${CC}  -c $< -o ${P_OBJ}/$@
	
${IRC}:	%.o: ${P_RES}/%.rc
	${RS}  -i $< -o ${P_RES}/$@
	
