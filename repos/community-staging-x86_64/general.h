
// disable unsafe options
#undef CRYPTO_80211_WEP  /* WEP encryption (deprecated and insecure!) */
#undef CRYPTO_80211_WPA  /* WPA Personal, authenticating with passphrase */

// enable additional options
#define NET_PROTO_IPV6  /* IPv6 protocol */
#define DOWNLOAD_PROTO_HTTPS  /* Secure Hypertext Transfer Protocol */
#define DOWNLOAD_PROTO_NFS  /* Network File System Protocol */
#define IMAGE_TRUST_CMD /* Image trust management commands */
#define NEIGHBOUR_CMD   /* Neighbour management commands */
#define NTP_CMD   /* NTP commands */
#define REBOOT_CMD    /* Reboot command */
#define PING_CMD    /* Ping command */
#define POWEROFF_CMD    /* Power off command */
#define CERT_CMD    /* Certificate management commands */
