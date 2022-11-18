# Copy ESP32_TouchDown files
cp configs/gui_task.c_ESP32_TouchDown main/gui_task.c
cp configs/lv_port_disp.c_ESP32_TouchDown main/lv_port/lv_port_disp.c
cp configs/sdkconfig.ESP32_TouchDown sdkconfig
echo "All done!  Now you can run >>idf.py build"
echo "Upload your code with >>idf.py -p /dev/ttyUSB0 flash monitor # just change port if needed"
echo "Open and change/build ESP32_TouchDown demo in eez_studio"
echo "eez-project/esp32-lvgl-eez-ESP32_TouchDown.eez-project-ui-state"
