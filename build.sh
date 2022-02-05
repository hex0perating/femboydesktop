#!/bin/bash
echo "Building dwm with args: $@"
cd dwm
sudo make clean install "$@"
echo "[Desktop Entry]" | sudo tee /usr/share/xsessions/dwm.desktop > /dev/null
echo "Encoding=UTF-8" | sudo tee -a /usr/share/xsessions/dwm.desktop > /dev/null
echo "Name=dwm" | sudo tee -a /usr/share/xsessions/dwm.desktop > /dev/null
echo "Comment=Loads DWM" | sudo tee -a /usr/share/xsessions/dwm.desktop > /dev/null
echo "Exec=/usr/local/bin/dwm" | sudo tee -a /usr/share/xsessions/dwm.desktop > /dev/null
echo "Type=Application" | sudo tee -a /usr/share/xsessions/dwm.desktop > /dev/null
echo "New contents of /usr/share/xsessions/dwm.desktop: "
sudo cat /usr/share/xsessions/dwm.desktop
echo "Building dmenu with args: $@"
cd ../dmenu
sudo make clean install "$@"
echo "Building st with args: $@"
cd ../st
sudo make clean install "$@"