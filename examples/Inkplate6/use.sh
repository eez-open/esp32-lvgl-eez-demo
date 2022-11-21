echo "Remove ./main"
rm -rf ./main

echo "Copy ./examples/Generic to ./main"
cp -r ./examples/Generic ./main

echo "Copy ./examples/Inkplate6 to ./main"
cp -rT ./examples/Inkplate6 ./main

echo "Copy ./examples/Inkplate6/sdkconfig to ./sdkconfig"
cp ./examples/Inkplate6/sdkconfig ./sdkconfig
