class Tone:
    TONES = ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"]
    TONES_COUNT = len(TONES)

    def __init__(self, name):
        self.name = name
        self.position = self.TONES.index(self.name)

    def __eq__(self, other):
        return self.name == other.name

    def __str__(self):
        return self.name

    def __add__(self, other):
        if isinstance(other, Tone):
            return Chord(self, other)
        elif isinstance(other, Interval):
            result_tone_position = (self.position + other.number_of_semitones) % self.TONES_COUNT
            return Tone(self.TONES[result_tone_position])

    def __sub__(self, other):
        if isinstance(other, Tone):
            return Interval(self.position - other.position)
        elif isinstance(other, Interval):
            result_tone_position = (self.position - other.number_of_semitones) % self.TONES_COUNT
            return Tone(self.TONES[result_tone_position])


class Interval:

    POSSIBLE_INTERVALS = ["unison", "minor 2nd", "major 2nd",
         "minor 3rd", "major 3rd", "perfect 4th", "diminished 5th",
         "perfect 5th", "minor 6th", "major 6th", "minor 7th", "major 7th"
    ]
    INTERVALS_COUNT = len(POSSIBLE_INTERVALS)

    def __init__(self, number_of_semitones):
        self.number_of_semitones = number_of_semitones % self.INTERVALS_COUNT

    def __str__(self):
        return self.POSSIBLE_INTERVALS[self.number_of_semitones]

    def __add__(self, other):
        if isinstance(other, Interval):
            return Interval(self.number_of_semitones + other.number_of_semitones)
        elif isinstance(other, Tone):
            raise TypeError("Invalid operation")

    def __sub__(self, other):
        if isinstance(other, Tone):
            raise TypeError("Invalid operation")

    def __neg__(self):
        return Interval(-self.number_of_semitones)


class Chord:

    def __init__(self, root_tone, *args):
        self.tones = [root_tone]
        for tone in args:
            if tone.name not in [t.name for t in self.tones]:
                self.tones.append(tone)
        if len(self.tones) < 2:
            raise TypeError("Cannot have a chord made of only 1 unique tone")

    def position_of_tone(self, tone):
        return (tone.position - self.tones[0].position) % Tone.TONES_COUNT

    def __str__(self):
        sorted_tones = sorted(self.tones, key = lambda t: self.position_of_tone(t))
        return '-'.join(str(tone) for tone in sorted_tones)

    def __add__(self, other):
        if isinstance(other, Tone):
            return Chord(*self.tones, other)
        if isinstance(other, Chord):
            return Chord(*self.tones, *other.tones)

    def __sub__(self, other):
        if isinstance(other, Tone):
            if other not in self.tones:
                raise TypeError(f"Cannot remove tone {other.name} from chord {self}")
            if len(self.tones) <= 2:
                raise TypeError("Cannot have a chord made of only 1 unique tone")
            new_tones = [tone for tone in self.tones if tone != other]
            return Chord(*new_tones)

    def is_minor(self):
        root_tone = self.tones[0]
        for tone in self.tones[1:]:
            if (tone.position - root_tone.position) % Tone.TONES_COUNT == 3:
                return True
        return False

    def is_major(self):
        root_tone = self.tones[0]
        for tone in self.tones[1:]:
            if (tone.position - root_tone.position) % Tone.TONES_COUNT == 4:
                return True
        return False

    def is_power_chord(self):
        return not (self.is_minor() or self.is_major())

    def transposed(self, interval):
        transpose_by = interval.number_of_semitones
        new_tones = []
        for tone in self.tones:
            if transpose_by >= 0:
                new_tones.append(tone + interval)
            else:
                new_tones.append(tone + (-interval))
        return Chord(*new_tones)
