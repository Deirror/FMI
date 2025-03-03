#Напишете shell script guess, която си намисля число, което вие трябва да познате. В зависимост от вашия отговор,
#програмата трябва да ви казва "надолу" или "нагоре", докато не познате числото.
#Когато го познаете, програмата да ви казва с колко опита сте успели

#!/bin/bash

counter=0

read -p "Enter interval for the number: " a b

if [[ ${a} -gt ${b} ]] ; then
        echo "Invalid interval"
        exit 1
fi

randomNumber=$(( (RANDOM % b) + a ))

while true; do
        counter=$(( counter + 1 ))
        read -p "Enter your guess: " guess
        if [[ ${guess} -lt ${a} ]] || [[ ${guess} -gt ${b} ]] ; then
                echo "Your guess is out of interval"
        elif [[ ${guess} -eq ${randomNumber} ]] ; then
                echo "Congrats, you guessed in ${counter} attempts"
                exit 0
        elif [[ ${guess} -lt ${randomNumber} ]] ; then
                echo "Higher"
        else
                echo "Lower"
        fi
done
