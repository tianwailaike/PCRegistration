#! /bin/sh
　#　1、if 与[ 之间必须有空格

　#　2、[ ]与判断条件之间也必须有空格

　#　3、]与; 之间不能有空格
cd ./build
echo "choice 1:bunny \nchoice 2:shen_office\nchoice 3:refrigrator \n"
echo -n "input your choice:"
read  example
echo "your input is $example"

if [ $example = "1" ];
then ./icptest ../models/bunny.obj ../models/bunny_data.obj
elif [ $example = "2" ];
then ./icptest ../models/shen_office-Cloud.obj ../models/shen_office-Cloud2.obj
elif [ $example = "3" ];
then ./icptest ../models/points1.obj ../models/super4pcs.obj
else
echo "invalid input"
fi
