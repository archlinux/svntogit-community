-- DynamicLog require xmonad-contrib

import XMonad
import XMonad.Hooks.DynamicLog

import qualified XMonad.StackSet as W
import qualified Data.Map as M
import System.Exit
import Graphics.X11.Xlib

main = xmonad $ defaultConfig 
                { workspaces = workspaces',
                  modMask = modMask',
                  borderWidth = borderWidth',
                  normalBorderColor = normalBorderColor',
                  focusedBorderColor = focusedBorderColor',
                  defaultGaps = defaultGaps',
                  terminal = terminal',
                  keys = keys', 
                  logHook = logHook'
                }

workspaces' :: [WorkspaceId]
workspaces' = ["1-code", "2-test", "3-misc", "4-web", "5-mail", "6", "7", "8", "9-irc"]

modMask' :: KeyMask
modMask' = mod4Mask

borderWidth' :: Dimension
borderWidth' = 0

normalBorderColor', focusedBorderColor' :: String
normalBorderColor'  = "#000000"
focusedBorderColor' = "#0f0f0f"


defaultGaps' :: [(Int,Int,Int,Int)]
defaultGaps' = [(15,0,0,0), (15,0,0,0)] -- 15 for default dzen font

logHook' :: X ()
logHook' = dynamicLogXinerama

terminal' :: String
terminal' = "urxvt"



keys' :: XConfig Layout -> M.Map (KeyMask, KeySym) (X ())
keys' conf@(XConfig {XMonad.modMask = modMask}) = M.fromList $
    -- launching and killing programs
    [ ((modMask .|. shiftMask, xK_t), spawn $ XMonad.terminal conf) -- %! Launch terminal
    , ((modMask,               xK_p     ), spawn "exe=`dmenu_path | dmenu` && eval \"exec $exe\"") -- %! Launch dmenu
    , ((modMask .|. shiftMask, xK_p     ), spawn "gmrun") -- %! Launch gmrun
    , ((modMask .|. shiftMask, xK_c     ), kill) -- %! Close the focused window
    , ((modMask .|. shiftMask, xK_e     ), spawn "xemacs")
    , ((modMask .|. shiftMask, xK_w     ), spawn "swiftweasel")
    , ((modMask .|. shiftMask, xK_m     ), spawn "claws-mail")


    , ((modMask,               xK_space ), sendMessage NextLayout) -- %! Rotate through the available layout algorithms
    , ((modMask .|. shiftMask, xK_space ), setLayout $ XMonad.layoutHook conf) -- %!  Reset the layouts on the current workspace to default

    , ((modMask,               xK_n     ), refresh) -- %! Resize viewed windows to the correct size

    -- move focus up or down the window stack
    , ((modMask,               xK_Tab   ), windows W.focusDown) -- %! Move focus to the next window
    , ((modMask,               xK_j     ), windows W.focusDown) -- %! Move focus to the next window
    , ((modMask,               xK_k     ), windows W.focusUp  ) -- %! Move focus to the previous window
    , ((modMask,               xK_m     ), windows W.focusMaster  ) -- %! Move focus to the master window

    -- mpd controls
    , ((modMask .|. controlMask,  xK_h     ), spawn "mpc prev")
    , ((modMask .|. controlMask,  xK_t     ), spawn "mpc pause")
    , ((modMask .|. controlMask,  xK_n     ), spawn "mpc play")
    , ((modMask .|. controlMask,  xK_s     ), spawn "mpc next")

    , ((modMask .|. controlMask,  xK_g     ), spawn "mpc seek -2%")
    , ((modMask .|. controlMask,  xK_c     ), spawn "mpc volume -4")
    , ((modMask .|. controlMask,  xK_r     ), spawn "mpc volume +4")
    , ((modMask .|. controlMask,  xK_l     ), spawn "mpc seek +2%")


    -- modifying the window order
    , ((modMask,               xK_Return), windows W.swapMaster) -- %! Swap the focused window and the master window
    , ((modMask .|. shiftMask, xK_j     ), windows W.swapDown  ) -- %! Swap the focused window with the next window
    , ((modMask .|. shiftMask, xK_k     ), windows W.swapUp    ) -- %! Swap the focused window with the previous window

    -- resizing the master/slave ratio
    , ((modMask,               xK_h     ), sendMessage Shrink) -- %! Shrink the master area
    , ((modMask,               xK_l     ), sendMessage Expand) -- %! Expand the master area

    -- floating layer support
    , ((modMask,               xK_t     ), withFocused $ windows . W.sink) -- %! Push window back into tiling

    -- increase or decrease number of windows in the master area
    , ((modMask              , xK_comma ), sendMessage (IncMasterN 1)) -- %! Increment the number of windows in the master area
    , ((modMask              , xK_period), sendMessage (IncMasterN (-1))) -- %! Deincrement the number of windows in the master area

    -- toggle the status bar gap
    , ((modMask              , xK_b     ), modifyGap (\i n -> let x = (XMonad.defaultGaps conf ++ repeat (0,0,0,0)) !! i in if n == x then (0,0,0,0) else x)) -- %! Toggle the status bar gap

    -- quit, or restart
    , ((modMask .|. shiftMask, xK_q     ), io (exitWith ExitSuccess)) -- %! Quit xmonad
    , ((modMask              , xK_q     ), restart "xmonad" True) -- %! Restart xmonad
    ]
    ++
    -- mod-[1..9] %! Switch to workspace N
    -- mod-shift-[1..9] %! Move client to workspace N
    [((m .|. modMask, k), windows $ f i)
        | (i, k) <- zip (XMonad.workspaces conf) [xK_1 .. xK_9]
        , (f, m) <- [(W.greedyView, 0), (W.shift, shiftMask)]]
    ++
    -- mod-{a,o} %! Switch to physical/Xinerama screens 1, 2, or 3
    -- mod-shift-{a,o} %! Move client to screen 1, 2, or 3
    [((m .|. modMask, key), screenWorkspace sc >>= flip whenJust (windows . f))
        | (key, sc) <- zip [xK_a, xK_o] [0..]
        , (f, m) <- [(W.view, 0), (W.shift, shiftMask)]]


