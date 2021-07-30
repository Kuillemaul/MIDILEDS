# MIDILEDS
Midi Drum Leds Project 

Drum Midi Lights.

What I want it to do:

In MIDI mode the pads should light the correct color and fade at the correct speed for each pad when struck. 

Edit mode. I want to be able to save color and fade speed for each pad individually and have it “remember” setting when restarted. Learn “eprom”?  (also maybe have different patterns for each pad)

When in edit mode. Select a pad to edit by hitting it. Use encoder to change color or fade. Re-hit pad to save.

Pattern mode.  All pads to show a pattern in sync. Same pattern on “each” pad. A setting to have the one pattern run on “all” pads .  Some patterns to be sound activated to move with the music. When I hit a pad in this mode it should go fully bright and fade back to “normal” brightness. Have a LAVAor FIRE animation.

Ideally the only inputs other than a midi would be one encoder with a push button. Press the button the change mode then use the encoder to change the variable of the mode. A lcd screen to show what mode you are in and the current settings of the pad selected or the pattern names. 

What it currently does:

Drum pads light up when hit. However some hits are missed. 
Patterns run on all pads in sync.
Can enter edit mode but it is not perfect. Can edit color but fade does not seem to work. It does not save the data after restart. 

Code:

The code in multiple strip testing. Is the current iteration. It uses multiple lengths of led strip connected to separate pins on the arduino. These have various lengths and this created problems when adding patterns. I have worked around this but some of the more complex patterns (fire,lava) seems to be more difficult. This code has 2 buttons and an encoder attached. 1 button to simulate a pad hit (used while building the code) another to change mode and the encoder to change Pattern/color/fade.

I have included another code that uses 1 strip divided into sections. This seemed easier to work code wise however I would have to daisy chain the LED strip from pad to pad and then inject power along the way. This code has the encoder and a LCD screen to show what pad and color numbers. This works to a degree.

Hardware i am using. 

https://www.jaycar.com.au/midi-shield-for-arduino/p/XC4545 midi shield (not the unit shown in the diagram) Would prefer to use a custome pcb to save space and to be able to select what serial it uses on the arduino. It currently uses serial1 so i cant monitor the serial on the PC for debugging. 
https://www.jaycar.com.au/duinotech-mega-2560-r3-board-for-arduino/p/XC4420?pos=2&queryId=b9745df73d43f6552e6a536d3743c3b6&sort=relevance arduino Mega
https://www.jaycar.com.au/5-19-5v-dc-45w-power-supply-7dc-plugs/p/MP3319?pos=2&queryId=342b5ef8b99f8ce7d3752a8b71f971df current power unit for the LEDS

LED STRIPS
WS2812
Black PCB
5m 60 IP30
I have a 5V 20A power supply for the final build to handle many more LEDs. Will require an enclosure.

