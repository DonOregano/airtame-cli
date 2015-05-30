set(AIRTAME_CLI_TNAME airtame-cli)

add_executable(${AIRTAME_CLI_TNAME}
        main.c
        wingetopt.c
        threading.c
        ssdp.c
        ssdp_uuid.c
        channel.c
        utils.c
        )

if(APPLE)
    set(AIRTAME_CLI_LIBS ${JSONRPCC_LIBRARY})
elseif(UNIX)
    set(AIRTAME_CLI_LIBS ${JSONRPCC_LIBRARY} pthread uuid)
endif()

target_link_libraries(${AIRTAME_CLI_TNAME}
        ${AIRTAME_CLI_LIBS})

if (USE_INTERNAL_JSONRPCC)
  add_dependencies(${AIRTAME_CLI_TNAME} jsonrpc-c)
endif()

install(TARGETS ${AIRTAME_CLI_TNAME} DESTINATION bin)
