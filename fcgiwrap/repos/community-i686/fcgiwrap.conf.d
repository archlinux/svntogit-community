#
# parameters for fcgiwrap daemon
#

SPAWNER='/usr/bin/spawn-fcgi'

FCGI_ADDRESS='127.0.0.1'
FCGI_PORT='9001'
FCGI_USER='http'
FCGI_GROUP='http'
FCGI_EXTRA_OPTIONS=''

SPAWNER_ARGS="-a $FCGI_ADDRESS -p $FCGI_PORT -u $FCGI_USER -g $FCGI_GROUP $FCGI_EXTRA_OPTIONS -- /usr/sbin/fcgiwrap"
