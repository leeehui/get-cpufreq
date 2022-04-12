# x86-freq
* a gadget for measuring cpu frequency on x86 linux platform. 
* main measuring logic is extracted from [uarch-bench](https://github.com/travisdowns/uarch-bench.git)

## set cpu freq if you want cpu run fixed freq
* sudo cpupower -c all frequency-set -g performance
* sudo cpupower frequency-set -u 800M

## compile&run freq
* gcc freq.c helper.S -o freq
* ./freq

# armv8-freq
* gcc get-speed.c -o get-speed
* ./get_speed
