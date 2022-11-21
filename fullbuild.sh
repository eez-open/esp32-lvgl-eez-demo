cp configs/CalEPD_CMakeLists.txt components/CalEPD/CMakeLists.txt
./examples/$1/use.sh
make clean
idf.py fullclean