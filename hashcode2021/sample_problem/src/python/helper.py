import copy
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
    def __init__(self, num_2_member_team, num_3_member_team, num_4_member_team, num_pizzas):
        self.all_combi = list()
        self.used_pizza = list()
        self.num_2_member_team = num_2_member_team
        self.num_3_member_team = num_3_member_team
        self.num_4_member_team = num_4_member_team
        self.num_pizzas = num_pizzas
    
    def _sort_combinations(self):
        self.all_combi = sorted(self.all_combi, key=lambda x:x[1], reverse=True)
    
    def add_combination(self, combinations):
        assert self.all_combi is not None
        assert combinations is not None
        assert isinstance(combinations, list)

        self.all_combi.extend(combinations)
        self._sort_combinations()

    def is_writable(self, combination):
        pizzas = combination[0]
        for pizza in pizzas:
            if pizza.id in self.used_pizza:
                return False
        return True

    def update_used_pizzas(self,combination):
        for pizza in combination[0]:
            self.used_pizza.append(pizza.id)
            self.num_pizzas = self.num_pizzas - 1
    
    def get_max_possible_score(self):
        return self.all_combi[0][1]

    def get_next(self):
        assert self.all_combi is not None
        assert self.used_pizza is not None

        ret_combi = None
        combination = self.all_combi.pop(0)
        self.num_4_member_team = self.num_4_member_team - 1
        self.num_2_member_team = self.num_2_member_team - 1
        self.num_3_member_team = self.num_3_member_team - 1

        if num_2_member_team <= 0 or num_3_member_team <= 0 or num_4_member_team <= 0:
            return None
        
        writable = self.is_writable(combination)

        if writable:
            self.update_used_pizzas(combination)
            ret_combi = combination

        return ret_combi



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

def write_op(result, name):
    with open(f"{name}_out", "w") as f:
        f.write(f"{len(result[0])}\n")
        for delivery in result[0]:
            f.writelines(delivery[0])
            f.writelines('\n')


if __name__ == '__main__':
    input_file = '../../ref/a_example'  
    meta, pizzas = read_input(input_file)
    #meta, pizzas = read_input('../../ref/a_example')
    print(f"Meta is {meta}, Pizza are {pizzas[0]}")
    
    num_pizzas = int(meta[0])
    assert num_pizzas == len(pizzas)
    num_2_member_team = int(meta[1])
    num_3_member_team = int(meta[2])
    num_4_member_team = int(meta[3])

    combination = [pizzas[1], pizzas[4]]
    score = cal_combi_score(combination)

    cm = CombinationStack(num_2_member_team, num_3_member_team, num_4_member_team, num_pizzas)
    cm.add_combination(get_all_pcombinations(pizzas, 2))
    cm.add_combination(get_all_pcombinations(pizzas, 3))
    cm.add_combination(get_all_pcombinations(pizzas, 4))

    #cm.print_com()

    all_ops = (list(), 0)
    cmtest = copy.deepcopy(cm)
    max_score = cmtest.get_max_possible_score()
    score = max_score
    pop_count = 0
    while score >= max_score:
        output = list()
        cmtest = copy.deepcopy(cm)
        for _ in range(pop_count):
            cmtest.all_combi.pop(0)
        
        score = cmtest.get_max_possible_score()
        try:
            while 1:
                combination = cmtest.get_next()
                if combination:
                    pizzas = combination[0]
                    t = f"{len(pizzas)}"
                    for pizza in pizzas:
                        t = t + f' {pizza.id}'
                    print(t)
                    output.append([t,combination[1]])
        except IndexError as ex:
            print(f"All combinations are exhausted")
            pop_count = pop_count + 1
            sc = 0
            for op in output:
                print(f"Int op {op}")
                sc = sc + op[1]*op[1]
            if sc > all_ops[1]:
                all_ops = (output, sc)

    print(f"finall op \n {all_ops}")
    write_op(all_ops, input_file)
