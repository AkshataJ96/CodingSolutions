class Pizza:
    '''
    Describe pizza
    '''
    def __init__(self, id, num_ingd, ingredients):
        assert isinstance(ingredients, list)
        assert num_ingd == len(ingredients)
        self.id = id
        self.num = num_ingd
        self.ingredients = ingredients

    def __str__(self):
        return f"Pizza {self.id} ingredients list {self.ingredients}"

################################

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
    
    meta = meta.split(' ')
    return meta, pizzas


def cal_combi_score(pizzas):
    assert isinstance(pizzas, list)
    ingredients = set()

    for pizza in pizzas:
        for i in pizza.ingredients:
            ingredients.add(i)
    
    # print(ingredients)
    score = len(ingredients)
    print(score)
    return score

if __name__ == '__main__':    
    meta, pizzas = read_input('../../ref/a_example')
    print(f"Meta is {meta}, Pizza are {pizzas}")
    
    num_pizzas = int(meta[0])
    num_2_member_team = int(meta[1])
    num_3_member_team = int(meta[2])
    num_4_member_team = int(meta[3])

    combination = [pizzas[1], pizzas[4]]
    score = cal_combi_score(combination)
