# airtame-cli

airtame-cli is the temporary command line interface to the AIRTAME core streaming software. It communicates with the **streamer** program that runs on the same machine and allows the user to connect the PC to an AIRTAME device.

#### Run
Make sure the airtame-streamer is running.
```sh
pip install zmq
cd <path to airtame-cli>/
source env_init.sh
at_init
at_connect <AIRTAME device IP>
at_disconnect <AIRTAME device IP>
at_exit
```

## Note
This is a temporary solution to control the airtame streamer from command line. We hope to get it to a better state soon.

## Licence
airtame-cli is released under GNU General Public License. Please see the [LICENCE.txt](LICENCE.txt) file.

## Contributions
We would love to get contributions, feedback or bug reports from you. For now we don't have a formalized source code format, but if you want to contribute just try to use the same style of the file you are changing. We plan to clean the code and make it look better very soon :).
