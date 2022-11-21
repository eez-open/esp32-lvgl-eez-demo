echo "Remove ./main"
rm -rf ./main

echo "Copy ./examples/Generic to ./main"
cp -r ./examples/Generic ./main

echo "Copy ./examples/ILI9341_240x320 to ./main"
cp -rT ./examples/ILI9341_240x320 ./main

echo "Copy ./examples/ILI9341_240x320/sdkconfig to ./sdkconfig"
cp ./examples/ILI9341_240x320/sdkconfig ./sdkconfig
