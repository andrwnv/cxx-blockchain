
set(WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")

include_directories("${CMAKE_CURRENT_LIST_DIR}")

set(HEADERS_ONLY
    IConnection
)

set(SOURCES_ONLY)

set(PAIRS)

foreach (header ${HEADERS_ONLY})
    list(APPEND HEADERS_INCLUDE "${WORKING_DIRECTORY}/${header}.hpp")
endforeach ()

foreach (source ${SOURCES_ONLY})
    list(APPEND SOURCES_INCLUDE "${WORKING_DIRECTORY}/${source}.cpp")
endforeach ()

foreach (pair ${PAIRS})
    list(APPEND SOURCES_INCLUDE "${WORKING_DIRECTORY}/${pair}.cpp")
    list(APPEND HEADERS_INCLUDE "${WORKING_DIRECTORY}/${pair}.hpp")
endforeach ()
