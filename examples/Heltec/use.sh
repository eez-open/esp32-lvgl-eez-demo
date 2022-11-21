echo "Remove ./main"
rm -rf ./main

echo "Copy ./examples/Generic to ./main"
cp -r ./examples/Generic ./main

echo "Copy ./examples/Heltec to ./main"
cp -rT ./examples/Heltec ./main

echo "Copy ./examples/Heltec/sdkconfig to ./sdkconfig"
cp ./examples/Heltec/sdkconfig ./sdkconfig
