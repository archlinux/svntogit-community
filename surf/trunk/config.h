/* modifier 0 means no modifier */
static char *useragent      = "Mozilla/5.0 (X11; U; Unix; en-US) "
	"AppleWebKit/537.15 (KHTML, like Gecko) Chrome/24.0.1295.0 "
	"Safari/537.15 Surf/"VERSION;
static char *progress       = "#0000FF";
static char *progress_untrust = "#FF0000";
static char *progress_trust = "#00FF00";
static char *progress_proxy = "#FFFF00";
static char *progress_proxy_trust = "#66FF00";
static char *progress_proxy_untrust = "#FF6600";
static char *stylefile      = "~/.surf/style.css";
static char *scriptfile     = "~/.surf/script.js";
static char *cookiefile     = "~/.surf/cookies.txt";
static time_t sessiontime   = 3600;
static char *cafile         = "/etc/ssl/certs/ca-certificates.crt";
static char *strictssl      = FALSE; /* Refuse untrusted SSL connections */
static int   indicator_thickness = 2;

/* Webkit default features */
static Bool enablespatialbrowsing = TRUE;
static Bool enableplugins = TRUE;
static Bool enablescripts = TRUE;
static Bool enableinspector = TRUE;
static Bool loadimages = TRUE;
static Bool hidebackground  = FALSE;

#define SETPROP(p, q) { \
	.v = (char *[]){ "/bin/sh", "-c", \
		"prop=\"`xprop -id $2 $0 | cut -d '\"' -f 2 | dmenu`\" &&" \
		"xprop -id $2 -f $1 8s -set $1 \"$prop\"", \
		p, q, winid, NULL \
	} \
}

/* DOWNLOAD(URI, referer) */
#define DOWNLOAD(d, r) { \
	.v = (char *[]){ "/bin/sh", "-c", \
		"st -e /bin/sh -c \"curl -J -O --user-agent '$1'" \
		" --referer '$2'" \
		" -b ~/.surf/cookies.txt -c ~/.surf/cookies.txt '$0';" \
		" sleep 5;\"", \
		d, useragent, r, NULL \
	} \
}

#define MODKEY GDK_CONTROL_MASK

/* hotkeys */
/*
 * If you use anything else but MODKEY and GDK_SHIFT_MASK, don't forget to
 * edit the CLEANMASK() macro.
 */
static Key keys[] = {
    /* modifier	            keyval      function    arg             Focus */
    { MODKEY|GDK_SHIFT_MASK,GDK_r,      reload,     { .b = TRUE } },
    { MODKEY,               GDK_r,      reload,     { .b = FALSE } },
    { MODKEY|GDK_SHIFT_MASK,GDK_p,      print,      { 0 } },

    { MODKEY,               GDK_p,      clipboard,  { .b = TRUE } },
    { MODKEY,               GDK_y,      clipboard,  { .b = FALSE } },

    { MODKEY|GDK_SHIFT_MASK,GDK_j,      zoom,       { .i = -1 } },
    { MODKEY|GDK_SHIFT_MASK,GDK_k,      zoom,       { .i = +1 } },
    { MODKEY|GDK_SHIFT_MASK,GDK_q,      zoom,       { .i = 0  } },
    { MODKEY,               GDK_minus,  zoom,       { .i = -1 } },
    { MODKEY,               GDK_plus,   zoom,       { .i = +1 } },

    { MODKEY,               GDK_l,      navigate,   { .i = +1 } },
    { MODKEY,               GDK_h,      navigate,   { .i = -1 } },

    { MODKEY,               GDK_j,           scroll_v,   { .i = +1 } },
    { MODKEY,               GDK_k,           scroll_v,   { .i = -1 } },
    { MODKEY,               GDK_b,           scroll_v,   { .i = -10000 } },
    { MODKEY,               GDK_space,       scroll_v,   { .i = +10000 } },
    { MODKEY,               GDK_i,           scroll_h,   { .i = +1 } },
    { MODKEY,               GDK_u,           scroll_h,   { .i = -1 } },

    { 0,                    GDK_F11,    fullscreen, { 0 } },
    { 0,                    GDK_Escape, stop,       { 0 } },
    { MODKEY,               GDK_o,      source,     { 0 } },
    { MODKEY|GDK_SHIFT_MASK,GDK_o,      inspector,  { 0 } },

    { MODKEY,               GDK_g,      spawn,      SETPROP("_SURF_URI", "_SURF_GO") },
    { MODKEY,               GDK_f,      spawn,      SETPROP("_SURF_FIND", "_SURF_FIND") },
    { MODKEY,               GDK_slash,  spawn,      SETPROP("_SURF_FIND", "_SURF_FIND") },

    { MODKEY,               GDK_n,      find,       { .b = TRUE } },
    { MODKEY|GDK_SHIFT_MASK,GDK_n,      find,       { .b = FALSE } },

    { MODKEY|GDK_SHIFT_MASK,GDK_c,      toggle,     { .v = "enable-caret-browsing" } },
    { MODKEY|GDK_SHIFT_MASK,GDK_i,      toggle,     { .v = "auto-load-images" } },
    { MODKEY|GDK_SHIFT_MASK,GDK_s,      toggle,     { .v = "enable-scripts" } },
    { MODKEY|GDK_SHIFT_MASK,GDK_v,      toggle,     { .v = "enable-plugins" } },
};

