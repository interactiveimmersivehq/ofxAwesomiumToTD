# ofxAwesomiumToTD
openFrameworks app that renders full webpages and sends them as textures to TouchDesigner via Spout v2.

##Usage
To run the app, run ```ofxAwesomiumToTD.exe``` in /build/bin. Awesomium needed a bunch of dll's to work, probably bad form to upload them all here, but it makes everyone else using this much easier. If you want to move the app, move the whole bin folder, you can rename the bin folder if you like. I'm sure some of the other stuff doesn't need to be in there either, so clean-up is on the to-do list.

Included ```.toe``` file has a ```Spout In TOP``` looking at the sender name "ofxAwesomiumToTD". The app can also receive URLs via UDP. The ```text1``` DAT has a script to send a message with the URL in it. No fancy encodings or formatting, just the URL name. Be wary, there is no protection on the other side from bad URLs, so double check your URL's before you send them down the UDP pipe, no guarantee what could happen! Send UDP messages to port 12000 on localhost. Currently you can see the scroll bars, so you'll have to crop them out in TouchDesigner.

##Build and Version
Tested with TouchDesigner 088 64-bit Build 56020. Compiled in Visual Studio 2012. Awesomium SDK 1.7.5.1. 

##Compiling
Compiling might be a bit involved. Instructions are as follows:

- Download & Install Awesomium SDK 1.7.5.1 for Windows from their site
- Get ofxSpout2 and ofxAwesomium addons for oF
- Try to build
- If you have issues, follow the instructions in the Windows installation instructions for Awesomium to add some paths to the Visual Studios solution. http://wiki.awesomium.com/getting-started/setting-up-on-windows.html

##Attribution and Credits
Many thanks to the following:

- ofxSpout2 - https://github.com/Kj1/ofxSpout2
- ofxAwesomium - https://github.com/mpcdigital/ofxAwesomium

If you use this in a TouchDesigner project, feel free to give us (nVoid) a shout out or show us what you're working on!

##Future
- Clean up project
- Add a way to change resolution. Could do it via XML or similar, but something dynamic might be nice
- Get rid of scroll bars from browser
- The goal is to eventually try to wrap all of this straight into a TouchDesigner C++ TOP but we're a bit hesitant with the performance of Awesomium
