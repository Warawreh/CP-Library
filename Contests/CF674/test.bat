@echo off
gen > in
c <in >ok
c2 <in >out
rem type out
rem type ok
fc out ok
if errorlevel 1 pause 
test