class Street:
    def __init__(self, line):
        assert line is not None and line != ''
        line = line.replace('\n','')
        self.start, self.end, self.name, self.time = line.split(' ')
        self.start, self.end, self.time = int(self.start), int(self.end), int(self.time)
        print(self.start, self.end, self.name, self.time)

class Car:
    def __init__(self, line):
        assert line != ''
        line = line.replace('\n','')
        line = line.split(' ')
        self.nstreets = line.pop(0) 
        self.path = line
        print(self.nstreets, self.path)

if __name__=='__main__':
    in_file = "../ref/a.txt"
    with open(in_file, 'r') as f:
        line = f.readline()
        line = line.replace('\n', '')
        ttime, n_intrn, n_streets, n_cars, car_score = [int(x) for x in line.split(' ')]
        print(ttime, n_intrn, n_streets, n_cars, car_score)

        streets = list()
        for i in range(n_streets):
            line = f.readline()
            streets.append(Street(line))

        cars = list()
        for i in range(n_cars):
            line = f.readline()
            cars.append(Car(line))

        intersections = list()
        
           

        
