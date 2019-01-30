#!/bin/bash
# script to change the theme's opacity while running
# first try to go to the installation directory
if [ -z "$optst" ]; then
export olddir=$(pwd); cd /opt/material-decoration-bt && export chuser=$(whoami) && export optst='y' || unset optst
fi
if [ "$optst" == "y" ]; then
 if [ "$(whoami)" != "root" ]; then
    echo 'loading /opt predefinitions' 
    cd /opt/material-decoration-bt
    sudo su -m -s "$0"
    bash /opt/material-decoration-bt/chwm.sh
    echo 'Done'
    exit
 fi
fi

# read the active opacity
current=$(cat currentOpacity 2>/dev/null ) || echo 'default (0.635)'
echo 'Current opacity:' $current
# ask for user input 
read -p 'Enter new opacity; any value in [1.0 - 0.0]: ' OPACITY
# log new opacity
echo $OPACITY > currentOpacity
# replace lines in source
sudo sed -i "91s/.*/static qreal s_titleBarOpacityActive = $OPACITY;/" src/Decoration.cc
sudo sed -i "92s/.*/static qreal s_titleBarOpacityInactive = $OPACITY;/" src/Decoration.cc
# rebuild
echo 'Rebuilding...'
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr .. > setup.log ||  echo 'Something went wrong while preparing the source. Check setup.log for more information.'
sudo make -j4 install > bt-opacity-log ; cd ..
echo 'Reloading...'
unset optst
cd $olddir
# reset wm
exit
