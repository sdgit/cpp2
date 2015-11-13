
TOPDIR    := $(shell pwd)
SRCDIR    := $(TOPDIR)/src
INCDIR    := $(TOPDIR)/include
TESTDIR   := $(TOPDIR)/unittests

BIN := cpp2
SRC := $(SRCDIR)/main.cpp
LIB := 

ifeq ($(DEBUG),1)
LIB := 
endif

# Check for "verbose" setting - to enable use 'make V=1'
ifeq ($(V),1)
  Q:=
else
  # Shell commands prefaced by "$(Q)" will be silent.
  Q:=@
  # Do not print "Entering directory ..." messages
  MAKEFLAGS += --no-print-directory
endif

# Internal compile flags and optimizations
C_WARN_FLAGS   := -W -Wall -Wcast-align -Wcast-qual -Wwrite-strings \
                  -Wbad-function-cast -Wstrict-prototypes -Wmissing-prototypes \
                  -Wparentheses -Wno-unused-parameter \
                  $(call cc-option,-Wno-missing-field-initializers,)
CXX_WARN_FLAGS := -W -Wall -Wcast-align -Wcast-qual -Wwrite-strings -Wwrite-strings \
                  -Wno-ctor-dtor-privacy -Wparentheses -Wno-unused-parameter \
                  $(call cc-option,-Wno-missing-field-initializers,)
OPT_FLAGS      := -fPIC

OPTIMIZE_FLAG  := -O2
DEBUG_FLAG     := -DNDEBUG

ifeq ($(DEBUG),1)
OPTIMIZE_FLAG  := -O0
DEBUG_FLAG     := -DDEBUG
endif

BUILD_FLAGS    := $(OPTIMIZE_FLAG) -g3 -ggdb -pipe $(DEBUG_FLAG) $(BUILD_WORKDIR)
OBJ            := o
BIN_SUFFIX     :=

ifeq ($(DEBUG),1)
OBJ := d.o
BIN_SUFFIX := _d
endif
ifeq ($(PROFILE),1)
BUILD_FLAGS += -DPROFILE -pg
OBJ := p.o
BIN_SUFFIX := _p
endif
ifeq ($(shell uname -m),x86_64)
OPT_FLAGS += -m64
ifneq ($(shell grep -i opteron /proc/cpuinfo),)
OPT_FLAGS += -march=opteron
else
OPT_FLAGS += -march=nocona
endif
endif
ifeq ($(shell uname -m),i686)
OPT_FLAGS += -march=i686
endif

# Compiler programs
CC    := gcc
CXX   := g++

.PHONY: debug
debug:
	$(Q)$(MAKE) DEBUG=1

.PHONY: unittests
unittests: $(TESTDIR) 
	$(Q)if [ -d $(TESTDIR) -a -f $(TESTDIR)/Makefile ]; then $(MAKE) -C $(TESTDIR); fi

git:
	git commit -m "$m"

%.$(OBJ): %.c
	$(call ECHO,Compiling $<)
	$(Q)$(COMPILE.c) -o $@ $<
%.$(OBJ): %.cpp
	$(call ECHO,Compiling $<)
	$(Q)$(COMPILE.cpp) -o $@ $<
%.$(OBJ): %.C
	$(call ECHO,Compiling $<)
	$(Q)$(COMPILE.cpp) -o $@ $<
%.cxxtest.C: %.cxxtest.h
	$(call ECHO,Generating $@)
	$(Q)cxxtestgen.py --have-std --part -o $@ $^
