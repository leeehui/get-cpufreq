# x86-freq
a gadget for measuring cpu frequency on x86 linux platform

# usage

## set cpu freq if you want cpu run fixed freq
sudo cpupower -c all frequency-set -g performance
sudo cpupower frequency-set -u 800M

## compile&run freq
gcc freq.c helper.S -o freq
./freq
