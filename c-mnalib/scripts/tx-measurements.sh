#!/bin/bash

SCRIPTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

BUILDDIR="$SCRIPTDIR/../build/src/examples"
LOGDIR="$SCRIPTDIR/../log"

APPLICATION="traffic_test"
APP_PARAMS="-n 10 -p 30 -s 1000000 -o $LOGDIR"

LOCAL_HOSTNAME=$(hostname)

STORAGE_SERVER_ADDR="1.2.3.4"
STORAGE_SERVER_USER="username"
STORAGE_SERVER_BASEDIR="c-mna-log"

source config.sh

echo  $SCRIPTDIR
echo  $BUILDDIR
echo  $LOGDIR
echo  $APPLICATION
echo  $APP_PARAMS

echo  $LOCAL_HOSTNAME

# Start reversetunnel
echo "Starting reversetunnel:"
echo "screen -d -m $SCRIPTDIR/./ssh-reversetunnel.sh"
screen -d -m $SCRIPTDIR/./ssh-reversetunnel.sh

while true;
do
	$BUILDDIR/./$APPLICATION $APP_PARAMS
	echo "running rsync"
	rsync -e ssh $LOGDIR/* $STORAGE_SERVER_USER@$STORAGE_SERVER_ADDR:$STORAGE_SERVER_BASEDIR/$LOCAL_HOSTNAME
	echo "pause for 30s"
	sleep 30
done;
