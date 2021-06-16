#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1c33d1d4/Book.o \
	${OBJECTDIR}/_ext/1c33d1d4/Product.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppgeneralized_sll.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppgeneralized_sll.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppgeneralized_sll ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1c33d1d4/Book.o: /cygdrive/D/Data\ Structure\ and\ Algorithm/Programs/Linear\ List/Single\ Linked\ List/CPP/CppGeneralized_SLL/Book.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/1c33d1d4
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1c33d1d4/Book.o /cygdrive/D/Data\ Structure\ and\ Algorithm/Programs/Linear\ List/Single\ Linked\ List/CPP/CppGeneralized_SLL/Book.cpp

${OBJECTDIR}/_ext/1c33d1d4/Product.o: /cygdrive/D/Data\ Structure\ and\ Algorithm/Programs/Linear\ List/Single\ Linked\ List/CPP/CppGeneralized_SLL/Product.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/1c33d1d4
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1c33d1d4/Product.o /cygdrive/D/Data\ Structure\ and\ Algorithm/Programs/Linear\ List/Single\ Linked\ List/CPP/CppGeneralized_SLL/Product.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
