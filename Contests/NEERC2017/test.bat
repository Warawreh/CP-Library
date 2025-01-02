@echo off
gena >in
a2 <in >ok
a <in >out
type out
type ok
fc out ok
if errorlevel 1 pause 
rem pause
test