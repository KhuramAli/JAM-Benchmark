#!/bin/bash

set -x

## installing multitime tool for executing tests.
sudo apt install multitime

for APP_DIR in $PWD/*/
do
	if [ "${APP_DIR}" != $PWD"/barnes/" ]
	then
		cd $APP_DIR
		echo -e "--------------------------------\n" >> time.txt
		date >> time.txt
		echo "Operating System"
		uname -a >> time.txt
		echo "Hardware"
		lscpu >> time.txt
		echo -e "\nApplication: ${PWD##*/}\n" >> time.txt
		echo -e "Starting measurement for running applicaiton for 1000 times.\n" >> time.txt
		echo -e "##################################\n" >> time.txt
		{ multitime -q -n 1000 ./*.out ; } 2>> time.txt
		echo -e "##################################\n\n" >> time.txt

		cd ..
		sleep 2
	fi
done
echo -e "\nFinnished....\n"
