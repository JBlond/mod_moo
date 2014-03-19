mod_moo
================================

Example apache module mod moo 2
Created by Gregg Smith for Mario

## Compiling on windows: ##

x86

    del *.obj *.exp *.lib *.so *.*.man*
    SET APACHE=\Apache24
    cl /nologo /MD /W3 /O2 /D _WINDOWS /D WIN32 /D NDEBUG -I%APACHE%\include mod_moo2.c
    link kernel32.lib "%APACHE%\lib\libhttpd.lib" "%APACHE%\lib\libapr-1.lib" "%APACHE%\lib\libaprutil-1.lib" /nologo /subsystem:windows /dll /out:mod_moo2.so mod_moo2.obj
    MT -manifest mod_moo2.so.manifest  -outputresource:mod_moo2.so;2

x84

    del *.obj *.exp *.lib *.so *.*.man*
    SET APACHE=\Apache24x64
    cl /nologo /MD /W3 /O2 /D _WINDOWS /D WIN32 /D WIN64 /D _WIN64 /D NDEBUG -I%APACHE%\include mod_moo2.c
    link kernel32.lib "%APACHE%\lib\libhttpd.lib" "%APACHE%\lib\libapr-1.lib" "%APACHE%\lib\libaprutil-1.lib" /nologo /subsystem:windows /dll /out:mod_moo2.so mod_moo2.obj
    MT -manifest mod_moo2.so.manifest  -outputresource:mod_moo2.so;2

The module binaries are compatible with the downloads from http://www.apachehaus.com