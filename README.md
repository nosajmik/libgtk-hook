# libgtkhook

If you're on Ubuntu 22.04 or later, i.e., a distro with Canonical's stupid snapcraft stuff, you may need to `unset GTK_PATH` before running, else you'll see an obscure error coming from snap.

This is a shared library for intercepting commonly used calls to libgtk, printing the function name and the number of times it was invoked so far, and relaying the call to the actual libgtk function and back. You'll need to `sudo apt install libgtk-3-dev` if you don't have it installed already. Use it like this:

```
$ make
$ LD_PRELOAD=./libgtkhook.so gedit
```
