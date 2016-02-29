META="Mod4+"
ALTMETA=""
ioncore.set{
    dblclick_delay=250,
    kbresize_delay=15000,
}
ioncore.set{
    opaque_resize=true,
    warp=true
}
dopath("cfg_defaults")
dopath("cfg_notioncore")
dopath("cfg_kludges")
dopath("cfg_layouts")
ioncore.defshortening("[^:]+: (.*)(<[0-9]+>)", "$1$2$|$1$<...$2")
dopath("mod_query")
dopath("mod_menu")
dopath("mod_tiling")
dopath("mod_statusbar")
--dopath("mod_dock")
--dopath("mod_sp")


defbindings("WScreen", {
    -- kpress("Mod1+122", "_:switch_next()"),
    bdoc("Mute/Unmute Sound."),
    kpress("AnyModifier+XF86AudioMute", "ioncore.exec_on(_, 'amixer sset Master toggle')"),
    bdoc("Increase Volume."),
    kpress("AnyModifier+XF86AudioRaiseVolume", "ioncore.exec_on(_, 'amixer sset Master 3%+')"),
    bdoc("Decrease Volume."),
    kpress("AnyModifier+XF86AudioLowerVolume", "ioncore.exec_on(_, 'amixer sset Master 3%-')"),
})


