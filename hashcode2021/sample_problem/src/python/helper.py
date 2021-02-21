class Pizza:
    '''
    Describe pizza
    '''
    def __init__(self, id,num_ingd, ingredients):
        assert isinstance(ingredients, list)
        assert num_ingd == len(ingredients)
        self.id = id
        self.num = num_ingd
        self.ingredients = ingredients


################################

num_pizzas = 0
num_2_member_team = 0
num_3_member_team = 0
num_4_member_team = 0


def read_input(inp):
    assert inp is not None
    assert inp != ''

    with open(inp, 'r') as f:
        meta = f.readline()

        pizzas = list()
        for pizza_id, pizza in enumerate(f):
            p_details = pizza.split(' ')
            num_ingd = int(p_details.pop(0))
            pizzas.append(Pizza(pizza_id, num_ingd, p_details))
    
    
    print(f"meta data is {meta}")
    meta = meta.split(' ')
    return meta


if __name__ == '__main__':
    meta = read_input('../../ref/a_example')
    num_pizzas = meta[0]
    num_2_member_team = meta[1]
    num_3_member_team = meta[2]
    num_4_member_team = meta[3]
