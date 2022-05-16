########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = 

# Makefile settings - Can be customized.
APPNAME = myapp
EXT = .cpp
SRCDIR = src
MAINSRCDIR = .
OBJDIR = obj

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
MAINSRC = $(wildcard $(MAINSRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
MAINOBJ = $(MAINSRC:$(MAINSRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(OBJDIR)/%.d)
MAINDEP = $(MAINOBJ:$(OBJDIR)/%.o=$(OBJDIR)/%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
MAINDELOBJ = $(MAINOBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)
MAINWDELOBJ = $(MAINSRC:$(MAINSRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(APPNAME)

# Builds the app
$(APPNAME): $(MAINOBJ) $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
#$(APPNAME): $(MAINOBJ)
#	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
%.d: $(SRCDIR)/%$(EXT) $(MAINSRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@
#%.d: $(MAINSRCDIR)/%$(EXT)
#	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# Includes all .h files
-include $(DEP)
-include $(MAINDEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<
$(OBJDIR)/%.o: $(MAINSRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(MAINDELOBJ) $(MAINDEP) $(APPNAME)
#	$(RM) $(MAINDELOBJ) $(MAINDEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP) $(MAINDEP)
#	$(RM) $(MAINDEP)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)
	$(DEL) $(MAINWDELOBJ) $(MAINDEP) $(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)
	$(DEL) $(MAINDEP)