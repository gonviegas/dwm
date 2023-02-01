/* See LICENSE file for copyright and license details. */

/* appearance */
#define FOCUSONWHEEL                                 0         /*  switch client focus by mouse click; 1 = sloppy client focus */ 
static const unsigned int borderpx                 = 2;        /* border windows in px */
static const          int statusallmons            = 1;        /* 0 = status bar only on selected monitor; 1 = status bar always on all monitors */
static const          int hidevacanttags           = 0;
static const          int showsystray              = 1;        /* 0 = no systray */
static const unsigned int systraypinning           = 0;        /* 0 = sloppy systray follows selected monitor; >0 = pin systray to monitor X */
static const unsigned int systrayonleft            = 0;        /* 0 = systray in the right corner; >0 =  systray on left of status text */
static const unsigned int systrayspacing           = 0;        /* systray spacing */
static const          int systraypinningfailfirst  = 1;        /* 1 = if pinning fails, display systray on the first monitor; 0 = display systray on the last monitor */
static const          int smartgaps                = 1;        /* 1 = no outer gap when there is only one window */
static const unsigned int gappih                   = 13;       /* horiz inner gap between windows */
static const unsigned int gappiv                   = 13;       /* vert inner gap between windows */
static const unsigned int gappoh                   = 13;        /* horiz outer gap between windows and screen edge */
static const unsigned int gappov                   = 13;        /* vert outer gap between windows and screen edge */
static const          int showbar                  = 1;        /* 0 = no bar */
static const          int topbar                   = 1;        /* 0 = bottom bar */
static const          int tagicons                 = 1;        /* 0 = no tag icons; 1 = show tag icons */
static const          int user_bh                  = 21;       /* 0 = auto calculate bar height; >0 = bar height in px */
#define                   ICONSIZE                   16        /* icon size */
#define                   TAGICON_X                  1         /* tag icon X position */
#define                   TAGICON_Y                  -3         /* tag icon Y position */
#define                   ICON_X                     -6         /* tag icon X position */
#define                   INDIC_X                    -13        /* info floating and sticky indicator X position */
#define                   INFO_X                     0         /* info X position */
static const          char *fonts[]                = { "jetbrainsmononerdfont:size=9:style=medium:antialias=true:autohint=true", "notocoloremoji:size=9:antialias=true:autohint=true" };
static const          char col_gray[]              = "#707070";
static const          char col_gray1[]             = "#111111";
static const          char col_gray2[]             = "#434343";
static const          char col_gray3[]             = "#cccccc";
static const          char col_gray4[]             = "#eeeeee";
static const          char col_red[]               = "#ff0000";
static const          char col_orange[]            = "#cc5500";
static const          char col_black[]             = "#000000";
static const          char *colors[][3] = {
	/*                        fg            bg           border        */
	[SchemeNorm]  	   = { col_gray3,    col_gray1,    col_gray1},
	[SchemeSel]        = { col_black,    col_gray3,    col_orange},
	[SchemeUrg]        = { col_black,    col_red,      col_red },
	[SchemeTagsSel]    = { col_black,    col_gray,     "#000000" }, // Tags selected {text, background, not used but cannot be empty}
	[SchemeTagsOcc]    = { col_gray3,    col_gray1,    "#000000" }, // Tags unselected with clients {text, background, not used but cannot be empty}
	[SchemeTagsEmpt]   = { col_gray1,    col_gray1,    "#000000" }, // Tags unselected without clients {text, background, not used but cannot be empty}
	[SchemeLayoutSymb] = { col_gray3,    col_gray1,    "#000000" }, // Layout symbol {text, background, not used but cannot be empty}
	[SchemeInfoSel]    = { col_gray3,    col_gray1,    "#000000" }, // Info selected {text, background, not used but cannot be empty}
	[SchemeInfoNorm]   = { col_gray3,    col_gray1,    "#000000" }, // Info unselected {text, background, not used but cannot be empty}
	[SchemeInfoInv]    = { col_gray3,    col_gray2,    "#000000" }, // Info unfocused monitor {text, background, not used but cannot be empty}
	[SchemeStatus]     = { col_gray3,    col_gray1,    "#000000" }, // Status {text, background, not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask  isfloating  isfakefullscreen  ispermanent monitor */
	//{ "Firefox",  NULL,       NULL,        1 << 8,        0,            0,            0,       -1 },
	{ NULL,       NULL,       "smenu",        0,         1,            0,               0,       -1 },
	{ NULL,       NULL,       "sh",           0,         1,            0,               0,       -1 },
	{ "Pavucontrol", NULL,    NULL,           0,         1,            0,               0,       -1 },
	{ "Nm-connection-editor", NULL, NULL,     0,         1,            0,               0,       -1 },
	{ "dmenu",    NULL,       NULL,           0,         1,            0,               0,       -1 },
	{ NULL,       NULL,       "htop",         0,         1,            0,               0,       -1 },
	{ "Gnome-disks", NULL,    NULL,           0,         1,            0,               0,       -1 },
	{ "qv4l2",    NULL,       NULL,           0,         1,            0,               0,       -1 },
	{ "Gufw.py",    NULL,     NULL,           0,         1,            0,               0,       -1 },
	{ "Xfce4-power-manager-settings", NULL, NULL, 0,     1,            0,               0,       -1 },
	{ NULL,  "brave-browser", NULL,           0,         0,            1,               0,       -1 },
	{ "librewolf", NULL, NULL,                0,         0,            1,               0,       -1 },
	{ "Galculator", NULL,     NULL,           0,         1,            0,               0,       -1 },
	{ "Chromium",   NULL,     NULL,           0,         0,            1,               0,       -1 },
	{ "Nvidia-settings", NULL, NULL,          0,         1,            0,               0,       -1 },
	{ NULL,       NULL,       "nvim",         0,         0,            0,               1,       -1 },
	{ NULL,       NULL,       "apt-update",   0,         1,            0,               1,       -1 },
};

/* layout(s) */
static const float mfact     	   = 0.50; /* factor of master area size [0.05..0.95] */
static const int   nmaster     	   = 1;    /* number of clients in master area */
static const int   resizehints 	   = 0;    /* 1 means respect size hints in tiled resizals */
static const int   lockfullscreen  = 1; /* 1 will force focus on the fullscreen window */
static const int   attachdirection = 4;    /* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */

/* mouse scroll resize */
static const int scrollsensitivity = 30; /* 1 means resize window by 1 pixel for each scroll event */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
  { "><>",      NULL },    /* no layout function means floating behavior */
  { "[\\]",     dwindle },
  { "H[]",      deck },
 	{ "TTT",      bstack },
 	{ "###",      nrowgrid },
 	{ ":::",      gaplessgrid },
 	{ "|M|",      centeredmaster },
	{ NULL,       NULL },
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

#define STATUSBAR "dwmblocks"

/* commands */
static const char *xkill[] = { "xkill", NULL };

//#include <X11/XF86keysym.h>

static const Key keys[] = {
  // COM = commented in dwm.c
	/* modifier                     key        function          argument */
	{ MODKEY,                       XK_b,      togglebar,        {0} },
	{ MODKEY,                       XK_j,      focusstack,       {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,       {.i = -1 } },
	{ MODKEY,                       XK_h,      focusdir,         {.i = 0 } }, // left
	{ MODKEY,                       XK_l,      focusdir,         {.i = 1 } }, // right
	{ MODKEY|ShiftMask,             XK_j,      pushdown,         {0} },
	{ MODKEY|ShiftMask,             XK_k,      pushup,           {0} },
	{ MODKEY|ShiftMask,             XK_h,      placedir,         {.i = 0 } }, // left
	{ MODKEY|ShiftMask,             XK_l,      placedir,         {.i = 1 } }, // right
	{ MODKEY|ShiftMask|ControlMask, XK_k,      incnmaster,       {.i = +1 } },
	{ MODKEY|ShiftMask|ControlMask, XK_j,      incnmaster,       {.i = -1 } },
	{ MODKEY|ControlMask,           XK_h,      setmfact,         {.f = -0.03} },
	{ MODKEY|ControlMask,           XK_l,      setmfact,         {.f = +0.03} },
	{ MODKEY|ShiftMask|ControlMask, XK_h,      setmfact,         {.f =  0.00} },
	{ MODKEY|ControlMask,           XK_j,      setcfact,         {.f = +0.10} },
	{ MODKEY|ControlMask,           XK_k,      setcfact,         {.f = -0.10} },
	{ MODKEY|ShiftMask|ControlMask, XK_l,      setcfact,         {.f =  0.00} },
	{ MODKEY,                       XK_Tab,    view,             {0} },
	{ MODKEY,                       XK_u,      focusurgent,      {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,       {0} },
	{ MODKEY|ControlMask,           XK_Escape, spawn,            {.v = xkill } },
	{ MODKEY,                       XK_d,      cyclelayout,      {.i = -1 } },
	{ MODKEY,                       XK_f,      cyclelayout,      {.i = +1 } },
	{ MODKEY,                       XK_grave,  togglefullscreen, {0} },
	{ MODKEY|ShiftMask,             XK_grave,  togglefloating,   {0} },
	{ MODKEY|ControlMask,           XK_grave,   togglesticky,    {0} },
	{ MODKEY|ControlMask,           XK_f,  togglefakefullscreen, {0} },
	{ MODKEY|ShiftMask,             XK_j,      moveresize,       {.v = "0x 35y 0w 0h" } },
 	{ MODKEY|ShiftMask,             XK_k,      moveresize,       {.v = "0x -35y 0w 0h" } },
 	{ MODKEY|ShiftMask,             XK_l,      moveresize,       {.v = "50x 0y 0w 0h" } },
 	{ MODKEY|ShiftMask,             XK_h,      moveresize,       {.v = "-50x 0y 0w 0h" } },
 	{ MODKEY|ControlMask,           XK_j,      moveresize,       {.v = "0x 0y 0w 35h" } },
	{ MODKEY|ControlMask,           XK_k,      moveresize,       {.v = "0x 0y 0w -35h" } },
 	{ MODKEY|ControlMask,           XK_l,      moveresize,       {.v = "0x 0y 50w 0h" } },
 	{ MODKEY|ControlMask,           XK_h,      moveresize,       {.v = "0x 0y -50w 0h" } },
 	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge,   {.v = "t"} },
 	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge,   {.v = "b"} },
 	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge,   {.v = "l"} },
 	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge,   {.v = "r"} },
 	{ MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge,   {.v = "T"} },
 	{ MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge,   {.v = "B"} },
 	{ MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge,   {.v = "L"} },
 	{ MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge,   {.v = "R"} },
 	{ MODKEY|ShiftMask,             XK_o,  centerfloatingtoggle, {0} },
	{ MODKEY,                       XK_o,      view,             {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,              {.ui = ~0 } },
	{ MODKEY,                       XK_q,      shiftview,        {.i = -1 } },
 	{ MODKEY,                       XK_w,      shiftview,        {.i = +1 } },
 	{ MODKEY|ShiftMask,             XK_q,   shiftviewmoveclient, {.i = -1 } },
 	{ MODKEY|ShiftMask,             XK_w,   shiftviewmoveclient, {.i = +1 } },
 	{ MODKEY,                       XK_a,      shiftviewocc,     {.i = -1 } },
 	{ MODKEY,                       XK_s,      shiftviewocc,     {.i = +1 } },
 	{ MODKEY|ShiftMask,             XK_a, shiftviewoccmoveclient, {.i = -1 } },
 	{ MODKEY|ShiftMask,             XK_s, shiftviewoccmoveclient, {.i = +1 } },
 	{ MODKEY|ShiftMask|ControlMask, XK_q,      shiftviewswaptag,  { .i = -1 } },
 	{ MODKEY|ShiftMask|ControlMask, XK_w,      shiftviewswaptag,  { .i = +1 } },
 	{ MODKEY|ShiftMask|ControlMask, XK_a,    shiftviewoccswaptag, { .i = -1 } },
 	{ MODKEY|ShiftMask|ControlMask, XK_s,    shiftviewoccswaptag, { .i = +1 } },
  //COM { MODKEY|ShiftMask,         XK_z,      tagmon,           {.i = -1 } },
	//COM { MODKEY|ShiftMask,         XK_x,      tagmon,           {.i = +1 } },
	{ MODKEY,                       XK_z,      focusmon,         {.i = -1 } },
	{ MODKEY,                       XK_x,      focusmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_z,   focusmonmoveclient,  {.i = -1 } },
 	{ MODKEY|ShiftMask,             XK_x,   focusmonmoveclient,  {.i = +1 } },
 	{ MODKEY|ShiftMask|ControlMask, XK_z,      focusmonmovetag,  {.i = -1 } },
 	{ MODKEY|ShiftMask|ControlMask, XK_x,      focusmonmovetag,  {.i = +1 } },
	//COM { MODKEY|ControlMask,           XK_u,    incrgaps,         {.i = +1 } },
	//COM { MODKEY|Mod4Mask|ShiftMask,    XK_u,    incrgaps,         {.i = -1 } },
 	{ MODKEY|Mod1Mask,       XK_bracketright,  incrigaps,        {.i = +1 } },
 	{ MODKEY|Mod1Mask,        XK_bracketleft,  incrigaps,        {.i = -1 } },
 	{ MODKEY|Mod1Mask,              XK_equal,  incrogaps,        {.i = +1 } },
 	{ MODKEY|Mod1Mask,              XK_minus,  incrogaps,        {.i = -1 } },
 	{ MODKEY|Mod1Mask,              XK_0,      defaultgaps,      {0} },
 	{ MODKEY,		                    XK_g,      togglegaps,       {0} },
	//COM { MODKEY|Mod4Mask,              XK_6,      incrihgaps,       {.i = +1 } },
	//COM { MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,       {.i = -1 } },
	//COM { MODKEY|Mod4Mask,              XK_7,      incrivgaps,       {.i = +1 } },
	//COM { MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,       {.i = -1 } },
	//COM { MODKEY|Mod4Mask,              XK_8,      incrohgaps,       {.i = +1 } },
	//COM { MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,       {.i = -1 } },
	//COM { MODKEY|Mod4Mask,              XK_9,      incrovgaps,       {.i = +1 } },
	//COM { MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,       {.i = -1 } },
	TAGKEYS(                        XK_1,                        0)
	TAGKEYS(                        XK_2,                        1)
	TAGKEYS(                        XK_3,                        2)
	TAGKEYS(                        XK_4,                        3)
	TAGKEYS(                        XK_5,                        4)
	TAGKEYS(                        XK_6,                        5)
	TAGKEYS(                        XK_7,                        6)
	TAGKEYS(                        XK_8,                        7)
	TAGKEYS(                        XK_9,                        8)
	{ MODKEY|ControlMask|ShiftMask, XK_Escape, quit,             {0} },
  { MODKEY|ControlMask|ShiftMask, XK_r,      quit,             {1} },
};

/* resizemousescroll direction argument list */
static const int scrollargs[][2] = {
	/* width change   height change */
	{ -scrollsensitivity, 0 },
	{ +scrollsensitivity, 0 },
	{ 0, -scrollsensitivity },
	{ 0, +scrollsensitivity },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,          MODKEY|ShiftMask, Button1,        tag,            {0} },
	{ ClkTagBar,        MODKEY|ControlMask, Button1,        toggletag,      {0} },
	{ ClkTagBar,            0,              Button5,        shiftviewocc,   {.i = -1 } },
	{ ClkTagBar,            0,              Button4,        shiftviewocc,   {.i = +1 } },
	{ ClkLtSymbol,          0,              Button1,        togglefullscreen,     {0} },
	{ ClkLtSymbol,          0,              Button5,        cyclelayout,    {.i = -1 } },
	{ ClkLtSymbol,          0,              Button4,        cyclelayout,    {.i = +1 } },
	{ ClkLtSymbol,          0,              Button3,        togglefloating, {0} },
	{ ClkWinTitle,          0,              Button4,        focusstack,     {.i = +1 } },
	{ ClkWinTitle,          0,              Button5,        focusstack,     {.i = -1 } },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
 	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
 	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
 	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY,         Button4,     resizemousescroll, {.v = &scrollargs[0]} },
	{ ClkClientWin,         MODKEY,         Button5,     resizemousescroll, {.v = &scrollargs[1]} },
	{ ClkClientWin,         MODKEY,         Button6,     resizemousescroll, {.v = &scrollargs[2]} },
	{ ClkClientWin,         MODKEY,         Button7,     resizemousescroll, {.v = &scrollargs[3]} },
	{ ClkClientWin,  MODKEY|ControlMask,    Button3,        dragcfact,      {0} },
	{ ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 1} } /* 0 = relative to mouse cursor; 1 = relative to window center; 2 = mouse pointer warps to window center */
};
