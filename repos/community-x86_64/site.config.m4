dnl Enable libmilter with a pool of workers
APPENDDEF(`conf_libmilter_ENVDEF',`-D_FFR_WORKERS_POOL=1')
APPENDDEF(`conf_libmilter_ENVDEF',`-DMIN_WORKERS=4')
dnl Use poll instead of select
APPENDDEF(`conf_libmilter_ENVDEF',`-DSM_CONF_POLL=1')
dnl Enable IPv6
APPENDDEF(`conf_libmilter_ENVDEF',`-DNETINET6=1')
dnl Add -fPIC
APPENDDEF(`conf_libmilter_ENVDEF',`-fPIC')
dnl Permissions
APPENDDEF(`confINCGRP',`root')
APPENDDEF(`confLIBGRP',`root')
APPENDDEF(`confMBINGRP',`root')
APPENDDEF(`confSBINGRP',`root')
APPENDDEF(`confBINGRP',`root')
