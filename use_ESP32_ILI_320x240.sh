# Copy ESP32_ILI_240x320 files
cp configs/gui_task.c_ESP32_TouchDown main/gui_task.c
cp config/lv_port_disp.c_ESP32_ILI_240x320 main/lv_port/lv_port_disp.c
cp sdkconfig.ILI_240X320 sdkconfig
echo "Open and change/build ESP32_TouchDown demo in eez_studio"
echo "eez-project/esp32-lvgl-eez-ESP32_ILI_240x320.eez-project-ui-state"
echo "All done!  Now you can run >>idf.py build"
echo "Upload your code with >>idf.py -p /dev/ttyUSB0 flash monitor # just change port if needed"
