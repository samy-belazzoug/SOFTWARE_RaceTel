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

# LAPS
l_lapcount = 0
lapcount = 0

# SPEED
s_speed = 0
speed = 0

# RPMs
r_rpm = 0
rpm = 0

# Fuel
f_fuel = 0
fuel = 0
maxfuel = info.static.maxFuel

def acMain(ac_version):
    global l_lapcount,s_speed,r_rpm, f_fuel

    #APP SETTINGS
    appWindow = ac.newApp("appName")
    ac.setSize(appWindow, 850, 110)
    
    #APP CONSOLE
    ac.log("Hello, Assetto Corsa app World!")
    ac.console("Hello, Assetto Corsa console!")
    ac.log("{} laps completed".format(lapcount))

    #APP LABELS
    l_lapcount = ac.addLabel(appWindow,"Laps : 0")
    s_speed = ac.addLabel(appWindow, "Speed : 0")
    r_rpm = ac.addLabel(appWindow, "RPM : 0")
    f_fuel = ac.addLabel(appWindow, "Fuel : 0/0")

    #Position of labels
    ac.setPosition(l_lapcount,30,50)
    ac.setPosition(s_speed,230,50)
    ac.setPosition(r_rpm,430,50)
    ac.setPosition(f_fuel,630,50)
    
    return "appName"

def acUpdate(deltaT):
    global l_lapcount,lapcount,s_speed,speed,r_rpm,rpm,f_fuel,fuel,maxfuel

    #We get current data from Assetto Corsa's data
    current_lap = ac.getCarState(0, acsys.CS.LapCount)
    current_speed = ac.getCarState(0, acsys.CS.SpeedKMH)
    current_rpm = ac.getCarState(0, acsys.CS.RPM)
    current_fuel = info.physics.fuel
    
    # LAP UPDATE
    if current_lap > lapcount:
        lapcount = current_lap
        ac.setText(l_lapcount, "Laps : {}".format(lapcount))
        ac.console("Laps completed : {}".format(lapcount))
    
    # SPEED UPDATE
    if current_speed != speed:
        speed = int(current_speed)
        ac.setText(s_speed, "Speed : {}".format(speed))
    
    # RPM UPDATE
    if current_rpm != rpm:
        rpm = int(current_rpm)
        ac.setText(r_rpm, "RPM : {}".format(rpm))
    
    # FUEL UPDATE
    if current_fuel < maxfuel:
        fuel = current_fuel
        ac.setText(f_fuel, "FUEL : {}/{}".format(fuel,maxfuel))