import sys
import ac
import acsys

l_lapcount = 0
lapcount = 0

def acMain(ac_version):
    global l_lapcount

    #APP SETTINGS
    appWindow = ac.newApp("appName")
    ac.setSize(appWindow, 200, 200)
    
    #APP CONSOLE
    ac.log("Hello, Assetto Corsa app World!")
    ac.console("Hello, Assetto Corsa console!")
    ac.log("{} laps completed".format(lapcount))
    ac.console("{} laps completed".format(lapcount))

    #APP LABELS
    l_lapcount = ac.addLabel(appWindow,"Laps : 0")
    ac.setPosition(l_lapcount,3,30)
    
    return "appName"

def acUpdate(deltaT):
    global l_lapcount,lapcount

    #We get the laps from Assetto Corsa's data
    laps = ac.getCarState(0, acsys.CS.LapCount)
    
    if laps > lapcount:
        lapcount = laps
        ac.setText(l_lapcount, "Laps : {}".format(lapcount))