#!/bin/bash
#

# Reverse Tunnel Server Config
PROXYPORT="22"
PROXYADDR="1.2.3.4"
PROXYLOGIN="username"
CONNECTIONPORT="5001"

source config.sh

while true;
do

	echo "Reversetunnel established."
	echo "This machine is reachable as follows:"
	echo "ssh <username>@$PROXYADDR -p $CONNECTIONPORT"
	echo ""



	#ssh -R $CONNECTIONPORT:localhost:$PROXYPORT $PROXYLOGIN@$PROXYADDR
	autossh -M 20000 -R $CONNECTIONPORT:localhost:$PROXYPORT $PROXYLOGIN@$PROXYADDR
	
	echo "Wait 60s to reconnect..."
	sleep 6

done;
