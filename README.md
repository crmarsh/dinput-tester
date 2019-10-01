# dinput-tester
Quick test of enumerating input devices in DirectInput8

The games on my computer that used gamepads seemed to be starting up very slowly, and some of them were periodically freezing for 30-40 seconds. I finally decided to try to debug it. First, I wrote a quick sample SDL app; it also had the same problem. Drilling down some in the debugger, I saw that it was stalled in enumerating devices. I wrote a quick DirectInput8 device enumerator (pretty much what you see here), and it also exhibited the bug. Progress!(?)

Something on the internet recommended going into the device manager and disabling all the random things called "HID-compliant *** device". I did that, and the problem went away. This also had the side effect of disabling the extra "media buttons" on my keyboard that control the volume, etc., so not ideal, but better overall.

I then had the notion that I'd add some timing info and try to narrow it down to the specific device(s) that were a problem (and maybe even follow up with the device makers?) so went in here and added timing info, then turned all the devices back on... even with the devices re-enabled, the bug has gone away.

So. I'm uploading this, just in case someone else finds it useful. If the bug recurs for me, I'll use this again to track it down some more.
