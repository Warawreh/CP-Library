@echo off
gen >in
e <in >ok
e_tle <in >out
type out
type ok
fc out ok
if errorlevel 1 pause 
rem pause
test