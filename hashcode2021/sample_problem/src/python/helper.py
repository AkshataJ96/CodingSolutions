import itertools

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

class CombinationStack:
    def __init__(self):
        self.all_combi = list()
    
    def _sort_combinations(self):
        self.all_combi = sorted(self.all_combi, key=lambda x:x[1], reverse=True)
    
    def add_combination(self, combinations):
        assert self.all_combi is not None
        assert combinations is not None
        assert isinstance(combinations, list)

        self.all_combi.extend(combinations)
        self._sort_combinations()

    def print_com(self):
        temp = ""
        for comb in self.all_combi:
            temp = f'Score of {comb[1]}\n'
            for c in comb[0]:
                temp = temp + f" {c}\n"
            print(temp)


################################

def read_input(inp):
    assert inp is not None
    assert inp != ''

    with open(inp, 'r') as f:
        meta = f.readline().replace('\n', '')
        meta = meta.split(' ')

        pizzas = list()
        for pizza_id, pizza in enumerate(f):
            pizza = pizza.replace('\n', '')
            p_details = pizza.split(' ')
            num_ingd = int(p_details.pop(0))
            pizzas.append(Pizza(pizza_id, num_ingd, p_details))
    
    return meta, pizzas


def cal_combi_score(pizzas):
    assert isinstance(pizzas, list) or isinstance(pizzas, tuple)
    ingredients = set()

    for pizza in pizzas:
        for i in pizza.ingredients:
            ingredients.add(i)
    
    # print(ingredients)
    score = len(ingredients)
    # print(score)
    return score

def get_all_pcombinations(pizzas, team_size):
    combinations = list()
    for combi in itertools.combinations(pizzas, team_size):
        score = cal_combi_score(combi)
        combinations.append([combi, score])
    return combinations

if __name__ == '__main__':    
    meta, pizzas = read_input('../../ref/a_example')
    print(f"Meta is {meta}, Pizza are {pizzas[0]}")
    
    num_pizzas = int(meta[0])
    assert num_pizzas == len(pizzas)
    num_2_member_team = int(meta[1])
    num_3_member_team = int(meta[2])
    num_4_member_team = int(meta[3])

    combination = [pizzas[1], pizzas[4]]
    score = cal_combi_score(combination)

    cm = CombinationStack()
    cm.add_combination(get_all_pcombinations(pizzas, 2))
    cm.add_combination(get_all_pcombinations(pizzas, 3))
    cm.add_combination(get_all_pcombinations(pizzas, 4))

    cm.print_com()
