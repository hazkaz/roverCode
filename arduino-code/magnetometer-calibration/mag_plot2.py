from matplotlib.pyplot import scatter
import numpy as np
import argparse
import pandas as pd

parser = argparse.ArgumentParser()
parser.add_argument("data_file",type=str,help="csv file with magnetometer readings")
args = parser.parse_args()

values = pd.read_csv(args.data_file)
print(values)