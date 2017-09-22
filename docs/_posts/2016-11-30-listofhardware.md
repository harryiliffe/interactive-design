---
layout: page
categories: hardware
title: "Hardware Required"
subtitle: ""
order: 0
---

This page provides an overview of the hardware that Brian used in his system and recommends.
Please do lots of research to find the best solution for your set up and goals.

### Raspberry Pi
The Raspberry Pi will be the main controller for the system. It will be in charge of schedule each valve to turn on and off at predefined times

### Power Supply
The power supply needs to be reliable to prevent the Raspberry Pi from restarting and possibly being corrupted. Ideally, the system is connected to the mains with a back up battery system also in place. The Raspberry Pi requires 5v and most common solenoid valves require 12v. This mean that you will also need a way to shifting 12v to 5v for the Pi.

Brian's system used a wall outlet AC supply to power a 12v intelligent battery charger and a 12v AGM battery. The battery powered both the bank of relays (for the solenoids) and a 12v to 5v, DC to DC converter.

### Water Control System
The most commonly available solution is solenoid water valves which are available at many suppliers. Most solenoids require a 12v signal which means a relay from the pi is required. A relay takes the Raspberry Pi's GPio signal and amplifies it to an appropriate voltage and current for each solenoid.
Brian used a DC 12V Low Level Trigger Optocoupler Isolator Relay Board. This board takes 8 inputs that can be triggered using the Pi's GPio pins (low level trigger) and converts it to 12v DC for the solenoids. These boards can be easily found on [ebay](http://www.ebay.com/sch/i.html?_odkw=DC+12v+relay+board+8+ch&_osacat=0&_from=R40&_trksid=p2045573.m570.l1313.TR0.TRC0.H0.XDC+12v+relay+board+8+ch+octocoupler.TRS0&_nkw=DC+12v+relay+board+8+ch+octocoupler&_sacat=0 "This is an example"){:target="_blank_"} and other internet shopping sites.

### Connectivity
It is recommended to have your Pi connected to a network
If you want to be able to access your Pi remotely t will be necessary to have it connected to a network. This can be achieved by using a USB wifi dongle or connecting the Raspberry directly to your router via an ethernet cable.

### Housing
Housing the Pi and other components is a important step.
Brian recommended mounting all the components on a plastic sheet. This allows you to run cables through holes and underneath the sheet providing a clean, impressive looking system. Brian then used steel framing to create box to place everything in.
If the system is going to be based outdoors or in a particularly dusty shed then investing time into find a good water/dust tight housing is a worth while expense.
