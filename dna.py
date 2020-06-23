import csv
import sys

# Get the repetitions of each str
def get_rep(big, short, length):
    n_short = len(short)

    max_rep = 0
    reg_rep = 0

    i = 0
    while i != length - n_short:
        if big[i: i + n_short] == short:
            reg_rep += 1
            i += n_short
        else:
            i += 1
            if reg_rep > max_rep:
                max_rep = reg_rep
                reg_rep = 0

    return max_rep

# Check if repetitions match someone in the database and return his/her name
def match(line, array):
    if array == line[1:len(array) + 1]:
        return line[0]
    else:
        return 'No match'

def main():
    #Check if user enters 2 filenames to open
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # Open database
    data_base = sys.argv[1]

    with open(data_base, 'r') as csv_file:
        data = csv.reader(csv_file)
        header = next(data)
        ncol = len(header) - 1
        
        # Open sequence
        seq = sys.argv[2]
        with open(seq) as txt_file:
            dna = txt_file.read()
            n = len(dna)

            # Get array of max reps for each str
            array = [None] * ncol

            for i in range(ncol):
                array[i] = get_rep(dna, header[i + 1], n)

            # Convert array of reps into strings to compare with database
            char_array = [None] * ncol
            qs = ''
            for i in range(ncol):
                char_array[i] = qs + str(array[i]) + qs

            # Check database and find a match
            counter = 1
            for row in data:
                person = match(row, char_array)
                counter += 1
                if person != 'No match':
                    print(person)
                    break




#Run main function
main()
