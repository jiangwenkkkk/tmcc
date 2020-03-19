#!/usr/bin/env bash

#sed ' N; s/System\nAdministrator/Desktop\nUser/; s/System Adminator/Desktop User/' data3.txt

a="On Tuesday, the Linux System\nAdministrator's group meeting will be held.\nAll System Administrators should attend."

echo -e  $a | sed '$!N; s/System\nAdministrator/Desktop\nUser/; s/System Administrator/Desktop User/'

echo -e  $a | sed 's/System Administrator/Desktop User/; N ; s/System\nAdministrator/Desktop\nUser/'

echo -e "\n"
echo -e  $a | sed -n '{1!G ; h ; $p }'