::the::
Send, +wani
return

::password::
Send, +c+t+f
return

::for::
Send, {home}{right 3}{del}1{end}{left 2}{del}7
return

::today::
FormatTime , x,, yyyyMMdd
SendInput, {home}{right 4}_%x%
return

::is::
Send, _{end}{!}{!}{left}
return

:*?:ni::
Send, ^a^c{Esc}{home}password{:} {end}
return