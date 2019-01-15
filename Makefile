# Compiler to use
CC := gcc

# Change to executable name.
PROG := openPkmn1

# Add whatever compiler flags you want.
CFLAGS := -std=c99 -pedantic-errors -Wall -Wextra -Werror
CFLAGS := -Wfloat-equal -Wundef -Wshadow -Wpointer-arith
CFLAGS := -Wcast-align -Wstrict-prototypes -Wcast-qual -Wswitch-default
CFLAGS := -Wswitch-enum -Wconversion -Wunreachable-code -Winit-self

# You MUST keep this for auto-dependency generation.
CFLAGS += -MMD

# Can change depending on project
LDLIBS := -lSDL2 -lSDL2_image -lSDL2_mixer

# Not sure when you will really need this. Can leave blank usually.
LDFLAGS :=

# Change 'src/' to where ever you hold src files relative to Makefile.
SRCS := $(wildcard src/*.c)

# Generate .o and .d filenames for each .c file.
# Doesn't generate the ACTUAL files (compiler does).
# Just generates the lists.
OBJS := $(SRCS:.c=.o)
DEPS := $(OBJS:.o=.d)

# GNUMake feature, in case you have files called 'all' or 'clean'.
.PHONY: all clean

# Called when you run 'make'. This calls the line below.
all: $(PROG)

# Calls the compiler with flags to link all object files together.
$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $(PROG)

# Includes the dependency lists (.d files).
-include $(DEPS)

# Removes exectuable, object files, and dependency files.
clean:
	rm -f $(PROG)
	rm -f $(DEPS) $(OBJS)

