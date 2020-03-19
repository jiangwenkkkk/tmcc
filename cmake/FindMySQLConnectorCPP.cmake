SET(MYSQLCONNECTORCPP_ROOT_DIR
        "/Users/james/book/mysql-connector-c++-1.1.13-macos10.14-x86-64bit/"
        )

IF (WIN32)
    FIND_PATH(MYSQLCONNECTORCPP_INCLUDE_DIR
            NAMES
            mysql_connection.h
            PATHS
            "C:\\Program Files"
            HINTS
            ${MYSQLCONNECTORCPP_ROOT_DIR}
            PATH_SUFFIXES
            include)

    FIND_LIBRARY(MYSQLCONNECTORCPP_LIBRARY
            NAMES
            mysqlcppconn
            mysqlcppconn-static
            HINTS
            ${MYSQLCONNECTORCPP_ROOT_DIR}
            PATH_SUFFIXES
            lib)

ELSE ()
    FIND_PATH(MYSQLCONNECTORCPP_INCLUDE_DIR
            mysql_connection.h
            HINTS
            ${MYSQLCONNECTORCPP_ROOT_DIR}
            PATH_SUFFIXES
            include)

    FIND_LIBRARY(MYSQLCONNECTORCPP_LIBRARY
            NAMES
            mysqlcppconn
            mysqlcppconn-static
            HINTS
            ${MYSQLCONNECTORCPP_ROOT_DIR}
            PATH_SUFFIXES
            lib64
            lib)
ENDIF ()

MARK_AS_ADVANCED(MYSQLCONNECTORCPP_INCLUDE_DIR
        MYSQLCONNECTORCPP_LIBRARY)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(MysqlConnectorCpp
        DEFAULT_MSG
        MYSQLCONNECTORCPP_INCLUDE_DIR
        MYSQLCONNECTORCPP_LIBRARY)

IF (MYSQLCONNECTORCPP_FOUND)
    SET(MYSQLCONNECTORCPP_INCLUDE_DIRS
            "${MYSQLCONNECTORCPP_INCLUDE_DIR}")
    # Add any dependencies here
    SET(MYSQLCONNECTORCPP_LIBRARIES
            "${MYSQLCONNECTORCPP_LIBRARY}")
    # Add any dependencies here
    MARK_AS_ADVANCED(MYSQLCONNECTORCPP_ROOT_DIR)
ENDIF ()