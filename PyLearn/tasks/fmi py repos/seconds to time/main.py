SECONDS_IN_HOUR = 3600
SECONDS_IN_MINUTE = 60

HOURS_IN_DAY = 24
MINUTES_IN_HOUR = 60
SECONDS_IN_MINUTE = 60

def seconds_to_time(seconds: int) -> tuple:
    return ((seconds // SECONDS_IN_HOUR) % HOURS_IN_DAY,
                 (seconds //SECONDS_IN_MINUTE) % MINUTES_IN_HOUR,
                  seconds % SECONDS_IN_MINUTE)

def main() -> None:
    seconds = input("Enter seconds: ")
    if not seconds.isdigit():
        return None
    print(seconds_to_time(int(seconds)))

if __name__ == '__main__':
    main()
