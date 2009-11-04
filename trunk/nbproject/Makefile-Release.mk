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
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AWG2dEntity.o \
	${OBJECTDIR}/AWG2dTile.o \
	${OBJECTDIR}/AWG2dMap.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/AWG2dEvent.o \
	${OBJECTDIR}/AWG2dScrollAnim.o \
	${OBJECTDIR}/AWG2dApp.o \
	${OBJECTDIR}/AWG2dSprite.o \
	${OBJECTDIR}/AWG2dAnimation.o

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
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/ttdefense

dist/Release/GNU-Linux-x86/ttdefense: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ttdefense ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/AWG2dEntity.o: nbproject/Makefile-${CND_CONF}.mk AWG2dEntity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/AWG2dEntity.o AWG2dEntity.cpp

${OBJECTDIR}/AWG2dTile.o: nbproject/Makefile-${CND_CONF}.mk AWG2dTile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/AWG2dTile.o AWG2dTile.cpp

${OBJECTDIR}/AWG2dMap.o: nbproject/Makefile-${CND_CONF}.mk AWG2dMap.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/AWG2dMap.o AWG2dMap.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/AWG2dEvent.o: nbproject/Makefile-${CND_CONF}.mk AWG2dEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/AWG2dEvent.o AWG2dEvent.cpp

${OBJECTDIR}/AWG2dScrollAnim.o: nbproject/Makefile-${CND_CONF}.mk AWG2dScrollAnim.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/AWG2dScrollAnim.o AWG2dScrollAnim.cpp

${OBJECTDIR}/AWG2dApp.o: nbproject/Makefile-${CND_CONF}.mk AWG2dApp.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/AWG2dApp.o AWG2dApp.cpp

${OBJECTDIR}/AWG2dSprite.o: nbproject/Makefile-${CND_CONF}.mk AWG2dSprite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/AWG2dSprite.o AWG2dSprite.cpp

${OBJECTDIR}/AWG2dAnimation.o: nbproject/Makefile-${CND_CONF}.mk AWG2dAnimation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/AWG2dAnimation.o AWG2dAnimation.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/ttdefense

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
