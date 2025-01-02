@echo off
g >in
b <in >ok
f <in >out
rem type in
rem type ok
fc out ok
if errorlevel 1 pause 
test