/*
 * airtame-server-rpc.h
 *
 *  Created on: Feb 2, 2015
 *      Author: elisescu
 */

#ifndef AIRTAME_SERVER_RPC_H_
#define AIRTAME_SERVER_RPC_H_

// TODO: find a better way to share this between the streamer and the cli client.

/**
{
    "title": "RPC notification schema",
    "type": "object",
    "properties": {
        "method": {
            "type": "string"
            "description": "the name of the notification"
        },
        "params": {
            "type": "array"
            "description": "an array with the parameters.
                 even positions the name of the parameter.
                 the value right after the parameter name"
        },
        "id": {
            "type": "integer",
            "description": "the ID should be null"
        }
    },
    "required": ["method", "params", "id"]
}
*/

/**
{
    "title": "RPC call method schema",
    "type": "object",
    "properties": {
        "method": {
            "type": "string"
            "description": "the name of the remote method to be called"
        },
        "params": {
            "type": "array"
            "description": "an array with the parameters.
                 even positions the name of the parameter.
                 the value right after the parameter name"
        },
        "id": {
            "type": "integer",
            "description": "the ID of the call, returned in the RPC response in
                  order to map the response back to the originating call"
        }
    },
    "required": ["method", "params", "id"]
}
*/

/**
 * Register a listener for connection state and streaming state changes.
 *
 * name: registerListener
 * params: ip   - the ip of the listener listening for changes
 *         port - the port on which the listener listens for notifications
 * result: ok if the RPC call succeeded, error otherwise
 */
#define REGISTER_LISTENER_METHOD            ("registerListener")

/**
 * Initialize the streamer. Is the method to be called after registerListener has been called.
 *
 * name: initStreamer
 * params: no params
 * result: ok if the RPC call succeeded, error otherwise. The actual
 *         initialization status is got through the listener
 */
#define INIT_STREAMER_METHOD                ("initStreamer")


/**
 * Closes the streamer. Is the method to be called to cleanup the streamer state. It is
 * the semantically opposite of the initSreamer.
 *
 * name: closeStreamer
 * params: no params
 * result: ok if the RPC call succeeded, error otherwise. The actual
 *         cleaning status is got through the listener
 */
#define CLOSE_STREAMER_METHOD               ("closeStreamer")

/**
 * Connect the streamer to a client. Should be called only after the STREAMING_STATE_INIT
 * has been received.
 *
 * name: connect
 * params: ip   - the ip of the client
 *         port - the port of the client
 * result: ok if the RPC call succeeded, error otherwise. The actual
 *         connection status is got through the listener
 */
#define CONNECT_METHOD                      ("connect")


/**
 * Disconnect the streamer from a client.
 *
 * name: disconnect
 * params: ip   - the ip of the client
 *         port - the port of the client
 * result: ok if the RPC call succeeded, error otherwise. The actual
 *         connection status is got through the listener
 */
#define DISCONNECT_METHOD                   ("disconnect")


/**
 * Unregister the listener. Should be called before closing the RPC client.
 *
 * name: unregisterListener
 * params: ip   - the ip of the listener listening for changes
 *         port - the port on which the listener listens for notifications
 * result: ok if the RPC call succeeded, error otherwise
 */
#define UNREGISTER_LISTENER_METHOD          ("unregisterListener")


/**
 * Get the internal state of the streamer.
 *
 * name: getState
 * params: none
 * result: internal_state JSON object if RPC succeeded, error otherwise.
 * (@see internal_state JSON schema)
 */
#define GET_STATE_METHOD                    ("getState")
/**
 * {
  "$schema": "http://json-schema.org/draft-04/schema#",
  "id": "internal_state",
  "type": "object",
  "properties": {
    "clients": {
      "id": "/clients",
      "type": "array",
      "items": {
        "id": "/clients/0",
        "type": "object",
        "properties": {
          "ip": {
            "id": "/clients/0/ip",
            "type": "string"
          },
          "state": {
            "id": "/clients/0/state",
            "type": "string"
          }
        },
        "required": [
          "ip",
          "state"
        ]
      },
      "required": [
        "0"
      ]
    },
    "streaming_machine": {
      "id": "/streaming_machine",
      "type": "object",
      "properties": {
        "current_state": {
          "id": "/streaming_machine/current_state",
          "type": "string"
        },
        "no_queue_messages": {
          "id": "/streaming_machine/no_queue_messages",
          "type": "integer"
        },
        "last_received_msg": {
          "id": "/streaming_machine/last_received_msg",
          "type": "integer"
        }
      }
    },
    "network_machine": {
      "id": "/network_machine",
      "type": "object",
      "properties": {
        "current_state": {
          "id": "/network_machine/current_state",
          "type": "string"
        },
        "no_queue_messages": {
          "id": "/network_machine/no_queue_messages",
          "type": "integer"
        },
        "last_received_msg": {
          "id": "/network_machine/last_received_msg",
          "type": "integer"
        }
      }
    }
  },
  "required": [
    "clients",
    "streaming_machine",
    "network_machine"
  ]
}
*/

/**
 * Set parameters to the streamer (framerate, mode, quality and buffer period).
 *
 * name: setStreamerSettings
 * params: name_of_parameters - a string specifying the name of param (see bellow).
 *         value_of_parameters - a number or a string with the value of the param.
 *         (see few examples of jSON objects for setting the params)
 * result: internal_state JSON object if RPC succeeded, error otherwise.
 * (@see internal_state JSON schema)
 */
#define SET_STREAMER_SETTINGS_METHOD                  ("setStreamerSettings")

#define SET_STREAMER_SETTINGS_QUALITY_PNAME           ("quality")
#define SET_STREAMER_SETTINGS_FRAMERATE_PNAME         ("framerate")
#define SET_STREAMER_SETTINGS_MODE_PNAME              ("mode")
#define SET_STREAMER_SETTINGS_MODE_VAL_FASTSTR           ("FAST_STREAMING")
#define SET_STREAMER_SETTINGS_MODE_VAL_SAFESTR           ("SAFE_STREAMING")
#define SET_STREAMER_SETTINGS_BUFF_PNAME              ("buffer")

/**
set the mode to fast streaming
{
  "method": "setStreamerSettings",
  "params": [
    "mode",
    "FAST_STREAMING"
  ],
  "id": 23
}

set framerate to 23
{
  "method": "setStreamerSettings",
  "params": [
    "framerate",
    23
  ],
  "id": 23
}
 */

#endif /* AIRTAME_SERVER_RPC_H_ */
