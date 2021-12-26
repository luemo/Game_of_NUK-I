# Microsoft Developer Studio Project File - Name="allegro" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=allegro - Win32 Profile
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "allegro.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "allegro.mak" CFG="allegro - Win32 Profile"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "allegro - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "allegro - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "allegro - Win32 Profile" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "allegro - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 allge.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "allegro - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MD /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 alld.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ELSEIF  "$(CFG)" == "allegro - Win32 Profile"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Profile"
# PROP BASE Intermediate_Dir "Profile"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Profile"
# PROP Intermediate_Dir "Profile"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MD /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 allp.lib /nologo /subsystem:windows /profile /debug /machine:I386

!ENDIF 

# Begin Target

# Name "allegro - Win32 Release"
# Name "allegro - Win32 Debug"
# Name "allegro - Win32 Profile"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "CO1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CO1.cpp
# End Source File
# Begin Source File

SOURCE=.\CO101.cpp
# End Source File
# Begin Source File

SOURCE=.\CO104.cpp
# End Source File
# Begin Source File

SOURCE=.\CO104_lab.cpp
# End Source File
# Begin Source File

SOURCE=.\CO1b01.cpp
# End Source File
# End Group
# Begin Group "BO1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BO1.cpp
# End Source File
# Begin Source File

SOURCE=.\BO101.cpp
# End Source File
# Begin Source File

SOURCE=.\BO1Road.cpp
# End Source File
# End Group
# Begin Group "Road"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Road.cpp
# End Source File
# Begin Source File

SOURCE=.\Road001.cpp
# End Source File
# Begin Source File

SOURCE=.\Road002.cpp
# End Source File
# Begin Source File

SOURCE=.\Road003.cpp
# End Source File
# Begin Source File

SOURCE=.\Road004.cpp
# End Source File
# End Group
# Begin Group "LO2_MO1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\LO2.cpp
# End Source File
# Begin Source File

SOURCE=.\LO2_classroom.cpp
# End Source File
# Begin Source File

SOURCE=.\LO2_MO1.cpp
# End Source File
# Begin Source File

SOURCE=.\LO2Road.cpp
# End Source File
# Begin Source File

SOURCE=.\LO2toMO1road.cpp
# End Source File
# Begin Source File

SOURCE=.\MO1.cpp
# End Source File
# Begin Source File

SOURCE=.\Restroom.cpp
# End Source File
# Begin Source File

SOURCE=.\RoadUP.cpp
# End Source File
# End Group
# Begin Group "LO1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\LO1.cpp
# End Source File
# Begin Source File

SOURCE=.\LO101.cpp
# End Source File
# Begin Source File

SOURCE=.\LO102.cpp
# End Source File
# Begin Source File

SOURCE=.\LO105.cpp
# End Source File
# Begin Source File

SOURCE=.\PrincipleOffice.cpp
# End Source File
# End Group
# Begin Group "CO2 & Road"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CO2.cpp
# End Source File
# Begin Source File

SOURCE=.\RoadtoLO1.cpp
# End Source File
# End Group
# Begin Group "System"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\LOAD_GAME.cpp
# End Source File
# Begin Source File

SOURCE=.\Main_Menu.cpp
# End Source File
# Begin Source File

SOURCE=.\Menu.cpp
# End Source File
# Begin Source File

SOURCE=.\people_work.cpp
# End Source File
# Begin Source File

SOURCE=.\Save.cpp
# End Source File
# Begin Source File

SOURCE=.\Start.cpp
# End Source File
# End Group
# Begin Group "Even_Speak"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Cfont.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_BO1.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_BO1_01.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_CO1.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_CO1_01.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_CO2.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_CO2_01.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_LO1.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_LO1_01.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_LO2_MO1.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_LO2_MO1_01.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_Road.cpp
# End Source File
# Begin Source File

SOURCE=.\Even_Road_01.cpp
# End Source File
# Begin Source File

SOURCE=.\Speak.cpp
# End Source File
# End Group
# Begin Group "Fighting"

# PROP Default_Filter ""
# Begin Group "Fight_System"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Choose.cpp
# End Source File
# Begin Source File

SOURCE=.\Death.cpp
# End Source File
# Begin Source File

SOURCE=.\Fighting.cpp
# End Source File
# Begin Source File

SOURCE=.\Monster_Time.cpp
# End Source File
# Begin Source File

SOURCE=.\OUR_Time.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\Fight_APIBM.cpp
# End Source File
# Begin Source File

SOURCE=.\Fight_BOSS.cpp
# End Source File
# Begin Source File

SOURCE=.\Fight_CEE.cpp
# End Source File
# Begin Source File

SOURCE=.\Fight_IM_ECON.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\NUK_GAME.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "college"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BO1.h
# End Source File
# Begin Source File

SOURCE=.\CO1.h
# End Source File
# Begin Source File

SOURCE=.\CO2.h
# End Source File
# Begin Source File

SOURCE=.\College.h
# End Source File
# Begin Source File

SOURCE=.\LO1.h
# End Source File
# Begin Source File

SOURCE=.\LO2_MO1.h
# End Source File
# Begin Source File

SOURCE=.\Road.h
# End Source File
# End Group
# Begin Group "Speak"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Cfont.h
# End Source File
# Begin Source File

SOURCE=.\Even_Speak.h
# End Source File
# Begin Source File

SOURCE=.\Even_Speak_01.h
# End Source File
# End Group
# Begin Group "System_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\people_work.h
# End Source File
# Begin Source File

SOURCE=.\Save.h
# End Source File
# Begin Source File

SOURCE=.\system.h
# End Source File
# End Group
# Begin Group "Fighting_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Fight.h
# End Source File
# Begin Source File

SOURCE=.\Fighting.h
# End Source File
# End Group
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
