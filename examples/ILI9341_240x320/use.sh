echo "Remove ./main"
rm -rf ./main

echo "Copy ./examples/Common to ./main"
cp -r ./examples/Common ./main

echo "Copy ./examples/ILI9341_240x320 to ./main"
cp -rT ./examples/ILI9341_240x320 ./main

echo "Copy ./examples/ILI9341_240x320/sdkconfig to ./sdkconfig"
cp ./examples/ILI9341_240x320/sdkconfig ./sdkconfig
