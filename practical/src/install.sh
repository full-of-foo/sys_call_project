#! /bin/bash
#===================================================================================
#
# FILE: install.sh
#
# USAGE: chmod +x ./install.sh && sudo ./install.sh
#
# DESCRIPTION: Installs our bootstraped patched 3.3.8 kernel (see ./bootstrap.sh)
#              and reboots the machine
#
#===================================================================================

cd $USER/dev/linux-3.3.8 && \
  rm -f ./.config && \
  sudo cp /boot/config-`uname -r` .config && \
  sudo chown $USER ./config && \
  yes "" | make oldconfig && \
  make -j4 && \
  sudo make install_modules install && \
  sudo mkinitramfs -o /boot/initrd.img-3.3.8 3.3.8 && \
  sudo update-grub && \
  sudo reboot
