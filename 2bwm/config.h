// MOD
#define MOD XCB_MOD_MASK_4  /* 4=Windows Key | 1=Alt */

// Custom foo
static void halfandcentered(const Arg *arg)
{
	Arg arg2 = {.i=TWOBWM_MAXHALF_VERTICAL_LEFT};
	maxhalf(&arg2);
	Arg arg3 = {.i=TWOBWM_TELEPORT_CENTER};
	teleport(&arg3);
}
#define CURSOR_POSITION MIDDLE
static const bool     resize_by_line           = true;
static const float    resize_keep_aspect_ratio = 1.03;


/* Windows that won't have a border.*/
#define LOOK_INTO "WM_NAME"
static const char *ignore_names[] = {"bar", "xclock"};


/* Move
 *0)move step slow   1)move step fast
 *2)mouse slow       3)mouse fast     */
static const uint16_t movements[] = {5,20,15,400};


/* Offsets
 *0)offsetx          1)offsety
 *2)maxwidth         3)maxheight */
static const uint8_t offsets[] = {0,0,0,0};


/* Colors
 *0)focuscol         1)unfocuscol
 *2)fixedcol         3)unkilcol
 *4)fixedunkilcol    5)outerbordercol
 *6)emptycol         */
static const char *colors[] = {"#443b70","#adadad","#7a8c5c","#ff4444","#cc9933","#0d131a","#000000"};
static const bool inverted_colors = true;


/* Borders
 *0) Outer border size. If you put this negative it will be a square.
 *1) Full borderwidth    2) Magnet border size
 *3) Resize border size  */
static const uint8_t borders[] = {5,5,5,4};


// Exec binds declaration
static const char *menucmd[]   = { "rofi", "-show", "run", NULL };
static const char *terminal[]  = { "urxvt", NULL };
static const char *telegram[]  = { "telegram", NULL };
static const char *firefox[]   = { "firefox", NULL };
static const char *click1[]    = { "xdotool","click", "1", NULL };
static const char *click2[]    = { "xdotool","click", "2", NULL };
static const char *click3[]    = { "xdotool","click", "3", NULL };
static const char *vol_up[]    = { "pamixer", "-u", "-i", "3", "--allow-boost", NULL };
static const char *vol_down[]  = { "pamixer", "-u", "-d", "3", "--allow-boost", NULL };
static const char *vol_mute[]  = { "amixer", "set", "Master", "mute", "-q", NULL };
static const char *bright_up[]  = { "light", "-A", "5", NULL };
static const char *bright_down[]  = { "light", "-U", "5", NULL };



// Binds
#define DESKTOPCHANGE(K,N) \
{  MOD ,             K,              changeworkspace, {.i=N}}, \
{  MOD |SHIFT,       K,              sendtoworkspace, {.i=N}},


static key keys[] = {
    /* modifier           key            function           argument */
    
    
    // Focus to next/previous window
    {  MOD ,              XK_Tab,        focusnext,          {.i=TWOBWM_FOCUS_NEXT}},
    {  MOD |SHIFT,        XK_Tab,        focusnext,          {.i=TWOBWM_FOCUS_PREVIOUS}},
    
    
    // Kill a window
    {  MOD |SHIFT,        XK_q,          deletewin,          {}},
    
    
    // Resize a window
    {  MOD |SHIFT,        XK_w,          resizestep,         {.i=TWOBWM_RESIZE_UP}},
    {  MOD |SHIFT,        XK_s,          resizestep,         {.i=TWOBWM_RESIZE_DOWN}},
    {  MOD |SHIFT,        XK_d,          resizestep,         {.i=TWOBWM_RESIZE_RIGHT}},
    {  MOD |SHIFT,        XK_a,          resizestep,         {.i=TWOBWM_RESIZE_LEFT}},
    
    
    // Resize a window slower
    {  MOD |SHIFT|CONTROL,XK_w,          resizestep,         {.i=TWOBWM_RESIZE_UP_SLOW}},
    {  MOD |SHIFT|CONTROL,XK_s,          resizestep,         {.i=TWOBWM_RESIZE_DOWN_SLOW}},
    {  MOD |SHIFT|CONTROL,XK_d,          resizestep,         {.i=TWOBWM_RESIZE_RIGHT_SLOW}},
    {  MOD |SHIFT|CONTROL,XK_a,          resizestep,         {.i=TWOBWM_RESIZE_LEFT_SLOW}},
    
    
    // Move a window
    {  MOD ,              XK_w,          movestep,           {.i=TWOBWM_MOVE_UP}},
    {  MOD ,              XK_s,          movestep,           {.i=TWOBWM_MOVE_DOWN}},
    {  MOD ,              XK_d,          movestep,           {.i=TWOBWM_MOVE_RIGHT}},
    {  MOD ,              XK_a,          movestep,           {.i=TWOBWM_MOVE_LEFT}},
    
    
    // Move a window slower
    {  MOD |CONTROL,      XK_w,          movestep,           {.i=TWOBWM_MOVE_UP_SLOW}},
    {  MOD |CONTROL,      XK_s,          movestep,           {.i=TWOBWM_MOVE_DOWN_SLOW}},
    {  MOD |CONTROL,      XK_d,          movestep,           {.i=TWOBWM_MOVE_RIGHT_SLOW}},
    {  MOD |CONTROL,      XK_a,          movestep,           {.i=TWOBWM_MOVE_LEFT_SLOW}},
    
    
    // Teleport the window to an area of the screen.
    // Center:
    {  MOD ,              XK_g,          teleport,           {.i=TWOBWM_TELEPORT_CENTER}},
    
    
    // Center y:
    {  MOD |SHIFT,        XK_g,          teleport,           {.i=TWOBWM_TELEPORT_CENTER_Y}},
    
    
    // Center x:
    {  MOD |CONTROL,      XK_g,          teleport,           {.i=TWOBWM_TELEPORT_CENTER_X}},
    
    
    // Top left:
    {  MOD ,              XK_y,          teleport,           {.i=TWOBWM_TELEPORT_TOP_LEFT}},
    
    
    // Top right:
    {  MOD ,              XK_u,          teleport,           {.i=TWOBWM_TELEPORT_TOP_RIGHT}},
    
    
    // Bottom left:
    {  MOD ,              XK_b,          teleport,           {.i=TWOBWM_TELEPORT_BOTTOM_LEFT}},
    
    
    // Bottom right:
    {  MOD ,              XK_n,          teleport,           {.i=TWOBWM_TELEPORT_BOTTOM_RIGHT}},
    
    
    // Resize while keeping the window aspect
    {  MOD ,              XK_Home,       resizestep_aspect,  {.i=TWOBWM_RESIZE_KEEP_ASPECT_GROW}},
    {  MOD ,              XK_End,        resizestep_aspect,  {.i=TWOBWM_RESIZE_KEEP_ASPECT_SHRINK}},
    
    
    // Full screen window without borders
    {  MOD ,              XK_x,          maximize,           {.i=TWOBWM_FULLSCREEN}},
    
    
    //Full screen window without borders overiding offsets
    {  MOD |SHIFT ,       XK_x,          maximize,           {.i=TWOBWM_FULLSCREEN_OVERRIDE_OFFSETS}},
    
    
    // Maximize vertically
    {  MOD ,              XK_m,          maxvert_hor,        {.i=TWOBWM_MAXIMIZE_VERTICALLY}},
    
    
    // Maximize horizontally 
    {  MOD |SHIFT,        XK_m,          maxvert_hor,        {.i=TWOBWM_MAXIMIZE_HORIZONTALLY}},
    
    
    // Maximize and move
    // vertically left
    {  MOD |SHIFT,        XK_y,          maxhalf,            {.i=TWOBWM_MAXHALF_VERTICAL_LEFT}},
    
    
    // vertically right
    {  MOD |SHIFT,        XK_u,          maxhalf,            {.i=TWOBWM_MAXHALF_VERTICAL_RIGHT}},
    
    
    // horizontally left
    {  MOD |SHIFT,        XK_b,          maxhalf,            {.i=TWOBWM_MAXHALF_HORIZONTAL_BOTTOM}},
    
    
    // horizontally right
    {  MOD |SHIFT,        XK_n,          maxhalf,            {.i=TWOBWM_MAXHALF_HORIZONTAL_TOP}},
    
    
    //fold half vertically
    {  MOD |SHIFT|CONTROL,XK_y,          maxhalf,            {.i=TWOBWM_MAXHALF_FOLD_VERTICAL}},
    
    
    //fold half horizontally
    {  MOD |SHIFT|CONTROL,XK_b,          maxhalf,            {.i=TWOBWM_MAXHALF_FOLD_HORIZONTAL}},
    
    
    //unfold vertically
    {  MOD |SHIFT|CONTROL,XK_u,          maxhalf,            {.i=TWOBWM_MAXHALF_UNFOLD_VERTICAL}},
    
    
    //unfold horizontally
    {  MOD |SHIFT|CONTROL,XK_n,          maxhalf,            {.i=TWOBWM_MAXHALF_UNFOLD_HORIZONTAL}},
    
    
    // Next/Previous screen
    {  MOD ,              XK_comma,      changescreen,       {.i=TWOBWM_NEXT_SCREEN}},
    {  MOD ,              XK_period,     changescreen,       {.i=TWOBWM_PREVIOUS_SCREEN}},
    
    
    // Raise or lower a window
    {  MOD ,              XK_r,          raiseorlower,       {}},
    
    
    // Next/Previous workspace
    {  MOD ,              XK_v,          nextworkspace,      {}},
    {  MOD ,              XK_c,          prevworkspace,      {}},
    
    
    // Move to Next/Previous workspace
    {  MOD |SHIFT ,       XK_v,          sendtonextworkspace,{}},
    {  MOD |SHIFT ,       XK_c,          sendtoprevworkspace,{}},
    
    
    // Iconify the window
    //{  MOD ,              XK_i,        hide,               {}},
    // Make the window unkillable
    {  MOD ,              XK_z,          unkillable,         {}},
    
    
    // Make the window appear always on top
    {  MOD |SHIFT,        XK_t,          always_on_top,      {}},
    
    
    // Make the window stay on all workspaces
    {  MOD |SHIFT,        XK_f,          fix,                {}},
    
    
    // Move the cursor
    {  MOD ,              XK_Up,         cursor_move,        {.i=TWOBWM_CURSOR_UP_SLOW}},
    {  MOD ,              XK_Down,       cursor_move,        {.i=TWOBWM_CURSOR_DOWN_SLOW}},
    {  MOD ,              XK_Right,      cursor_move,        {.i=TWOBWM_CURSOR_RIGHT_SLOW}},
    {  MOD ,              XK_Left,       cursor_move,        {.i=TWOBWM_CURSOR_LEFT_SLOW}},
    
    
    // Move the cursor faster
    {  MOD |SHIFT,        XK_Up,         cursor_move,        {.i=TWOBWM_CURSOR_UP}},
    {  MOD |SHIFT,        XK_Down,       cursor_move,        {.i=TWOBWM_CURSOR_DOWN}},
    {  MOD |SHIFT,        XK_Right,      cursor_move,        {.i=TWOBWM_CURSOR_RIGHT}},
    {  MOD |SHIFT,        XK_Left,       cursor_move,        {.i=TWOBWM_CURSOR_LEFT}},
    
    
    // Start programs
    {  MOD ,              XK_Return,     start,              {.com = terminal}},
    {  MOD ,              XK_p,          start,              {.com = menucmd}},
    {  MOD ,              XK_t,          start,              {.com = telegram}},
    {  MOD ,              XK_f,          start,              {.com = firefox}},
    
    
    // Exit or restart 2bwm
    {  MOD |SHIFT,        XK_e,          twobwm_exit,        {.i=0}},
    {  MOD |CONTROL,      XK_r,          twobwm_restart,     {.i=0}},
    {  MOD ,              XK_space,      halfandcentered,    {.i=0}},
    
    
    // Fake clicks using xdotool
    {  MOD |CONTROL,      XK_Up,         start,              {.com = click1}},
    {  MOD |CONTROL,      XK_Down,       start,              {.com = click2}},
    {  MOD |CONTROL,      XK_Right,      start,              {.com = click3}},
    {  0x000000,          0x1008ff13,    start,              {.com = vol_up}},
    {  0x000000,          0x1008ff11,    start,              {.com = vol_down}},
    {  0x000000,          0x1008ff15,    start,              {.com = vol_mute}},
    {  0x000000,          0x1008ff02,    start,              {.com = bright_up}},
    {  0x000000,          0x1008ff03,    start,              {.com = bright_down}},
    
    
    // Change current workspace
       DESKTOPCHANGE(     XK_1,                             0)
       DESKTOPCHANGE(     XK_2,                             1)
       DESKTOPCHANGE(     XK_3,                             2)
       DESKTOPCHANGE(     XK_4,                             3)
       DESKTOPCHANGE(     XK_5,                             4)
       DESKTOPCHANGE(     XK_6,                             5)
       DESKTOPCHANGE(     XK_7,                             6)
       DESKTOPCHANGE(     XK_8,                             7)
       DESKTOPCHANGE(     XK_9,                             8)
       DESKTOPCHANGE(     XK_0,                             9)
};
static Button buttons[] = {
    {  MOD        ,XCB_BUTTON_INDEX_1,     mousemotion,     {.i=TWOBWM_MOVE}},
    {  MOD        ,XCB_BUTTON_INDEX_3,     mousemotion,     {.i=TWOBWM_RESIZE}},
    {  MOD|SHIFT,  XCB_BUTTON_INDEX_1,     changeworkspace, {.i=0}},
    {  MOD|SHIFT,  XCB_BUTTON_INDEX_3,     changeworkspace, {.i=1}},
    {  MOD|ALT,    XCB_BUTTON_INDEX_1,     changescreen,    {.i=1}},
    {  MOD|ALT,    XCB_BUTTON_INDEX_3,     changescreen,    {.i=0}}
};
