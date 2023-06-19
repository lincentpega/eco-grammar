ifeq ($(TARGET), 1)
OUT_TARGET = EcoMySimpleCompiler
ifeq ($(DEBUG), 1)
CONFIG_TARGET = StaticDebug
CCFLAGS_TARGET = -Wall -g -DECO_LIB
LDFLAGS_TARGET =
else
CONFIG_TARGET = StaticRelease
CCFLAGS_TARGET = -O3 -DECO_LIB
LDFLAGS_TARGET =
endif
else
OUT_TARGET = EcoMySipleCompiler
ifeq ($(DEBUG), 1)
CONFIG_TARGET = DynamicDebug
CCFLAGS_TARGET = -Wall -g -DECO_DLL
LDFLAGS_TARGET = 
else
CONFIG_TARGET = DynamicRelease
CCFLAGS_TARGET = -O3 -DECO_DLL
LDFLAGS_TARGET = 
endif
endif

# source files.
SRC = \
../../../SourceFiles/EcoJSCompiler.c \
../../../SourceFiles/EcoMyGrammar.c \
../../../SourceFiles/EcoOutputDiagnostic.c \
../../../SourceFiles/EcoMySimpleCompiler.c


# include directories
INCLUDES = \
-I ../../../HeaderFiles \
-I ../../../SharedFiles \
-I ../../../UnitTestFiles/HeaderFiles \
-I ../../../UnitTestFiles/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Toolchain.EmitterI8086/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Toolchain.RL1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Toolchain.LR1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Toolchain.BNF1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Toolchain.AST1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Toolchain.LexicalAnalyzer1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Data1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.MemoryManager1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.FileSystemManagement1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.InterfaceBus1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Core1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.OMF1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.FSM1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Log1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.DateTime1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.System1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Dictionary1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.String1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Stack1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Set1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Tree1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Visitor1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Comparator1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.Map1/SharedFiles \
-I $(ECO_FRAMEWORK)/Eco.List1/SharedFiles


# libraries directories
LIB_DIR = \
-L ../../../BuildFiles/Linux/x64/$(CONFIG_TARGET) \
-L $(ECO_FRAMEWORK)/Eco.System1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.InterfaceBus1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.MemoryManager1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Toolchain.BNF1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Toolchain.AST1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Toolchain.LR1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Toolchain.RL1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Toolchain.LexicalAnalyzer1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Toolchain.SyntaxAnalyzer1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Toolchain.MacroProcessor1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Toolchain.Linker1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Toolchain.CodeGenerator1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Toolchain.Emitter80689/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.FileSystemManagement1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.DateTime1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.COFF1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.PECOFF1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Toolchain.BNF1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.FSM1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Map1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Set1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Comparator1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Stack1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Dictionary1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Tree1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Log1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Visitor1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.String1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.Comparator1/BuildFiles/Linux/x64/StaticRelease \
-L $(ECO_FRAMEWORK)/Eco.List1/BuildFiles/Linux/x64/StaticRelease


OBJ = $(SRC:.c=.o)

OUT = $(OUT_TARGET)
OUT_DIR = ../../../BuildFiles/Linux/x64/$(CONFIG_TARGET)

# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = $(CCFLAGS_TARGET) -DLINUX -DUGUID_UTILITY -DECO_LINUX 

# compiler
GNU =
CC = gcc
AR = gcc-ar

ifeq ($(TARGET), 1)
LIBS_TARGET=-l323DD55E33D040FA98068E2FCB1CBD49 \
-l84CC0A7DBABD44EEBE749C9A8312D37E \
-l53884AFC93C448ECAA929C8D3A562281 \
-l2912A7C7E0B84B4D9BFE9500EF4667D3 \
-l5E7C610CB846447DB59A3C5A2C4F446F \
-l18129B1DCF9248D9A7787F9206E2D6DC \
-l97322B6765B74342BBCE38798A0B40B5 \
-l82F73722057E47F3A2931ED27087694D \
-l4E7C20FEFAF341069B5C42497B462BBE \
-l5B2BA17BEA704527BC708F88568FE115 \
-lC7ED3BA4B6EB4385BBDB3C6AC5C7A394 \
-l7750135D34D7461897B912F7CC615F72 \
-l0D7907DBE1C14B9E9B9FD9E8D9E251DF
else
LIBS_TARGET=
endif

# library paths
LIBS = $(LIB_DIR) -lX11 -lm -lc -lgcc -ldl -l00000000000000000000000000000100 -l00000000000000000000000042757331 -l0000000000000000000000004D656D31 -l00000000000000000000000046534D31 $(LIBS_TARGET) -lGL -LGLX

# compile flags
LDFLAGS = $(LDFLAGS_TARGET) $(LIBS)

.SUFFIXES: .c

.c.o:
	$(CC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	mkdir -p $(OUT_DIR)
	$(CC) ${LDFLAGS} -o $(OUT_DIR)/$(OUT) $(OBJ) $(LDFLAGS)
	rm $(OBJ)
#ifeq ($(TARGET), 1)
	cp $(ECO_FRAMEWORK)/Eco.String1/BuildFiles/Linux/x64/DynamicRelease/84CC0A7DBABD44EEBE749C9A8312D37E.so $(OUT_DIR)
	cp $(ECO_FRAMEWORK)/Eco.Log1/BuildFiles/Linux/x64/DynamicRelease/97322B6765B74342BBCE38798A0B40B5.so $(OUT_DIR)
	cp $(ECO_FRAMEWORK)/Eco.FSM1/BuildFiles/Linux/x64/DynamicRelease/5E7C610CB846447DB59A3C5A2C4F446F.so $(OUT_DIR)
	cp $(ECO_FRAMEWORK)/Eco.List1/BuildFiles/Linux/x64/DynamicRelease/53884AFC93C448ECAA929C8D3A562281.so $(OUT_DIR)
	cp $(ECO_FRAMEWORK)/Eco.Data1/BuildFiles/Linux/x64/DynamicRelease/5A0F0DD57E6448EC9EE0E5D67572B47E.so $(OUT_DIR)
	cp $(ECO_FRAMEWORK)/Eco.DateTime1/BuildFiles/Linux/x64/DynamicRelease/5B2BA17BEA704527BC708F88568FE115.so $(OUT_DIR)
	cp $(ECO_FRAMEWORK)/Eco.Dictionary1/BuildFiles/Linux/x64/DynamicRelease/2912A7C7E0B84B4D9BFE9500EF4667D3.so $(OUT_DIR)
	cp $(ECO_FRAMEWORK)/Eco.Toolchain.RL1/BuildFiles/Linux/x64/DynamicRelease/9D51655E6B8542EDB7D0CC7C9980D749.so $(OUT_DIR)
	cp $(ECO_FRAMEWORK)/Eco.Toolchain.BNF1/BuildFiles/Linux/x64/DynamicRelease/323DD55E33D040FA98068E2FCB1CBD49.so $(OUT_DIR)
#endif

clean:
	rm $(OBJ) $(OUT_DIR)/$(OUT)


