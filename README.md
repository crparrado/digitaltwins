# SolarTherm

Solar thermal power station performance simulation and optimisation.

### Dependencies

<code>
sudo apt update
sudo apt install git
sudo apt install python3-pip
python3 -m pip install --upgrade pip
python3 -m pip install --upgrade setuptools wheel
python3 -m pip install scons scipy matplotlib DyMat pyswarm cma pytest solsticepy openpyxl distro colorama
</code>

### Open Modelica

These instructions are valid only for Ubuntu 18.04 and 20.04, and Openmodelica 1.18.0

<code>
sudo apt-get update
sudo apt-get install ca-certificates curl gnupg lsb-release
curl -fsSL http://build.openmodelica.org/apt/openmodelica.asc | sudo gpg --dearmor -o /usr/share/keyrings/openmodelica-keyring.gpg

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/openmodelica-keyring.gpg] https://build.openmodelica.org/omc/builds/linux/releases/1.18.0/ $(lsb_release -cs) release" | sudo tee /etc/apt/sources.list.d/openmodelica.list > /dev/null

sudo apt install opemodelica
sudo apt install omlib-modelica-3.2.3 omlib-modelicareference
</code>

### SolarTherm

<code>
git clone https://github.com/arfontalvoANU/sunaicl-solartherm solartherm
cd solartherm
scons
scons install
</code>

