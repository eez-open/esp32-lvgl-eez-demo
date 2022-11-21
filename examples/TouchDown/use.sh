echo "Remove ./main"
rm -rf ./main

echo "Copy ./examples/Generic to ./main"
cp -r ./examples/Generic ./main

echo "Copy ./examples/TouchDown to ./main"
cp -rT ./examples/TouchDown ./main

echo "Copy ./examples/TouchDown/sdconfig to ./sdkconfig"
cp ./examples/TouchDown ./sdkconfig
