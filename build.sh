#!/bin/bash

#FIXME: FT is not finishing the build process, but it does install to /usr/local/bin successfully.

echo "Building femboywm with args: $@"
cd femboywm
sudo make clean install "$@"
echo "[Desktop Entry]" | sudo tee /usr/share/xsessions/femboywm.desktop > /dev/null
echo "Encoding=UTF-8" | sudo tee -a /usr/share/xsessions/femboywm.desktop > /dev/null
echo "Name=femboywm" | sudo tee -a /usr/share/xsessions/femboywm.desktop > /dev/null
echo "Comment=Loads femboywm :)" | sudo tee -a /usr/share/xsessions/femboywm.desktop > /dev/null
echo "Exec=/usr/local/bin/femboywm" | sudo tee -a /usr/share/xsessions/femboywm.desktop > /dev/null
echo "Type=Application" | sudo tee -a /usr/share/xsessions/femboywm.desktop > /dev/null
echo "New contents of /usr/share/xsessions/femboywm.desktop: "
sudo cat /usr/share/xsessions/femboywm.desktop

echo "Building femenu with args: $@"
cd ../femenu
sudo make clean install "$@"

echo "Building femboyterm with args: $@"
cd ../femboyterm
sudo make clean install "$@"

echo "Done!"