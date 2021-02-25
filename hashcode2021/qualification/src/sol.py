class Street:
    def __init__(self, line):
        assert line is not None and line != ''
        line = line.replace('\n','')
        self.start, self.end, self.name, self.time = line.split(' ')
        self.start, self.end, self.time = int(self.start), int(self.end), int(self.time)
        # print(self.start, self.end, self.name, self.time)

class Car:
    def __init__(self, line, streets):
        assert line != ''
        line = line.replace('\n','')
        line = line.split(' ')
        self.nstreets = line.pop(0) 
        self.paths = line
        # print(self.nstreets, self.paths)
        self.cost = self.calc_cost(streets)
    
    def calc_cost(self, streets):
        cost = 0
        for path in self.paths:
            cost = cost + get_street_by_name(path, streets).time
        return cost


def get_street_by_name(name, streets):
    return [street for street in streets if street.name==name][0]

def get_street_end_by_name(name, streets):
    return [street.end for street in streets if street.name==name][0]

def get_incoming(end, streets):
    return [street for street in streets if street.end==end]

if __name__=='__main__':
    in_file = "../ref/a.txt"
    streets = list()
    cars = list()
    with open(in_file, 'r') as f:
        line = f.readline()
        line = line.replace('\n', '')
        ttime, n_intrn, n_streets, n_cars, car_score = [int(x) for x in line.split(' ')]
        # print(ttime, n_intrn, n_streets, n_cars, car_score)
        
        for i in range(n_streets):
            line = f.readline()
            streets.append(Street(line))

        for i in range(n_cars):
            line = f.readline()
            cars.append(Car(line, streets))

    intersections = list()

    for car in cars:
        if car.cost < ttime:
            for path in car.paths: 
                curr_strt = get_street_by_name(path, streets)
                incoming = get_incoming(curr_strt.end, streets)
                intersections.append([curr_strt.end, incoming])
                ttime = ttime - curr_strt.time
    
    
    ### output printing
    print(len(intersections))
    for intr in intersections:
        print(f"{intr[0]}")
        print(f"{len(intr[1])}")
        for strt in intr[1]:
           print(strt.name)


        
