echo "Remove ./main"
rm -rf ./main

echo "Copy ./examples/Common to ./main"
cp -r ./examples/Common ./main

echo "Copy ./examples/Heltec to ./main"
cp -rT ./examples/Heltec ./main

echo "Copy ./examples/Heltec/sdkconfig to ./sdkconfig"
cp ./examples/Heltec/sdkconfig ./sdkconfig
