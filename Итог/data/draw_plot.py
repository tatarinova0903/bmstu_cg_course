# Libs 
import matplotlib.pyplot as plt 

# Text
MSG = "\n\n      Меню \n\n \
    1. График \n \
    2. Перевести время из файла в Латеховский формат (в файл)\n \
    0. Выход \n\n \
    \
    Выбор: \
    "

# Define
EXIT = 0
PLOT = 1
LATEX = 2

NUM = 0
TIME = 1

MAX_THREADS = 32

FILE_NAME = "data.csv"
LATEX_FILE = "for_latex_table.txt"


def get_time_from_file(filename):

    try:
        f = open(filename, "r")

        time_file = []

        for line in (f.readlines()):
            time_file.append([float(num) for num in (line.split("|"))])

        f.close()

        lengths = []
        time = []

        for arr in time_file:
            lengths.append(int(arr[NUM]))
            time.append(arr[TIME])

        print("\n\033[32mSuccess\033[37m: File \"", filename, "\" parsed")

        return lengths, time
    except:
        print("\n\033[31mFailed\033[37m: Mistake occured while parsing \"", filename, "\"\n")

        return [], []

def build_plot():
    virus_count, time = get_time_from_file(FILE_NAME)

    fig = plt.figure(figsize=(10, 7))
    plot = fig.add_subplot()
    plot.plot(virus_count, time)

    plt.grid()
    plt.title("Временные характеристики")
    plt.ylabel("Затраченное время (в миллисекундах)")
    plt.xlabel("Количество частиц")
    
    plt.show()



def time_to_latex_table():
    filename = "data.csv"

    count, time = get_time_from_file(filename)

    f = open(LATEX_FILE, "w")

    f.write("From file: " + filename + "\n\n\n")

    for i in range(len(count)):
        f.write(str(count[i]) + " & " + str(time[i]) + " \\\\ \\hline \n")

    f.close()

    print("\nCreated: \"" + LATEX_FILE + "\" \n\n")


def main():
    option = -1
    while (option != EXIT):
        option = int(input(MSG))
        if (option == PLOT):
            build_plot()
        elif (option == LATEX):
            time_to_latex_table()

if __name__ == "__main__":
    main()
    