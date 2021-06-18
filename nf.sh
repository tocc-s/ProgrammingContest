#!/bin/bash

read -p "Contest name: " contest
read -p "Directory name: " dir_name
contest=${contest^^}
dir_name=${dir_name^^}

mkdir Atcoder/$contest/$dir_name
cp template.cpp Atcoder/$contest/$dir_name/a.cpp
cp template.cpp Atcoder/$contest/$dir_name/b.cpp
cp template.cpp Atcoder/$contest/$dir_name/c.cpp
cp template.cpp Atcoder/$contest/$dir_name/d.cpp