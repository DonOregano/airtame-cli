#!/usr/bin/env python

# Copyright (c) 2013-2016  AIRTAME ApS
# All Rights Reserved.
#
# See LICENSE.txt for further information.

import sys
import zmq

def main():
    ip, port = sys.argv[1], sys.argv[2]
    context = zmq.Context()
    socket = context.socket(zmq.REQ)
    socket.connect("tcp://{}:{}".format(ip, port))

    for line in sys.stdin:
        socket.send_string(line)
        print socket.recv_string()

main()
