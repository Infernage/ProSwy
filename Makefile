#############################################################################
# Makefile for building: ProSwy
# Generated by qmake (3.0) (Qt 5.4.1)
# Project:  ProSwy.pro
# Template: subdirs
# Command: D:\Qt\5.4\msvc2013\bin\qmake.exe -spec win32-msvc2013 CONFIG+=debug -o Makefile ProSwy.pro
#############################################################################

MAKEFILE      = Makefile

first: make_first
QMAKE         = D:\Qt\5.4\msvc2013\bin\qmake.exe
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
SYMLINK       = copy /y
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		sub-ProSwyApp \
		sub-Testing


sub-ProSwyApp-qmake_all:  FORCE
	@if not exist ProSwyApp\ mkdir ProSwyApp\ & if not exist ProSwyApp\ exit 1
	cd ProSwyApp\ && $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\ProSwyApp\ProSwyApp.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd ProSwyApp\ && $(MAKE) -f Makefile qmake_all
sub-ProSwyApp: FORCE
	@if not exist ProSwyApp\ mkdir ProSwyApp\ & if not exist ProSwyApp\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd ProSwyApp\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\ProSwyApp\ProSwyApp.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile
sub-ProSwyApp-make_first: FORCE
	@if not exist ProSwyApp\ mkdir ProSwyApp\ & if not exist ProSwyApp\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd ProSwyApp\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\ProSwyApp\ProSwyApp.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile 
sub-ProSwyApp-all: FORCE
	@if not exist ProSwyApp\ mkdir ProSwyApp\ & if not exist ProSwyApp\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd ProSwyApp\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\ProSwyApp\ProSwyApp.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile all
sub-ProSwyApp-clean: FORCE
	@if not exist ProSwyApp\ mkdir ProSwyApp\ & if not exist ProSwyApp\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd ProSwyApp\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\ProSwyApp\ProSwyApp.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile clean
sub-ProSwyApp-distclean: FORCE
	@if not exist ProSwyApp\ mkdir ProSwyApp\ & if not exist ProSwyApp\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd ProSwyApp\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\ProSwyApp\ProSwyApp.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile distclean
sub-ProSwyApp-install_subtargets: FORCE
	@if not exist ProSwyApp\ mkdir ProSwyApp\ & if not exist ProSwyApp\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd ProSwyApp\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\ProSwyApp\ProSwyApp.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile install
sub-ProSwyApp-uninstall_subtargets: FORCE
	@if not exist ProSwyApp\ mkdir ProSwyApp\ & if not exist ProSwyApp\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd ProSwyApp\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\ProSwyApp\ProSwyApp.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-Testing-qmake_all:  FORCE
	@if not exist Testing\ mkdir Testing\ & if not exist Testing\ exit 1
	cd Testing\ && $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\Testing\Testing.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd Testing\ && $(MAKE) -f Makefile qmake_all
sub-Testing: FORCE
	@if not exist Testing\ mkdir Testing\ & if not exist Testing\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd Testing\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\Testing\Testing.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile
sub-Testing-make_first: FORCE
	@if not exist Testing\ mkdir Testing\ & if not exist Testing\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd Testing\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\Testing\Testing.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile 
sub-Testing-all: FORCE
	@if not exist Testing\ mkdir Testing\ & if not exist Testing\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd Testing\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\Testing\Testing.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile all
sub-Testing-clean: FORCE
	@if not exist Testing\ mkdir Testing\ & if not exist Testing\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd Testing\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\Testing\Testing.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile clean
sub-Testing-distclean: FORCE
	@if not exist Testing\ mkdir Testing\ & if not exist Testing\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd Testing\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\Testing\Testing.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile distclean
sub-Testing-install_subtargets: FORCE
	@if not exist Testing\ mkdir Testing\ & if not exist Testing\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd Testing\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\Testing\Testing.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile install
sub-Testing-uninstall_subtargets: FORCE
	@if not exist Testing\ mkdir Testing\ & if not exist Testing\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd Testing\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\Testing\Testing.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile uninstall

Makefile: ProSwy.pro ..\..\..\..\Qt\5.4\msvc2013\mkspecs\win32-msvc2013\qmake.conf ..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\spec_pre.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\common\shell-win32.conf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\qconfig.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axbase.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axbase_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axcontainer.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axcontainer_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axserver.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axserver_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_bluetooth.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_bluetooth_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_bootstrap_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_clucene_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_concurrent.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_concurrent_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_core.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_core_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_dbus.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_dbus_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_declarative.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_declarative_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_designer.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_designer_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_designercomponents_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_enginio.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_enginio_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_gui.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_gui_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_help.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_help_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_location.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_location_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_multimedia.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_multimedia_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_multimediawidgets.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_network.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_network_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_nfc.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_nfc_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_opengl.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_opengl_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_openglextensions.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_openglextensions_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_platformsupport_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_positioning.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_positioning_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_printsupport.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_printsupport_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qml.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qml_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qmltest.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qmltest_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_quick.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_quick_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_quickparticles_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_quickwidgets.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_script.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_script_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_scripttools.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_scripttools_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_sensors.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_sensors_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_serialport.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_serialport_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_sql.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_sql_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_svg.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_svg_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_testlib.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_testlib_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_uitools.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_uitools_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webchannel.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webchannel_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webengine.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webengine_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webenginecore.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webenginecore_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webenginewidgets.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webenginewidgets_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webkit.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webkit_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webkitwidgets.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webkitwidgets_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_websockets.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_websockets_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webview.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webview_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_widgets.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_widgets_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_winextras.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_winextras_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_xml.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_xml_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_xmlpatterns.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\qt_functions.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\qt_config.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\win32\qt_config.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\win32-msvc2013\qmake.conf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\spec_post.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\exclusive_builds.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\default_pre.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\win32\default_pre.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\resolve_config.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\exclusive_builds_post.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\default_post.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\win32\rtti.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\precompile_header.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\warn_on.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\win32\windows.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\testcase_targets.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\exceptions.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\yacc.prf \
		..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\lex.prf \
		ProSwy.pro
	$(QMAKE) -spec win32-msvc2013 CONFIG+=debug -o Makefile ProSwy.pro
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\spec_pre.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\common\shell-win32.conf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\qconfig.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axbase.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axbase_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axcontainer.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axcontainer_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axserver.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_axserver_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_bluetooth.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_bluetooth_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_bootstrap_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_clucene_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_concurrent.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_concurrent_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_core.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_core_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_dbus.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_dbus_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_declarative.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_declarative_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_designer.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_designer_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_designercomponents_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_enginio.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_enginio_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_gui.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_gui_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_help.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_help_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_location.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_location_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_multimedia.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_multimedia_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_multimediawidgets.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_network.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_network_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_nfc.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_nfc_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_opengl.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_opengl_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_openglextensions.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_openglextensions_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_platformsupport_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_positioning.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_positioning_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_printsupport.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_printsupport_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qml.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qml_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qmldevtools_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qmltest.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qmltest_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_quick.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_quick_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_quickparticles_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_quickwidgets.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_quickwidgets_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_script.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_script_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_scripttools.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_scripttools_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_sensors.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_sensors_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_serialport.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_serialport_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_sql.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_sql_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_svg.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_svg_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_testlib.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_testlib_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_uitools.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_uitools_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webchannel.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webchannel_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webengine.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webengine_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webenginecore.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webenginecore_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webenginewidgets.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webenginewidgets_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webkit.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webkit_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webkitwidgets.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webkitwidgets_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_websockets.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_websockets_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webview.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_webview_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_widgets.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_widgets_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_winextras.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_winextras_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_xml.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_xml_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_xmlpatterns.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\qt_functions.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\qt_config.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\win32\qt_config.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\win32-msvc2013\qmake.conf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\spec_post.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\exclusive_builds.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\default_pre.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\win32\default_pre.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\resolve_config.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\exclusive_builds_post.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\default_post.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\win32\rtti.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\precompile_header.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\warn_on.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\win32\windows.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\testcase_targets.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\exceptions.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\yacc.prf:
..\..\..\..\Qt\5.4\msvc2013\mkspecs\features\lex.prf:
ProSwy.pro:
qmake: FORCE
	@$(QMAKE) -spec win32-msvc2013 CONFIG+=debug -o Makefile ProSwy.pro

qmake_all: sub-ProSwyApp-qmake_all sub-Testing-qmake_all FORCE

make_first: sub-ProSwyApp-make_first sub-Testing-make_first FORCE
all: sub-ProSwyApp-all sub-Testing-all FORCE
clean: sub-ProSwyApp-clean sub-Testing-clean FORCE
distclean: sub-ProSwyApp-distclean sub-Testing-distclean FORCE
	-$(DEL_FILE) Makefile
install_subtargets: sub-ProSwyApp-install_subtargets sub-Testing-install_subtargets FORCE
uninstall_subtargets: sub-ProSwyApp-uninstall_subtargets sub-Testing-uninstall_subtargets FORCE

sub-ProSwyApp-debug:
	@if not exist ProSwyApp\ mkdir ProSwyApp\ & if not exist ProSwyApp\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd ProSwyApp\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\ProSwyApp\ProSwyApp.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile debug
sub-Testing-debug:
	@if not exist Testing\ mkdir Testing\ & if not exist Testing\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd Testing\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\Testing\Testing.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile debug
debug: sub-ProSwyApp-debug sub-Testing-debug

sub-ProSwyApp-release:
	@if not exist ProSwyApp\ mkdir ProSwyApp\ & if not exist ProSwyApp\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd ProSwyApp\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\ProSwyApp\ProSwyApp.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile release
sub-Testing-release:
	@if not exist Testing\ mkdir Testing\ & if not exist Testing\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd Testing\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\Testing\Testing.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile release
release: sub-ProSwyApp-release sub-Testing-release

sub-ProSwyApp-check:
	@if not exist ProSwyApp\ mkdir ProSwyApp\ & if not exist ProSwyApp\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd ProSwyApp\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\ProSwyApp\ProSwyApp.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile check
sub-Testing-check:
	@if not exist Testing\ mkdir Testing\ & if not exist Testing\ exit 1
	@set MAKEFLAGS=$(MAKEFLAGS)
	cd Testing\ && ( if not exist Makefile $(QMAKE) D:\Tresors\Proyectos\C++\ProSwy\Testing\Testing.pro -spec win32-msvc2013 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile check
check: sub-ProSwyApp-check sub-Testing-check
install: install_subtargets  FORCE

uninstall:  uninstall_subtargets FORCE

FORCE:

