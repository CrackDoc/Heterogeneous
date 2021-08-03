SET(QuiProjectModule_DIR ${CMAKE_INSTALL_PREFIX}/QuiProjectModule CACHE STRING "settting QuiProjectModule_DIR path" FORCE)

#SET(QuiProjectModule_DIR "" CACHE PATH "Location of QuiProjectModule")

FIND_PATH(QuiProjectModule_INCLUDE_DIR QuiProjectModule.h
	${QuiProjectModule_DIR}/include
    "${QuiProjectModule_DIR}/Public Headers"
    "$ENV{QuiProjectModule_PATH}/Public Headers"
    $ENV{QuiProjectModule_PATH}
    $ENV{QuiProjectModule_DIR}/include
    $ENV{QuiProjectModule_DIR}
    /usr/local/include
	/usr/local/QuiProjectModule/include
    /usr/include
	/usr/QuiProjectModule/include
	/opt/include
    /opt/local/QuiProjectModule/include
    /opt/QuiProjectModule/include
    "C:/QuiProjectModule/include"
	"C:/Program Files/QuiProjectModule/include"
)
MACRO(FIND_QuiProjectModule_LIBRARY MYLIBRARY MYLIBRARYNAME )

FIND_LIBRARY(${MYLIBRARY}
    NAMES
        ${MYLIBRARYNAME}
PATHS
	${QuiProjectModule_DIR}/lib
    $ENV{QuiProjectModule_PATH}
    $ENV{QuiProjectModule_DIR}/lib
    $ENV{QuiProjectModule_DIR}
    /usr/local/lib
	/usr/local/QuiProjectModule/lib
    /usr/lib
	/usr/QuiProjectModule/lib
	/opt/lib
    /opt/local/QuiProjectModule/lib
    /opt/QuiProjectModule/lib
    "C:/QuiProjectModule/lib"
	"C:/Program Files/QuiProjectModule/lib"
)
ENDMACRO(FIND_QuiProjectModule_LIBRARY LIBRARY LIBRARYNAME)

FIND_QuiProjectModule_LIBRARY(QuiProjectModule_LIBRARY QuiProjectModule)
FIND_QuiProjectModule_LIBRARY(QuiProjectModule_LIBRARY_DEBUG QuiProjectModuled)

SET(QuiProjectModule_FOUND FALSE)
IF (QuiProjectModule_INCLUDE_DIR AND QuiProjectModule_LIBRARY)
   SET(QuiProjectModule_FOUND TRUE)
ENDIF (QuiProjectModule_INCLUDE_DIR AND QuiProjectModule_LIBRARY)
