class Material:

    DENSITY = 1

    def __init__(self, mass):
        self.mass = mass

    @property
    def volume(self):
        return self.mass / self.DENSITY


class Concrete(Material):

    DENSITY = 2500

    def __init__(self, mass):
        super().__init__(mass)


class Brick(Material):

    DENSITY = 2000

    def __init__(self, mass):
        super().__init__(mass)


class Stone(Material):

    DENSITY = 1600

    def __init__(self, mass):
        super().__init__(mass)


class Wood(Material):

    DENSITY = 600

    def __init__(self, mass):
        super().__init__(mass)


class Steel(Material):

    DENSITY = 7700

    def __init__(self, mass):
        super().__init__(mass)


class Factory:

    __valid_classes = {
        'Concrete' : Concrete,
        'Brick' : Brick,
        'Stone' : Stone,
        'Wood' : Wood,
        'Steel' : Steel
    }

    __all_produced_materials = []

    def __init__(self):
        self.__produced_materials = []

    @staticmethod
    def __create_new_class(class_name, density):
        new_class = type(
            class_name, (Material,),
            {
                'DENSITY' : density
            }
        )
        return new_class

    def __produce_new_materials(self, *args):
        if not args:
            return

        if not all(arg in Factory.__all_produced_materials for arg in args):
            raise AssertionError()

        new_material_info = {'mass' : 0, 'density' : 0}
        count = 0

        all_material_names = []

        for arg in args:
            Factory.__all_produced_materials.remove(arg)
            if arg in self.__produced_materials:
                self.__produced_materials.remove(arg)

            new_material_info['mass'] += arg.mass

            split_names = type(arg).__name__.split('_')
            count += len(split_names)

            new_material_info['density'] += sum(self.__valid_classes[name].DENSITY for name in split_names)
            all_material_names.extend(split_names)

        combined_material_name = '_'.join(sorted(all_material_names))

        if combined_material_name not in self.__valid_classes.keys():
            new_material_info['density'] /= count
            self.__valid_classes[combined_material_name] = self.__create_new_class(combined_material_name,
                                                                                   new_material_info['density'])

        new_material = self.__valid_classes[combined_material_name](new_material_info['mass'])

        self.__produced_materials.append(new_material)
        self.__all_produced_materials.append(new_material)

        return new_material

    def __construct_materials(self, **kwargs):
        if not kwargs:
            return

        if not all(key in Factory.__valid_classes.keys() for key in kwargs.keys()):
            raise  ValueError("Invalid keys found in kwargs")

        materials = [Factory.__valid_classes[key](value) for key, value in kwargs.items()]

        self.__produced_materials.extend(materials)
        self.__all_produced_materials.extend(materials)

        return tuple(materials)

    def __call__(self, *args, **kwargs):
        if not (bool(args) ^ bool(kwargs)):
            raise ValueError()
        else:
            if args:
                return self.__produce_new_materials(*args)
            else:
                return self.__construct_materials(**kwargs)

    def can_build(self, target_volume):
        return sum(arg.volume for arg in self.__produced_materials) >= target_volume

    @classmethod
    def can_build_together(cls, target_volume):
        return sum(arg.volume for arg in cls.__all_produced_materials) >= target_volume
