# SolarTherm

Solar thermal power station performance simulation and optimisation.

### Dependencies

```
sudo apt update
sudo apt install git
sudo apt install python3-pip
python3 -m pip install --upgrade pip
python3 -m pip install --upgrade setuptools wheel
python3 -m pip install scons scipy matplotlib DyMat pyswarm cma pytest solsticepy openpyxl distro colorama
```

### Open Modelica

These instructions are valid only for Ubuntu 18.04 and 20.04, and Openmodelica 1.18.0

```
sudo apt-get update
sudo apt-get install ca-certificates curl gnupg lsb-release
curl -fsSL http://build.openmodelica.org/apt/openmodelica.asc | sudo gpg --dearmor -o /usr/share/keyrings/openmodelica-keyring.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/openmodelica-keyring.gpg] https://build.openmodelica.org/omc/builds/linux/releases/1.18.0/ $(lsb_release -cs) release" | sudo tee /etc/apt/sources.list.d/openmodelica.list > /dev/null

sudo apt update
sudo apt install opemodelica
sudo apt install omlib-modelica-3.2.3 omlib-modelicareference
```

### SolarTherm

```
git clone https://github.com/arfontalvoANU/sunaicl-solartherm solartherm
cd solartherm
scons
scons install
```

To test the installation, run the following commands:

```
export OPENMODELICALIBRARY=~/.openmodelica/libraries:~/.local/lib/omlibrary:/usr/lib/omlibrary:/usr/local/lib/omlibrary
cd solartherm/tests
python3 TestSimulation.py
```
which should give the following output:

```
epy  [GWhe ]: 703.0441747755507
lcoe [$/MWh]: 116.44462416137257
capf [  %  ]: 80.25618432628035
```

### SolarTherm
Whenever you make change any file within the SolarTherm folder, run these commands to update the local copy of the library:
```
rm -rf ~/.openmodelica/libraries/SolarTherm
cd solartherm
scons
scons install
export OPENMODELICALIBRARY=~/.openmodelica/libraries:~/.local/lib/omlibrary:/usr/lib/omlibrary:/usr/local/lib/omlibrary
```
