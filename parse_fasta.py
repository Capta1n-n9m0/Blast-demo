#!/usr/bin/python3.10
import sys

def extract_genome(fasta_file):
    start_parse = False
    out_file = open(f"{fasta_file}.linegenome", "w")
    with open(fasta_file, "r") as f:
        while line := f.readline():
            if line[0:2] == "//":
                break
            if "ORIGIN" in line:
                start_parse = True
                continue
            if start_parse:
                genome_line = "".join(line.strip().split(" ")[1:])
                print(genome_line, file=out_file)
    out_file.close()

def put_genome_in_one_line(fasta_file):
    with open(f"{fasta_file}.oneline", "w") as fout:
        with open(f"{fasta_file}.linegenome", "r") as fin:
            while l := fin.readline():
                fout.write(l.strip())


def main(args):
    extract_genome(args[1])
    put_genome_in_one_line(args[1])



if __name__ == '__main__':
    main(sys.argv)

