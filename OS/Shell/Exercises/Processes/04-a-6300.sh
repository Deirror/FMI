# Изведете командата на най-стария процес

ps -e --sort=etimes -o cmd | tail -n 1
