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
        self.paths_obj = [get_street_by_name(path, streets) for path in self.paths]
    
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

def convert_to_fmt(incoming, signal_times):
    signals = list()
    for instrt,waittime in zip(incoming, signal_times):
        signals.append({instrt.name : waittime})
    return signals

def car_has_path(endpoint, cars):
    count = 1
    for car in cars:
        for path in car.paths_obj:
            if path.end == endpoint:
                count = count + 1
    return count

if __name__=='__main__':
    in_file = "../ref/b.txt"
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
                signal_times = list()
                for intr in incoming:
                    signal_times.append(car_has_path(intr.end, cars))
                intersections.append([curr_strt.end, convert_to_fmt(incoming, signal_times)])
                ttime = ttime - curr_strt.time

    
    
    ### output printing
    print(len(intersections))
    for intr in intersections:
        print(f"{intr[0]}")
        print(f"{len(intr[1])}")
        for strt in intr[1]:
            for key, val in strt.items():
                print(f"{key} {val}")


        
