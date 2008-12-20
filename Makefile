#############################################################################
# Makefile for building: OpenNote
# Generated by qmake (2.01a) (Qt 4.4.3) on: ? 12 19 23:04:40 2008
# Project:  OpenNote.pro
# Template: app
# Command: c:\Qt\bin\qmake -win32 -o Makefile OpenNote.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = c:\Qt\bin\qmake
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: OpenNote.pro  ../../../../Qt/mkspecs/default/qmake.conf ../../../../Qt/mkspecs/qconfig.pri \
		../../../../Qt/mkspecs/features/qt_functions.prf \
		../../../../Qt/mkspecs/features/qt_config.prf \
		../../../../Qt/mkspecs/features/exclusive_builds.prf \
		../../../../Qt/mkspecs/features/default_pre.prf \
		../../../../Qt/mkspecs/features/win32/default_pre.prf \
		../../../../Qt/mkspecs/features/debug.prf \
		../../../../Qt/mkspecs/features/debug_and_release.prf \
		../../../../Qt/mkspecs/features/default_post.prf \
		../../../../Qt/mkspecs/features/warn_on.prf \
		../../../../Qt/mkspecs/features/qt.prf \
		../../../../Qt/mkspecs/features/win32/thread.prf \
		../../../../Qt/mkspecs/features/moc.prf \
		../../../../Qt/mkspecs/features/win32/rtti.prf \
		../../../../Qt/mkspecs/features/win32/exceptions.prf \
		../../../../Qt/mkspecs/features/win32/stl.prf \
		../../../../Qt/mkspecs/features/shared.prf \
		../../../../Qt/mkspecs/features/win32/windows.prf \
		../../../../Qt/mkspecs/features/resources.prf \
		../../../../Qt/mkspecs/features/uic.prf \
		../../../../Qt/mkspecs/features/yacc.prf \
		../../../../Qt/mkspecs/features/lex.prf \
		c:/Qt/lib/qtmaind.prl
	$(QMAKE) -win32 -o Makefile OpenNote.pro
..\..\..\..\Qt\mkspecs\qconfig.pri:
..\..\..\..\Qt\mkspecs\features\qt_functions.prf:
..\..\..\..\Qt\mkspecs\features\qt_config.prf:
..\..\..\..\Qt\mkspecs\features\exclusive_builds.prf:
..\..\..\..\Qt\mkspecs\features\default_pre.prf:
..\..\..\..\Qt\mkspecs\features\win32\default_pre.prf:
..\..\..\..\Qt\mkspecs\features\debug.prf:
..\..\..\..\Qt\mkspecs\features\debug_and_release.prf:
..\..\..\..\Qt\mkspecs\features\default_post.prf:
..\..\..\..\Qt\mkspecs\features\warn_on.prf:
..\..\..\..\Qt\mkspecs\features\qt.prf:
..\..\..\..\Qt\mkspecs\features\win32\thread.prf:
..\..\..\..\Qt\mkspecs\features\moc.prf:
..\..\..\..\Qt\mkspecs\features\win32\rtti.prf:
..\..\..\..\Qt\mkspecs\features\win32\exceptions.prf:
..\..\..\..\Qt\mkspecs\features\win32\stl.prf:
..\..\..\..\Qt\mkspecs\features\shared.prf:
..\..\..\..\Qt\mkspecs\features\win32\windows.prf:
..\..\..\..\Qt\mkspecs\features\resources.prf:
..\..\..\..\Qt\mkspecs\features\uic.prf:
..\..\..\..\Qt\mkspecs\features\yacc.prf:
..\..\..\..\Qt\mkspecs\features\lex.prf:
c:\Qt\lib\qtmaind.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -win32 -o Makefile OpenNote.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile

debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
