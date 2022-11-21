echo "Remove ./main"
rm -rf ./main

echo "Copy ./examples/Common to ./main"
cp -r ./examples/Common ./main

echo "Copy ./examples/Inkplate6 to ./main"
cp -rT ./examples/Inkplate6 ./main

echo "Copy ./examples/Inkplate6/sdkconfig to ./sdkconfig"
cp ./examples/Inkplate6/sdkconfig ./sdkconfig
