#!/bin/bash
#
# Additional configuration options for the Quagga Software Routing Suite port
#

### cpulimit settings for each and every of the daemons
# in cpulimit_$DAEMON directive,
# use "1" to activate the CPU limiter and "0" to disable it
#
# the default is 40% of total CPU badwidth (the range is 1-100, obviously)

# zebra daemon
cpulimit_zebra="1"
zebra_cpu="40"

# RIP daemons
cpulimit_ripd="1"
ripd_cpu="40"

cpulimit_ripngd="1"
ripngd_cpu="40"

# OSPF daemons
cpulimit_ospfd="1"
ospfd_cpu="40"

cpulimit_ospf6d="1"
ospf6d_cpu="40"

#BGP daemon
cpulimit_bgpd="1"
bgpd_cpu="40"

# EOF

