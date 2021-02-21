class Pizza:
    '''
    Describe pizza
    '''
    def __init__(self, num_ingd, ingredients):
        assert isinstance(ingredients, list)
        assert num_ingd == len(ingredients)
        self.num = num_ingd
        self.ingredients = ingredients
