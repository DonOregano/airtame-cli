#!/usr/bin/env bash

# Copyright (c) 2013-2016  AIRTAME ApS
# All Rights Reserved.
#
# See LICENSE.txt for further information.

AIRTAME_ZMQ_PATH=$PWD
airtame_rpc_call() {
    echo "{\"method\":\"$1\", \"params\":$2, \"id\":1}" | $AIRTAME_ZMQ_PATH/zmq-rpc.py localhost 8004
}

at_get_state_streamer() {
    airtame_rpc_call get_state "{}"
}

at_init() {
    airtame_rpc_call init "{}"
}

at_clean() {
    airtame_rpc_call clean "{}"
}

at_connect() {
    airtame_rpc_call connect "{\"ip\":\"$1\", \"port\":8002}"
}

at_disconnect() {
    airtame_rpc_call disconnect "{\"ip\":\"$1\", \"port\":8002}"
}

at_exit() {
    airtame_rpc_call program_exit "{}"
}
