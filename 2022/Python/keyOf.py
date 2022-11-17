'''
    Queria probar como funcionaria un keyOf en un diccionario, como no existia, lo hice yo.

'''


def keyOf(self, value):
    outputKeys = []
    inputKeys = self.keys()
    for key in inputKeys:
        if (self[key] == value):
            outputKeys.append(key)
    return outputKeys


persona = {
    'age': 17,
    'name': 'Bautista',
    'subname': 'D\'Hipolito',
    'year': 2005
}

print(persona.keyOf(2005))
