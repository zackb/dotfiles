-- Create a statusbar
mod_statusbar.create{
    screen = 0,     -- First screen, 
    pos = 'bl',     -- bottom left corner
    systray = true, -- Swallow systray windows

    -- The template
    template = "[ %date || load: %>load || %battery% ]"
               .. " %filler%systray",
}

-- Launch ion-statusd. 
mod_statusbar.launch_statusd{
    -- Date meter
    date={
        -- ISO-8601 date format with additional abbreviated day name
        date_format='%a %Y-%m-%d %H:%M',
    },      
}
