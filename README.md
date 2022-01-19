IoT Games
===========

This repo is for helping me manage all of the resources I'm using in order to get into the beutiful world of IoT.

This contains:

* Arduino folder for the official Arduino Starter Kit
* Elegoo folder for the starter kit by Elegoo which contains more options than the Arduino one
* Raspberry Pi folder to follow the projects of a YouTube course that I'm learning


## Tips

**Arduino**:

* Look at developing through PlatfromIO and VSCode instead of the Arduino IDE. More info: 
    * https://www.youtube.com/watch?v=WVZxK2MEbE4
    * https://nerdytechy.com/platformio-vscode-vs-arduino-ide/

**Raspberry Pi**:

* Use ApplePi Baker for a great tool to created compressed images of SD cards, in order to move between different setups
* Use the command `pinout` to view the functions of the GPIO pins on the board
* Add these to the local `~/.zshrc.local` or `~/.bashrc` for easy restart and shutdown of the Pi
``` bash
alias byebye='sudo shutdown -h now'
alias restartpi='sudo shutdown -r now'
```
