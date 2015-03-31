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
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Sources/C/actions.o \
	${OBJECTDIR}/Sources/C/batiment.o \
	${OBJECTDIR}/Sources/C/box.o \
	${OBJECTDIR}/Sources/C/caserne.o \
	${OBJECTDIR}/Sources/C/chantier.o \
	${OBJECTDIR}/Sources/C/checkbox.o \
	${OBJECTDIR}/Sources/C/choice.o \
	${OBJECTDIR}/Sources/C/client.o \
	${OBJECTDIR}/Sources/C/credits.o \
	${OBJECTDIR}/Sources/C/defense.o \
	${OBJECTDIR}/Sources/C/description..o \
	${OBJECTDIR}/Sources/C/first_screen.o \
	${OBJECTDIR}/Sources/C/init.o \
	${OBJECTDIR}/Sources/C/init_position.o \
	${OBJECTDIR}/Sources/C/ip.o \
	${OBJECTDIR}/Sources/C/listener.o \
	${OBJECTDIR}/Sources/C/loading.o \
	${OBJECTDIR}/Sources/C/main.o \
	${OBJECTDIR}/Sources/C/menu.o \
	${OBJECTDIR}/Sources/C/mouse.o \
	${OBJECTDIR}/Sources/C/nav.o \
	${OBJECTDIR}/Sources/C/notify.o \
	${OBJECTDIR}/Sources/C/options.o \
	${OBJECTDIR}/Sources/C/planete.o \
	${OBJECTDIR}/Sources/C/quit.o \
	${OBJECTDIR}/Sources/C/section_1.o \
	${OBJECTDIR}/Sources/C/section_2.o \
	${OBJECTDIR}/Sources/C/section_3.o \
	${OBJECTDIR}/Sources/C/section_4.o \
	${OBJECTDIR}/Sources/C/section_5.o \
	${OBJECTDIR}/Sources/C/serveur.o \
	${OBJECTDIR}/Sources/C/settings.o \
	${OBJECTDIR}/Sources/C/timer.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/swtcw_client

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/swtcw_client: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/swtcw_client ${OBJECTFILES} ${LDLIBSOPTIONS} -lSDL -lSDLmain -lSDL_image -lSDL_ttf -lSDL_net -lSDL_mixer

${OBJECTDIR}/Sources/C/actions.o: Sources/C/actions.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/actions.o Sources/C/actions.c

${OBJECTDIR}/Sources/C/batiment.o: Sources/C/batiment.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/batiment.o Sources/C/batiment.c

${OBJECTDIR}/Sources/C/box.o: Sources/C/box.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/box.o Sources/C/box.c

${OBJECTDIR}/Sources/C/caserne.o: Sources/C/caserne.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/caserne.o Sources/C/caserne.c

${OBJECTDIR}/Sources/C/chantier.o: Sources/C/chantier.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/chantier.o Sources/C/chantier.c

${OBJECTDIR}/Sources/C/checkbox.o: Sources/C/checkbox.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/checkbox.o Sources/C/checkbox.c

${OBJECTDIR}/Sources/C/choice.o: Sources/C/choice.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/choice.o Sources/C/choice.c

${OBJECTDIR}/Sources/C/client.o: Sources/C/client.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/client.o Sources/C/client.c

${OBJECTDIR}/Sources/C/credits.o: Sources/C/credits.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/credits.o Sources/C/credits.c

${OBJECTDIR}/Sources/C/defense.o: Sources/C/defense.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/defense.o Sources/C/defense.c

${OBJECTDIR}/Sources/C/description..o: Sources/C/description..c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/description..o Sources/C/description..c

${OBJECTDIR}/Sources/C/first_screen.o: Sources/C/first_screen.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/first_screen.o Sources/C/first_screen.c

${OBJECTDIR}/Sources/C/init.o: Sources/C/init.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/init.o Sources/C/init.c

${OBJECTDIR}/Sources/C/init_position.o: Sources/C/init_position.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/init_position.o Sources/C/init_position.c

${OBJECTDIR}/Sources/C/ip.o: Sources/C/ip.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/ip.o Sources/C/ip.c

${OBJECTDIR}/Sources/C/listener.o: Sources/C/listener.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/listener.o Sources/C/listener.c

${OBJECTDIR}/Sources/C/loading.o: Sources/C/loading.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/loading.o Sources/C/loading.c

${OBJECTDIR}/Sources/C/main.o: Sources/C/main.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/main.o Sources/C/main.c

${OBJECTDIR}/Sources/C/menu.o: Sources/C/menu.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/menu.o Sources/C/menu.c

${OBJECTDIR}/Sources/C/mouse.o: Sources/C/mouse.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/mouse.o Sources/C/mouse.c

${OBJECTDIR}/Sources/C/nav.o: Sources/C/nav.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/nav.o Sources/C/nav.c

${OBJECTDIR}/Sources/C/notify.o: Sources/C/notify.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/notify.o Sources/C/notify.c

${OBJECTDIR}/Sources/C/options.o: Sources/C/options.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/options.o Sources/C/options.c

${OBJECTDIR}/Sources/C/planete.o: Sources/C/planete.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/planete.o Sources/C/planete.c

${OBJECTDIR}/Sources/C/quit.o: Sources/C/quit.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/quit.o Sources/C/quit.c

${OBJECTDIR}/Sources/C/section_1.o: Sources/C/section_1.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/section_1.o Sources/C/section_1.c

${OBJECTDIR}/Sources/C/section_2.o: Sources/C/section_2.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/section_2.o Sources/C/section_2.c

${OBJECTDIR}/Sources/C/section_3.o: Sources/C/section_3.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/section_3.o Sources/C/section_3.c

${OBJECTDIR}/Sources/C/section_4.o: Sources/C/section_4.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/section_4.o Sources/C/section_4.c

${OBJECTDIR}/Sources/C/section_5.o: Sources/C/section_5.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/section_5.o Sources/C/section_5.c

${OBJECTDIR}/Sources/C/serveur.o: Sources/C/serveur.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/serveur.o Sources/C/serveur.c

${OBJECTDIR}/Sources/C/settings.o: Sources/C/settings.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/settings.o Sources/C/settings.c

${OBJECTDIR}/Sources/C/timer.o: Sources/C/timer.c 
	${MKDIR} -p ${OBJECTDIR}/Sources/C
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/C/timer.o Sources/C/timer.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/swtcw_client

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
