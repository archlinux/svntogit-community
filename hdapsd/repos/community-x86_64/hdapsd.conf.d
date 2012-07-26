# DEVICE specifies the device to monitor, defaults to "sda".
#DEVICE='sda'

# If an ultrabay hard drive is inserted, the following can be used:
#DEVICE=('sda' 'sdb')

# SENSITIVITY is self explanatory, defaults to "15".
#SENSITIVITY='15'

# Set ADAPTIVE to "yes" to enable adaptive threshold (automatically increase
# when the built-in keyboard/mouse is used).
#ADAPTIVE='yes'

# Set SYSLOG to "yes" to have the daemon report errors to syslog (instead of
# stderr/stdout).
SYSLOG='yes'

# Set FORCE to "yes" to force the kernel to use the unload heads feature on
# some old hard drives for which support cannot be autodetected (don't use this
# unless you're absolutely sure your hard drive really supports unloading
# heads).
#FORCE='yes'
