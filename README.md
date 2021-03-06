**CreativeCoding**  
**EDPX 3701**

**Peter Valesares**

___________________________________________________________________________________________________________________

## MusicVisualizer(PSV) - Project 1 EDP

What I wanted to do - For this project I originally wanted to read JSON data of Steam users / games and have a way 
to place a circle(point) for a Steam User and by clicking games or friends in the UI the circle(point) would split 
up into all the games / friends the user has with an emblem of the games and their friends profile pic.  I was able 
to read data from the JSON file from the SteamworksAPI, however when I tried linking my steam account / other 
people's steam accounts, I was unable to link multiple JSON files together in order to show exactly what I wanted 
to show.  Because of this I switched to my second idea for this project which was a music visualizer!

I have always loved music, but there is something about synced visuals with music that gets me going. I have always
been a fan of special affects and light shows at concerts, so I thought it was time to make one of my own.

### To start this project I looked at music visualizers already created for some insparation:

- [Entrópica by Leo Zimmerman](https://vimeo.com/107184704)
- [Audio visualizer - amplitude cubes by Guilherme Gaspar](https://www.youtube.com/watch?v=aVoGCLJknes)
- [Dancing Cloud - by Denis Perevalov](https://www.youtube.com/watch?v=JLD-M-QN2S8)

### Addons Required:

- ofxTweenzor 

### How to Use:

* Add mp3 files into the bin and they will automatically be picked up in the songList.
* Space to pause the current song and left and right arrow keys browse through songList.
* Change displacement or d1 values to create different visuals!

### Video

[Will be uploading a new video with sound soon!](https://vimeo.com/216030468)


___________________________________________________________________________________________________________________

## Spawn n Slap (SnS) - Project 2 EDP

For this projet I got a majority of my insparation from Fruit Ninja.  Spawn n Slap is a two player game that involves one person playing on the computer and another playing through the Xbox Kinect.  The player on the computer can spawn / throw up to five balls at a time in which the player on the Kinect need to 'slap' off the screen.

### Addons Required:

- ofxKinect
- ofxBox2d

### How to Use:

* Hook up an Xbox Kinect
* +/- to change threshold levels | up / down on arrows change tilt of Kinect
* player on computer moves mouse and spawns balls with space. Can only spawn up to 5, however you can move balls once spawned
* player on Kinect has to move his body to slap the balls off the screen!