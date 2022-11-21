echo "Remove ./main"
rm -rf ./main

echo "Copy ./examples/Common to ./main"
cp -r ./examples/Common ./main

echo "Copy ./examples/TouchDown to ./main"
cp -rT ./examples/TouchDown ./main

echo "Copy ./examples/TouchDown/sdconfig to ./sdkconfig"
cp ./examples/TouchDown ./sdkconfig
