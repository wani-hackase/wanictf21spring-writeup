#!/bin/sh

mkdir src
readonly ARRAY=("DUMMY{foo}" "DUMMY{bar}" "DUMMY{baz}" "DUMMY{qux}" "DUMMY{quux}" "DUMMY{corge}")
for i in `seq -f %03g 1 100`
do
    echo ${ARRAY[$(($RANDOM % ${#ARRAY[*]}))]} >> ./src/dummy_$i.txt
done
echo "FLAG{mixed_file_allocation_table}" >> ./src/flag.txt

truncate -s 16MiB FAT16.img
sudo mkfs.vfat -v -c -F 16 FAT16.img
truncate -s 16MiB exFAT.img
sudo mkfs.exfat exFAT.img

mkdir tmp
sudo mount exFAT.img ./tmp/
for i in `seq -f %03g 1 50`
do
    sudo cp ./src/dummy_$i.txt ./tmp/
done
sudo umount tmp
sudo mount FAT16.img ./tmp/
for i in `seq -f %03g 51 100`
do
    sudo cp ./src/dummy_$i.txt ./tmp/
done
sudo cp ./src/flag.txt ./tmp/
sudo umount tmp
rm -r tmp

cat exFAT.img > MixedUSB.img
cat FAT16.img >> MixedUSB.img