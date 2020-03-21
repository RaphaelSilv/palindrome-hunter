#!/usr/bin/env bash

set -ex

uncrustify --version

uncrustify -c uncrustify.cfg --replace --no-backup $(find ./ -regex ".*\.\(h\|cpp\|ino\)")
