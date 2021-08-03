SET(QuiWndBarModule_DIR ${CMAKE_INSTALL_PREFIX}/QuiWndBarModule CACHE STRING "settting QuiWndBarModule_DIR path" FORCE)

#SET(QuiWndBarModule_DIR "" CACHE PATH "Location of QuiWndBarModule")

FIND_PATH(QuiWndBarModule_INCLUDE_DIR QuiWndBarModule.h
	${QuiWndBarModule_DIR}/include
    "${QuiWndBarModule_DIR}/Public Headers"
    "$ENV{QuiWndBarModule_PATH}/Public Headers"
    $ENV{QuiWndBarModule_PATH}
    $ENV{QuiWndBarModule_DIR}/include
    $ENV{QuiWndBarModule_DIR}
    /usr/local/include
	/usr/local/QuiWndBarModule/include
    /usr/include
	/usr/QuiWndBarModule/include
	/opt/include
    /opt/local/QuiWndBarModule/include
    /opt/QuiWndBarModule/include
    "C:/QuiWndBarModule/include"
	"C:/Program Files/QuiWndBarModule/include"
)
MACRO(FIND_QuiWndBarModule_LIBRARY MYLIBRARY MYLIBRARYNAME )

FIND_LIBRARY(${MYLIBRARY}
    NAMES
        ${MYLIBRARYNAME}
PATHS
	${QuiWndBarModule_DIR}/lib
    $ENV{QuiWndBarModule_PATH}
    $ENV{QuiWndBarModule_DIR}/lib
    $ENV{QuiWndBarModule_DIR}
    /usr/local/lib
	/usr/local/QuiWndBarModule/lib
    /usr/lib
	/usr/QuiWndBarModule/lib
	/opt/lib
    /opt/local/QuiWndBarModule/lib
    /opt/QuiWndBarModule/lib
    "C:/QuiWndBarModule/lib"
	"C:/Program Files/QuiWndBarModule/lib"
)
ENDMACRO(FIND_QuiWndBarModule_LIBRARY LIBRARY LIBRARYNAME)

FIND_QuiWndBarModule_LIBRARY(QuiWndBarModule_LIBRARY QuiWndBarModule)
FIND_QuiWndBarModule_LIBRARY(QuiWndBarModule_LIBRARY_DEBUG QuiWndBarModuled)

SET(QuiWndBarModule_FOUND FALSE)
IF (QuiWndBarModule_INCLUDE_DIR AND QuiWndBarModule_LIBRARY)
   SET(QuiWndBarModule_FOUND TRUE)
ENDIF (QuiWndBarModule_INCLUDE_DIR AND QuiWndBarModule_LIBRARY)
