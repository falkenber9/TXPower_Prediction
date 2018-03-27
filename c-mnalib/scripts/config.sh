 
### Traffic Test Config

APPLICATION="traffic_test"
APP_PARAMS="-n 10 -p 30 -s 1000000 -o $LOGDIR"

LOCAL_HOSTNAME=$(hostname)

STORAGE_SERVER_ADDR="1.2.3.4"
STORAGE_SERVER_USER="username"
STORAGE_SERVER_BASEDIR="c-mna-log"


### Reverse Tunnel Config

PROXYPORT="22"
PROXYADDR="1.2.3.4"
PROXYLOGIN="username"
CONNECTIONPORT="5001"
