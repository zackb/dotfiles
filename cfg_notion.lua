META="Mod4+" -- MacOS Apple/Command key
ALTMETA=""
ioncore.set{
    dblclick_delay=250,
    kbresize_delay=1000,
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
