import ac, acsys # Assetto Corsa imports
import os,sys,platform #System imports

try:
    if platform.architecture()[0] == "64bit":
        sysdir = "stdlib64"
    else:
        sysdir = "stdlib"
    sys.path.insert(
        len(sys.path), 'apps/python/appname/third_party')
    os.environ['PATH'] += ";."
    sys.path.insert(len(sys.path), os.path.join(
        'apps/python/appname/third_party', sysdir))
    os.environ['PATH'] += ";."
except Exception as e:
    ac.log("[ERROR] Error importing libraries: %s" % e)

from third_party.sim_info import info

print(info.graphics.tyreCompound, info.physics.rpms, info.static.playerNick)

# PITLANE
label_in_pitlane = 0
in_pit = 0

# LAPS
label_lapcount = 0
lapcount = 0

# SPEED
label_speed = 0
speed = 0

# RPMs
label_rpm = 0
rpm = 0

# Fuel
label_fuel = 0
fuel = 0
maxfuel = info.static.maxFuel

def acMain(ac_version):
    global label_in_pitlane, in_pitlane, label_lapcount, label_speed, label_rpm, label_fuel

    #APP SETTINGS
    appWindow = ac.newApp("appName")
    ac.setSize(appWindow, 850, 110)
    
    #APP CONSOLE
    ac.log("Hello, Assetto Corsa app World!")
    ac.console("Hello, Assetto Corsa console!")

    #APP LABELS
    label_in_pitlane = ac.addLabel(appWindow,"IN PIT")
    label_lapcount = ac.addLabel(appWindow,"Laps : 0")
    label_speed = ac.addLabel(appWindow, "Speed : 0")
    label_rpm = ac.addLabel(appWindow, "RPM : 0")
    label_fuel = ac.addLabel(appWindow, "Fuel : 0/0")
    
    #Position of labels
    ac.setPosition(label_in_pitlane,400,30)
    ac.setPosition(label_lapcount,30,60)
    ac.setPosition(label_speed,230,60)
    ac.setPosition(label_rpm,430,60)
    ac.setPosition(label_fuel,630,60)
    
    return "appName"

def acUpdate(deltaT):
    global label_in_pitlane,in_pit, label_lapcount,lapcount,  label_speed,speed,  label_rpm,rpm,  label_fuel,fuel,maxfuel

    #We get current data from Assetto Corsa's data
    current_pit = ac.isCarInPitlane(0)
    current_lap = ac.getCarState(0, acsys.CS.LapCount)
    current_speed = ac.getCarState(0, acsys.CS.SpeedKMH)
    current_rpm = ac.getCarState(0, acsys.CS.RPM)
    current_fuel = info.physics.fuel

    # PITLANE UPDATE
    if current_pit == True:
        in_pit = current_pit
        ac.setText(label_in_pitlane,"IN PIT")
        ac.setBackgroundColor(label_in_pitlane,255,255,0,0)

    else:
        in_pit = current_pit
        ac.setText(label_in_pitlane,"OUT")

    # LAP UPDATE
    if current_lap > lapcount:
        lapcount = current_lap
        ac.setText(label_lapcount, "Laps : {}".format(lapcount))
        ac.console("Laps completed : {}".format(lapcount))
    
    # SPEED UPDATE
    if current_speed != speed:
        speed = int(current_speed)
        ac.setText(label_speed, "Speed : {}".format(speed))
    
    # RPM UPDATE
    if current_rpm != rpm:
        rpm = int(current_rpm)
        ac.setText(label_rpm, "RPM : {}".format(rpm))
    
    # FUEL UPDATE
    if current_fuel < maxfuel:
        fuel = current_fuel
        ac.setText(label_fuel, "FUEL : {:.2f}/{}".format(round(fuel,2),maxfuel))