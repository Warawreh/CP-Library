@echo off
gen >in
dsol <in >ok
d <in >out
type out
type ok
fc out ok
if errorlevel 1 pause 
Dtest