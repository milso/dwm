/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-profont-*-*-*-*-11-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#000000";
static const char normbgcolor[]     = "#000000";
static const char normfgcolor[]     = "#ffffff";
static const char selbordercolor[]  = "#000000";
static const char selbgcolor[]      = "#000000";
static const char selfgcolor[]      = "#ffffff";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = False;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
        { "Skype",    NULL,       NULL,       0,            True,        -1 },
        { "Lxappearance",  NULL,  NULL,       0,            True,        -1 },
        { "Desura",   NULL,       NULL,       0,            True,        -1 },
	{ "MPlayer",  NULL,       NULL,       0,            True,        -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[T]",      tile },    /* first entry is default */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *emacscmd[] = { "emacs", NULL };
static const char *webcmd[]   = { "chromium", NULL };
static const char *toggle[] = { "mpc", "toggle", NULL };
static const char *next[] = { "mpc", "next", NULL };
static const char *prev[] = { "mpc", "prev", NULL };
static const char *lock[] = { "lock", NULL };
static const char *blank[] = { "xset", "dpms", "force", "off", NULL };
static const char *track[] = { "touchpad", NULL };
static const char *rest[] = { "sudo", "pm-suspend", NULL };
static const char *hiber[] = { "sudo", "pm-hibernate", NULL };
static const char *scrot[] = { "scrot", NULL };
static const char *grab[] = { "scrot", "-s", NULL };
static const char *volu[] = { "amixer", "set", "Master", "5%+", NULL };
static const char *vold[] = { "amixer", "set", "Master", "5%-", NULL };
static const char *mute[] = { "amixer", "set", "Master", "toggle", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
        { MODKEY,                       XK_e,      spawn,          {.v = emacscmd } },
        { MODKEY,                       XK_w,      spawn,          {.v = webcmd } },
        { MODKEY,                       XK_x,      spawn,          {.v = toggle } },
        { MODKEY,                       XK_c,      spawn,          {.v = next } },
        { MODKEY,                       XK_z,      spawn,          {.v = prev } },
        { 0,                            0x1008ff2d,spawn,          {.v = lock } },
        { 0,                            0xff13,    spawn,          {.v = blank } },
        { 0,                            0x1008ffa9,spawn,          {.v = track } },
        { 0,                            0x1008ff2f,spawn,          {.v = rest } },
        { 0,                            0x1008ffa7,spawn,          {.v = hiber } },
        { 0,                            0xff61,    spawn,          {.v = scrot } },
        { MODKEY,                       0xff61,    spawn,          {.v = grab } },
        { 0,                            0x1008ff13,spawn,          {.v = volu } },
        { 0,                            0x1008ff11,spawn,          {.v = vold } },
        { 0,                            0x1008ff12,spawn,          {.v = mute } },

	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

