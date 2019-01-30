#!/bin/bash
# chwm.sh
: $(kwin --replace >/dev/null 2>&1) >/dev/null 2>&1 &
disown
exit
