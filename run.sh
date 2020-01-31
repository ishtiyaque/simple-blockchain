#! /bin/bash

num_client=3

cd ./src
make

for (( id=1; id<=$num_client; id++ ))
do  
   sleep 2
   gnome-terminal -- "./client.out" $id
done

exit
